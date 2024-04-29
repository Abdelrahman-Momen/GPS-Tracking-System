#include "GPIO.h"


int main(){
	MCAL_GPIO_Init(PORTF);
	MCAL_GPIO_Digital_INIT(PORTF, PIN_0);
	MCAL_GPIO_Digital_INIT(PORTF, PIN_1);
	MCAL_GPIO_Digital_INIT(PORTF, PIN_2);
	MCAL_GPIO_Digital_INIT(PORTF, PIN_3);
	MCAL_GPIO_Digital_INIT(PORTF, PIN_4);
	MCAL_GPIO_Digital_PIN_MODE(PORTF,PIN_0, Input, Pull_up);
	MCAL_GPIO_Digital_PIN_MODE(PORTF,PIN_4, Input, Pull_up);
	MCAL_GPIO_Digital_PIN_MODE(PORTF,PIN_1, Output, Pull_up);
	MCAL_GPIO_Digital_PIN_MODE(PORTF,PIN_2, Output, Pull_up);
	MCAL_GPIO_Digital_PIN_MODE(PORTF,PIN_3, Output, Pull_up);
	while(1){
		if(MCAL_GPIO_Read_pin(PORTF, PIN_0)){
			MCAL_GPIO_Write_Pin(PORTF, PIN_1, 1);
		}
		else{
			MCAL_GPIO_Write_Pin(PORTF, PIN_1, 0);
		}
	}
}