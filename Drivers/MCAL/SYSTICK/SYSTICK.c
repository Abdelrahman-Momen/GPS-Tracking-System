#include "inc/tm4c123gh6pm.h"   // Include the TM4C123 register definitions
#include "SYSTICK.h"


void SysTick_Init(uint32_t delay) {
    NVIC_ST_CTRL_R = 0;                // Disable SysTick during setup
    de
    NVIC_ST_RELOAD_R = delay - 1;      // Set reload value for the specified delay
    NVIC_ST_CURRENT_R = 0;             // Clear the current register value
    NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE | NVIC_ST_CTRL_CLK_SRC; // Enable SysTick with core clock
}

void systick_delay(uint32_t time_ms)
{
uint32_t tick_num;
tick_num = (time_ms * 0.001 * clock)-1 ; // number of clock edges in time in ms
SysTick_Init(tick_num);
while ( NVIC_ST_CTRL_R & 0x00010000 == 0);
}
