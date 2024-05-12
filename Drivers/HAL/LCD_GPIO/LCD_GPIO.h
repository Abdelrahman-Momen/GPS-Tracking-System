#ifndef LCD_GPIO_H_
#define LCD_H_

#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "GPIO.h"

#define RS_PIN 1
#define RW_PIN 2
#define EN_PIN 3
#define D4_PIN 4
#define D5_PIN 5
#define D6_PIN 6
#define D7_PIN 7


//Prototypes
void LCD_INIT();
void LCD_Send_CMD(uint8_t cmd);
void LCD_Send_Data(uint8_t c);
void LCD_SEND_STRING(uint8_t * str);
void LCD_Send_Num(double num);
void LCD_ClR();
void LCD_SetCursor(uint8_t x, uint8_t y);

#endif
