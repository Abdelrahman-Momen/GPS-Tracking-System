#include "LCD_GPIO.h"

void SEND_ON_PINS(uint8_t data,uint8_t rs){
	MCAL_GPIO_Write_Pin(PORTB,RS_PIN,rs);
	
	MCAL_GPIO_Write_Pin(PORTB,D7_PIN,(data>>3)&1);
	MCAL_GPIO_Write_Pin(PORTB,D6_PIN,(data>>2)&1);
	MCAL_GPIO_Write_Pin(PORTB,D5_PIN,(data>>1)&1);
	MCAL_GPIO_Write_Pin(PORTB,D4_PIN,(data>>0)&1);
	
	MCAL_GPIO_Write_Pin(PORTB,EN_PIN,1);
	systick_delay(2);
	MCAL_GPIO_Write_Pin(PORTB,EN_PIN,0);
	systick_delay(2);
}


void LCD_SEND_CMD(uint8_t cmd){
	uint8_t firsthalf, secondhalf;
	firsthalf = ((cmd>>4)&0xf);
	secondhalf = ((cmd)&0xf);
	SEND_ON_PINS(firsthalf,0);
	SEND_ON_PINS(secondhalf,0);
}
void LCD_SEND_DATA(uint8_t data){
	uint8_t firsthalf, secondhalf;
	firsthalf = ((data>>4)&0xf);
	secondhalf = ((data)&0xf);
	SEND_ON_PINS(firsthalf,1);
	SEND_ON_PINS(secondhalf,1);
}

void LCD_INIT(){
	// init gpio
	int i =0;
	MCAL_GPIO_Init(PORTB);
	for(i=0;i<=7;i++){
		if(i==3)continue;
		MCAL_GPIO_Digital_INIT(PORTB,i);
		MCAL_GPIO_Digital_PIN_MODE(PORTB,i,Output,1);
	}
	// init LCD in 4 bit mode
	systick_delay(50);
	LCD_SEND_CMD(0x30);
	systick_delay(5);
	LCD_SEND_CMD(0x30);
	systick_delay(1);
	LCD_SEND_CMD(0x30);
	systick_delay(20);
	LCD_SEND_CMD(0x20);
	systick_delay(20);
	
	//dislay initialisation
	LCD_SEND_CMD (0x28);
	systick_delay(1);
	LCD_SEND_CMD (0x08);
	systick_delay(1);
	LCD_SEND_CMD(0x01); 
	systick_delay(2); 
	LCD_SEND_CMD(0x06); 
	systick_delay (1);
	LCD_SEND_CMD(0x0C); 
	systick_delay (1);
}
void LCD_CLEAR(){
	LCD_SEND_CMD(0x1);
	systick_delay(2);
}


void LCD_SEND_STRING(uint8_t* string){
	int i=0;
	while(string[i] != '\0'){
		LCD_SEND_DATA(string[i]);
		i++;
		systick_delay (1);
	}
}
void LCD_PUT_CURSOR(uint8_t row,uint8_t column){
	if(row){
		LCD_SEND_CMD(column|0x80);
	}
	else{
		LCD_SEND_CMD(column|0xC0);
	}
}