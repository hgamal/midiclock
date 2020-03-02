#include <stdint.h>
#include "debounce.h"

uint8_t debounce(uint8_t value, uint8_t *state)
{
  if (value)
    switch(*state) {
    case 0:
      *state = 1;
      break;

    case 1:
      *state = 2;
      return KEY_DOWN;
      break;

    default:
      break;
    }
  else
    if (*state) {
      *state = 0;
      return KEY_UP;
    }

  return KEY_NOCHANGE;
}

