#ifndef SYSTICK_h
#define SYSTICK_h

#include <stdint.h>
#define clock 16000000u
void SysTick_Init();
void systick_delay(uint32_t time_ms);

#endif
