#include <U8glib.h>
#include "micro_panel.h"

//#include <HardwareSerial.h>
//extern HardwareSerial Serial;

static char buffer[4][22];
static uint8_t x=0, y=0;
static char _buffer[64];
static uint8_t _reload = 0;
static uint8_t state=0;

class U8GLIB *MicroPanel::u8g = NULL;

void MicroPanel::init(U8GLIB *_u8g)
{
	u8g = _u8g; 
}

void MicroPanel::reload()
{
	state = 0;
	if (_reload == 255)
		return;

	_reload++;
}

void MicroPanel::refresh(MicroPanel *target)
{
	if (!_reload)
		return;

	//sprintf(buffer, "state=%d, reload = %d", state, reload);
	//Serial.println(buffer);
	
	if (state == 0) {
		u8g->firstPage();
		state = 1;
		return;
	}
	
	if (state == 1) {
		target->draw();
		state = 2;
		return;
	}
	
	if (state == 2 && u8g->nextPage()) {
		state = 1;
		return;
	}

	//Serial.println("reload = 0");

	if (_reload)
		_reload--;
	state = 0;
}

void MicroPanel::refresh()
{
	refresh(this);
}

MicroPanel::MicroPanel()
{
}

MicroPanelMenu::MicroPanelMenu(const char **_menuItens):
	MicroPanel()
{
	menuStrings = _menuItens;
	menuItensCount = 0;
	for (const char **p = menuStrings; *p; p++)
		menuItensCount++;
}

void MicroPanelMenu::draw() {
	uint8_t i, h;
	u8g_uint_t w, d;
	u8g->setFont(u8g_font_6x13);
	u8g->setFontRefHeightText();
	u8g->setFontPosTop();
	h = u8g->getFontAscent()-u8g->getFontDescent();
	w = u8g->getWidth();
	for(i = 0; i < menuItensCount; i++) {        // draw all menu items
		// Serial.println(menuStrings[i]);
		d = (w-u8g->getStrWidth(menuStrings[i]))/2;
		u8g->setDefaultForegroundColor();
		if (i == menuCurrent) {                   // current selected menu item
			u8g->drawBox(0, i*h+1, w, h);            // draw cursor bar
			u8g->setDefaultBackgroundColor();
		}
		
		u8g->drawStr(d, i*h, menuStrings[i]);
	}
}

void MicroPanelMenu::updateMenu(int8_t dir)
{
	if (dir == 1) {
	menuCurrent++;
	if (menuCurrent >= menuItensCount)
		menuCurrent = 0;
	} else if (dir == -1) {
		if (menuCurrent == 0)
			menuCurrent = menuItensCount;
		menuCurrent--;
	}
}

uint8_t MicroPanelMenu::getCurrItem(void)
{
	return menuCurrent;
}

void MicroPanelMenu::setCurrItem(uint8_t pos)
{
    menuCurrent = pos;
    
    if (menuCurrent > menuItensCount)
      menuCurrent = 0;
    else if (menuCurrent < 0)
      menuCurrent = menuItensCount-1;
}

MicroPanelCheck::MicroPanelCheck(const char **_menuItens, uint8_t *checkItem): 
		MicroPanelMenu(_menuItens), checkedItem(checkItem) 
{
}

static const uint8_t check_bitmap[] U8G_PROGMEM = {
  0x01,         // 00000001 
  0x03,         // 00000011
  0x02,         // 00000010
  0xc6,         // 11000110
  0x64,         // 01100100 
  0x34,         // 00110100
  0x18,         // 00011000 
  0x08          // 00001000
};

void MicroPanelCheck::draw() {
  uint8_t i, h;

  u8g_uint_t w, d;
  u8g->setFont(u8g_font_6x13);
  u8g->setFontRefHeightText();
  u8g->setFontPosTop();
  h = u8g->getFontAscent()-u8g->getFontDescent();
  w = u8g->getWidth();
  for(i = 0; i < menuItensCount; i++) {        // draw all menu items
    // Serial.println(menuStrings[i]);
    d = (w-u8g->getStrWidth(menuStrings[i]))/2;
    u8g->setDefaultForegroundColor();
    if (i == menuCurrent) {                   // current selected menu item
      u8g->drawBox(0, i*h+1, w, h);            // draw cursor bar
      u8g->setDefaultBackgroundColor();
    }
    u8g->drawStr(d, i*h, menuStrings[i]);
	
    if (i == *checkedItem)
		u8g->drawBitmapP(2, i*h+2, 1, 8, check_bitmap);
  }
}

MicroPanelTerminal::MicroPanelTerminal():MicroPanel()
{
	clear();
}

void MicroPanelTerminal::clear()
{
	x = y = 0;
	memset(buffer, 0, sizeof(buffer));
}


void MicroPanelTerminal::draw()
{
	u8g->setFont(u8g_font_6x13);
	u8g->setDefaultForegroundColor();
	uint8_t h = u8g->getFontAscent()-u8g->getFontDescent();
	uint8_t t = 0;
	u8g->drawStr(0, t, (const char *) buffer);
	u8g->drawStr(0, t+=h, (const char *) (buffer+1));
	u8g->drawStr(0, t+=h, (const char *) (buffer+2));
	u8g->drawStr(0, t+=h, (const char *) (buffer+3));
}

void MicroPanelTerminal::puts(const char *p)
{
	while (*p) {
		if (*p != '\n' && *p != '\r')
			buffer[y][x] = *p;

		x++;
		if (x > 20 || *p == '\n') {
			x = 0;
			y++;
			if (y > 3) {
				y = 3;
				memcpy(buffer[0], buffer[1], sizeof(buffer[y])*3);
				memset(buffer[y], 0, sizeof(buffer[y]));
			}
		}

		if (*p == '\r') {
			x = 0;
			memset(buffer[y], 0, sizeof(buffer[y]));
		}

		p++;
	}

	buffer[0][21] = 0;
	buffer[1][21] = 0;
	buffer[2][21] = 0;
	buffer[3][21] = 0;
}

int MicroPanelTerminal::printf(const char *format, ...)
{
	va_list ap;
	int r = 0;

	va_start(ap, format);
	r = vsprintf(_buffer, format, ap);
	va_end(ap);

	puts(_buffer);

	return r;
}

MicroPanelBigNumber::MicroPanelBigNumber(const char *_title, uint16_t _number):
	title(_title), number(_number), MicroPanel()
{	
}
	
void MicroPanelBigNumber::draw() 
{
	uint8_t w;
	uint8_t h;
	if (title) {
		u8g->setFont(u8g_font_6x13);
		w = u8g->getStrWidth(title);
		h = u8g->getFontAscent() - u8g->getFontDescent();
		u8g->drawStr((128-w)/2, h, title);
	}

	u8g->setFont(u8g_font_fub35n);
	u8g->setDefaultForegroundColor();
	sprintf(_buffer, "%d", number);
	h = u8g->getFontAscent() - u8g->getFontDescent();
	w = u8g->getStrWidth(_buffer);
	u8g->drawStr((128-w)/2, 64-(64-h)/2, _buffer);
}








