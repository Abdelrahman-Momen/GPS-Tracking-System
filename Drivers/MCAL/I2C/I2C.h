#ifndef I2C_HEADER
#define I2C_HEADER
#include "GPIO.h"

// I2C Specific
#define SCL_CLK  100000

// addresses of clock
#define RCGCI2C			(*((volatile unsigned long*)0x40FE620))
#define PRI2C			(*((volatile unsigned long*)0x40FEA20))

//base address of I2C
#define BASE_I2C0 		(0x40020000)
#define BASE_I2C1 		(0x40021000)
#define BASE_I2C2 		(0x40022000)
#define BASE_I2C3 		(0x40023000)

//I2C Master Configuration
#define	I2C0_MCR			(*((volatile unsigned long*)(BASE_I2C0 + 0x020)))
#define I2C1_MCR      (*((volatile unsigned long*)(BASE_I2C1 + 0x020)))
#define	I2C2_MCR      (*((volatile unsigned long*)(BASE_I2C2 + 0x020)))
#define I2C3_MCR      (*((volatile unsigned long*)(BASE_I2C3 + 0x020)))
	
//I2C Master Timer Period
#define	I2C0_MTPR			 (*((volatile unsigned long*)(BASE_I2C0 + 0x00C)))
#define I2C1_MTPR      (*((volatile unsigned long*)(BASE_I2C1 + 0x00C)))
#define	I2C2_MTPR      (*((volatile unsigned long*)(BASE_I2C2 + 0x00C)))
#define I2C3_MTPR      (*((volatile unsigned long*)(BASE_I2C3 + 0x00C)))
//I2C Master Slave Address
#define	I2C0_MSA			 (*((volatile unsigned long*)(BASE_I2C0)))
#define I2C1_MSA       (*((volatile unsigned long*)(BASE_I2C1)))
#define	I2C2_MSA       (*((volatile unsigned long*)(BASE_I2C2)))
#define I2C3_MSA       (*((volatile unsigned long*)(BASE_I2C3)))
	
//I2C Master Data
#define	I2C0_MDR			 (*((volatile unsigned long*)(BASE_I2C0 + 0x008)))
#define I2C1_MDR       (*((volatile unsigned long*)(BASE_I2C1 + 0x008)))
#define	I2C2_MDR       (*((volatile unsigned long*)(BASE_I2C2 + 0x008)))
#define I2C3_MDR       (*((volatile unsigned long*)(BASE_I2C3 + 0x008)))
	
//I2C Master Control/Status
#define	I2C0_MCS			 (*((volatile unsigned long*)(BASE_I2C0 + 0x004)))
#define I2C1_MCS       (*((volatile unsigned long*)(BASE_I2C1 + 0x004)))
#define	I2C2_MCS       (*((volatile unsigned long*)(BASE_I2C2 + 0x004)))
#define I2C3_MCS       (*((volatile unsigned long*)(BASE_I2C3 + 0x004)))

// I2C modules
#define I2C0_MASK						0x1
#define I2C1_MASK						0x2
#define I2C2_MASK						0x4
#define I2C3_MASK						0x8


//////////////////////////////////////////////////////////////////////////
//API's
void MCAL_I2C_Init_master(I2C_Select Select);
uint8_t MCAL_I2C_Transmit(I2C_Select Select, uint8_t address, uint8_t DATA);
#endif