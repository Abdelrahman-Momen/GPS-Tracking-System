#include "GPIO.h"
#include "UART.h"
#include "PORTF.h"
#include "string.h"

int main(){
	HAL_PORTF_LEDS_Init();
	MCAL_UART_CONFIG(0, 8, UART_PARITY_DISABLE, 1, 9600, 16);
	while(1){
		char a[10];
		MCAL_UART_SendString(0,"Enter:\n");
		MCAL_UART_ReadString(0, a);
		MCAL_UART_SendString(0,"\n");
		if(!strcmp(a,"RedOn")){
			HAL_PORTF_SetLedValue(RED,1);
		}
		if(!strcmp(a,"RedOff")){
			HAL_PORTF_SetLedValue(RED,0);
		}
		if(!strcmp(a,"GreenOn")){
			HAL_PORTF_SetLedValue(GREEN,1);
		}
		//bla bla bla
	}
}