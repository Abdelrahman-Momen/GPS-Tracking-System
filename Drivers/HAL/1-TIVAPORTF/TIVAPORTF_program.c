#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"
#include "../../MCAL/02-GPIO/GPIO_interface.h"

#include "TIVAPORTF_interface.h"
#include "TIVAPORTF_private.h"
#include "TIVAPORTF_config.h"

void HAL_TIVAPORTF_vInit(void)
{
	MCAL_GPIO_vEnablePort(GPIO_PORTF);
	MCAL_GPIO_vUnlockPort(GPIO_PORTF);
	
	MCAL_GPIO_vConfigPin(&button2);
	MCAL_GPIO_vConfigPin(&red);
	MCAL_GPIO_vConfigPin(&blue);
	MCAL_GPIO_vConfigPin(&green);
	MCAL_GPIO_vConfigPin(&button1);
}

uint32_t HAL_TIVAPORTF_uint8_tGetButtonState(uint8_t Copy_uint8_tButton)
{
	return MCAL_GPIO_uint8_tGetPinState(GPIO_PORTF, Copy_uint8_tButton);
}

void HAL_TIVAPORTF_vTurnLedOn(uint8_t Copy_uint8_tColour)
{
	MCAL_GPIO_vSetPinState(GPIO_PORTF, Copy_uint8_tColour, GPIO_PIN_SET);
}

void HAL_TIVAPORTF_vTurnLedOff(uint8_t Copy_uint8_tColour)
{
	MCAL_GPIO_vSetPinState(GPIO_PORTF, Copy_uint8_tColour, GPIO_PIN_RESET);
}

void HAL_TIVAPORTF_vTurnLedToggle(uint8_t Copy_uint8_tColour)
{
	MCAL_GPIO_vTogglePin(GPIO_PORTF, Copy_uint8_tColour);
}

void HAL_TIVAPORTF_vTurnAllLedOff(void)
{
	HAL_TIVAPORTF_vTurnLedOff(RED);
	HAL_TIVAPORTF_vTurnLedOff(BLUE);
	HAL_TIVAPORTF_vTurnLedOff(GREEN);
}
