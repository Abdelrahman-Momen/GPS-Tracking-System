#include "LCD_GPIO.h"
#include "string.h"
#include "stdio.h"
#include "SYSTICK.h"

void LCD_GPIO_INIT()
{
		int i =0;
		MCAL_GPIO_Init(PORTE);
		for(i=1;i<4;i++){
			MCAL_GPIO_Digital_INIT(PORTE,i);
			MCAL_GPIO_Digital_PIN_MODE(PORTE,i,Output,1);
		} 
		MCAL_GPIO_Init(PORTB);
		for(i=4;i<=7;i++){
			MCAL_GPIO_Digital_INIT(PORTB,i);
			MCAL_GPIO_Digital_PIN_MODE(PORTB,i,Output,1);
		} 
}

void LCD_INIT()
{	
		LCD_GPIO_INIT();
	
		LCD_Send_CMD(0x33);
		LCD_Send_CMD(0x32);
		LCD_Send_CMD(0x28);	
		LCD_Send_CMD(0x01);
		LCD_Send_CMD(0x0C);                        		                  	  
}
void LCD_Send_CMD(uint8_t data)
{
	
	  MCAL_GPIO_Write_Pin(PORTE,RS_PIN,0);
    MCAL_GPIO_Write_Pin(PORTE,RW_PIN,0);

    MCAL_GPIO_Write_Pin(PORTE,EN_PIN,1);
    systick_delay(1);                
		GPIO_PORTB_DATA = (GPIO_PORTB_DATA&0x0F)|(data&0xF0);
    systick_delay(1);                  
    MCAL_GPIO_Write_Pin(PORTE,EN_PIN,0);
    systick_delay(1);                 
    MCAL_GPIO_Write_Pin(PORTE,EN_PIN,1);
    systick_delay(1);                
		GPIO_PORTB_DATA = (GPIO_PORTB_DATA&0x0F)|((data&0xF)<<4);
    systick_delay(1);                   
    MCAL_GPIO_Write_Pin(PORTE,EN_PIN,0);
    systick_delay(1);        
}
void LCD_Send_Data(uint8_t data)
{
		MCAL_GPIO_Write_Pin(PORTE,RS_PIN,1);
    MCAL_GPIO_Write_Pin(PORTE,RW_PIN,0);

    MCAL_GPIO_Write_Pin(PORTE,EN_PIN,1);
    systick_delay(1);
		GPIO_PORTB_DATA = (GPIO_PORTB_DATA&0x0F)|(data&0xF0);
    systick_delay(1);                  
    MCAL_GPIO_Write_Pin(PORTE,EN_PIN,0);
    systick_delay(1);                 
    MCAL_GPIO_Write_Pin(PORTE,EN_PIN,1);
    systick_delay(1);                
		GPIO_PORTB_DATA = (GPIO_PORTB_DATA&0x0F)|((data&0xF)<<4);
    systick_delay(1);                   
    MCAL_GPIO_Write_Pin(PORTE,EN_PIN,0);
    systick_delay(1);
}
	
void LCD_SEND_STRING(uint8_t * str)
{
	uint8_t counter = 0;
	while(str[counter] != '\0'){
		LCD_Send_Data(str[counter]);
		counter++;
	}
		
}
void HAL_LCD_Send_Num(double num)
{
	  char str[5] = {0};
    sprintf(str, "%.2f", num);
    LCD_SEND_STRING(str);
}
void LCD_ClR()
{
	 LCD_Send_CMD(0x01);
}
void LCD_SetCursor(uint8_t x, uint8_t y)
{
		uint8_t cursor;
		
    switch(x)
    {
        case 0:
                cursor=y;
                break;
        case 1:
                cursor = y+0x40;
                break;
    }
    LCD_Send_CMD(cursor | 0x80);
}
