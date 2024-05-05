#include "GPIO.h"
#include "PORTF.h"
#include "string.h"
#include "I2C.h"
#include "LCD.h"
#include "SYSTICK.h"

int main()
{
	MCAL_I2C_Init_master(I2C3);
	SysTick_Init(10);
	LCD_Init();
	lcd_send_string("Mohamed");
	while(1)
	{
	}
}