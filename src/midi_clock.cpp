#include <avr/io.h>
#include "midi.h"

static uint32_t lastClock;
static uint16_t bpm;
static uint32_t absolute_position = 0;
static uint32_t clk_period_us = 0;

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

#ifdef USB
	printf("bpm=%d\n", bpm);
#endif

#ifdef DISPLAY
	odisplay_printf("\rbpm=%d %ld\n", bpm, clk_period_us);
#endif
}

uint16_t midi_clock_getBPM(void)
{
	return bpm;
}

uint32_t midi_clock_process(uint32_t now, midi_clock_event event_proc)
{
	uint32_t diff = now - lastClock;
	if (diff  >= clk_period_us) {
		lastClock = now - (diff - clk_period_us);
		
		// Send a clock, bypasing the transmit queue
		if (event_proc)
			event_proc(0xf8, absolute_position, bpm);
		
		absolute_position++;
	}

	return absolute_position;
}

void midi_clock_add(int8_t amount)
{
	unsigned int new_bpm = bpm - amount;
	midi_clock_setBPM(new_bpm);
}

