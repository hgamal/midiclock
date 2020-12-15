#pragma once

#define MKPORT(io, pin)	((io << 3) + (pin))

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

// compatible to uint8_t u8g_Pin(uint8_t port, uint8_t bitpos);

void digitalWrite(uint8_t pin, uint8_t value);
uint8_t digitalRead(uint8_t pin);
void pinMode(uint8_t pin, uint8_t mode);
