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

uint8_t state =0;
float totaldistance=0,temp;
uint16_t EEPROM_address = 0x0002 , word_counter = 0,i;
float firstdistance[3]={-1,-1,-1}, seconddistance[3] = {-1,-1,-1}; 
char str_buffer[10];

int main()
{
	HAL_PORTF_LEDS_Init();
	HAL_PORTF_SW1_SW2_Init();
	HAL_PORTF_SetLedValue(RED,LED_ON);
	MCAL_UART_CONFIG(UART2,8,0,1,104,11);
	MCAL_UART_CONFIG(UART0,8,0,1,104,11);
	MCAL_EEPROM_Init();
	LCD_INIT();
	LCD_SEND_STRING("Let's Start");
	systick_delay(1000);
	LCD_ClR();
	LCD_SEND_STRING("Choose a mode: ");
	LCD_SetCursor(1,0);
	LCD_SEND_STRING("R: SW1 S: SW2");
	while(1){
		if(!HAL_PORTF_GetSwitchValue(4)){
			MCAL_EEPROM_massErase();
			break;
		}
		else if(!HAL_PORTF_GetSwitchValue(0)){
			state =0;
			break;
		}
	}
	while(1)
	{
		while(!HAL_PORTF_GetSwitchValue(0)){
			 state = 1;
				LCD_ClR();
				LCD_SEND_STRING("Finished :)");
				systick_delay(2000);
				LCD_ClR();
				LCD_SEND_STRING("Sending Data ");
				LCD_SetCursor(1,0);
				LCD_SEND_STRING("from EEPROM....");
		}
		if(state == 0){
			firstdistance[0] = seconddistance[0];
			firstdistance[1] = seconddistance[1];
			GPS_Read();
			GPS_FORMAT(seconddistance);
			if(firstdistance[0] == -1){
				firstdistance[0] = seconddistance[0];
				firstdistance[1] = seconddistance[1];
			}
			temp = GPS_GetDistance(firstdistance[0],firstdistance[1],seconddistance[0],seconddistance[1]);
			
			if(temp<10 && seconddistance[2] >1){
				totaldistance+= temp;
				MCAL_EEPROM_write(&EEPROM_address,seconddistance,2);
				word_counter += 2;
				MCAL_EEPROM_write_specific(word_counter);
			}
			else{
				firstdistance[0] = -1;
				firstdistance[1] = -1;
				seconddistance[0]=-1;
				seconddistance[1]=-1;
			}
			LCD_ClR();
			LCD_SEND_STRING("Total Distance: ");
			LCD_SetCursor(1,0);
			LCD_Send_Num(totaldistance);
		}
		else{
				HAL_PORTF_SetLedValue(RED,LED_OFF);
				HAL_PORTF_SetLedValue(GREEN,LED_ON);
				MCAL_UART_SendChar(UART0,'U');
				MCAL_UART_SendChar(UART0,'\n');
				while(MCAL_UART_ReadChar(UART0) != 'U');
				MCAL_UART_SendChar(UART0,'\n');
				EEPROM_address=2;
			  MCAL_EEPROM_read_specific(&word_counter);
				while(word_counter)
				{
					MCAL_EEPROM_read(&EEPROM_address,seconddistance,2);
					sprintf(str_buffer,"%f",seconddistance[0]);
					MCAL_UART_SendString(UART0,(uint8_t*)str_buffer);
					MCAL_UART_SendChar(UART0,'\n');
					sprintf(str_buffer,"%f",seconddistance[1]);
					MCAL_UART_SendString(UART0,(uint8_t*)str_buffer);
					MCAL_UART_SendChar(UART0,'\n');
					
					word_counter -= 2;
				}
				MCAL_UART_SendString(UART0,"Done");
				MCAL_UART_SendChar(UART0,'\n');
				systick_delay(1000);
				LCD_ClR();
				LCD_SEND_STRING("Transfer Done :)");
		}
	}
}