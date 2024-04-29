#include "LCD.h"

volatile int i;

void delay(double i){
	volatile int x = 0;
	for(x =0;x< i*SYSTEM_CLOCK/1000;x++);
}

void LCD_Set_Cursur(int row, int col){
	switch(row){
		case 0:
				col |= 0x80;
		break;
		case 1:
				col |= 0xC0;
		break;
	}
	LCD_Send_CMD(col);
}
void LCD_Send_CMD(char cmd){
	char data_u,data_l;
	uint8_t data_t[4];
	data_u = (cmd&0xf0);
	data_l = ((cmd<<4)&0xf0);
	data_t[0] = data_u | 0x0C;
	data_t[1] = data_u | 0x08;
	data_t[2] = data_l | 0x0C;
	data_t[3] = data_l | 0x08;
	for(i = 0;i<4;i++){
		MCAL_I2C_Transmit(I2C0, Slave_Address, data_t[i]);
		delay(1);
	}
}
void LCD_Send_Data(char data){
	char data_u,data_l;
	uint8_t data_t[4];
	data_u = (data&0xf0);
	data_l = ((data<<4)&0xf0);
	data_t[0] = data_u | 0x0D;
	data_t[1] = data_u | 0x09;
	data_t[2] = data_l | 0x0D;
	data_t[3] = data_l | 0x09;
	for(i = 0;i<4;i++){
		MCAL_I2C_Transmit(I2C0, Slave_Address, data_t[i]);
		delay(1);
	}
}

void LCD_Init(){
	delay(20);
	LCD_Send_CMD(0x30);
	delay(5);
	LCD_Send_CMD(0x30);
	delay(1);
	LCD_Send_CMD(0x30);
	delay(20);
	LCD_Send_CMD(0x20);
	delay(20);
	
	//dislay initialisation
	LCD_Send_CMD (0x28); // Funation set --> DI=0 (4 bit mode), N - 1 (2 1ane display) E - O (5x8 characters) 
	delay(1);
	LCD_Send_CMD (0x08); //Display on/off control -=> D=0,C=0, B=0
	delay(1);
	LCD_Send_CMD(0x01); // clear display
	delay(1); 
	delay(1);
	LCD_Send_CMD(0x06); //Entry mode set -?> I/D = 1 (increment cursor) «S = 0 (no shifc)
	delay (1);
	LCD_Send_CMD(0x0C); //Display on/off control -?> D = 1, C and B = 0- (Cursoz and blink, last two bits)
	delay (1);
}
void lcd_send_string (char *str){
		while(*str) LCD_Send_Data (*str++);
}