//
//  UART.h
//  GPS_project
//
//  Created by amr khaled on 4/22/24.
//

#ifndef UART_h
#define UART_h
#include <stdint.h>
#include "GPIO.h"

//UARTs' addresses and PCTL:
//*********************************************************************
// UART registers (UART0)

#define UART0_DR              (*((volatile unsigned long *)0x4000C000))
#define UART0_RSR             (*((volatile unsigned long *)0x4000C004))
#define UART0_ECR             (*((volatile unsigned long *)0x4000C004))
#define UART0_FR              (*((volatile unsigned long *)0x4000C018))
#define UART0_ILPR            (*((volatile unsigned long *)0x4000C020))
#define UART0_IBRD            (*((volatile unsigned long *)0x4000C024))
#define UART0_FBRD            (*((volatile unsigned long *)0x4000C028))
#define UART0_LCRH            (*((volatile unsigned long *)0x4000C02C))
#define UART0_CTL             (*((volatile unsigned long *)0x4000C030))
#define UART0_IFLS            (*((volatile unsigned long *)0x4000C034))
#define UART0_IM              (*((volatile unsigned long *)0x4000C038))
#define UART0_RIS             (*((volatile unsigned long *)0x4000C03C))
#define UART0_MIS             (*((volatile unsigned long *)0x4000C040))
#define UART0_ICR             (*((volatile unsigned long *)0x4000C044))
#define UART0_DMACTL          (*((volatile unsigned long *)0x4000C048))
#define UART0_9BITADDR        (*((volatile unsigned long *)0x4000C0A4))
#define UART0_9BITAMASK       (*((volatile unsigned long *)0x4000C0A8))
#define UART0_PP              (*((volatile unsigned long *)0x4000CFC0))
#define UART0_CC              (*((volatile unsigned long *)0x4000CFC8))

//port A GPIO_PCTL register bit fields defines.

#define GPIO_PA0_U0RX           0x00000001  // U0RX PIN
#define GPIO_PA1_U0TX           0x00000002  // U0TX PIN
#define GPIO_PCTL_PA0_U0RX      0x00000001  // U0RX digital function on PA0
#define GPIO_PCTL_PA1_U0TX      0x00000010  // U0TX digital function on PA1

//*********************************************************************
// UART registers (UART1)

#define UART1_DR              (*((volatile unsigned long *)0x4000D000))
#define UART1_RSR             (*((volatile unsigned long *)0x4000D004))
#define UART1_ECR             (*((volatile unsigned long *)0x4000D004))
#define UART1_FR              (*((volatile unsigned long *)0x4000D018))
#define UART1_ILPR            (*((volatile unsigned long *)0x4000D020))
#define UART1_IBRD            (*((volatile unsigned long *)0x4000D024))
#define UART1_FBRD            (*((volatile unsigned long *)0x4000D028))
#define UART1_LCRH            (*((volatile unsigned long *)0x4000D02C))
#define UART1_CTL             (*((volatile unsigned long *)0x4000D030))
#define UART1_IFLS            (*((volatile unsigned long *)0x4000D034))
#define UART1_IM              (*((volatile unsigned long *)0x4000D038))
#define UART1_RIS             (*((volatile unsigned long *)0x4000D03C))
#define UART1_MIS             (*((volatile unsigned long *)0x4000D040))
#define UART1_ICR             (*((volatile unsigned long *)0x4000D044))
#define UART1_DMACTL          (*((volatile unsigned long *)0x4000D048))
#define UART1_9BITADDR        (*((volatile unsigned long *)0x4000D0A4))
#define UART1_9BITAMASK       (*((volatile unsigned long *)0x4000D0A8))
#define UART1_PP              (*((volatile unsigned long *)0x4000DFC0))
#define UART1_CC              (*((volatile unsigned long *)0x4000DFC8))

//port B GPIO_PCTL register bit fields defines.

#define GPIO_PB0_U1RX           0x00000001  // U1RX PIN
#define GPIO_PB1_U1TX           0x00000002  // U1TX PIN
#define GPIO_PCTL_PB0_U1RX      0x00000001  // U1RX on PB0
#define GPIO_PCTL_PB1_U1TX      0x00000010  // U1TX on PB1

//*********************************************************************
// UART registers (UART2)

#define UART2_DR              (*((volatile unsigned long *)0x4000E000))
#define UART2_RSR             (*((volatile unsigned long *)0x4000E004))
#define UART2_ECR             (*((volatile unsigned long *)0x4000E004))
#define UART2_FR              (*((volatile unsigned long *)0x4000E018))
#define UART2_ILPR            (*((volatile unsigned long *)0x4000E020))
#define UART2_IBRD            (*((volatile unsigned long *)0x4000E024))
#define UART2_FBRD            (*((volatile unsigned long *)0x4000E028))
#define UART2_LCRH            (*((volatile unsigned long *)0x4000E02C))
#define UART2_CTL             (*((volatile unsigned long *)0x4000E030))
#define UART2_IFLS            (*((volatile unsigned long *)0x4000E034))
#define UART2_IM              (*((volatile unsigned long *)0x4000E038))
#define UART2_RIS             (*((volatile unsigned long *)0x4000E03C))
#define UART2_MIS             (*((volatile unsigned long *)0x4000E040))
#define UART2_ICR             (*((volatile unsigned long *)0x4000E044))
#define UART2_DMACTL          (*((volatile unsigned long *)0x4000E048))
#define UART2_9BITADDR        (*((volatile unsigned long *)0x4000E0A4))
#define UART2_9BITAMASK       (*((volatile unsigned long *)0x4000E0A8))
#define UART2_PP              (*((volatile unsigned long *)0x4000EFC0))
#define UART2_CC              (*((volatile unsigned long *)0x4000EFC8))

//port D GPIO_PCTL register bit fields defines.

#define GPIO_PD6_U2RX           0x00000040  // U2RX PIN
#define GPIO_PD7_U2TX           0x00000080  // U2TX PIN
#define GPIO_PCTL_PD6_U2RX      0x01000000  // U2RX on PD6
#define GPIO_PCTL_PD7_U2TX      0x10000000  // U2TX on PD7

//*********************************************************************
// UART registers (UART3)

#define UART3_DR              (*((volatile unsigned long *)0x4000F000))
#define UART3_RSR             (*((volatile unsigned long *)0x4000F004))
#define UART3_ECR             (*((volatile unsigned long *)0x4000F004))
#define UART3_FR              (*((volatile unsigned long *)0x4000F018))
#define UART3_ILPR            (*((volatile unsigned long *)0x4000F020))
#define UART3_IBRD            (*((volatile unsigned long *)0x4000F024))
#define UART3_FBRD            (*((volatile unsigned long *)0x4000F028))
#define UART3_LCRH            (*((volatile unsigned long *)0x4000F02C))
#define UART3_CTL             (*((volatile unsigned long *)0x4000F030))
#define UART3_IFLS            (*((volatile unsigned long *)0x4000F034))
#define UART3_IM              (*((volatile unsigned long *)0x4000F038))
#define UART3_RIS             (*((volatile unsigned long *)0x4000F03C))
#define UART3_MIS             (*((volatile unsigned long *)0x4000F040))
#define UART3_ICR             (*((volatile unsigned long *)0x4000F044))
#define UART3_DMACTL          (*((volatile unsigned long *)0x4000F048))
#define UART3_9BITADDR        (*((volatile unsigned long *)0x4000F0A4))
#define UART3_9BITAMASK       (*((volatile unsigned long *)0x4000F0A8))
#define UART3_PP              (*((volatile unsigned long *)0x4000FFC0))
#define UART3_CC              (*((volatile unsigned long *)0x4000FFC8))

//port C GPIO_PCTL register bit fields defines.

#define GPIO_PC6_U3RX           0x00000040  // U3RX PIN
#define GPIO_PC7_U3TX           0x00000080  // U3TX PIN
#define GPIO_PCTL_PC6_U3RX      0x01000000  // U3RX on PC6
#define GPIO_PCTL_PC7_U3TX      0x10000000  // U3TX on PC7

//*********************************************************************
// UART registers (UART4)

#define UART4_DR              (*((volatile unsigned long *)0x40010000))
#define UART4_RSR             (*((volatile unsigned long *)0x40010004))
#define UART4_ECR             (*((volatile unsigned long *)0x40010004))
#define UART4_FR              (*((volatile unsigned long *)0x40010018))
#define UART4_ILPR            (*((volatile unsigned long *)0x40010020))
#define UART4_IBRD            (*((volatile unsigned long *)0x40010024))
#define UART4_FBRD            (*((volatile unsigned long *)0x40010028))
#define UART4_LCRH            (*((volatile unsigned long *)0x4001002C))
#define UART4_CTL             (*((volatile unsigned long *)0x40010030))
#define UART4_IFLS            (*((volatile unsigned long *)0x40010034))
#define UART4_IM              (*((volatile unsigned long *)0x40010038))
#define UART4_RIS             (*((volatile unsigned long *)0x4001003C))
#define UART4_MIS             (*((volatile unsigned long *)0x40010040))
#define UART4_ICR             (*((volatile unsigned long *)0x40010044))
#define UART4_DMACTL          (*((volatile unsigned long *)0x40010048))
#define UART4_9BITADDR        (*((volatile unsigned long *)0x400100A4))
#define UART4_9BITAMASK       (*((volatile unsigned long *)0x400100A8))
#define UART4_PP              (*((volatile unsigned long *)0x40010FC0))
#define UART4_CC              (*((volatile unsigned long *)0x40010FC8))

//port C GPIO_PCTL register bit fields defines.

#define GPIO_PC4_U4RX           0x00000010  // U4RX PIN
#define GPIO_PC5_U4TX           0x00000020  // U4TX PIN
#define GPIO_PCTL_PC4_U4RX      0x00010000  // U4RX on PC4
#define GPIO_PCTL_PC5_U4TX      0x00100000  // U4TX on PC5

//*********************************************************************
// UART registers (UART5)

#define UART5_DR              (*((volatile unsigned long *)0x40011000))
#define UART5_RSR             (*((volatile unsigned long *)0x40011004))
#define UART5_ECR             (*((volatile unsigned long *)0x40011004))
#define UART5_FR              (*((volatile unsigned long *)0x40011018))
#define UART5_ILPR            (*((volatile unsigned long *)0x40011020))
#define UART5_IBRD            (*((volatile unsigned long *)0x40011024))
#define UART5_FBRD            (*((volatile unsigned long *)0x40011028))
#define UART5_LCRH            (*((volatile unsigned long *)0x4001102C))
#define UART5_CTL             (*((volatile unsigned long *)0x40011030))
#define UART5_IFLS            (*((volatile unsigned long *)0x40011034))
#define UART5_IM              (*((volatile unsigned long *)0x40011038))
#define UART5_RIS             (*((volatile unsigned long *)0x4001103C))
#define UART5_MIS             (*((volatile unsigned long *)0x40011040))
#define UART5_ICR             (*((volatile unsigned long *)0x40011044))
#define UART5_DMACTL          (*((volatile unsigned long *)0x40011048))
#define UART5_9BITADDR        (*((volatile unsigned long *)0x400110A4))
#define UART5_9BITAMASK       (*((volatile unsigned long *)0x400110A8))
#define UART5_PP              (*((volatile unsigned long *)0x40011FC0))
#define UART5_CC              (*((volatile unsigned long *)0x40011FC8))

//port E GPIO_PCTL register bit fields defines.

#define GPIO_PE4_U5RX           0x00000010  // U5RX PIN
#define GPIO_PE5_U5TX           0x00000020  // U5TX PIN
#define GPIO_PCTL_PE4_U5RX      0x00010000  // U5RX on PE4
#define GPIO_PCTL_PE5_U5TX      0x00100000  // U5TX on PE5

//*********************************************************************
// UART registers (UART6)

#define UART6_DR              (*((volatile unsigned long *)0x40012000))
#define UART6_RSR             (*((volatile unsigned long *)0x40012004))
#define UART6_ECR             (*((volatile unsigned long *)0x40012004))
#define UART6_FR              (*((volatile unsigned long *)0x40012018))
#define UART6_ILPR            (*((volatile unsigned long *)0x40012020))
#define UART6_IBRD            (*((volatile unsigned long *)0x40012024))
#define UART6_FBRD            (*((volatile unsigned long *)0x40012028))
#define UART6_LCRH            (*((volatile unsigned long *)0x4001202C))
#define UART6_CTL             (*((volatile unsigned long *)0x40012030))
#define UART6_IFLS            (*((volatile unsigned long *)0x40012034))
#define UART6_IM              (*((volatile unsigned long *)0x40012038))
#define UART6_RIS             (*((volatile unsigned long *)0x4001203C))
#define UART6_MIS             (*((volatile unsigned long *)0x40012040))
#define UART6_ICR             (*((volatile unsigned long *)0x40012044))
#define UART6_DMACTL          (*((volatile unsigned long *)0x40012048))
#define UART6_9BITADDR        (*((volatile unsigned long *)0x400120A4))
#define UART6_9BITAMASK       (*((volatile unsigned long *)0x400120A8))
#define UART6_PP              (*((volatile unsigned long *)0x40012FC0))
#define UART6_CC              (*((volatile unsigned long *)0x40012FC8))

//port D GPIO_PCTL register bit fields defines.

#define GPIO_PD4_U6RX           0x00000010  // U4RX PIN
#define GPIO_PD5_U6TX           0x00000020  // U4TX PIN
#define GPIO_PCTL_PD4_U6RX      0x00010000  // U6RX on PD4
#define GPIO_PCTL_PD5_U6TX      0x00100000  // U6TX on PD5

//*********************************************************************
// UART registers (UART7)

#define UART7_DR              (*((volatile unsigned long *)0x40013000))
#define UART7_RSR             (*((volatile unsigned long *)0x40013004))
#define UART7_ECR             (*((volatile unsigned long *)0x40013004))
#define UART7_FR              (*((volatile unsigned long *)0x40013018))
#define UART7_ILPR            (*((volatile unsigned long *)0x40013020))
#define UART7_IBRD            (*((volatile unsigned long *)0x40013024))
#define UART7_FBRD            (*((volatile unsigned long *)0x40013028))
#define UART7_LCRH            (*((volatile unsigned long *)0x4001302C))
#define UART7_CTL             (*((volatile unsigned long *)0x40013030))
#define UART7_IFLS            (*((volatile unsigned long *)0x40013034))
#define UART7_IM              (*((volatile unsigned long *)0x40013038))
#define UART7_RIS             (*((volatile unsigned long *)0x4001303C))
#define UART7_MIS             (*((volatile unsigned long *)0x40013040))
#define UART7_ICR             (*((volatile unsigned long *)0x40013044))
#define UART7_DMACTL          (*((volatile unsigned long *)0x40013048))
#define UART7_9BITADDR        (*((volatile unsigned long *)0x400130A4))
#define UART7_9BITAMASK       (*((volatile unsigned long *)0x400130A8))
#define UART7_PP              (*((volatile unsigned long *)0x40013FC0))
#define UART7_CC              (*((volatile unsigned long *)0x40013FC8))

//port E GPIO_PCTL register bit fields defines.

#define GPIO_PE0_U7RX           0x00000001  // U0RX PIN
#define GPIO_PE1_U7TX           0x00000002  // U0TX PIN
#define GPIO_PCTL_PE0_U7RX      0x00000001  // U7RX on PE0
#define GPIO_PCTL_PE1_U7TX      0x00000010  // U7TX on PE1

//*********************************************************************

//initialisation scheme:

#define SYSCTL_RCGCUART       (*((volatile unsigned long *)0x400FE618))
#define UART_CLK              16000000    // 16 MHZ CLK
#define UARTEN                0x00000001  // UART Enable
#define UART_CTL_RXE          0x00000200  // UART Receive Enable
#define UART_CTL_TXE          0x00000100  // UART Transmit Enable

#define UART_FR_TXFE          0x00000080  // UART Transmit FIFO Empty
#define UART_FR_RXFF          0x00000040  // UART Receive FIFO Full
#define UART_FR_TXFF          0x00000020  // UART Transmit FIFO Full
#define UART_FR_RXFE          0x00000010  // UART Receive FIFO Empty
#define UART_FR_BUSY          0x00000008  // UART Busy
#define UART_FR_CTS           0x00000001  // Clear To Send

#define UART_LCRH_WLEN        5
#define UART_LCRH_FEN         0x00000010  // UART Enable FIFOs
#define UART_LCRH_STP2        0x00000008  // UART Two Stop Bits Select
#define UART_LCRH_SPS         0x00000080  // UART Stick Parity Select
#define UART_LCRH_EPS         0x00000004  // UART Even Parity Select
#define UART_LCRH_PEN         0x00000002  // UART Parity Enable
#define UART_LCRH_BRK         0x00000001  // UART Send Break

#define UART_PARITY_DISABLE   0
#define UART_PARITY_ODD       1
#define UART_PARITY_EVEN      2

#define UART_IBRD_MASK        0x0000FFFF
#define UART_FBRD_MASK        0x0000003F
#define UART_DATA_MASK        0x000000FF  //UART Mask to Read without the flags

typedef enum{
    UART0, UART1, UART2, UART3, UART4, UART5, UART6, UART7
}UART_Select;

void MCAL_UART_CONFIG(UART_Select UART_NO, uint8_t DATA_BITS, uint8_t PARITY, uint8_t STOP_BITS, uint32_t IBRD,uint32_t FBRD);
void MCAL_UART_SETBRD(uint32_t BAUD_RATE, uint32_t CLK_DIV);
void MCAL_UART_INIT(UART_Select Select);

uint8_t MCAL_UART_ReadAvailable(UART_Select UART_NO);
uint8_t MCAL_UART_SendAvailable(UART_Select UART_NO);

void MCAL_UART_SendChar(UART_Select UART_NO , uint8_t Data);
uint8_t MCAL_UART_ReadChar(UART_Select UART_NO);

void MCAL_UART_SendString(UART_Select UART_NO , uint8_t *str);
void MCAL_UART_ReadString(uint8_t UART_NO, uint8_t *buffer);

#endif /* UART_h */
