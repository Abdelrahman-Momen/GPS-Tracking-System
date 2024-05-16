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

uint16_t EEPROM_address = 0x0000 , word_counter = 0,i;
float firstdistance[3]={-1,-1,-1}, seconddistance[3] = {-1,-1,-1}; 
char str_buffer[10];


int main()
{	
	MCAL_EEPROM_write(&EEPROM_address,seconddistance,2);
	word_counter += 2;
	MCAL_UART_SendChar(UART0,'U');
	MCAL_UART_SendChar(UART0,'\n');
	while(MCAL_UART_ReadChar(UART0) != 'U');
	MCAL_UART_SendChar(UART0,'\n');
	EEPROM_address=0;
	while(word_counter)
	{
					MCAL_EEPROM_read(&EEPROM_address,firstdistance,2);
					sprintf(str_buffer,"%f",firstdistance[0]);
					MCAL_UART_SendString(UART0,(uint8_t*)str_buffer);
					MCAL_UART_SendChar(UART0,'\n');
					sprintf(str_buffer,"%f",firstdistance[1]);
					MCAL_UART_SendString(UART0,(uint8_t*)str_buffer);
					MCAL_UART_SendChar(UART0,'\n');
					word_counter -= 2;
					MCAL_UART_SendString(UART0,"Done");
					MCAL_UART_SendChar(UART0,'\n');
	}
	while(1);
}