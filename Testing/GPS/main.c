#include "GPIO.h"
#include "UART.h"
#include "PORTF.h"
#include "string.h"
#include "I2C.h"
#include "LCD.h"
#include "SYSTICK.h"
#include "gps.h"
uint8_t sw1State  , swCounter = 0;
float distance1[2],distance2[2];
float finalresult=0;
int main()
{
	HAL_PORTF_SW1_SW2_Init();
	HAL_PORTF_LEDS_Init();
	HAL_PORTF_led_Toggle(RED);
	GPS_Init();
	while(1)
	{
	  float temp[2];
		GPS_Read(6);
		GPS_FORMAT(temp);
		sw1State = HAL_PORTF_GetSwitchValue(SW1);
		swCounter+= !sw1State;
		//systick_delay(10);
		if(sw1State == 0)
		{
			if (swCounter&1)
			{
				HAL_PORTF_led_Toggle(RED);
				HAL_PORTF_led_Toggle(GREEN);
				distance1[0] = temp[0];
				distance1[1] = temp[1];
			}
			else
			{
				HAL_PORTF_led_Toggle(GREEN);
				HAL_PORTF_led_Toggle(RED);
				distance2[0] = temp[0];
				distance2[1] = temp[1];
				finalresult = GPS_GetDistance(distance1[0],distance1[1],distance2[0],distance2[1]);
			}
			while(!HAL_PORTF_GetSwitchValue(SW1));
		}
	}
}
