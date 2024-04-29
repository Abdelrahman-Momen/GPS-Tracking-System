#include "I2C.h"

void MCAL_I2C_Init_master(I2C_Select Select){
			switch(Select){
					case I2C0:
						RCGCI2C |= I2C0_MASK;
						while((PRI2C & I2C0_MASK) == 0);
						MCAL_GPIO_Init(PORTB);
						MCAL_GPIO_I2C_Init(I2C0);
						I2C0_MCR |= (0x1<<4);
						I2C0_MTPR |= (SYSTEM_CLOCK/(2*(10)*SCL_CLK))-1;
					break;
					case I2C1:
						RCGCI2C |= I2C1_MASK;
						while((PRI2C & I2C1_MASK) == 0);
						MCAL_GPIO_Init(PORTA);
						MCAL_GPIO_I2C_Init(I2C1);
						I2C1_MCR |= (0x1<<4);
						I2C1_MTPR |= (SYSTEM_CLOCK/(2*(10)*SCL_CLK))-1;
					break;
					case I2C2:
						RCGCI2C |= I2C2_MASK;
						while((PRI2C & I2C2_MASK) == 0);
						MCAL_GPIO_Init(PORTE);
						MCAL_GPIO_I2C_Init(I2C2);
						I2C2_MCR |= (0x1<<4);
						I2C2_MTPR |= (SYSTEM_CLOCK/(2*(10)*SCL_CLK))-1;
					break;
					case I2C3:
						RCGCI2C |= I2C3_MASK;
						while((PRI2C & I2C3_MASK) == 0);
						MCAL_GPIO_Init(PORTD);
						MCAL_GPIO_I2C_Init(I2C3);
						I2C3_MCR |= (0x1<<4);
						I2C3_MTPR |= (SYSTEM_CLOCK/(2*(10)*SCL_CLK))-1;
					break;
		}
}

uint8_t MCAL_I2C_Transmit(I2C_Select Select, uint8_t address, uint8_t DATA){
					switch(Select){
									case I2C0:
										I2C0_MSA |= (address<<1);
										I2C0_MDR &= DATA;
										I2C0_MCS |= 0x7;
										while(I2C0_MCS&1);
										return I2C0_MCS&0x2;
									break;
									case I2C1:
										I2C1_MSA |= (address<<1);
										I2C1_MDR &= DATA;
										I2C1_MCS |= 0x7;
										while(I2C1_MCS&1);
										return I2C1_MCS&0x2;
									break;
									case I2C2:
										I2C2_MSA |= (address<<1);
										I2C2_MDR &= DATA;
										I2C2_MCS |= 0x7;
										while(I2C2_MCS&1);
										return I2C2_MCS&0x2;
									break;
									case I2C3:
										I2C3_MSA |= (address<<1);
										I2C3_MDR &= DATA;
										I2C3_MCS |= 0x7;
										while(I2C3_MCS&1);
										return I2C3_MCS&0x2;
									break;
						}
}