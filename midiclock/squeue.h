#pragma once

#include <stdint.h>

#define QUEUE_EMPTY	0xffff

#ifdef __cplusplus
extern "C" {
#endif

void enqueue(uint8_t x);
uint16_t dequeue(void);
uint8_t empty();

#ifdef __cplusplus
}
#endif

