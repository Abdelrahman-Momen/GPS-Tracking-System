#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void MCAL_GPIO_vEnablePort(uint8_t Copy_uint8_tPort)
{
	SET_BIT(SYSCTRL_RCGCGPIO, Copy_uint8_tPort);
	while (!(SYSCTRL_PRGPIO & (1 << Copy_uint8_tPort)));
}

void MCAL_GPIO_vUnlockPort(uint8_t Copy_uint8_tPort)
{
	switch (Copy_uint8_tPort)
	{
	case GPIO_PORTA:
		GPIO_PORTA_APB_GPIOLOCK = GPIO_UNLOCK_KEY;
		break;

	case GPIO_PORTB:
		GPIO_PORTB_APB_GPIOLOCK = GPIO_UNLOCK_KEY;
		break;

	case GPIO_PORTC:
		GPIO_PORTC_APB_GPIOLOCK = GPIO_UNLOCK_KEY;
		break;

	case GPIO_PORTD:
		GPIO_PORTD_APB_GPIOLOCK = GPIO_UNLOCK_KEY;
		break;

	case GPIO_PORTE:
		GPIO_PORTE_APB_GPIOLOCK = GPIO_UNLOCK_KEY;
		break;

	case GPIO_PORTF:
		GPIO_PORTF_APB_GPIOLOCK = GPIO_UNLOCK_KEY;
		break;

	default:
		break;
	}
}

void MCAL_GPIO_vPinCommitChange(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin)
{
	switch (Copy_uint8_tPort)
	{
	case GPIO_PORTA:
		SET_BIT(GPIO_PORTA_APB_GPIOCR, Copy_uint8_tPin);
		break;

	case GPIO_PORTB:
		SET_BIT(GPIO_PORTB_APB_GPIOCR, Copy_uint8_tPin);
		break;

	case GPIO_PORTC:
		SET_BIT(GPIO_PORTC_APB_GPIOCR, Copy_uint8_tPin);
		break;

	case GPIO_PORTD:
		SET_BIT(GPIO_PORTD_APB_GPIOCR, Copy_uint8_tPin);
		break;

	case GPIO_PORTE:
		SET_BIT(GPIO_PORTE_APB_GPIOCR, Copy_uint8_tPin);
		break;

	case GPIO_PORTF:
		SET_BIT(GPIO_PORTF_APB_GPIOCR, Copy_uint8_tPin);
		break;

	default:
		break;
	}
}

void MCAL_GPIO_vDigitalEnablePin(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin)
{
	switch (Copy_uint8_tPort)
	{
	case GPIO_PORTA:
		SET_BIT(GPIO_PORTA_APB_GPIODEN, Copy_uint8_tPin);
		break;

	case GPIO_PORTB:
		SET_BIT(GPIO_PORTB_APB_GPIODEN, Copy_uint8_tPin);
		break;

	case GPIO_PORTC:
		SET_BIT(GPIO_PORTC_APB_GPIODEN, Copy_uint8_tPin);
		break;

	case GPIO_PORTD:
		SET_BIT(GPIO_PORTD_APB_GPIODEN, Copy_uint8_tPin);
		break;

	case GPIO_PORTE:
		SET_BIT(GPIO_PORTE_APB_GPIODEN, Copy_uint8_tPin);
		break;

	case GPIO_PORTF:
		SET_BIT(GPIO_PORTF_APB_GPIODEN, Copy_uint8_tPin);
		break;

	default:
		break;
	}
}

void MCAL_GPIO_vDigitalDisablePin(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin)
{
	switch (Copy_uint8_tPort)
	{
	case GPIO_PORTA:
		CLR_BIT(GPIO_PORTA_APB_GPIODEN, Copy_uint8_tPin);
		break;

	case GPIO_PORTB:
		CLR_BIT(GPIO_PORTB_APB_GPIODEN, Copy_uint8_tPin);
		break;

	case GPIO_PORTC:
		CLR_BIT(GPIO_PORTC_APB_GPIODEN, Copy_uint8_tPin);
		break;

	case GPIO_PORTD:
		CLR_BIT(GPIO_PORTD_APB_GPIODEN, Copy_uint8_tPin);
		break;

	case GPIO_PORTE:
		CLR_BIT(GPIO_PORTE_APB_GPIODEN, Copy_uint8_tPin);
		break;

	case GPIO_PORTF:
		CLR_BIT(GPIO_PORTF_APB_GPIODEN, Copy_uint8_tPin);
		break;

	default:
		break;
	}
}

void MCAL_GPIO_vPinNoChange(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin)
{
	switch (Copy_uint8_tPort)
	{
	case GPIO_PORTA:
		CLR_BIT(GPIO_PORTA_APB_GPIOCR, Copy_uint8_tPin);
		break;

	case GPIO_PORTB:
		CLR_BIT(GPIO_PORTB_APB_GPIOCR, Copy_uint8_tPin);
		break;

	case GPIO_PORTC:
		CLR_BIT(GPIO_PORTC_APB_GPIOCR, Copy_uint8_tPin);
		break;

	case GPIO_PORTD:
		CLR_BIT(GPIO_PORTD_APB_GPIOCR, Copy_uint8_tPin);
		break;

	case GPIO_PORTE:
		CLR_BIT(GPIO_PORTE_APB_GPIOCR, Copy_uint8_tPin);
		break;

	case GPIO_PORTF:
		CLR_BIT(GPIO_PORTF_APB_GPIOCR, Copy_uint8_tPin);
		break;

	default:
		break;
	}
}

void MCAL_GPIO_vLockPort(uint8_t Copy_uint8_tPort)
{
	switch (Copy_uint8_tPort)
	{
	case GPIO_PORTA:
		GPIO_PORTA_APB_GPIOLOCK = GPIO_LOCK;
		break;

	case GPIO_PORTB:
		GPIO_PORTB_APB_GPIOLOCK = GPIO_LOCK;
		break;

	case GPIO_PORTC:
		GPIO_PORTC_APB_GPIOLOCK = GPIO_LOCK;
		break;

	case GPIO_PORTD:
		GPIO_PORTD_APB_GPIOLOCK = GPIO_LOCK;
		break;

	case GPIO_PORTE:
		GPIO_PORTE_APB_GPIOLOCK = GPIO_LOCK;
		break;

	case GPIO_PORTF:
		GPIO_PORTF_APB_GPIOLOCK = GPIO_LOCK;
		break;

	default:
		break;
	}
}

void MCAL_GPIO_vDisablePort(uint8_t Copy_uint8_tPort)
{
	CLR_BIT(SYSCTRL_RCGCGPIO, Copy_uint8_tPort);
}

void MCAL_GPIO_vSetPinDirection(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin, uint8_t Copy_uint8_tDirection)
{
	switch (Copy_uint8_tPort)
	{
	case GPIO_PORTA:
		if (Copy_uint8_tDirection == GPIO_PIN_INPUT)
		{
			CLR_BIT(GPIO_PORTA_APB_GPIODIR, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tDirection == GPIO_PIN_OUTPUT)
		{
			SET_BIT(GPIO_PORTA_APB_GPIODIR, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTB:
		if (Copy_uint8_tDirection == GPIO_PIN_INPUT)
		{
			CLR_BIT(GPIO_PORTB_APB_GPIODIR, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tDirection == GPIO_PIN_OUTPUT)
		{
			SET_BIT(GPIO_PORTB_APB_GPIODIR, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTC:
		if (Copy_uint8_tDirection == GPIO_PIN_INPUT)
		{
			CLR_BIT(GPIO_PORTC_APB_GPIODIR, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tDirection == GPIO_PIN_OUTPUT)
		{
			SET_BIT(GPIO_PORTC_APB_GPIODIR, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTD:
		if (Copy_uint8_tDirection == GPIO_PIN_INPUT)
		{
			CLR_BIT(GPIO_PORTD_APB_GPIODIR, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tDirection == GPIO_PIN_OUTPUT)
		{
			SET_BIT(GPIO_PORTD_APB_GPIODIR, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTE:
		if (Copy_uint8_tDirection == GPIO_PIN_INPUT)
		{
			CLR_BIT(GPIO_PORTE_APB_GPIODIR, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tDirection == GPIO_PIN_OUTPUT)
		{
			SET_BIT(GPIO_PORTE_APB_GPIODIR, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTF:
		if (Copy_uint8_tDirection == GPIO_PIN_INPUT)
		{
			CLR_BIT(GPIO_PORTF_APB_GPIODIR, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tDirection == GPIO_PIN_OUTPUT)
		{
			SET_BIT(GPIO_PORTF_APB_GPIODIR, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	default:
		break;
	}
}

void MCAL_GPIO_vSetPinAmsel(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin, uint8_t Copy_uint8_tAmsel)
{
	switch (Copy_uint8_tPort)
	{
	case GPIO_PORTA:
		if (Copy_uint8_tAmsel == GPIO_PIN_AMSEL_RESET)
		{
			CLR_BIT(GPIO_PORTA_APB_GPIOAMSEL, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tAmsel == GPIO_PIN_AMSEL_SET)
		{
			SET_BIT(GPIO_PORTA_APB_GPIOAMSEL, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTB:
		if (Copy_uint8_tAmsel == GPIO_PIN_AMSEL_RESET)
		{
			CLR_BIT(GPIO_PORTB_APB_GPIOAMSEL, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tAmsel == GPIO_PIN_AMSEL_SET)
		{
			SET_BIT(GPIO_PORTB_APB_GPIOAMSEL, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTC:
		if (Copy_uint8_tAmsel == GPIO_PIN_AMSEL_RESET)
		{
			CLR_BIT(GPIO_PORTC_APB_GPIOAMSEL, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tAmsel == GPIO_PIN_AMSEL_SET)
		{
			SET_BIT(GPIO_PORTC_APB_GPIOAMSEL, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTD:
		if (Copy_uint8_tAmsel == GPIO_PIN_AMSEL_RESET)
		{
			CLR_BIT(GPIO_PORTD_APB_GPIOAMSEL, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tAmsel == GPIO_PIN_AMSEL_SET)
		{
			SET_BIT(GPIO_PORTD_APB_GPIOAMSEL, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTE:
		if (Copy_uint8_tAmsel == GPIO_PIN_AMSEL_RESET)
		{
			CLR_BIT(GPIO_PORTE_APB_GPIOAMSEL, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tAmsel == GPIO_PIN_AMSEL_SET)
		{
			SET_BIT(GPIO_PORTE_APB_GPIOAMSEL, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTF:
		if (Copy_uint8_tAmsel == GPIO_PIN_AMSEL_RESET)
		{
			CLR_BIT(GPIO_PORTF_APB_GPIOAMSEL, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tAmsel == GPIO_PIN_AMSEL_SET)
		{
			SET_BIT(GPIO_PORTF_APB_GPIOAMSEL, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	default:
		break;
	}
}

void MCAL_GPIO_vSetPinAfsel(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin, uint8_t Copy_uint8_tAfsel)
{
	switch (Copy_uint8_tPort)
	{
	case GPIO_PORTA:
		if (Copy_uint8_tAfsel == GPIO_PIN_AFSEL_RESET)
		{
			CLR_BIT(GPIO_PORTA_APB_GPIOAFSEL, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tAfsel == GPIO_PIN_AFSEL_SET)
		{
			SET_BIT(GPIO_PORTA_APB_GPIOAFSEL, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTB:
		if (Copy_uint8_tAfsel == GPIO_PIN_AFSEL_RESET)
		{
			CLR_BIT(GPIO_PORTB_APB_GPIOAFSEL, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tAfsel == GPIO_PIN_AFSEL_SET)
		{
			SET_BIT(GPIO_PORTB_APB_GPIOAFSEL, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTC:
		if (Copy_uint8_tAfsel == GPIO_PIN_AFSEL_RESET)
		{
			CLR_BIT(GPIO_PORTC_APB_GPIOAFSEL, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tAfsel == GPIO_PIN_AFSEL_SET)
		{
			SET_BIT(GPIO_PORTC_APB_GPIOAFSEL, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTD:
		if (Copy_uint8_tAfsel == GPIO_PIN_AFSEL_RESET)
		{
			CLR_BIT(GPIO_PORTD_APB_GPIOAFSEL, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tAfsel == GPIO_PIN_AFSEL_SET)
		{
			SET_BIT(GPIO_PORTD_APB_GPIOAFSEL, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTE:
		if (Copy_uint8_tAfsel == GPIO_PIN_AFSEL_RESET)
		{
			CLR_BIT(GPIO_PORTE_APB_GPIOAFSEL, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tAfsel == GPIO_PIN_AFSEL_SET)
		{
			SET_BIT(GPIO_PORTE_APB_GPIOAFSEL, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTF:
		if (Copy_uint8_tAfsel == GPIO_PIN_AFSEL_RESET)
		{
			CLR_BIT(GPIO_PORTF_APB_GPIOAFSEL, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tAfsel == GPIO_PIN_AFSEL_SET)
		{
			SET_BIT(GPIO_PORTF_APB_GPIOAFSEL, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	default:
		break;
	}
}

void MCAL_GPIO_vSetPinPctl(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin, uint8_t Copy_uint8_tPctl)
{
	switch (Copy_uint8_tPort)
	{
	case GPIO_PORTA:
		GPIO_PORTA_APB_GPIOPCTL &= ~(0xF << 4 * Copy_uint8_tPin);
		GPIO_PORTA_APB_GPIOPCTL |= (Copy_uint8_tPctl << 4 * Copy_uint8_tPin);
		break;

	case GPIO_PORTB:
		GPIO_PORTB_APB_GPIOPCTL &= ~(0xF << 4 * Copy_uint8_tPin);
		GPIO_PORTB_APB_GPIOPCTL |= (Copy_uint8_tPctl << 4 * Copy_uint8_tPin);
		break;

	case GPIO_PORTC:
		GPIO_PORTC_APB_GPIOPCTL &= ~(0xF << 4 * Copy_uint8_tPin);
		GPIO_PORTC_APB_GPIOPCTL |= (Copy_uint8_tPctl << 4 * Copy_uint8_tPin);
		break;

	case GPIO_PORTD:
		GPIO_PORTD_APB_GPIOPCTL &= ~(0xF << 4 * Copy_uint8_tPin);
		GPIO_PORTD_APB_GPIOPCTL |= (Copy_uint8_tPctl << 4 * Copy_uint8_tPin);
		break;

	case GPIO_PORTE:
		GPIO_PORTE_APB_GPIOPCTL &= ~(0xF << 4 * Copy_uint8_tPin);
		GPIO_PORTE_APB_GPIOPCTL |= (Copy_uint8_tPctl << 4 * Copy_uint8_tPin);
		break;

	case GPIO_PORTF:
		GPIO_PORTF_APB_GPIOPCTL &= ~(0xF << 4 * Copy_uint8_tPin);
		GPIO_PORTF_APB_GPIOPCTL |= (Copy_uint8_tPctl << 4 * Copy_uint8_tPin);
		break;

	default:
		break;
	}
}

void MCAL_GPIO_vSetPinPur(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin, uint8_t Copy_uint8_tPur)
{
	switch (Copy_uint8_tPort)
	{
	case GPIO_PORTA:
		if (Copy_uint8_tPur == GPIO_PIN_PUR_RESET)
		{
			CLR_BIT(GPIO_PORTA_APB_GPIOPUR, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tPur == GPIO_PIN_PUR_SET)
		{
			SET_BIT(GPIO_PORTA_APB_GPIOPUR, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTB:
		if (Copy_uint8_tPur == GPIO_PIN_PUR_RESET)
		{
			CLR_BIT(GPIO_PORTB_APB_GPIOPUR, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tPur == GPIO_PIN_PUR_SET)
		{
			SET_BIT(GPIO_PORTB_APB_GPIOPUR, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTC:
		if (Copy_uint8_tPur == GPIO_PIN_PUR_RESET)
		{
			CLR_BIT(GPIO_PORTC_APB_GPIOPUR, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tPur == GPIO_PIN_PUR_SET)
		{
			SET_BIT(GPIO_PORTC_APB_GPIOPUR, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTD:
		if (Copy_uint8_tPur == GPIO_PIN_PUR_RESET)
		{
			CLR_BIT(GPIO_PORTD_APB_GPIOPUR, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tPur == GPIO_PIN_PUR_SET)
		{
			SET_BIT(GPIO_PORTD_APB_GPIOPUR, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTE:
		if (Copy_uint8_tPur == GPIO_PIN_PUR_RESET)
		{
			CLR_BIT(GPIO_PORTE_APB_GPIOPUR, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tPur == GPIO_PIN_PUR_SET)
		{
			SET_BIT(GPIO_PORTE_APB_GPIOPUR, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTF:
		if (Copy_uint8_tPur == GPIO_PIN_PUR_RESET)
		{
			CLR_BIT(GPIO_PORTF_APB_GPIOPUR, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tPur == GPIO_PIN_PUR_SET)
		{
			SET_BIT(GPIO_PORTF_APB_GPIOPUR, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	default:
		break;
	}
}

void MCAL_GPIO_vSetPinPdr(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin, uint8_t Copy_uint8_tPdr)
{
	switch (Copy_uint8_tPort)
	{
	case GPIO_PORTA:
		if (Copy_uint8_tPdr == GPIO_PIN_PDR_RESET)
		{
			CLR_BIT(GPIO_PORTA_APB_GPIOPDR, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tPdr == GPIO_PIN_PDR_SET)
		{
			SET_BIT(GPIO_PORTA_APB_GPIOPDR, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTB:
		if (Copy_uint8_tPdr == GPIO_PIN_PDR_RESET)
		{
			CLR_BIT(GPIO_PORTB_APB_GPIOPDR, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tPdr == GPIO_PIN_PDR_SET)
		{
			SET_BIT(GPIO_PORTB_APB_GPIOPDR, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTC:
		if (Copy_uint8_tPdr == GPIO_PIN_PDR_RESET)
		{
			CLR_BIT(GPIO_PORTC_APB_GPIOPDR, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tPdr == GPIO_PIN_PDR_SET)
		{
			SET_BIT(GPIO_PORTC_APB_GPIOPDR, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTD:
		if (Copy_uint8_tPdr == GPIO_PIN_PDR_RESET)
		{
			CLR_BIT(GPIO_PORTD_APB_GPIOPDR, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tPdr == GPIO_PIN_PDR_SET)
		{
			SET_BIT(GPIO_PORTD_APB_GPIOPDR, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTE:
		if (Copy_uint8_tPdr == GPIO_PIN_PDR_RESET)
		{
			CLR_BIT(GPIO_PORTE_APB_GPIOPDR, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tPdr == GPIO_PIN_PDR_SET)
		{
			SET_BIT(GPIO_PORTE_APB_GPIOPDR, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTF:
		if (Copy_uint8_tPdr == GPIO_PIN_PDR_RESET)
		{
			CLR_BIT(GPIO_PORTF_APB_GPIOPDR, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tPdr == GPIO_PIN_PDR_SET)
		{
			SET_BIT(GPIO_PORTF_APB_GPIOPDR, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	default:
		break;
	}
}

void MCAL_GPIO_vConfigPin(GPIO_pinConfig_t* Ptr_uint8_tConfig)
{
	MCAL_GPIO_vPinCommitChange(Ptr_uint8_tConfig->port, Ptr_uint8_tConfig->pin);

	if (Ptr_uint8_tConfig->digitalEnable == GPIO_PIN_DIGITAL_DISABLE)
	{
		MCAL_GPIO_vDigitalDisablePin(Ptr_uint8_tConfig->port, Ptr_uint8_tConfig->pin);
	}
	else if (Ptr_uint8_tConfig->digitalEnable == GPIO_PIN_DIGITAL_ENABLE)
	{
		MCAL_GPIO_vDigitalEnablePin(Ptr_uint8_tConfig->port, Ptr_uint8_tConfig->pin);
	}
	else 
	{

	}

	MCAL_GPIO_vSetPinDirection(Ptr_uint8_tConfig->port, Ptr_uint8_tConfig->pin, Ptr_uint8_tConfig->direction);
	MCAL_GPIO_vSetPinAmsel(Ptr_uint8_tConfig->port, Ptr_uint8_tConfig->pin, Ptr_uint8_tConfig->amsel);
	MCAL_GPIO_vSetPinAfsel(Ptr_uint8_tConfig->port, Ptr_uint8_tConfig->pin, Ptr_uint8_tConfig->afsel);
	MCAL_GPIO_vSetPinPctl(Ptr_uint8_tConfig->port, Ptr_uint8_tConfig->pin, Ptr_uint8_tConfig->pctl);
	MCAL_GPIO_vSetPinPur(Ptr_uint8_tConfig->port, Ptr_uint8_tConfig->pin, Ptr_uint8_tConfig->pur);
	MCAL_GPIO_vSetPinPdr(Ptr_uint8_tConfig->port, Ptr_uint8_tConfig->pin, Ptr_uint8_tConfig->pdr);
}

void MCAL_GPIO_vSetPinState(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin, uint8_t Copy_uint8_tState)
{
	switch (Copy_uint8_tPort)
	{
	case GPIO_PORTA:
		if (Copy_uint8_tState == GPIO_PIN_RESET)
		{
			CLR_BIT(GPIO_PORTA_APB_GPIODATA, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tState == GPIO_PIN_SET)
		{
			SET_BIT(GPIO_PORTA_APB_GPIODATA, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTB:
		if (Copy_uint8_tState == GPIO_PIN_RESET)
		{
			CLR_BIT(GPIO_PORTB_APB_GPIODATA, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tState == GPIO_PIN_SET)
		{
			SET_BIT(GPIO_PORTB_APB_GPIODATA, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTC:
		if (Copy_uint8_tState == GPIO_PIN_RESET)
		{
			CLR_BIT(GPIO_PORTC_APB_GPIODATA, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tState == GPIO_PIN_SET)
		{
			SET_BIT(GPIO_PORTC_APB_GPIODATA, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTD:
		if (Copy_uint8_tState == GPIO_PIN_RESET)
		{
			CLR_BIT(GPIO_PORTD_APB_GPIODATA, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tState == GPIO_PIN_SET)
		{
			SET_BIT(GPIO_PORTD_APB_GPIODATA, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTE:
		if (Copy_uint8_tState == GPIO_PIN_RESET)
		{
			CLR_BIT(GPIO_PORTE_APB_GPIODATA, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tState == GPIO_PIN_SET)
		{
			SET_BIT(GPIO_PORTE_APB_GPIODATA, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	case GPIO_PORTF:
		if (Copy_uint8_tState == GPIO_PIN_RESET)
		{
			CLR_BIT(GPIO_PORTF_APB_GPIODATA, Copy_uint8_tPin);
		}
		else if (Copy_uint8_tState == GPIO_PIN_SET)
		{
			SET_BIT(GPIO_PORTF_APB_GPIODATA, Copy_uint8_tPin);
		}
		else
		{

		}
		break;

	default:
		break;
	}
}

void MCAL_GPIO_vTogglePin(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin)
{
	switch (Copy_uint8_tPort)
	{
	case GPIO_PORTA:
		TOG_BIT(GPIO_PORTA_APB_GPIODATA, Copy_uint8_tPin);
		break;

	case GPIO_PORTB:
		TOG_BIT(GPIO_PORTB_APB_GPIODATA, Copy_uint8_tPin);
		break;

	case GPIO_PORTC:
		TOG_BIT(GPIO_PORTC_APB_GPIODATA, Copy_uint8_tPin);
		break;

	case GPIO_PORTD:
		TOG_BIT(GPIO_PORTD_APB_GPIODATA, Copy_uint8_tPin);
		break;

	case GPIO_PORTE:
		TOG_BIT(GPIO_PORTE_APB_GPIODATA, Copy_uint8_tPin);
		break;

	case GPIO_PORTF:
		TOG_BIT(GPIO_PORTF_APB_GPIODATA, Copy_uint8_tPin);
		break;

	default:
		break;
	}
}

uint32_t MCAL_GPIO_uint8_tGetPinState(uint8_t Copy_uint8_tPort, uint8_t Copy_uint8_tPin)
{
	uint32_t x;
	switch (Copy_uint8_tPort)
	{
	case GPIO_PORTA:
		return GET_BIT(GPIO_PORTA_APB_GPIODATA, Copy_uint8_tPin);
		break;

	case GPIO_PORTB:
		return GET_BIT(GPIO_PORTB_APB_GPIODATA, Copy_uint8_tPin);
		break;

	case GPIO_PORTC:
		return GET_BIT(GPIO_PORTC_APB_GPIODATA, Copy_uint8_tPin);
		break;

	case GPIO_PORTD:
		return GET_BIT(GPIO_PORTD_APB_GPIODATA, Copy_uint8_tPin);
		break;

	case GPIO_PORTE:
		return GET_BIT(GPIO_PORTE_APB_GPIODATA, Copy_uint8_tPin);
		break;

	case GPIO_PORTF:
		return GET_BIT(GPIO_PORTF_APB_GPIODATA, Copy_uint8_tPin);
		break;

	default:
		return 0;
		break;
	}
}
