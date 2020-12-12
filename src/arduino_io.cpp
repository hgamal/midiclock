#include <avr/io.h>

#include "arduino_io.h"

void pinMode(uint16_t pin, uint8_t mode)
{
	uint16_t addr = (pin >> 3);
	pin = 1 << (pin & 0x7);

	if (mode && OUTPUT) {
		if (addr == PORTB)
			DDRB |= pin;
		else if (addr == PORTC)
			DDRC |= pin;
		else if (addr == PORTD)
			DDRD |= pin;
		else if (addr == PORTE)
			DDRD |= pin;
		else if (addr == PORTF)
			DDRD |= pin;
		return;
	}

	pin = ~pin;
	if (addr == PINB)
		DDRB &= pin;
	else if (addr == PINC)
		DDRC &= pin;
	else if (addr == PIND)
		DDRD &= pin;
	else if (addr == PINE)
		DDRE &= pin;
	else if (addr == PINF)
		DDRF &= pin;

	pin = ~pin;
	if (mode & INPUT_PULLUP)
		* ((volatile uint8_t *) addr) |= pin;
}


void digitalWrite(uint16_t pin, uint8_t val)
{
	volatile uint8_t * addr = (volatile uint8_t *) (pin >> 3);
	pin = 1 << (pin & 0x7);

	if (val)
		*addr |= pin;
	else
		*addr &= ~pin;
}

uint8_t digitalRead(uint16_t pin)
{
	volatile uint8_t * addr = (volatile uint8_t *) (pin >> 3);
	pin &= 0x7;

	return (*addr & (1 << pin)) >> pin;
}

