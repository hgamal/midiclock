#pragma once

#define KEY_UP       1
#define KEY_DOWN     2
#define KEY_NOCHANGE 0

uint8_t debounce(uint8_t value, uint8_t *state);
