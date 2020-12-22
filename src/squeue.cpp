#include "squeue.h"

#define QUEUE_SIZE 32

static uint8_t queue[QUEUE_SIZE];
static int8_t inq = 0;
static int8_t outq = 0;

void enqueue(uint8_t x)
{
    int8_t n = (inq + 1) % QUEUE_SIZE;
    if (n == outq) {
        // puts("queue overflow");
        return;
    }

    queue[inq] = x;
    inq = n;
}

uint16_t dequeue()
{
    if (outq == inq)
        return QUEUE_EMPTY;

    uint16_t r =  queue[outq];

    outq = (outq + 1) % QUEUE_SIZE;

    return r;
}

uint8_t empty()
{
	return outq == inq;
}

