#ifndef SYSCTRL_INTERFACE_H
#define SYSCTRL_INTERFACE_H

/******** Includes ********/
#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATHS.h"

/******* Macros ******/

/********* RCC *********/
//Oscillator Source
#define SYSCTRL_MOSC		0x00
#define SYSCTRL_PIOSC		0x01
#define SYSCTRL_PIOSC_DIV_4	0x02
#define SYSCTRL_LFIOSC		0x03
#define SYSCTRL_32_768_KHZ	0x07

//XTAL Values
#define SYSCTRL_XTAL_4_MHZ			0x06
#define SYSCTRL_XTAL_4_096_MHZ		0x07
#define SYSCTRL_XTAL_4_9152_MHZ		0x08
#define SYSCTRL_XTAL_5_MHZ			0x09
#define SYSCTRL_XTAL_5_12_MHZ		0x0A
#define SYSCTRL_XTAL_6_MHZ			0x0B
#define SYSCTRL_XTAL_6_144_MHZ		0x0C
#define SYSCTRL_XTAL_7_3728_MHZ		0x0D
#define SYSCTRL_XTAL_8_MHZ			0x0E
#define SYSCTRL_XTAL_8_192_MHZ		0x0F
#define SYSCTRL_XTAL_10_MHZ			0x10
#define SYSCTRL_XTAL_12_MHZ			0x11
#define SYSCTRL_XTAL_12_288_MHZ		0x12
#define SYSCTRL_XTAL_13_56_MHZ		0x13
#define SYSCTRL_XTAL_14_31818_MHZ	0x14
#define SYSCTRL_XTAL_16_MHZ 		0x15
#define SYSCTRL_XTAL_16_384_MHZ		0x16
#define SYSCTRL_XTAL_18_MHZ 		0x17
#define SYSCTRL_XTAL_20_MHZ 		0x18
#define SYSCTRL_XTAL_24_MHZ 		0x19
#define SYSCTRL_XTAL_25_MHZ 		0x1A

//PWM Division
#define SYSCTRL_PWMIV_2		0x00
#define SYSCTRL_PWMIV_4		0x01
#define SYSCTRL_PWMIV_8		0x02
#define SYSCTRL_PWMIV_16	0x03
#define SYSCTRL_PWMIV_32	0x04
#define SYSCTRL_PWMIV_64	0x07

/************** Functions ***************/
void SYSCTRL_vSetClockOptions();


#endif