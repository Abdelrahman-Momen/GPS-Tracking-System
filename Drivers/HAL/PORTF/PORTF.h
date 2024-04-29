#ifndef PORTF_HEADER
#define PORTF_HEADER
#include "stdint.h"

#define PF4             			(*(( volatile unsigned long *)0x40025040)) 
#define PF3            			  (*(( volatile unsigned long *)0x40025020)) 
#define PF2             		  (*(( volatile unsigned long *)0x40025010)) 
#define PF1             		  (*(( volatile unsigned long *)0x40025008)) 
#define PF0             			(*(( volatile unsigned long *)0x40025004)) 
#define SYSCTL_RCGCGPIO_R 		(*(( volatile unsigned long *)0x400FE608))
#define SYSCTL_PRGPIO_R    		(*(( volatile unsigned long *)0x400FEA08)) 
#define GPIO_LOCK_KEK         0x4C4F434B
 /* Definitions Macros  */
#define PF_MASK			0x20
#define LEDS_MASK		0x0E
#define SW_MASK		  0x11
#define RED_LED     0x02           
#define BLUE_LED    0x04           
#define GREEN_LED   0x08
#define SWITCH_1    0x10  
#define SWITCH_2    0x01 
//switche state(PIN NO.)
#define SW1 4
#define SW2 0
#define SW_NOT_PRESSED 1

//led state 
#define LED_ON 1
#define LED_OFF 0

//led color state(PIN NO.)
#define RED     1           
#define BLUE    2           
#define GREEN   3



 /* Functions Prototypes   */
void HAL_PORTF_LEDS_Init(void);     
void HAL_PORTF_SW1_SW2_Init(void); 
unsigned char HAL_PORTF_GetSwitchValue(unsigned char SW);                    //Read Switch (SW1-->pin4 , SW1-->pin0)
void HAL_PORTF_SetLedValue (unsigned char LedColor,unsigned char LedState);  //LedState-->ON OR OFF According Led Color
void HAL_PORTF_leds_Off();    												  //LEDs TURN OFF
void HAL_PORTF_led_Toggle(unsigned char LED_PIN);      //LED TOGGLE

#endif 
