#ifndef SYSTICK_h
#define SYSTICK_h

#include <stdint.h>
#define clock 16000000u
void SysTick_Init(uint32_t delay);
void systick_delay(uint32_t time_ms);

#endif
