#include "PORTF.h"
#include "GPIO.h"
#include "BIT_MATHS.h"

void HAL_PORTF_LEDS_Init(void){
SYSCTL_RCGCGPIO_R|=PF_MASK	; //INTIALIZE THE CLOCK OF PORTF
while((SYSCTL_PRGPIO_R & PF_MASK)==0); //delay
GPIO_PORTF_LOCK = GPIO_LOCK_KEY; //unlocking the ports have the same value
GPIO_PORTF_CR |= LEDS_MASK; //Allow changing pin 3,2,1 in portF
GPIO_PORTF_AMSEL &=~LEDS_MASK; //disable the analog function
GPIO_PORTF_PCTL &=~0x0000FFF0;//GPIO CLEAR BIT PCTL
GPIO_PORTF_AFSEL &=~LEDS_MASK; //disable the alternate function
GPIO_PORTF_DIR |= LEDS_MASK; //Pin 1,2,3 is output
GPIO_PORTF_DEN |=LEDS_MASK;
GPIO_PORTF_DATA &=~LEDS_MASK; //intialize pins 1,2,3 to be off
}

void HAL_PORTF_SW1_SW2_Init(void){
SYSCTL_RCGCGPIO_R|=PF_MASK	; //INTIALIZE THE CLOCK OF PORTF
while((SYSCTL_PRGPIO_R & PF_MASK)==0); //delay
GPIO_PORTF_LOCK = GPIO_LOCK_KEK; //Constant value unlock portf
GPIO_PORTF_CR |= SW_MASK; //setting pin p4 to change
GPIO_PORTF_AMSEL &=~SW_MASK; //disable analog function
GPIO_PORTF_PCTL &=~0x000F000F; //GPIO CLEAR BIT PCTL
GPIO_PORTF_AFSEL &=~SW_MASK; //disable alterante function
GPIO_PORTF_DIR &=~SW_MASK; //DIR--> 0->input & 1->output
GPIO_PORTF_PUR |=SW_MASK; //active low
GPIO_PORTF_DEN |= SW_MASK; //Enable digital for sw1

}
unsigned char HAL_PORTF_GetSwitchValue(unsigned char SWITCH){
 return MCAL_GPIO_Read_pin(PORTF,SWITCH);

}

void HAL_PORTF_SetLedValue (unsigned char LedColor,unsigned char LedState){      //LedState-->ON OR OFF
switch(LedColor){
		case RED : 
				MCAL_GPIO_Write_Pin(PORTF, PIN_1, LedState);break;
				
		case BLUE : 
				MCAL_GPIO_Write_Pin(PORTF, PIN_2, LedState);break;

		case GREEN : 
				MCAL_GPIO_Write_Pin(PORTF, PIN_3, LedState);break;
				
		 default: break;

		}

}


//led Toggle
void HAL_PORTF_led_Toggle(unsigned char LED_PIN){
TOG_BIT(GPIO_PORTF_DATA,LED_PIN);

}

// leds Off
void HAL_PORTF_leds_Off(){
			GPIO_PORTF_DATA &= ~(LEDS_MASK);
}                       
