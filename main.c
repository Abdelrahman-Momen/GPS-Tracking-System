#include "GPIO.h"
#include "UART.h"
#include "PORTF.h"
#include "string.h"
#include "I2C.h"
#include "LCD.h"
#include "SYSTICK.h"
#include "gps.h"

int main()
{
	HAL_PORTF_SW1_SW2_Init();
	HAL_PORTF_LEDS_Init();
	while(1)
	{
		uint8_t Switch1 = (uint8_t)HAL_PORTF_GetSwitchValue(SW1);
		if(!Switch1){
			HAL_PORTF_SetLedValue(GREEN,LED_ON);
		}
		else{
			HAL_PORTF_SetLedValue(GREEN,LED_OFF);
		}
	}
}
