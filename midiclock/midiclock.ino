#include <U8glib.h>
#include <EEPROM.h>

#include "debounce.h"
#include "micro_panel.h"
#include "squeue.h"
#include "midi.h"

#define TAPSWT  5
#define TAPLED  6
#define RXLED   17
#define CLICK   7

#define TAP1	A3
#define TAP2	A10

// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI  16
#define OLED_CLK   15
#define OLED_DC    A1
#define OLED_CS    A2
#define OLED_RESET A0

#define encoder0PinA 9
#define encoder0PinB 8

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

//U8GLIB_SSD1306_128X64 u8g(OLED_CLK, OLED_MOSI, OLED_CS, OLED_DC, OLED_RESET);
U8GLIB_SSD1306_128X64 u8g(OLED_CS, OLED_DC, OLED_RESET);

const char *main_itens[] = { "BPM View", "Messages", "Config", "Save", NULL };
const char *button_itens[] = { "Normaly Closed", "Normaly Opened", "Latched", "Return", NULL };
const char *config_itens[] = { "MIDI Channel", "MIDI CC TAP Key", "Button 1", "Button 2", "Return", NULL };

MicroPanelMenu *mainMenu;
MicroPanelMenu *configMenu;
MicroPanelCheck *buttonMenu1;
MicroPanelCheck *buttonMenu2;
MicroPanelTerminal *terminal;
MicroPanelBigNumber *bign;
MicroPanelBigNumber *midiChannelPanel;
MicroPanelBigNumber *midiTapCCPanel;

MicroPanel *panel = mainMenu;

uint16_t blinkTime = 0;
uint8_t inTap = 0;

uint8_t buttonPort[2] = { TAP1, TAP2 };
uint8_t buttonState[2] = { 0, 0 };
uint8_t currButton = 0;

#define BT_NORMALY_CLOSED	0
#define BT_NORMALY_OPEN		1
#define BT_LATCHED			2

/** Cponfigurations to be saved on EEPROM **/
uint8_t channel = 1;
uint8_t tapcc = 64;
uint8_t buttonType[2] = { BT_NORMALY_CLOSED, BT_NORMALY_OPEN };
uint16_t bpmConfig = 200;

void readConfig()
{
	channel = EEPROM.read(1);
	tapcc	= EEPROM.read(2);
	buttonType[0] = EEPROM.read(3);
	buttonType[1] = EEPROM.read(4);
	bpmConfig = EEPROM.read(5);
}

void writeConfig()
{
	EEPROM.update(1, channel);
	if (channel > 15)
		channel = 1;
		
	EEPROM.update(2, tapcc);
	if (tapcc > 127)
		tapcc = 64;
		
	EEPROM.update(3, buttonType[0]);
	if (buttonType[0] > BT_LATCHED)
		buttonType[0] = BT_NORMALY_CLOSED;
		
	EEPROM.update(4, buttonType[1]);
	if (buttonType[1] > BT_LATCHED)
		buttonType[1] = BT_NORMALY_OPEN;

	EEPROM.update(5, bpmConfig);
}


void processMIDIClock()
{
	uint32_t now = micros();
	static uint32_t old_time = 0;
	uint32_t diff = now - old_time;

	bpmConfig = 25000000UL / diff;
	midi_clock_setBPM(bpmConfig);
	MicroPanel::reload();

	inTap = 0;
	old_time = now;
}

void processTAP()
{
	static uint32_t old_time = 0;
	uint32_t now = micros();
	uint32_t diff = now - old_time;

	if (!old_time) {
		inTap = 1;
		old_time = now;
		return;
	}	

	if (diff > MAX_TIME) {
		old_time = 0;
		inTap = 0;
		return;
	}

	bpmConfig = 60000000UL / diff;
	midi_clock_setBPM(bpmConfig);
	MicroPanel::reload();

	inTap = 0;
	old_time = now;
}

void sendMIDI(uint8_t message)
{
	if (Serial1.availableForWrite())
		Serial1.write(message);
	else
		enqueue(message);
}

void eventClockProc(uint8_t message, uint32_t absolute_position, uint16_t bpm)
{
	if (absolute_position % 24 == 0)
		blinkTime = 100;

	sendMIDI(message);
}

void eventMidiProc(uint8_t message, uint8_t control, uint8_t value)
{	
	if (((message & 0xf0) == 0xB0) && (control == tapcc) && (value == 127)) {
		uint32_t now = micros();
		processTAP();
    	terminal->printf("\nTAP %d\n", midi_clock_getBPM());
	}
}

void serialEvent1() 
{
	while (Serial1.available()) {
	    // get the new byte:
    	char message = (char) Serial1.read();
    	
		terminal->printf("%02x ", message & 0xff);
		
		midi_evaluate_state(message);
		
		sendMIDI(message);
		
		MicroPanel::reload();
  	}
}

void switchButton(uint8_t id, uint8_t state)
{
	if (buttonState[id] != state) {
		switch(buttonType[id]) {
			case BT_NORMALY_OPEN:
				digitalWrite(buttonPort[id], state);
				break;
				
			case BT_NORMALY_CLOSED:
				digitalWrite(buttonPort[id], !state);
				break;
				
			case BT_LATCHED:
				digitalWrite(buttonPort[id], buttonState[id]);
				break;
		}
		buttonState[id] = state;
	}
}

ISR(TIMER1_COMPA_vect)          // timer compare interrupt service routine
{
	uint32_t now = micros();
	midi_clock_process(now);

	if (inTap) {
	    digitalWrite(TAPLED, HIGH);
	} else {
		if (blinkTime) {
		  if (--blinkTime == 0) {
		    digitalWrite(TAPLED, LOW);
		    switchButton(0, LOW);
		    switchButton(1, LOW);
		  } else {
		    digitalWrite(TAPLED, HIGH);
		    switchButton(0, HIGH);
		    switchButton(1, HIGH);
		  }
		}
	}
}

void initCounter(void)
{
	cli();           // disable all interrupts
	
	// initialize timer1 
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1  = 0;
	// N = Precaler factor 1, 8, 64, 256, 1024) 
	// CSN2 CSN1 CSN0 Description
	//    0    0    0 No clock source (Timer/Counter stopped)
	//    0    0    1 clkI/O/(No prescaling)
	//    0    1    0 clkI/O/8 (From prescaler)
	//    0    1    1 clkI/O/64 (From prescaler)
	//    1    0    0 clkI/O/256 (From prescaler)
	//    1    0    1 clkI/O/1024 (From prescaler)
	//    1    1    0 External clock source on T0 pin. Clock on falling edge.
	//    1    1    1 External clock source on T0 pin. Clock on rising edge.
	// F = Flck / (2 * N * (1 + OCRnX))
	// OCRnX = Fclk / (F * 2 * N )  + 1
	// F = 1ms => 
#if F_CPU == 16000000
	//OCR1A = 311;            // 100 Hz => 10 ms (100.16 Hz => 9.984 ms)
	OCR1A = 30;               // 1000 Hz => 1 ms (1008.06 Hz => 0.992 ms)
	TCCR1B |= (1 << CS12);    // 256 prescaler 
#else
	//OCR1A = 624;            // 100 Hz => 10 ms (100.00 Hz => 10 ms)
	//OCR1A = 61;             // 1000 Hz => 1 ms (1008.06 Hz => 0.992 ms)
	TCCR1B |= (1 << CS10) | (1 << CS11);    // 64 prescaler 
#endif
	TCCR1B |= (1 << WGM12);   // CTC mode
	TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
	
	sei(); 
}

/** this code rules what occurs when the dial button is clicked **/
void menuClick()
{
	if (panel == mainMenu) {
		uint8_t x = mainMenu->getCurrItem();
		switch(x) {
		case 0:
			panel = bign;
			break;

		case 1:
			panel = terminal;
			break;

		case 2:
			panel = configMenu;
			break;

		case 3:
			writeConfig();
			break;
		}  
	} else if (panel == buttonMenu1 || panel == buttonMenu2) {
		uint8_t x = ((MicroPanelCheck *) panel)->getCurrItem();
		if (x == 3)
			panel = configMenu;
		else
			*(((MicroPanelCheck *) panel)->checkedItem) = x;
	} else if (panel == configMenu) {
		uint8_t x = ((MicroPanelMenu *) panel)->getCurrItem();
		switch(x) {
		case 0:
			panel = midiChannelPanel;
			break;
		case 1:
			panel = midiTapCCPanel;
			break;
		case 2:
			panel = buttonMenu1;
			break;
		case 3:
			panel = buttonMenu2;
			break;		
		case 4:
			panel = mainMenu;	
			break;
		}
	} else if (panel == midiChannelPanel || panel == midiTapCCPanel) {
		panel = configMenu;
	} else  {
		panel = mainMenu;
	}
	
	MicroPanel::reload();
}

void setup()
{
	Serial.begin(9600);
	Serial1.begin(31250);
	midi_init(eventMidiProc, eventClockProc);

	pinMode(1, OUTPUT);
	pinMode(RXLED, OUTPUT);
	pinMode(TAPLED,OUTPUT);
	pinMode(TAP1, OUTPUT);
	pinMode(TAP2, OUTPUT);
	pinMode(OLED_MOSI, OUTPUT);
	pinMode(OLED_CLK, OUTPUT);
	pinMode(OLED_DC, OUTPUT);
	pinMode(OLED_CS, OUTPUT);
	pinMode(OLED_RESET, OUTPUT);

	pinMode(0, INPUT);
	pinMode(CLICK,INPUT);
	pinMode(TAPSWT,INPUT);
	pinMode(encoder0PinA, INPUT);
	pinMode(encoder0PinB, INPUT);

	MicroPanel::init(&u8g);
	
	u8g.setContrast(255);
	u8g.setColorIndex(1);
	u8g.setFont(u8g_font_6x13B);
	
	mainMenu = new MicroPanelMenu(main_itens);
	terminal = new MicroPanelTerminal();
	buttonMenu1 = new MicroPanelCheck(button_itens, &buttonType[0]);
	buttonMenu2 = new MicroPanelCheck(button_itens, &buttonType[1]);
	configMenu = new MicroPanelMenu(config_itens);
	bign = new MicroPanelBigNumber("bpm", 0);
	midiChannelPanel = new MicroPanelBigNumber("channel", 0);
	midiTapCCPanel = new MicroPanelBigNumber("TAP CC", 0);
	
	panel = bign;
	
	initCounter();

	readConfig();

	midi_set_channel(channel);
	midi_clock_init(micros(), bpmConfig);
	
	MicroPanel::reload();
	terminal->puts("Messages\n");
}

void loop() 
{
	/** purge serial characters **/
	if (!empty()) {
		noInterrupts();
		if (Serial1.availableForWrite())
			Serial1.write(dequeue());
		interrupts();
	}
	
	static uint8_t click=0;
	uint8_t n = digitalRead(CLICK);
	if (debounce(!n, &click) == KEY_DOWN)
		menuClick();

	static uint8_t tap=0;
	n = digitalRead(TAPSWT);
	if (debounce(!n, &tap) == KEY_DOWN)
		processTAP();

	static uint32_t lastCheck = 0;
	static uint8_t encoder0PinALast = HIGH;
	static int16_t encoderOldPosition = 0;
	static int16_t encoderPosition = 0;
	uint32_t now = micros();
	if (now - lastCheck > 200) {
		lastCheck = now;
		n = digitalRead(encoder0PinA);
		if (encoder0PinALast && !n) {
			if (digitalRead(encoder0PinB))
				encoderPosition--;
			else
				encoderPosition++;

			digitalWrite(RXLED, digitalRead(RXLED) ^ 1);
		}
		encoder0PinALast = n;

		/** this code rules what occurs when the dial button is used **/
		if (encoderPosition != encoderOldPosition) {
			uint8_t inc = encoderPosition > encoderOldPosition ? -1 : 1;
			if(!digitalRead(TAPSWT)) 
				inc *= 10;

			if (panel == bign) {
				midi_clock_add(inc);
				MicroPanel::reload();
			} else if (panel == midiChannelPanel) {
				channel = (channel - inc) & 15;
				MicroPanel::reload();
				midi_set_channel(channel);
			} else if (panel == midiTapCCPanel) {
				tapcc = (tapcc - inc) & 127;
				MicroPanel::reload();
			} else if (panel != terminal) {
				((MicroPanelMenu *)panel)->updateMenu(encoderPosition > encoderOldPosition ? 1 : -1);
				MicroPanel::reload();
				inTap = 0;
			}

			encoderOldPosition = encoderPosition;
		}
	}
	
	/** this code rules what is drawed to screen **/
	if (panel == bign)
		bpmConfig = bign->number = midi_clock_getBPM();
	else if (panel == midiChannelPanel)
		midiChannelPanel->number = channel;
	else if (panel == midiTapCCPanel)
		midiTapCCPanel->number = tapcc;

	panel->refresh();
}
