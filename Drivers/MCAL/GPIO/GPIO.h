#ifndef GPIO_HEADER
#define GPIO_HEADER
// libraries needed
#include "stdint.h"

//////////////////////////////////////////////////////////////////////
//general defines
#define SYSTEM_CLOCK  20000000000
// addresses
#define RCGCGPIO			(*((volatile unsigned long*)0x40FE608))
#define PRGPIO			(*((volatile unsigned long*)0x40FEA08))
//base address
#define BASE_GPIOA_APB 		(0x40004000)
#define BASE_GPIOB_APB 		(0x40005000)
#define BASE_GPIOC_APB 		(0x40006000)
#define BASE_GPIOD_APB 		(0x40007000)
#define BASE_GPIOE_APB 		(0x40024000)
#define BASE_GPIOF_APB 		(0x40025000)
//direction
#define GPIOA_DIR					(*((volatile unsigned long*)(BASE_GPIOA_APB + 0x400)))
#define GPIOB_DIR					(*((volatile unsigned long*)(BASE_GPIOB_APB + 0x400)))
#define GPIOC_DIR					(*((volatile unsigned long*)(BASE_GPIOC_APB + 0x400)))
#define GPIOD_DIR					(*((volatile unsigned long*)(BASE_GPIOD_APB + 0x400)))
#define GPIOE_DIR					(*((volatile unsigned long*)(BASE_GPIOE_APB + 0x400)))
#define GPIOF_DIR					(*((volatile unsigned long*)(BASE_GPIOF_APB + 0x400)))
//Alternate function
#define GPIOA_AFSEL					(*((volatile unsigned long*)(BASE_GPIOA_APB + 0x420)))
#define GPIOB_AFSEL					(*((volatile unsigned long*)(BASE_GPIOB_APB + 0x420)))
#define GPIOC_AFSEL					(*((volatile unsigned long*)(BASE_GPIOC_APB + 0x420)))
#define GPIOD_AFSEL					(*((volatile unsigned long*)(BASE_GPIOD_APB + 0x420)))
#define GPIOE_AFSEL					(*((volatile unsigned long*)(BASE_GPIOE_APB + 0x420)))
#define GPIOF_AFSEL					(*((volatile unsigned long*)(BASE_GPIOF_APB + 0x420)))
//prepherial selection
#define GPIOA_PCTL					(*((volatile unsigned long*)(BASE_GPIOA_APB + 0x52C)))
#define GPIOB_PCTL					(*((volatile unsigned long*)(BASE_GPIOB_APB + 0x52C)))
#define GPIOC_PCTL					(*((volatile unsigned long*)(BASE_GPIOC_APB + 0x52C)))
#define GPIOD_PCTL					(*((volatile unsigned long*)(BASE_GPIOD_APB + 0x52C)))
#define GPIOE_PCTL					(*((volatile unsigned long*)(BASE_GPIOE_APB + 0x52C)))
#define GPIOF_PCTL					(*((volatile unsigned long*)(BASE_GPIOF_APB + 0x52C)))
//Pull UP
#define GPIOA_PUR				(*((volatile unsigned long*)(BASE_GPIOA_APB + 0x510)))
#define GPIOB_PUR				(*((volatile unsigned long*)(BASE_GPIOB_APB + 0x510)))
#define GPIOC_PUR				(*((volatile unsigned long*)(BASE_GPIOC_APB + 0x510)))
#define GPIOD_PUR				(*((volatile unsigned long*)(BASE_GPIOD_APB + 0x510)))
#define GPIOE_PUR				(*((volatile unsigned long*)(BASE_GPIOE_APB + 0x510)))
#define GPIOF_PUR				(*((volatile unsigned long*)(BASE_GPIOF_APB + 0x510)))
//Digital enable
#define GPIOA_DEN				(*((volatile unsigned long*)(BASE_GPIOA_APB + 0x51C)))
#define GPIOB_DEN				(*((volatile unsigned long*)(BASE_GPIOB_APB + 0x51C)))
#define GPIOC_DEN				(*((volatile unsigned long*)(BASE_GPIOC_APB + 0x51C)))
#define GPIOD_DEN				(*((volatile unsigned long*)(BASE_GPIOD_APB + 0x51C)))
#define GPIOE_DEN				(*((volatile unsigned long*)(BASE_GPIOE_APB + 0x51C)))
#define GPIOF_DEN				(*((volatile unsigned long*)(BASE_GPIOF_APB + 0x51C)))
//LOCK register
#define GPIOA_LOCK				(*((volatile unsigned long*)(BASE_GPIOA_APB + 0x520)))
#define GPIOB_LOCK				(*((volatile unsigned long*)(BASE_GPIOB_APB + 0x520)))
#define GPIOC_LOCK				(*((volatile unsigned long*)(BASE_GPIOC_APB + 0x520)))
#define GPIOD_LOCK				(*((volatile unsigned long*)(BASE_GPIOD_APB + 0x520)))
#define GPIOE_LOCK				(*((volatile unsigned long*)(BASE_GPIOE_APB + 0x520)))
#define GPIOF_LOCK				(*((volatile unsigned long*)(BASE_GPIOF_APB + 0x520)))
//Commit register
#define GPIOA_CR				(*((volatile unsigned long*)(BASE_GPIOA_APB + 0x524)))
#define GPIOB_CR				(*((volatile unsigned long*)(BASE_GPIOB_APB + 0x524)))
#define GPIOC_CR				(*((volatile unsigned long*)(BASE_GPIOC_APB + 0x524)))
#define GPIOD_CR				(*((volatile unsigned long*)(BASE_GPIOD_APB + 0x524)))
#define GPIOE_CR				(*((volatile unsigned long*)(BASE_GPIOE_APB + 0x524)))
#define GPIOF_CR				(*((volatile unsigned long*)(BASE_GPIOF_APB + 0x524)))
//Analog enable
#define GPIOA_AMSEL				(*((volatile unsigned long*)(BASE_GPIOA_APB + 0x528)))
#define GPIOB_AMSEL				(*((volatile unsigned long*)(BASE_GPIOB_APB + 0x528)))
#define GPIOC_AMSEL				(*((volatile unsigned long*)(BASE_GPIOC_APB + 0x528)))
#define GPIOD_AMSEL				(*((volatile unsigned long*)(BASE_GPIOD_APB + 0x528)))
#define GPIOE_AMSEL				(*((volatile unsigned long*)(BASE_GPIOE_APB + 0x528)))
#define GPIOF_AMSEL				(*((volatile unsigned long*)(BASE_GPIOF_APB + 0x528)))
//Data/READ/WRITE register
#define GPIOA_DATA				(*((volatile unsigned long*)(BASE_GPIOA_APB+0x3FC)))
#define GPIOB_DATA				(*((volatile unsigned long*)(BASE_GPIOB_APB+0x3FC)))
#define GPIOC_DATA				(*((volatile unsigned long*)(BASE_GPIOC_APB+0x3FC)))
#define GPIOD_DATA				(*((volatile unsigned long*)(BASE_GPIOD_APB+0x3FC)))
#define GPIOE_DATA				(*((volatile unsigned long*)(BASE_GPIOE_APB+0x3FC)))
#define GPIOF_DATA				(*((volatile unsigned long*)(BASE_GPIOF_APB+0x3FC)))
//Open-drain register
#define GPIOA_ODR				(*((volatile unsigned long*)(BASE_GPIOA_APB+0x50C)))
#define GPIOB_ODR				(*((volatile unsigned long*)(BASE_GPIOB_APB+0x50C)))
#define GPIOC_ODR				(*((volatile unsigned long*)(BASE_GPIOC_APB+0x50C)))
#define GPIOD_ODR				(*((volatile unsigned long*)(BASE_GPIOD_APB+0x50C)))
#define GPIOE_ODR				(*((volatile unsigned long*)(BASE_GPIOE_APB+0x50C)))
#define GPIOF_ODR				(*((volatile unsigned long*)(BASE_GPIOF_APB+0x50C)))
////////////////////////////////////////////////////////////////////////////////////////
//defines
#define LOCK_KEY					0x4C4F434B
#define PIN_0							0
#define PIN_1							1
#define PIN_2							2
#define PIN_3							3
#define PIN_4							4
#define PIN_5							5
#define PIN_6							6
#define PIN_7							7
//ports
#define PA_MASK						0x1
#define PB_MASK						0x2
#define PC_MASK						0x4
#define PD_MASK						0x8
#define PE_MASK						0x10
#define PF_MASK						0x20
////////////////////////////////////////////////////////////////////////////
//enums
// for initing GPIO
typedef enum{
	GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF 
}PORT_select;
//for init a pin
typedef enum{
	Pull_down, Pull_up
}Polarity_select;
//for uart
typedef enum{
	UART0, UART1, UART2, UART3, UART4, UART5, UART6, UART7
}UART_select;
typedef enum{
	I2C0, I2C1, I2C2, I2C3
}I2C_select;

/////////////////////////////////////////////////////////////////////////////////
//API's
void MCAL_GPIO_Init(PORT_select GPIOSEL); // just give clock to the GPIO
void MCAL_GPIO_Digital_Input_INIT(PORT_select GPIOSEL,uint32_t pin, Polarity_select P);// enable one pin as an input digital
uint8_t MCAL_GPIO_Read_pin(PORT_select GPIOSEL, uint32_t pin); //Read the input data of a specific pin
void MCAL_GPIO_Write_Pin(PORT_select GPIOSEL, uint32_t pin, uint8_t data); // Write a value on a pin
void MCAL_GPIO_UART_Init(UART_select Select); // init specific UART module
void MCAL_GPIO_I2C_Init(I2C_select Select);

#endif