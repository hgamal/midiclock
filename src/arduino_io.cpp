#include <avr/io.h>
#include <u8g.h>

#include "arduino_io.h"

void pinMode(uint8_t pin, uint8_t mode)
{
	if (mode & OUTPUT)
		u8g_SetPinOutput(pin);
	else
		u8g_SetPinInput(pin);

	if (mode & INPUT_PULLUP)
		u8g_SetPinOutput(pin);
}


void digitalWrite(uint8_t pin, uint8_t val)
{
	u8g_SetPinLevel(pin, val);
}

uint8_t digitalRead(uint8_t pin)
{
	return u8g_GetPinLevel(pin);
}

