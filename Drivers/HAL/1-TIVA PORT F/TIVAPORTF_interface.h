#ifndef TIVAPORTF_INTERFACE_H
#define TIVAPORTF_INTERFACE_H

/****** Includes *******/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"

/******* Macros *******/
/*Buttons*/
#define BUTTON2 0
#define BUTTON1 4

/*LED*/
#define RED		1
#define BLUE	2
#define	GREEN	3

/****** Functions ******/
void HAL_TIVAPORTF_vInit(void);
uint8_t HAL_TIVAPORTF_uint8_tGetButtonState(uint8_t Copy_uint8_tButton);
void HAL_TIVAPORTF_vTurnLedOn(uint8_t Copy_uint8_tColour);
void HAL_TIVAPORTF_vTurnLedOff(uint8_t Copy_uint8_tColour);
void HAL_TIVAPORTF_vTurnLedToggle(uint8_t Copy_uint8_tColour);
void HAL_TIVAPORTF_vTurnAllLedOff(void);

#endif
