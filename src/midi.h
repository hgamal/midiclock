#pragma once

#include <stdint.h>

#define MIN_BPM		30UL
#define MAX_BPM		260UL

#define MIN_TIME	(60000000UL / MAX_BPM)
#define MAX_TIME	(60000000UL / MIN_BPM)

#ifdef __cplusplus
//extern "C" {
#endif

extern uint8_t midi_curr_channel;
extern uint8_t midi_curr_cmd;
extern uint8_t midi_curr_state;
extern uint8_t midi_curr_crtl;
extern uint8_t midi_curr_data;

typedef void (*midi_clock_event)(uint8_t, uint32_t, uint16_t);
typedef void (*midi_event)(uint8_t, uint8_t, uint8_t);

void midi_evaluate_state(uint8_t ReceivedByte, midi_event);
void midi_set_channel(uint8_t channel);

void midi_clock_init(uint32_t now, uint16_t bpm);
void midi_clock_setBPM(uint16_t bpm);
void midi_clock_add(int8_t amount);
uint16_t midi_clock_getBPM(void);
uint32_t midi_clock_process(uint32_t now, midi_clock_event);
//uint8_t midi_clock_processTAP(uint32_t now);

#ifdef __cplusplus
//}
#endif

