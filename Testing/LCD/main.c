#include "GPIO.h"
#include "PORTF.h"
#include "string.h"
#include <stdio.h>
#include "I2C.h"
#include "LCD_GPIO.h"
#include "SYSTICK.h"
#include "EEPROM.h"
#include "UART.h"
#include "gps.h"

int main(){
	LCD_INIT();
	LCD_ClR();
	LCD_SEND_STRING("Hello, guys!!");
	LCD_SetCursor(1,0);
	LCD_SEND_STRING("GPS Project ;)");
	systick_delay(5000);
	LCD_ClR();
	LCD_SEND_STRING("This is LCD test");
	LCD_SetCursor(1,7);
	LCD_SEND_STRING("Byee :3");
}