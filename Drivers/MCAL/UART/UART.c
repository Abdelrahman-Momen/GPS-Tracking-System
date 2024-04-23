//
//  UART.c
//  GPS_project
//
//  Created by amr khaled on 4/22/24.
//

#include "UART.h"
#include "GPIO.h"
#include <stdint.h>
#include "BIT_MATHS.h"

uint16_t IBRD;
uint8_t FBRD;

void MCAL_SETBRD(uint32_t BAUD_RATE, uint8_t CLK_DIV){
    
    float BRD = UART_CLK/(CLK_DIV * BAUD_RATE);
    IBRD = (int)BRD;
    FBRD = (int)((BRD - IBRD)*64 + 0.5);
    
}


void MCAL_UART_Init(UART_GPIO UART_NO, uint8_t DATA_BITS, uint8_t PARITY, uint8_t STOP_BITS){
    
    switch (UART_NO) {
        case UART0:
            SET_BIT(SYSCTL_RCGCUART, UART_NO);  //eneble UART clk
            SET_BIT(RCGCGPIO, GPIOA);           // correspondent port for UART0
            while (!GET_BIT(PRGPIO, GPIOA));    //wait for clk to stabilize
            
            //pin configurations for pins 0,1 PORT A:
            GPIOA_LOCK = LOCK_KEY;                                  //unlock port A
            GPIOA_CR |= GPIO_PA0_U0RX | GPIO_PA1_U0TX;              //eneble committing
            GPIOA_AFSEL |= GPIO_PA0_U0RX | GPIO_PA1_U0TX;           //set pins 0,1 to operate in alternate mode
            GPIOA_PCTL |= GPIO_PCTL_PA0_U0RX | GPIO_PCTL_PA1_U0TX;  //select UART as alternate function
            GPIOA_DIR |= GPIO_PA1_U0TX;                             //set TX to be output
            GPIOA_DIR &= ~GPIO_PA1_U0TX;                            //set RX to be input
            GPIOA_AMSEL &= ~(GPIO_PA0_U0RX | GPIO_PA1_U0TX);        //disable analog function
            GPIOA_DEN |= GPIO_PA0_U0RX | GPIO_PA1_U0TX;             //eneble digital function
            UART0_CTL &= ~UARTEN;                                   //disable UART
            UART0_IBRD = (uint32_t)IBRD;                            //baud rate calc.
            UART0_FBRD = (uint32_t)FBRD;
            UART0_LCRH = (DATA_BITS - 5) << UART_LCRH_WLEN;         //set data format
            
            if(PARITY == UART_PARITY_DISABLE)                       //PARITY = 0 --> disable stick parity
            {
                UART0_LCRH &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
            }
            else if(PARITY == UART_PARITY_ODD)                      //PARITY = 1 --> enable odd stick parity
            {
                UART0_LCRH |= (UART_LCRH_PEN | UART_LCRH_SPS)&(~UART_LCRH_EPS);
            }
            else if(PARITY == UART_PARITY_EVEN)                     //PARITY = 1 --> enable even stick parity
            {
                UART0_LCRH |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
            }
            else{}
            
            if(STOP_BITS == 1)                                      //stop bit configuration
            {
                UART0_LCRH &=~UART_LCRH_STP2;
            }
            else if(STOP_BITS == 2)
            {
                UART0_LCRH |= UART_LCRH_STP2;
            }
            else{}
            
            UART0_CTL |= UARTEN;                                   //re-enable UART
            
            break;
          
            //*************************************** <END OF UART0> *********************************************

        case UART1:
            SET_BIT(SYSCTL_RCGCUART, UART_NO);  //eneble UART clk
            SET_BIT(RCGCGPIO, GPIOB);           // correspondent port for UART0
            while (!GET_BIT(PRGPIO, GPIOB));    //wait for clk to stabilize
            
            //pin configurations for pins 0,1 PORT B:
            GPIOA_LOCK = LOCK_KEY;                                  //unlock port B
            GPIOA_CR |= GPIO_PB0_U1RX | GPIO_PB1_U1TX;              //eneble committing
            GPIOA_AFSEL |= GPIO_PB0_U1RX | GPIO_PB1_U1TX;           //set pins 0,1 to operate in alternate mode
            GPIOA_PCTL |= GPIO_PCTL_PB0_U1RX | GPIO_PCTL_PB1_U1TX;  //select UART as alternate function
            GPIOA_DIR |= GPIO_PB1_U1TX;                             //set TX to be output
            GPIOA_DIR &= ~GPIO_PB0_U1RX;                            //set RX to be input
            GPIOA_AMSEL &= ~(GPIO_PB0_U1RX | GPIO_PB1_U1TX);        //disable analog function
            GPIOA_DEN |= GPIO_PB0_U1RX | GPIO_PB1_U1TX;             //eneble digital function
            UART0_CTL &= ~UARTEN;                                   //disable UART
            UART0_IBRD = (uint32_t)IBRD;                            //baud rate calc.
            UART0_FBRD = (uint32_t)FBRD;
            UART0_LCRH = (DATA_BITS - 5) << UART_LCRH_WLEN;         //set data format
            
            if(PARITY == UART_PARITY_DISABLE)                       //PARITY = 0 --> disable stick parity
            {
                UART0_LCRH &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
            }
            else if(PARITY == UART_PARITY_ODD)                      //PARITY = 1 --> enable odd stick parity
            {
                UART0_LCRH |= (UART_LCRH_PEN | UART_LCRH_SPS)&(~UART_LCRH_EPS);
            }
            else if(PARITY == UART_PARITY_EVEN)                     //PARITY = 1 --> enable even stick parity
            {
                UART0_LCRH |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
            }
            else{}
            
            if(STOP_BITS == 1)                                      //stop bit configuration
            {
                UART0_LCRH &=~UART_LCRH_STP2;
            }
            else if(STOP_BITS == 2)
            {
                UART0_LCRH |= UART_LCRH_STP2;
            }
            else{}
            
            UART0_CTL |= UARTEN;                                   //re-enable UART
            
            break;
            
            //*************************************** <END OF UART1> *********************************************

        case UART2:
            SET_BIT(SYSCTL_RCGCUART, UART_NO);  //eneble UART clk
            SET_BIT(RCGCGPIO, GPIOD);           // correspondent port for UART0
            while (!GET_BIT(PRGPIO, GPIOD));    //wait for clk to stabilize
            
            //pin configurations for pins 6,7 PORT D:
            GPIOA_LOCK = LOCK_KEY;                                  //unlock port D
            GPIOA_CR |= GPIO_PD6_U2RX | GPIO_PD7_U2TX;              //eneble committing
            GPIOA_AFSEL |= GPIO_PD6_U2RX | GPIO_PD7_U2TX;           //set pins 6,7 to operate in alternate mode
            GPIOA_PCTL |= GPIO_PCTL_PD6_U2RX | GPIO_PCTL_PD7_U2TX;  //select UART as alternate function
            GPIOA_DIR |= GPIO_PD7_U2TX;                             //set TX to be output
            GPIOA_DIR &= ~GPIO_PD6_U2RX;                            //set RX to be input
            GPIOA_AMSEL &= ~(GPIO_PD6_U2RX | GPIO_PD7_U2TX);        //disable analog function
            GPIOA_DEN |= GPIO_PD6_U2RX | GPIO_PD7_U2TX;             //eneble digital function
            UART0_CTL &= ~UARTEN;                                   //disable UART
            UART0_IBRD = (uint32_t)IBRD;                            //baud rate calc.
            UART0_FBRD = (uint32_t)FBRD;
            UART0_LCRH = (DATA_BITS - 5) << UART_LCRH_WLEN;         //set data format
            
            if(PARITY == UART_PARITY_DISABLE)                       //PARITY = 0 --> disable stick parity
            {
                UART0_LCRH &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
            }
            else if(PARITY == UART_PARITY_ODD)                      //PARITY = 1 --> enable odd stick parity
            {
                UART0_LCRH |= (UART_LCRH_PEN | UART_LCRH_SPS)&(~UART_LCRH_EPS);
            }
            else if(PARITY == UART_PARITY_EVEN)                     //PARITY = 1 --> enable even stick parity
            {
                UART0_LCRH |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
            }
            else{}
            
            if(STOP_BITS == 1)                                      //stop bit configuration
            {
                UART0_LCRH &=~UART_LCRH_STP2;
            }
            else if(STOP_BITS == 2)
            {
                UART0_LCRH |= UART_LCRH_STP2;
            }
            else{}
            
            UART0_CTL |= UARTEN;                                   //re-enable UART
            
            break;
            
            //*************************************** <END OF UART2> *********************************************

        case UART3:
            SET_BIT(SYSCTL_RCGCUART, UART_NO);  //eneble UART clk
            SET_BIT(RCGCGPIO, GPIOC);           // correspondent port for UART0
            while (!GET_BIT(PRGPIO, GPIOC));    //wait for clk to stabilize
            
            //pin configurations for pins 6,7 PORT C:
            GPIOA_LOCK = LOCK_KEY;                                  //unlock port C
            GPIOA_CR |= GPIO_PC6_U3RX | GPIO_PC7_U3TX;              //eneble committing
            GPIOA_AFSEL |= GPIO_PC6_U3RX | GPIO_PC7_U3TX;           //set pins 6,7 to operate in alternate mode
            GPIOA_PCTL |= GPIO_PCTL_PC6_U3RX | GPIO_PCTL_PC7_U3TX;  //select UART as alternate function
            GPIOA_DIR |= GPIO_PC7_U3TX;                             //set TX to be output
            GPIOA_DIR &= ~GPIO_PC6_U3RX;                            //set RX to be input
            GPIOA_AMSEL &= ~(GPIO_PC6_U3RX | GPIO_PC7_U3TX);        //disable analog function
            GPIOA_DEN |= GPIO_PC6_U3RX | GPIO_PC7_U3TX;             //eneble digital function
            UART0_CTL &= ~UARTEN;                                   //disable UART
            UART0_IBRD = (uint32_t)IBRD;                            //baud rate calc.
            UART0_FBRD = (uint32_t)FBRD;
            UART0_LCRH = (DATA_BITS - 5) << UART_LCRH_WLEN;         //set data format
            
            if(PARITY == UART_PARITY_DISABLE)                       //PARITY = 0 --> disable stick parity
            {
                UART0_LCRH &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
            }
            else if(PARITY == UART_PARITY_ODD)                      //PARITY = 1 --> enable odd stick parity
            {
                UART0_LCRH |= (UART_LCRH_PEN | UART_LCRH_SPS)&(~UART_LCRH_EPS);
            }
            else if(PARITY == UART_PARITY_EVEN)                     //PARITY = 1 --> enable even stick parity
            {
                UART0_LCRH |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
            }
            else{}
            
            if(STOP_BITS == 1)                                      //stop bit configuration
            {
                UART0_LCRH &=~UART_LCRH_STP2;
            }
            else if(STOP_BITS == 2)
            {
                UART0_LCRH |= UART_LCRH_STP2;
            }
            else{}
            
            UART0_CTL |= UARTEN;                                   //re-enable UART
            
            break;
            
            //*************************************** <END OF UART3> *********************************************

        case UART4:
            SET_BIT(SYSCTL_RCGCUART, UART_NO);  //eneble UART clk
            SET_BIT(RCGCGPIO, GPIOC);           // correspondent port for UART0
            while (!GET_BIT(PRGPIO, GPIOC));    //wait for clk to stabilize
            
            //pin configurations for pins 4,5 PORT C:
            GPIOA_LOCK = LOCK_KEY;                                  //unlock port C
            GPIOA_CR |= GPIO_PC4_U4RX | GPIO_PC5_U4TX;              //eneble committing
            GPIOA_AFSEL |= GPIO_PC4_U4RX | GPIO_PC5_U4TX;           //set pins 4,5 to operate in alternate mode
            GPIOA_PCTL |= GPIO_PCTL_PC4_U4RX | GPIO_PCTL_PC5_U4TX;  //select UART as alternate function
            GPIOA_DIR |= GPIO_PC5_U4TX;                             //set TX to be output
            GPIOA_DIR &= ~GPIO_PC4_U4RX;                            //set RX to be input
            GPIOA_AMSEL &= ~(GPIO_PC4_U4RX | GPIO_PC5_U4TX);        //disable analog function
            GPIOA_DEN |= GPIO_PC4_U4RX | GPIO_PC5_U4TX;             //eneble digital function
            UART0_CTL &= ~UARTEN;                                   //disable UART
            UART0_IBRD = (uint32_t)IBRD;                            //baud rate calc.
            UART0_FBRD = (uint32_t)FBRD;
            UART0_LCRH = (DATA_BITS - 5) << UART_LCRH_WLEN;         //set data format
            
            if(PARITY == UART_PARITY_DISABLE)                       //PARITY = 0 --> disable stick parity
            {
                UART0_LCRH &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
            }
            else if(PARITY == UART_PARITY_ODD)                      //PARITY = 1 --> enable odd stick parity
            {
                UART0_LCRH |= (UART_LCRH_PEN | UART_LCRH_SPS)&(~UART_LCRH_EPS);
            }
            else if(PARITY == UART_PARITY_EVEN)                     //PARITY = 1 --> enable even stick parity
            {
                UART0_LCRH |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
            }
            else{}
            
            if(STOP_BITS == 1)                                      //stop bit configuration
            {
                UART0_LCRH &=~UART_LCRH_STP2;
            }
            else if(STOP_BITS == 2)
            {
                UART0_LCRH |= UART_LCRH_STP2;
            }
            else{}
            
            UART0_CTL |= UARTEN;                                   //re-enable UART
            
            break;
            
            //*************************************** <END OF UART4> *********************************************

        case UART5:
            SET_BIT(SYSCTL_RCGCUART, UART_NO);  //eneble UART clk
            SET_BIT(RCGCGPIO, GPIOE);           // correspondent port for UART0
            while (!GET_BIT(PRGPIO, GPIOE));    //wait for clk to stabilize
            
            //pin configurations for pins 4,5 PORT e:
            GPIOA_LOCK = LOCK_KEY;                                  //unlock port e
            GPIOA_CR |= GPIO_PE4_U5RX | GPIO_PE5_U5TX;              //eneble committing
            GPIOA_AFSEL |= GPIO_PE4_U5RX | GPIO_PE5_U5TX;           //set pins 4,5 to operate in alternate mode
            GPIOA_PCTL |= GPIO_PCTL_PE4_U5RX | GPIO_PCTL_PE5_U5TX;  //select UART as alternate function
            GPIOA_DIR |= GPIO_PE5_U5TX;                             //set TX to be output
            GPIOA_DIR &= ~GPIO_PE4_U5RX;                            //set RX to be input
            GPIOA_AMSEL &= ~(GPIO_PE4_U5RX | GPIO_PE5_U5TX);        //disable analog function
            GPIOA_DEN |= GPIO_PE4_U5RX | GPIO_PE5_U5TX;             //eneble digital function
            UART0_CTL &= ~UARTEN;                                   //disable UART
            UART0_IBRD = (uint32_t)IBRD;                            //baud rate calc.
            UART0_FBRD = (uint32_t)FBRD;
            UART0_LCRH = (DATA_BITS - 5) << UART_LCRH_WLEN;         //set data format
            
            if(PARITY == UART_PARITY_DISABLE)                       //PARITY = 0 --> disable stick parity
            {
                UART0_LCRH &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
            }
            else if(PARITY == UART_PARITY_ODD)                      //PARITY = 1 --> enable odd stick parity
            {
                UART0_LCRH |= (UART_LCRH_PEN | UART_LCRH_SPS)&(~UART_LCRH_EPS);
            }
            else if(PARITY == UART_PARITY_EVEN)                     //PARITY = 1 --> enable even stick parity
            {
                UART0_LCRH |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
            }
            else{}
            
            if(STOP_BITS == 1)                                      //stop bit configuration
            {
                UART0_LCRH &=~UART_LCRH_STP2;
            }
            else if(STOP_BITS == 2)
            {
                UART0_LCRH |= UART_LCRH_STP2;
            }
            else{}
            
            UART0_CTL |= UARTEN;                                   //re-enable UART
            
            break;
            
            //*************************************** <END OF UART5> *********************************************

        case UART6:
            SET_BIT(SYSCTL_RCGCUART, UART_NO);  //eneble UART clk
            SET_BIT(RCGCGPIO, GPIOD);           // correspondent port for UART0
            while (!GET_BIT(PRGPIO, GPIOD));    //wait for clk to stabilize
            
            //pin configurations for pins 4,5 PORT D:
            GPIOA_LOCK = LOCK_KEY;                                  //unlock port D
            GPIOA_CR |= GPIO_PD4_U6RX | GPIO_PD5_U6TX;              //eneble committing
            GPIOA_AFSEL |= GPIO_PD4_U6RX | GPIO_PD5_U6TX;           //set pins 4,5 to operate in alternate mode
            GPIOA_PCTL |= GPIO_PCTL_PD4_U6RX | GPIO_PCTL_PD5_U6TX;  //select UART as alternate function
            GPIOA_DIR |= GPIO_PD5_U6TX;                             //set TX to be output
            GPIOA_DIR &= ~GPIO_PD4_U6RX;                            //set RX to be input
            GPIOA_AMSEL &= ~(GPIO_PD4_U6RX | GPIO_PD5_U6TX);        //disable analog function
            GPIOA_DEN |= GPIO_PD4_U6RX | GPIO_PD5_U6TX;             //eneble digital function
            UART0_CTL &= ~UARTEN;                                   //disable UART
            UART0_IBRD = (uint32_t)IBRD;                            //baud rate calc.
            UART0_FBRD = (uint32_t)FBRD;
            UART0_LCRH = (DATA_BITS - 5) << UART_LCRH_WLEN;         //set data format
            
            if(PARITY == UART_PARITY_DISABLE)                       //PARITY = 0 --> disable stick parity
            {
                UART0_LCRH &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
            }
            else if(PARITY == UART_PARITY_ODD)                      //PARITY = 1 --> enable odd stick parity
            {
                UART0_LCRH |= (UART_LCRH_PEN | UART_LCRH_SPS)&(~UART_LCRH_EPS);
            }
            else if(PARITY == UART_PARITY_EVEN)                     //PARITY = 1 --> enable even stick parity
            {
                UART0_LCRH |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
            }
            else{}
            
            if(STOP_BITS == 1)                                      //stop bit configuration
            {
                UART0_LCRH &=~UART_LCRH_STP2;
            }
            else if(STOP_BITS == 2)
            {
                UART0_LCRH |= UART_LCRH_STP2;
            }
            else{}
            
            UART0_CTL |= UARTEN;                                   //re-enable UART
            
            break;
            
            //*************************************** <END OF UART6> *********************************************

        case UART7:
            SET_BIT(SYSCTL_RCGCUART, UART_NO);  //eneble UART clk
            SET_BIT(RCGCGPIO, GPIOE);           // correspondent port for UART0
            while (!GET_BIT(PRGPIO, GPIOE));    //wait for clk to stabilize
            
            //pin configurations for pins 0,1 PORT E:
            GPIOA_LOCK = LOCK_KEY;                                  //unlock port E
            GPIOA_CR |= GPIO_PE0_U7RX | GPIO_PE1_U7TX;              //eneble committing
            GPIOA_AFSEL |= GPIO_PE0_U7RX | GPIO_PE1_U7TX;           //set pins 0,1 to operate in alternate mode
            GPIOA_PCTL |= GPIO_PCTL_PE0_U7RX | GPIO_PCTL_PE1_U7TX;  //select UART as alternate function
            GPIOA_DIR |= GPIO_PE1_U7TX;                             //set TX to be output
            GPIOA_DIR &= ~GPIO_PE0_U7RX;                            //set RX to be input
            GPIOA_AMSEL &= ~(GPIO_PE0_U7RX | GPIO_PE1_U7TX);        //disable analog function
            GPIOA_DEN |= GPIO_PE0_U7RX | GPIO_PE1_U7TX;             //eneble digital function
            UART0_CTL &= ~UARTEN;                                   //disable UART
            UART0_IBRD = (uint32_t)IBRD;                            //baud rate calc.
            UART0_FBRD = (uint32_t)FBRD;
            UART0_LCRH = (DATA_BITS - 5) << UART_LCRH_WLEN;         //set data format
            
            if(PARITY == UART_PARITY_DISABLE)                       //PARITY = 0 --> disable stick parity
            {
                UART0_LCRH &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
            }
            else if(PARITY == UART_PARITY_ODD)                      //PARITY = 1 --> enable odd stick parity
            {
                UART0_LCRH |= (UART_LCRH_PEN | UART_LCRH_SPS)&(~UART_LCRH_EPS);
            }
            else if(PARITY == UART_PARITY_EVEN)                     //PARITY = 1 --> enable even stick parity
            {
                UART0_LCRH |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
            }
            else{}
            
            if(STOP_BITS == 1)                                      //stop bit configuration
            {
                UART0_LCRH &=~UART_LCRH_STP2;
            }
            else if(STOP_BITS == 2)
            {
                UART0_LCRH |= UART_LCRH_STP2;
            }
            else{}
            
            UART0_CTL |= UARTEN;                                   //re-enable UART
            
            break;
            
            //*************************************** <END OF UART7> *********************************************

        default:
            break;
    }
    
    
    
}
