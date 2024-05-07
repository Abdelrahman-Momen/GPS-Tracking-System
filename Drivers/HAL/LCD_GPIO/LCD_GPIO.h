#ifndef LCD_GPIO_H
#define LCD_GPIO_H

#include "SYSTICK.h"
#include "GPIO.h"

#define RS_PIN 0
#define RW_PIN 1
#define EN_PIN 2
#define D4_PIN 4
#define D5_PIN 5
#define D6_PIN 6
#define D7_PIN 7

void LCD_SEND_CMD(uint8_t cmd);
void LCD_SEND_DATA(uint8_t data);

/////////////////////////////////////////////////////////////////////
// those are for the user don't use any one from the above

void LCD_INIT();// use this at the first to initialize the LCD and make it ready
void LCD_CLEAR();// use this to clear the LCD
void LCD_SEND_STRING(uint8_t* string); // put here an array of characters
void LCD_PUT_CURSOR(uint8_t row,uint8_t column); // row (0-1) coloumn(0-15)



#endif