#ifndef SYSCTRL_PRIVATE_H
#define SYSCTRL_PRIVATE_H

/******** Includes ********/
#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATHS.h"

/******* Base Address *******/
#define SYSCTRL_BASE_ADDRESS 0x400FE000

/****** System Control Registers ******/
#define SYSCTRL_RCC			(*((volatile uint32_t*)(SYSTEM_CONTROL_BASE_ADDRESS + 0x060)))
#define SYSCTRL_RCC2		(*((volatile uint32_t*)(SYSTEM_CONTROL_BASE_ADDRESS + 0x070)))
#define SYSCTRL_GPIOHBCTL	(*((volatile uint32_t*)(SYSTEM_CONTROL_BASE_ADDRESS + 0x06C)))
#define SYSCTRL_RCGCGPIO	(*((volatile uint32_t*)(SYSTEM_CONTROL_BASE_ADDRESS + 0x608)))

#endif