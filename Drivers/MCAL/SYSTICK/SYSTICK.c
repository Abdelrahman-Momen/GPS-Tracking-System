#include "inc/tm4c123gh6pm.h"   // Include the TM4C123 register definitions
#include "SYSTICK.h"

void SysTick_Init() {
    NVIC_ST_CTRL_R = 0;               													
    NVIC_ST_RELOAD_R = 16000 - 1; 											
    NVIC_ST_CURRENT_R = 0;            													
    NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE | NVIC_ST_CTRL_CLK_SRC;
}

void systick_delay(uint32_t time_ms){
	uint32_t seconds =0;
	for(seconds = 0;seconds<time_ms;seconds++){
		SysTick_Init();
		while ( (NVIC_ST_CTRL_R & 0x00010000) == 0);
	}
}
