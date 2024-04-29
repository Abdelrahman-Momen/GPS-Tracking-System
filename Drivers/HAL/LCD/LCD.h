#ifndef LCD_H
#define LCD_H

#include "I2C.h"
#include "GPIO.h"

void LCD_Send_CMD(char cmd);
void delay(double i);
void LCD_Set_Cursur(int row, int col);
void LCD_Send_Data(char data);
void LCD_Init();
void lcd_send_string (char *str);

#endif