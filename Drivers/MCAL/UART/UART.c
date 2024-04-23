#include "UART.h"
#include <stdint.h>

unsigned char MCAL_UART_ReadAvailable(UART_Select UART_NO){
	switch(UART_NO)
	{
		case UART0:
		return ((UART0_FR & UART_FR_RXFE) == UART_FR_RXFE) ? 1 : 0;  //empty = 1 , 0 otherwise
		break;
		
		case UART1:
		return ((UART1_FR & UART_FR_RXFE) == UART_FR_RXFE) ? 1 : 0;
		break;
		
		case UART2:
		return ((UART2_FR & UART_FR_RXFE) == UART_FR_RXFE) ? 1 : 0;	
		break;
		
		case UART3:
		return ((UART3_FR & UART_FR_RXFE) == UART_FR_RXFE) ? 1 : 0;;	
		break;
		
		case UART4:
		return ((UART4_FR & UART_FR_RXFE) == UART_FR_RXFE) ? 1 : 0;	
		break;
		
		case UART5:
		return ((UART5_FR & UART_FR_RXFE) == UART_FR_RXFE) ? 1 : 0;
		break;
		
		case UART6:
		return ((UART6_FR & UART_FR_RXFE) == UART_FR_RXFE) ? 1 : 0;
		break;
		
		case UART7:
		return ((UART7_FR & UART_FR_RXFE) == UART_FR_RXFE) ? 1 : 0;
		break;
		
		default : return 0; break;
	}
}




unsigned char MCAL_UART_SendAvailable(UART_Select UART_NO){
	switch(UART_NO)
	{
		case UART0:
		return ((UART0_FR & UART_FR_TXFF) == UART_FR_TXFF) ? 1 : 0;  //full = 1 , 0 otherwise
		break;
		
		case UART1:
		return ((UART1_FR & UART_FR_TXFF) == UART_FR_TXFF) ? 1 : 0;	
		break;
		
		case UART2:
		return ((UART2_FR & UART_FR_TXFF) == UART_FR_TXFF) ? 1 : 0;
		break;
		
		case UART3:
		return ((UART3_FR & UART_FR_TXFF) == UART_FR_TXFF) ? 1 : 0;	
		break;
		
		case UART4:
		return ((UART4_FR & UART_FR_TXFF) == UART_FR_TXFF) ? 1 : 0;	
		break;
		
		case UART5:
		return ((UART5_FR & UART_FR_TXFF) == UART_FR_TXFF) ? 1 : 0;
		break;
		
		case UART6:
	  return ((UART6_FR & UART_FR_TXFF) == UART_FR_TXFF) ? 1 : 0;
		break;
		
		case UART7:
		return ((UART7_FR & UART_FR_TXFF) == UART_FR_TXFF) ? 1 : 0;	
		break;
		
		default :  return 0; break;
	}
}


void MCAL_UART_SendChar(UART_Select UART_NO , uint8_t Data){
	
	switch(UART_NO)
	{
		case UART0:
		while(MCAL_UART_SendAvailable(UART_NO));
		UART0_DR = Data;
		break;
		
		case UART1:
		while(MCAL_UART_SendAvailable(UART_NO));
		UART1_DR = Data;
		break;
		
		case UART2:
		while(MCAL_UART_SendAvailable(UART_NO));
		UART2_DR = Data;
		break;
		
		case UART3:
		while(MCAL_UART_SendAvailable(UART_NO));
		UART3_DR = Data;
		break;
		
		case UART4:
		while(MCAL_UART_SendAvailable(UART_NO));
		UART4_DR = Data;
		break;
		
		case UART5:
		while(MCAL_UART_SendAvailable(UART_NO));
		UART5_DR = Data;
		break;
		
		case UART6:
		while(MCAL_UART_SendAvailable(UART_NO));
		UART6_DR = Data;
		break;
		
		case UART7:
		while(MCAL_UART_SendAvailable(UART_NO));
		UART7_DR = Data;
		break;
		
		default : break;
	}
}

uint8_t MCAL_UART_ReadChar(UART_Select UART_NO){

	switch(UART_NO)
	{
		case UART0:
		while(MCAL_UART_ReadAvailable(UART_NO));
		return (uint8_t)(UART0_DR &= UART_MASK) ;
		break;
		
		case UART1:
		while(MCAL_UART_ReadAvailable(UART_NO));
		return (uint8_t)(UART1_DR &= UART_MASK) ;
		break;
		
		case UART2:
		while(MCAL_UART_ReadAvailable(UART_NO));
		return (uint8_t)(UART2_DR &= UART_MASK) ;
		break;
		
		case UART3:
		while(MCAL_UART_ReadAvailable(UART_NO));
		return (uint8_t)(UART3_DR &= UART_MASK) ;
		break;
		
		case UART4:
		while(MCAL_UART_ReadAvailable(UART_NO));
		return (uint8_t)(UART4_DR &= UART_MASK) ;
		break;
		
		case UART5:
		while(MCAL_UART_ReadAvailable(UART_NO));
		return (uint8_t)(UART5_DR &= UART_MASK) ;
		break;
		
		case UART6:
		while(MCAL_UART_ReadAvailable(UART_NO));
		return (uint8_t)(UART6_DR &= UART_MASK) ;
		break;
		
		case UART7:
		while(MCAL_UART_ReadAvailable(UART_NO));
		return (uint8_t)(UART7_DR &= UART_MASK) ;
		break;
		
		default : break;
	} 
}


void MCAL_UART_SendString(UART_Select UART_NO, uint8_t *str) {
    while (*str != '\0') {
        MCAL_UART_SendChar(UART_NO, *str);
        str++;
    }
}

void MCAL_UART_ReadString(uint8_t UART_NO, uint8_t *buffer) {
    int i = 0;
    while (1) {  // Continue indefinitely
        char c = MCAL_UART_ReadChar(UART_NO);
        if (c == '\0') {
            break;  // Break if null terminator is received
        }
        buffer[i++] = c;
    }
    buffer[i] = '\0';  // Null-terminate the string
}

