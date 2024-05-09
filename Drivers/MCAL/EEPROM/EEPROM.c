#include "EEPROM.h"

EEPROM_error_t MCAL_EEPROM_Init(void)
{
	
	volatile uint8_t i;
	SET_BIT(SYSCTRL_RCGCEEPROM, 0);
	while (!GET_BIT(SYSCTRL_RCGCEEPROM, 0));

	for (i = 0; i < 6; i++);

	while (GET_BIT(EEPROM_EEDONE, 0));

	if (GET_BIT(EEPROM_EESUPP, 3))
	{
		SET_BIT(EEPROM_EESUPP, 0);
		return	PRETRY;
	}

	if (GET_BIT(EEPROM_EESUPP, 2))
	{
		SET_BIT(EEPROM_EESUPP, 0);
		return	ERETRY;
	}

	if (GET_BIT(EEPROM_EESUPP, 1))
	{
		SET_BIT(EEPROM_EESUPP, 0);
		return	EREQ;
	}

	else
	{
		SET_BIT(SYSCTRL_SREEPROM, 0);
		CLR_BIT(SYSCTRL_SREEPROM, 0);

		for (i = 0; i < 6; i++);

		while (GET_BIT(EEPROM_EEDONE, 0));

		if (GET_BIT(EEPROM_EESUPP, 3))
		{
			SET_BIT(EEPROM_EESUPP, 0);
			return	PRETRY;
		}

		if (GET_BIT(EEPROM_EESUPP, 2))
		{
			SET_BIT(EEPROM_EESUPP, 0);
			return	ERETRY;
		}

		if (GET_BIT(EEPROM_EESUPP, 1))
		{
			SET_BIT(EEPROM_EESUPP, 0);
			return	EREQ;
		}

		else
		{
			EEPROM_EEDBGME = 0xE37B0000;
			SET_BIT(EEPROM_EEDBGME, 0);
			while (GET_BIT(EEPROM_EEDBGME, 0));
			EEPROM_EEBLOCK = 0x00000000;
			EEPROM_EEOFFSET = 0x00000000;
			return	EEPROM_OK;
		}
	}
}

void MCAL_EEPROM_write(uint16_t address, float* data, uint8_t length)
{
	EEPROM_EEBLOCK = (0x0000FFFF)&(address>>4);
	EEPROM_EEOFFSET = 0x0000000F & address;
	
	uint8_t i =0;
	for (i = 0; i < length; i++)
	{
		EEPROM_EERDWRINC = (uint32_t)data[i];
		while (GET_BIT(EEPROM_EEDONE, 0));
	}
}

void MCAL_EEPROM_read(uint16_t address, float* buffer, uint8_t length)
{
	EEPROM_EEBLOCK = (0x0000FFFF)&(address>>4);
	EEPROM_EEOFFSET = 0x0000000F & address;
	
	uint8_t i =0;
	for (i = 0; i < length; i++)
	{
		buffer[i] = (float)EEPROM_EERDWRINC;
		while (GET_BIT(EEPROM_EEDONE, 0));
	}
}
