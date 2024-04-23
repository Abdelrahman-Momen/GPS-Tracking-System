#include "GPIO.h"

void MCAL_GPIO_Init(GPIO_Port_Select GPIOSEL){
		switch(GPIOSEL){
			case PORTA:
				SET_BIT(RCGCGPIO,PORTA);
				while((PRGPIO & 0x1<<PORTA) == 0);
				GPIO_PORTA_LOCK = GPIO_LOCK_KEY;
			break;
			case PORTB:
				SET_BIT(RCGCGPIO,PORTB);
				while((PRGPIO & 0x1<<PORTB) == 0);
				GPIO_PORTB_LOCK = GPIO_LOCK_KEY;
			break;
			case PORTC:
				SET_BIT(RCGCGPIO,PORTC);
				while((PRGPIO & 0x1<<PORTC) == 0);
				GPIO_PORTC_LOCK = GPIO_LOCK_KEY;
			break;
			case PORTD:
				SET_BIT(RCGCGPIO,PORTD);
				while((PRGPIO & 0x1<<PORTD) == 0);
				GPIO_PORTD_LOCK = GPIO_LOCK_KEY;
			break;
			case PORTE:
				SET_BIT(RCGCGPIO,PORTE);
				while((PRGPIO & 0x1<<PORTE) == 0);
				GPIO_PORTE_LOCK = GPIO_LOCK_KEY;
			break;
			case PORTF:
				SET_BIT(RCGCGPIO,PORTF);
				while((PRGPIO & 0x1<<PORTF) == 0);
				GPIO_PORTF_LOCK = GPIO_LOCK_KEY;
			break;
		}
}
void MCAL_GPIO_Digital_INIT(GPIO_Port_Select GPIOSEL,uint32_t pin){
			switch(GPIOSEL){
					case PORTA:
						SET_BIT(GPIO_PORTA_CR,pin);
						CLR_BIT(GPIO_PORTA_AMSEL,pin);
					  CLR_BIT(GPIO_PORTA_AFSEL,pin);
					  GPIO_PORTA_PCTL  &= ~(0xF<<(pin*4));
					  SET_BIT(GPIO_PORTA_DEN,pin);
					break;
					case PORTB:
						SET_BIT(GPIO_PORTB_CR,pin);
						CLR_BIT(GPIO_PORTB_AMSEL,pin);
					  CLR_BIT(GPIO_PORTB_AFSEL,pin);
					  GPIO_PORTB_PCTL  &= ~(0xF<<(pin*4));
					  SET_BIT(GPIO_PORTB_DEN,pin);	
					break;
					case PORTC:
					  SET_BIT(GPIO_PORTC_CR,pin);
						CLR_BIT(GPIO_PORTC_AMSEL,pin);
					  CLR_BIT(GPIO_PORTC_AFSEL,pin);
					  GPIO_PORTC_PCTL  &= ~(0xF<<(pin*4));
					  SET_BIT(GPIO_PORTC_DEN,pin);	
					break;
					case PORTD:
						SET_BIT(GPIO_PORTD_CR,pin);
						CLR_BIT(GPIO_PORTD_AMSEL,pin);
					  CLR_BIT(GPIO_PORTD_AFSEL,pin);
					  GPIO_PORTD_PCTL  &= ~(0xF<<(pin*4));
					  SET_BIT(GPIO_PORTD_DEN,pin);	
					break;
					case PORTE:
						SET_BIT(GPIO_PORTE_CR,pin);
						CLR_BIT(GPIO_PORTE_AMSEL,pin);
					  CLR_BIT(GPIO_PORTE_AFSEL,pin);
					  GPIO_PORTE_PCTL  &= ~(0xF<<(pin*4));
					  SET_BIT(GPIO_PORTE_DEN,pin);	
					break;
					case PORTF:
						SET_BIT(GPIO_PORTF_CR,pin);
						CLR_BIT(GPIO_PORTF_AMSEL,pin);
					  CLR_BIT(GPIO_PORTF_AFSEL,pin);
					  GPIO_PORTF_PCTL  &= ~(0xF<<(pin*4));
					  SET_BIT(GPIO_PORTF_DEN,pin);	
					break;
		}
}
void MCAL_GPIO_Digital_PIN_MODE(GPIO_Port_Select Port,uint8_t pin, GPIO_Mode_Select Mode, GPIO_Polarity_Select Polarity){
		switch(Port){
					case PORTA:
						if(Mode)
							SET_BIT(GPIO_PORTA_DIR, pin);
						else{
							CLR_BIT(GPIO_PORTA_DIR, pin);
							if(Polarity == 0){
								SET_BIT(GPIO_PORTA_PUR,pin);
							}
							else if(Polarity == 1){
								SET_BIT(GPIO_PORTA_PDR,pin);
							}
							else{
								CLR_BIT(GPIO_PORTA_PUR,pin);
								CLR_BIT(GPIO_PORTA_PDR,pin);
							}
						}
					break;
					case PORTB:
						if(Mode)
							SET_BIT(GPIO_PORTB_DIR, pin);
						else{
							CLR_BIT(GPIO_PORTB_DIR, pin);
							if(Polarity == 0){
								SET_BIT(GPIO_PORTB_PUR,pin);
							}
							else if(Polarity == 1){
								SET_BIT(GPIO_PORTB_PDR,pin);
							}
							else{
								CLR_BIT(GPIO_PORTB_PUR,pin);
								CLR_BIT(GPIO_PORTB_PDR,pin);
							}
						}
					break;
					case PORTC:
					  if(Mode)
							SET_BIT(GPIO_PORTC_DIR, pin);
						else{
							CLR_BIT(GPIO_PORTC_DIR, pin);
							if(Polarity == 0){
								SET_BIT(GPIO_PORTC_PUR,pin);
							}
							else if(Polarity == 1){
								SET_BIT(GPIO_PORTC_PDR,pin);
							}
							else{
								CLR_BIT(GPIO_PORTC_PUR,pin);
								CLR_BIT(GPIO_PORTC_PDR,pin);
							}
						}
					break;
					case PORTD:
						if(Mode)
							SET_BIT(GPIO_PORTD_DIR, pin);
						else{
							CLR_BIT(GPIO_PORTD_DIR, pin);
							if(Polarity == 0){
								SET_BIT(GPIO_PORTD_PUR,pin);
							}
							else if(Polarity == 1){
								SET_BIT(GPIO_PORTD_PDR,pin);
							}
							else{
								CLR_BIT(GPIO_PORTD_PUR,pin);
								CLR_BIT(GPIO_PORTD_PDR,pin);
							}
						}
					break;
					case PORTE:
						if(Mode)
							SET_BIT(GPIO_PORTE_DIR, pin);
						else{
							CLR_BIT(GPIO_PORTE_DIR, pin);
							if(Polarity == 0){
								SET_BIT(GPIO_PORTE_PUR,pin);
							}
							else if(Polarity == 1){
								SET_BIT(GPIO_PORTE_PDR,pin);
							}
							else{
								CLR_BIT(GPIO_PORTE_PUR,pin);
								CLR_BIT(GPIO_PORTE_PDR,pin);
							}
						}
					break;
					case PORTF:
						if(Mode)
							SET_BIT(GPIO_PORTF_DIR, pin);
						else{
							CLR_BIT(GPIO_PORTF_DIR, pin);
							if(Polarity == 0){
								SET_BIT(GPIO_PORTF_PUR,pin);
							}
							else if(Polarity == 1){
								SET_BIT(GPIO_PORTF_PDR,pin);
							}
							else{
								CLR_BIT(GPIO_PORTF_PUR,pin);
								CLR_BIT(GPIO_PORTF_PDR,pin);
							}
						}
					break;
		}
}
void MCAL_GPIO_Write_Pin(GPIO_Port_Select GPIOSEL, uint32_t pin, GPIO_Write_Select data){
	switch(GPIOSEL){
					case PORTA:
						if(data)
							SET_BIT(GPIO_PORTA_DATA,pin);
						else
							CLR_BIT(GPIO_PORTA_DATA,pin);
					break;
					case PORTB:
					  if(data)
							SET_BIT(GPIO_PORTB_DATA,pin);
						else
							CLR_BIT(GPIO_PORTB_DATA,pin);
					break;
					case PORTC:
						if(data)
							SET_BIT(GPIO_PORTC_DATA,pin);
						else
							CLR_BIT(GPIO_PORTC_DATA,pin);
					break;
					case PORTD:
						if(data)
							SET_BIT(GPIO_PORTD_DATA,pin);
						else
							CLR_BIT(GPIO_PORTD_DATA,pin);
					break;
					case PORTE:
						if(data)
							SET_BIT(GPIO_PORTE_DATA,pin);
						else
							CLR_BIT(GPIO_PORTE_DATA,pin);
					break;
					case PORTF:
						if(data)
							SET_BIT(GPIO_PORTF_DATA,pin);
						else
							CLR_BIT(GPIO_PORTF_DATA,pin);
					break;
		}
}
uint8_t MCAL_GPIO_Read_pin(GPIO_Port_Select GPIOSEL, uint32_t pin){
	switch(GPIOSEL){
					case PORTA:
						return GET_BIT(GPIO_PORTA_DATA,pin);
					break;
					case PORTB:
						return GET_BIT(GPIO_PORTB_DATA,pin);
					break;
					case PORTC:
						return GET_BIT(GPIO_PORTC_DATA,pin);
					break;
					case PORTD:
						return GET_BIT(GPIO_PORTD_DATA,pin);
					break;
					case PORTE:
						return GET_BIT(GPIO_PORTE_DATA,pin);
					break;
					case PORTF:
						return GET_BIT(GPIO_PORTF_DATA,pin);
					break;
		}
}
void MCAL_GPIO_UART_Init(UART_Select Select){
		switch(Select){
					case UART0:
						GPIO_PORTA_CR |= 0x3;
						GPIO_PORTA_AMSEL &= ~(0x3);
						GPIO_PORTA_AFSEL |= (0x3);
						GPIO_PORTA_PCTL  |= (0x11);
						GPIO_PORTA_DEN   |= (0x3);	
					break;
					case UART1:
						//DIDN'T UNDERSTAND
					break;
					case UART2:
						GPIO_PORTD_CR    |= 	(0x3<<6);
						GPIO_PORTD_AMSEL &= ~(0x3<<6);
						GPIO_PORTD_AFSEL |=  (0x3<<6);
						GPIO_PORTD_PCTL  |=  (0x11<<6*4);
						GPIO_PORTD_DEN   |=  (0x3<<6);	
					break;
					case UART3:
						GPIO_PORTC_CR    |= 	(0x3<<6);
						GPIO_PORTC_AMSEL &= ~(0x3<<6);
						GPIO_PORTC_AFSEL |=  (0x3<<6);
						GPIO_PORTC_PCTL  |=  (0x11<<6*4);
						GPIO_PORTC_DEN   |=  (0x3<<6);	
					break;
					case UART4:
						GPIO_PORTC_CR    |= 	(0x3<<4);
						GPIO_PORTC_AMSEL &= ~(0x3<<4);
						GPIO_PORTC_AFSEL |=  (0x3<<4);
						GPIO_PORTC_PCTL  |=  (0x11<<4*4);
						GPIO_PORTC_DEN   |=  (0x3<<4);	
					break;
					case UART5:
						GPIO_PORTE_CR    |= 	(0x3<<4);
						GPIO_PORTE_AMSEL &= ~(0x3<<4);
						GPIO_PORTE_AFSEL |=  (0x3<<4);
						GPIO_PORTE_PCTL  |=  (0x11<<4*4);
						GPIO_PORTE_DEN   |=  (0x3<<4);	
					break;
					case UART6:
						GPIO_PORTD_CR    |= 	(0x3<<4);
						GPIO_PORTD_AMSEL &= ~(0x3<<4);
						GPIO_PORTD_AFSEL |=  (0x3<<4);
						GPIO_PORTD_PCTL  |=  (0x11<<4*4);
						GPIO_PORTD_DEN   |=  (0x3<<4);	
					break;
					case UART7:
						GPIO_PORTE_CR    |= 	(0x3);
						GPIO_PORTE_AMSEL &= ~(0x3);
						GPIO_PORTE_AFSEL |=  (0x3);
						GPIO_PORTE_PCTL  |=  (0x11*4);
						GPIO_PORTE_DEN   |=  (0x3);	
					break;
		}
}
void MCAL_GPIO_I2C_Init(I2C_Select Select){
		switch(Select){
					case I2C0:
						GPIO_PORTB_CR    |=  (0x3<<2);
						GPIO_PORTB_AMSEL &= ~(0x3<<2);
						GPIO_PORTB_AFSEL |=  (0x3<<2);
						GPIO_PORTB_PCTL  |=  (0x33<<2*4);									
						GPIO_PORTB_DEN   |=  (0x3<<2);
						GPIO_PORTB_ODR   |=  (0x2<<2);
					break;
					case I2C1:
						GPIO_PORTA_CR    |=  (0x3<<6);
						GPIO_PORTA_AMSEL &= ~(0x3<<6);
						GPIO_PORTA_AFSEL |=  (0x3<<6);
						GPIO_PORTA_PCTL  |=  (0x33<<6*4);									
						GPIO_PORTA_DEN   |=  (0x3<<6);
						GPIO_PORTA_ODR   |=  (0x2<<6);
					break;
					case I2C2:
						GPIO_PORTE_CR    |=  (0x3<<4);
						GPIO_PORTE_AMSEL &= ~(0x3<<4);
						GPIO_PORTE_AFSEL |=  (0x3<<4);
						GPIO_PORTE_PCTL  |=  (0x33<<4*4);									
						GPIO_PORTE_DEN   |=  (0x3<<4);
						GPIO_PORTE_ODR   |=  (0x2<<4);
					break;
					case I2C3:
						GPIO_PORTD_CR    |=  (0x3);
						GPIO_PORTD_AMSEL &= ~(0x3);
						GPIO_PORTD_AFSEL |=  (0x3);
						GPIO_PORTD_PCTL  |=  (0x33);									
						GPIO_PORTD_DEN   |=  (0x3);
						GPIO_PORTD_ODR   |=  (0x2);
					break;
		}
}