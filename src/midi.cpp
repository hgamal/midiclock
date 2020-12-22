#include <stdint.h>
#include "midi.h"

#define MIDI_STATE_IDLE						0
#define MIDI_STATE_WAIT_FOR_CONTROLLER_ID	1
#define MIDI_STATE_WAIT_FOR_CONTROL_VALUE 	2

// MIDI CHANNEL
uint8_t midi_selected_channel = 1;

// MIDI CLOCK STATES
static uint32_t lastClock;
static uint16_t bpm;
static uint32_t absolute_position = 0;
static uint32_t clk_period_us = 0;

// MIDI MESSAGES STATE
uint8_t midi_curr_cmd = 0;
uint8_t midi_curr_state = MIDI_STATE_IDLE;
uint8_t midi_curr_crtl = 0;
uint8_t midi_curr_data = 0;


void midi_def_clk_event(uint8_t message, uint32_t absolute_position, uint16_t bpm)
{
}

void midi_def_msg_event(uint8_t message, uint8_t control, uint8_t value)
{	
}

static midi_clk_event clk_event_proc = midi_def_clk_event;
static midi_msg_event msg_event_proc = midi_def_msg_event;

void midi_init(midi_msg_event msg_proc, midi_clk_event clock_proc)
{
	if (msg_proc)
		msg_event_proc = msg_proc;

	if (clock_proc)
		clk_event_proc = clock_proc;
}

void midi_evaluate_state(uint8_t receivedByte)
{
	if (receivedByte & 0x80) {
		if (receivedByte == 0xF8) {
			// External MIDI CLock
			
		} else {
			uint8_t midi_curr_channel = receivedByte & 0xf;
			
			if (midi_selected_channel == 0 || // OMNI
				midi_curr_channel == midi_selected_channel-1) {
				midi_curr_cmd = receivedByte & 0xf0;

				if (midi_curr_cmd  == 0xB0)
					midi_curr_state = MIDI_STATE_WAIT_FOR_CONTROLLER_ID;
			}
		}
	} else {
		if (midi_curr_cmd == 0xB0) {		// Control Change
			switch(midi_curr_state) {
				case MIDI_STATE_WAIT_FOR_CONTROLLER_ID:				
					midi_curr_crtl = receivedByte;
					midi_curr_state = MIDI_STATE_WAIT_FOR_CONTROL_VALUE;
					break;

				case MIDI_STATE_WAIT_FOR_CONTROL_VALUE:
					midi_curr_data = receivedByte;
					midi_curr_state = MIDI_STATE_IDLE;
					msg_event_proc(midi_curr_cmd, midi_curr_crtl, midi_curr_data);
					break;

			}
		}
	}
}

void midi_set_channel(uint8_t channel)
{
	midi_selected_channel = channel;
}

void midi_clock_init(uint32_t now, uint16_t startBPM)
{
	absolute_position = 0;
	lastClock = now;
	midi_clock_setBPM(startBPM);
}

void midi_clock_setBPM(uint16_t _bpm)
{
	if (_bpm < MIN_BPM || _bpm > MAX_BPM)
		return;

	bpm = _bpm;
	clk_period_us = 60000000 / (24 * bpm);
}

uint16_t midi_clock_getBPM(void)
{
	return bpm;
}

uint32_t midi_clock_process(uint32_t now)
{
	uint32_t diff;

	// check if there was 'now' overflow (every 4.294,97 seconds or 71,59 minutes)
	if (now > lastClock) 
		diff = now - lastClock;
	else
		diff = 4294967295UL - lastClock + now;

	if (diff  >= clk_period_us) {
		lastClock = now - (diff - clk_period_us);
		
		// Send a clock, bypasing the transmit queue
		if (clk_event_proc)
			clk_event_proc(0xf8, absolute_position, bpm);
		
		absolute_position++;
	}

	return absolute_position;
}

void midi_clock_add(int8_t amount)
{
	unsigned int new_bpm = bpm - amount;
	midi_clock_setBPM(new_bpm);
}

