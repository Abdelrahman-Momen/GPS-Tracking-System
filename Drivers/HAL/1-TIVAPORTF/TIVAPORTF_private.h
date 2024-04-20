#ifndef TIVAPORTF_PRIVATE_H
#define TIVAPORTF_PRIVATE_H

/***** Variables *****/
GPIO_pinConfig_t button2 = {
						.port = GPIO_PORTF,
						.bus = GPIO_BUS_APB,
						.pin = GPIO_PIN0,
						.digitalEnable = GPIO_PIN_DIGITAL_ENABLE,
						.direction = GPIO_PIN_INPUT,
						.amsel = GPIO_PIN_AMSEL_RESET,
						.afsel = GPIO_PIN_AFSEL_RESET,
						.pctl = 0x00,
						.pur = GPIO_PIN_PUR_SET,
						.pdr = GPIO_PIN_PDR_RESET
							};

GPIO_pinConfig_t red = {
						.port = GPIO_PORTF,
						.bus = GPIO_BUS_APB,
						.pin = GPIO_PIN1,
						.digitalEnable = GPIO_PIN_DIGITAL_ENABLE,
						.direction = GPIO_PIN_OUTPUT,
						.amsel = GPIO_PIN_AMSEL_RESET,
						.afsel = GPIO_PIN_AFSEL_RESET,
						.pctl = 0x00,
						.pur = GPIO_PIN_PUR_RESET,
						.pdr = GPIO_PIN_PDR_RESET
							};

GPIO_pinConfig_t blue = {
						.port = GPIO_PORTF,
						.bus = GPIO_BUS_APB,
						.pin = GPIO_PIN2,
						.digitalEnable = GPIO_PIN_DIGITAL_ENABLE,
						.direction = GPIO_PIN_OUTPUT,
						.amsel = GPIO_PIN_AMSEL_RESET,
						.afsel = GPIO_PIN_AFSEL_RESET,
						.pctl = 0x00,
						.pur = GPIO_PIN_PUR_RESET,
						.pdr = GPIO_PIN_PDR_RESET
							};

GPIO_pinConfig_t green = {
						.port = GPIO_PORTF,
						.bus = GPIO_BUS_APB,
						.pin = GPIO_PIN3,
						.digitalEnable = GPIO_PIN_DIGITAL_ENABLE,
						.direction = GPIO_PIN_OUTPUT,
						.amsel = GPIO_PIN_AMSEL_RESET,
						.afsel = GPIO_PIN_AFSEL_RESET,
						.pctl = 0x00,
						.pur = GPIO_PIN_PUR_RESET,
						.pdr = GPIO_PIN_PDR_RESET
							};

GPIO_pinConfig_t button1 = {
						.port = GPIO_PORTF,
						.bus = GPIO_BUS_APB,
						.pin = GPIO_PIN4,
						.digitalEnable = GPIO_PIN_DIGITAL_ENABLE,
						.direction = GPIO_PIN_INPUT,
						.amsel = GPIO_PIN_AMSEL_RESET,
						.afsel = GPIO_PIN_AFSEL_RESET,
						.pctl = 0x00,
						.pur = GPIO_PIN_PUR_SET,
						.pdr = GPIO_PIN_PDR_RESET
							};

#endif
