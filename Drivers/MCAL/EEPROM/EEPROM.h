#ifndef EEPROM_H
#define EEPROM_H

#include "BIT_MATHS.h"
#include <stdint.h>

#define EEPROM_BASE_ADDRESS	0x400AF000

/*Registers*/
#define SYSCTRL_SREEPROM	(*((volatile uint32_t*)0x400FE558))
#define SYSCTRL_RCGCEEPROM	(*((volatile uint32_t*)0x400FE658))
#define SYSCTRL_PREEPROM	(*((volatile uint32_t*)0x400FEA58))
#define EEPROM_EESIZE		(*((volatile uint32_t*)(EEPROM_BASE_ADDRESS + 0x000)))
#define EEPROM_EEBLOCK		(*((volatile uint32_t*)(EEPROM_BASE_ADDRESS + 0x004)))
#define EEPROM_EEOFFSET		(*((volatile uint32_t*)(EEPROM_BASE_ADDRESS + 0x008)))
#define EEPROM_EERDWR		(*((volatile uint32_t*)(EEPROM_BASE_ADDRESS + 0x010)))
#define EEPROM_EERDWRINC	(*((volatile uint32_t*)(EEPROM_BASE_ADDRESS + 0x014)))
#define EEPROM_EEDONE		(*((volatile uint32_t*)(EEPROM_BASE_ADDRESS + 0x018)))
#define EEPROM_EESUPP		(*((volatile uint32_t*)(EEPROM_BASE_ADDRESS + 0x01C)))
#define EEPROM_EEUNLOCK		(*((volatile uint32_t*)(EEPROM_BASE_ADDRESS + 0x020)))
#define EEPROM_EEPROT		(*((volatile uint32_t*)(EEPROM_BASE_ADDRESS + 0x030)))
#define EEPROM_EEPASS0		(*((volatile uint32_t*)(EEPROM_BASE_ADDRESS + 0x034)))
#define EEPROM_EEPASS1		(*((volatile uint32_t*)(EEPROM_BASE_ADDRESS + 0x038)))
#define EEPROM_EEPASS2		(*((volatile uint32_t*)(EEPROM_BASE_ADDRESS + 0x03C)))
#define EEPROM_EEINT		(*((volatile uint32_t*)(EEPROM_BASE_ADDRESS + 0x040)))
#define EEPROM_EEHIDE		(*((volatile uint32_t*)(EEPROM_BASE_ADDRESS + 0x050)))
#define EEPROM_EEDBGME		(*((volatile uint32_t*)(EEPROM_BASE_ADDRESS + 0x080)))
#define EEPROM_EEPROMPP		(*((volatile uint32_t*)(EEPROM_BASE_ADDRESS + 0xFC0)))

typedef enum {
	EEPROM_OK, WRBUSY, NOPERM, PRETRY, ERETRY, EREQ
}EEPROM_error_t;

EEPROM_error_t MCAL_EEPROM_Init(void);
void MCAL_EEPROM_massErase(void);
void MCAL_EEPROM_write(uint16_t *address, float* data, uint8_t length);
void MCAL_EEPROM_write_specific(uint8_t data);
void MCAL_EEPROM_read(uint16_t *address, float* buffer, uint8_t length);
void MCAL_EEPROM_read_specific(uint16_t* buffer);

#endif // !EEPROM_H
