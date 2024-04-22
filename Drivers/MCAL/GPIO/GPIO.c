#include "GPIO.h"

void MCAL_GPIO_Init(PORT GPIOSEL){
		switch(GPIOSEL){
			case 0:
				RCGCGPIO |= PA_MASK;
				while((PRGPIO & PA_MASK) == 0);
				GPIOA_LOCK = LOCK_KEY;
			break;
			case 1:
				RCGCGPIO |= PB_MASK;
				while((PRGPIO & PB_MASK) == 0);
				GPIOB_LOCK = LOCK_KEY;
			break;
			case 2:
				RCGCGPIO |= PC_MASK;
				while((PRGPIO & PC_MASK) == 0);
				GPIOC_LOCK = LOCK_KEY;
			break;
			case 3:
				RCGCGPIO |= PD_MASK;
				while((PRGPIO & PD_MASK) == 0);
				GPIOD_LOCK = LOCK_KEY;
			break;
			case 4:
				RCGCGPIO |= PE_MASK;
				while((PRGPIO & PE_MASK) == 0);
				GPIOE_LOCK = LOCK_KEY;
			break;
			case 5:
				RCGCGPIO |= PF_MASK;
				while((PRGPIO & PF_MASK) == 0);
				GPIOF_LOCK = LOCK_KEY;
			break;
		}
}
void MCAL_GPIO_Digital_Input_INIT(PORT GPIOSEL,uint32_t pin, Polarity P){
			switch(GPIOSEL){
					case 0:
						GPIOA_CR |= (0x1<<pin);
						GPIOA_AMSEL &= ~(0x1<<pin);
						GPIOA_AFSEL &= ~(0x1<<pin);
						GPIOA_PCTL  &= ~(0xF<<(pin*4));
						GPIOA_DEN   |= (0x1<<pin);	
					break;
					case 1:
						GPIOB_CR |= (0x1<<pin);
						GPIOB_AMSEL &= ~(0x1<<pin);
						GPIOB_AFSEL &= ~(0x1<<pin);
						GPIOB_PCTL  &= ~(0xF<<(pin*4));
						GPIOB_DEN   |= (0x1<<pin);	
					break;
					case 2:
						GPIOC_CR |= (0x1<<pin);
						GPIOC_AMSEL &= ~(0x1<<pin);
						GPIOC_AFSEL &= ~(0x1<<pin);
						GPIOC_PCTL  &= ~(0xF<<(pin*4));
						GPIOC_DEN   |= (0x1<<pin);	
					break;
					case 3:
						GPIOD_CR |= (0x1<<pin);
						GPIOD_AMSEL &= ~(0x1<<pin);
						GPIOD_AFSEL &= ~(0x1<<pin);
						GPIOD_PCTL  &= ~(0xF<<(pin*4));
						GPIOD_DEN   |= (0x1<<pin);	
					break;
					case 4:
						GPIOE_CR |= (0x1<<pin);
						GPIOE_AMSEL &= ~(0x1<<pin);
						GPIOE_AFSEL &= ~(0x1<<pin);
						GPIOE_PCTL  &= ~(0xF<<(pin*4));
						GPIOE_DEN   |= (0x1<<pin);	
					break;
					case 5:
						GPIOF_CR |= (0x1<<pin);
						GPIOF_AMSEL &= ~(0x1<<pin);
						GPIOF_AFSEL &= ~(0x1<<pin);
						GPIOF_PCTL  &= ~(0xF<<(pin*4));
						GPIOF_DEN   |= (0x1<<pin);	
					break;
		}
}
void MCAL_GPIO_Write_Pin(PORT GPIOSEL, uint32_t pin, uint8_t data){
	switch(GPIOSEL){
					case 0:
						GPIOA_DATA  |= (0x1<<pin);
					break;
					case 1:
						GPIOB_DATA  |= (0x1<<pin);
					break;
					case 2:
						GPIOC_DATA  |= (0x1<<pin);
					break;
					case 3:
						GPIOD_DATA  |= (0x1<<pin);
					break;
					case 4:
						GPIOE_DATA  |= (0x1<<pin);
					break;
					case 5:
						GPIOF_DATA  |= (0x1<<pin);
					break;
		}
}
uint8_t MCAL_GPIO_Read_pin(PORT GPIOSEL, uint32_t pin){
	switch(GPIOSEL){
					case 0:
						return GPIOA_DATA &(0x1<<pin);
					break;
					case 1:
						return GPIOB_DATA &(0x1<<pin);
					break;
					case 2:
						return GPIOC_DATA &(0x1<<pin);
					break;
					case 3:
						return GPIOD_DATA &(0x1<<pin);
					break;
					case 4:
						return GPIOE_DATA &(0x1<<pin);
					break;
					case 5:
						return GPIOF_DATA &(0x1<<pin);
					break;
		}
}
void MCAL_GPIO_UART_Init(UART_GPIO Select){
		switch(Select){
					case 0:
						GPIOA_CR |= 0x3;
						GPIOA_AMSEL &= ~(0x3);
						GPIOA_AFSEL |= (0x3);
						GPIOA_PCTL  |= (0x11);
						GPIOA_DEN   |= (0x3);	
					break;
					case 1:
						//DIDN'T UNDERSTAND
					break;
					case 2:
						GPIOD_CR    |= 	(0x3<<6);
						GPIOD_AMSEL &= ~(0x3<<6);
						GPIOD_AFSEL |=  (0x3<<6);
						GPIOD_PCTL  |=  (0x11<<6*4);
						GPIOD_DEN   |=  (0x3<<6);	
					break;
					case 3:
						GPIOC_CR    |= 	(0x3<<6);
						GPIOC_AMSEL &= ~(0x3<<6);
						GPIOC_AFSEL |=  (0x3<<6);
						GPIOC_PCTL  |=  (0x11<<6*4);
						GPIOC_DEN   |=  (0x3<<6);	
					break;
					case 4:
						GPIOC_CR    |= 	(0x3<<4);
						GPIOC_AMSEL &= ~(0x3<<4);
						GPIOC_AFSEL |=  (0x3<<4);
						GPIOC_PCTL  |=  (0x11<<4*4);
						GPIOC_DEN   |=  (0x3<<4);	
					break;
					case 5:
						GPIOE_CR    |= 	(0x3<<4);
						GPIOE_AMSEL &= ~(0x3<<4);
						GPIOE_AFSEL |=  (0x3<<4);
						GPIOE_PCTL  |=  (0x11<<4*4);
						GPIOE_DEN   |=  (0x3<<4);	
					break;
					case 6:
						GPIOD_CR    |= 	(0x3<<4);
						GPIOD_AMSEL &= ~(0x3<<4);
						GPIOD_AFSEL |=  (0x3<<4);
						GPIOD_PCTL  |=  (0x11<<4*4);
						GPIOD_DEN   |=  (0x3<<4);	
					break;
					case 7:
						GPIOE_CR    |= 	(0x3);
						GPIOE_AMSEL &= ~(0x3);
						GPIOE_AFSEL |=  (0x3);
						GPIOE_PCTL  |=  (0x11*4);
						GPIOE_DEN   |=  (0x3);	
					break;
		}
}
void MCAL_GPIO_I2C_Init(I2C_GPIO Select){
		switch(Select){
					case 0:
						GPIOB_CR    |=  (0x3<<2);
						GPIOB_AMSEL &= ~(0x3<<2);
						GPIOB_AFSEL |=  (0x3<<2);
						GPIOB_PCTL  |=  (0x33<<2*4);									
						GPIOB_DEN   |=  (0x3<<2);
						GPIOB_ODR   |=  (0x2<<2);
					break;
					case 1:
						GPIOA_CR    |=  (0x3<<6);
						GPIOA_AMSEL &= ~(0x3<<6);
						GPIOA_AFSEL |=  (0x3<<6);
						GPIOA_PCTL  |=  (0x33<<6*4);									
						GPIOA_DEN   |=  (0x3<<6);
						GPIOA_ODR   |=  (0x2<<6);
					break;
					case 2:
						GPIOE_CR    |=  (0x3<<4);
						GPIOE_AMSEL &= ~(0x3<<4);
						GPIOE_AFSEL |=  (0x3<<4);
						GPIOE_PCTL  |=  (0x33<<4*4);									
						GPIOE_DEN   |=  (0x3<<4);
						GPIOE_ODR   |=  (0x2<<4);
					break;
					case 3:
						GPIOD_CR    |=  (0x3);
						GPIOD_AMSEL &= ~(0x3);
						GPIOD_AFSEL |=  (0x3);
						GPIOD_PCTL  |=  (0x33);									
						GPIOD_DEN   |=  (0x3);
						GPIOD_ODR   |=  (0x2);
					break;
		}
}