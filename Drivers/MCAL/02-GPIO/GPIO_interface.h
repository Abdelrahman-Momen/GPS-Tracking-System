#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/******* Macros ********/
#define GPIO_UNLOCK_KEY	0x4C4F434B
#define GPIO_LOCK	0x00000000

/*Ports*/
#define GPIO_PORTA	0
#define GPIO_PORTB	1
#define GPIO_PORTC	2
#define GPIO_PORTD	3
#define GPIO_PORTE	4
#define GPIO_PORTF	5

/*Busses*/
#define GPIO_BUS_APB	0
#define GPIO_BUS_AHB	1

/*Pins*/
#define GPIO_PIN0  0
#define GPIO_PIN1  1
#define GPIO_PIN2  2
#define GPIO_PIN3  3
#define GPIO_PIN4  4
#define GPIO_PIN5  5
#define GPIO_PIN6  6
#define GPIO_PIN7  7

/*Directions*/
#define GPIO_PIN_INPUT	0
#define GPIO_PIN_OUTPUT	1

/*Digital Enable*/
#define GPIO_PIN_DIGITAL_DISABLE	0
#define GPIO_PIN_DIGITAL_ENABLE		1

/*Stats*/
#define GPIO_PIN_RESET	0
#define GPIO_PIN_SET	1

/*Analog Mode selection*/
#define GPIO_PIN_AMSEL_RESET 0
#define GPIO_PIN_AMSEL_SET 1

/*Altarnative Function selection*/
#define GPIO_PIN_AFSEL_RESET 0
#define GPIO_PIN_AFSEL_SET 1

/*Pull Up Resistor selection*/
#define GPIO_PIN_PUR_RESET 0
#define GPIO_PIN_PUR_SET 1

/*Pull Down Resistor selection*/
#define GPIO_PIN_PDR_RESET 0
#define GPIO_PIN_PDR_SET 1

/******* Variables *******/
typedef struct GPIO_pinConfig_t
{
	uint8_t port;
	uint8_t bus;
	uint8_t pin;
	uint8_t digitalEnable;
	uint8_t direction;
	uint8_t amsel;
	uint8_t afsel;
	uint8_t pctl;
	uint8_t pur;
	uint8_t pdr;

}GPIO_pinConfig_t;

/******* Functions ******/
void MCAL_GPIO_vEnablePort(uint8_t Copy_uint8_tPort);
void MCAL_GPIO_vUnlockPort(uint8_t Copy_uint8_tPort);
void MCAL_GPIO_vPinCommitChange(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin);
void MCAL_GPIO_vDigitalEnablePin(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin);
void MCAL_GPIO_vDigitalDisablePin(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin);
void MCAL_GPIO_vPinNoChange(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin);
void MCAL_GPIO_vLockPort(uint8_t Copy_uint8_tPort);
void MCAL_GPIO_vDisablePort(uint8_t Copy_uint8_tPort);
void MCAL_GPIO_vSetPinDirection(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin, uint8_t Copy_uint8_tDirection);
void MCAL_GPIO_vSetPinAmsel(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin, uint8_t Copy_uint8_tAmsel);
void MCAL_GPIO_vSetPinAfsel(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin, uint8_t Copy_uint8_tAfsel);
void MCAL_GPIO_vSetPinPctl(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin, uint8_t Copy_uint8_tPctl);
void MCAL_GPIO_vSetPinPur(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin, uint8_t Copy_uint8_tPur);
void MCAL_GPIO_vSetPinPdr(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin, uint8_t Copy_uint8_tPdr);
void MCAL_GPIO_vConfigPin(GPIO_pinConfig_t* Ptr_uint8_tConfig);
void MCAL_GPIO_vSetPinState(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin, uint8_t Copy_uint8_tState);
void MCAL_GPIO_vTogglePin(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin);
uint32_t MCAL_GPIO_uint8_tGetPinState(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin);

#endif
