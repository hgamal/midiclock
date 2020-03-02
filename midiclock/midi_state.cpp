#include <stdint.h>
#include "midi.h"

//#include <HardwareSerial.h>
//extern HardwareSerial Serial;

#define MIDI_STATE_IDLE						0
#define MIDI_STATE_WAIT_FOR_CONTROLLER_ID	1
#define MIDI_STATE_WAIT_FOR_CONTROL_VALUE 	2

uint8_t midi_selected_channel = 1;

uint8_t midi_curr_cmd = 0;
uint8_t midi_curr_state = MIDI_STATE_IDLE;
uint8_t midi_curr_crtl = 0;
uint8_t midi_curr_data = 0;

void midi_evaluate_state(uint8_t receivedByte, midi_event proc)
{
	if (receivedByte & 0x80) {
		uint8_t midi_curr_channel = receivedByte & 0xf;
		
		if (midi_curr_channel == midi_selected_channel) {
			midi_curr_cmd = receivedByte & 0xf0;

			if (midi_curr_cmd  == 0xB0)
				midi_curr_state = MIDI_STATE_WAIT_FOR_CONTROLLER_ID;
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
					proc(midi_curr_cmd, midi_curr_crtl, midi_curr_data);
					break;

			}
		}
	}
}

void midi_set_channel(uint8_t channel)
{
	midi_selected_channel = channel;
}
