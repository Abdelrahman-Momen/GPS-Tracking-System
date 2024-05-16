#include "PORTF.h"
#include "gps.h"

uint8_t Switch1State, oldSwitch1State = 1;

int main()
{
	HAL_PORTF_SW1_SW2_Init();
	HAL_PORTF_LEDS_Init();
	while(1)
	{
		Switch1State = HAL_PORTF_GetSwitchValue(SW1);
		if(!Switch1State , oldSwitch1State){
			HAL_PORTF_led_Toggle(GREEN);
		}
	}
}