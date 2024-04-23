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

void MCAL_UART_SETBRD(uint32_t BAUD_RATE, uint8_t CLK_DIV){
    
    float BRD = UART_CLK/(CLK_DIV * BAUD_RATE);
    IBRD = (int)BRD;
    FBRD = (int)((BRD - IBRD)*64 + 0.5);
}

void MCAL_UART_INIT(UART_Select UART_NO){
        switch(UART_NO){
                
                //******************************************* < UART_0 > *********************************************
                
            case UART0:
                GPIO_PORTA_CR |= GPIO_PA0_U0RX | GPIO_PA1_U0TX;              //eneble committing
                GPIO_PORTA_AFSEL |= GPIO_PA0_U0RX | GPIO_PA1_U0TX;           //set pins 0,1 to operate in alternate mode
                GPIO_PORTA_PCTL |= GPIO_PCTL_PA0_U0RX | GPIO_PCTL_PA1_U0TX;  //select UART as alternate function
                GPIO_PORTA_DIR |= GPIO_PA1_U0TX;                             //set TX to be output
                GPIO_PORTA_DIR &= ~GPIO_PA1_U0TX;                            //set RX to be input
                GPIO_PORTA_AMSEL &= ~(GPIO_PA0_U0RX | GPIO_PA1_U0TX);        //disable analog function
                GPIO_PORTA_DEN |= GPIO_PA0_U0RX | GPIO_PA1_U0TX;             //eneble digital function
            break;
                
                //******************************************* < UART_1 > *********************************************
                
            case UART1:
                GPIO_PORTB_CR |= GPIO_PB0_U1RX | GPIO_PB1_U1TX;              //eneble committing
                GPIO_PORTB_AFSEL |= GPIO_PB0_U1RX | GPIO_PB1_U1TX;           //set pins 0,1 to operate in alternate mode
                GPIO_PORTB_PCTL |= GPIO_PCTL_PB0_U1RX | GPIO_PCTL_PB1_U1TX;  //select UART as alternate function
                GPIO_PORTB_DIR |= GPIO_PB1_U1TX;                             //set TX to be output
                GPIO_PORTB_DIR &= ~GPIO_PB0_U1RX;                            //set RX to be input
                GPIO_PORTB_AMSEL &= ~(GPIO_PB0_U1RX | GPIO_PB1_U1TX);        //disable analog function
                GPIO_PORTB_DEN |= GPIO_PB0_U1RX | GPIO_PB1_U1TX;             //eneble digital function
            break;
                
                //******************************************* < UART_2 > *********************************************
                
            case UART2:
                GPIO_PORTD_CR |= GPIO_PD6_U2RX | GPIO_PD7_U2TX;              //eneble committing
                GPIO_PORTD_AFSEL |= GPIO_PD6_U2RX | GPIO_PD7_U2TX;           //set pins 6,7 to operate in alternate mode
                GPIO_PORTD_PCTL |= GPIO_PCTL_PD6_U2RX | GPIO_PCTL_PD7_U2TX;  //select UART as alternate function
                GPIO_PORTD_DIR |= GPIO_PD7_U2TX;                             //set TX to be output
                GPIO_PORTD_DIR &= ~GPIO_PD6_U2RX;                            //set RX to be input
                GPIO_PORTD_AMSEL &= ~(GPIO_PD6_U2RX | GPIO_PD7_U2TX);        //disable analog function
                GPIO_PORTD_DEN |= GPIO_PD6_U2RX | GPIO_PD7_U2TX;             //eneble digital function
            break;
                
                //******************************************* < UART_3 > *********************************************
            
            case UART3:
                GPIO_PORTC_CR |= GPIO_PC6_U3RX | GPIO_PC7_U3TX;              //eneble committing
                GPIO_PORTC_AFSEL |= GPIO_PC6_U3RX | GPIO_PC7_U3TX;           //set pins 6,7 to operate in alternate mode
                GPIO_PORTC_PCTL |= GPIO_PCTL_PC6_U3RX | GPIO_PCTL_PC7_U3TX;  //select UART as alternate function
                GPIO_PORTC_DIR |= GPIO_PC7_U3TX;                             //set TX to be output
                GPIO_PORTC_DIR &= ~GPIO_PC6_U3RX;                            //set RX to be input
                GPIO_PORTC_AMSEL &= ~(GPIO_PC6_U3RX | GPIO_PC7_U3TX);        //disable analog function
                GPIO_PORTC_DEN |= GPIO_PC6_U3RX | GPIO_PC7_U3TX;             //eneble digital function
            break;
                
                //******************************************* < UART_4 > *********************************************
            
            case UART4:
                GPIO_PORTC_CR |= GPIO_PC4_U4RX | GPIO_PC5_U4TX;              //eneble committing
                GPIO_PORTC_AFSEL |= GPIO_PC4_U4RX | GPIO_PC5_U4TX;           //set pins 4,5 to operate in alternate mode
                GPIO_PORTC_PCTL |= GPIO_PCTL_PC4_U4RX | GPIO_PCTL_PC5_U4TX;  //select UART as alternate function
                GPIO_PORTC_DIR |= GPIO_PC5_U4TX;                             //set TX to be output
                GPIO_PORTC_DIR &= ~GPIO_PC4_U4RX;                            //set RX to be input
                GPIO_PORTC_AMSEL &= ~(GPIO_PC4_U4RX | GPIO_PC5_U4TX);        //disable analog function
                GPIO_PORTC_DEN |= GPIO_PC4_U4RX | GPIO_PC5_U4TX;             //eneble digital function
            break;
                
                //******************************************* < UART_5 > *********************************************
            
            case UART5:
                GPIO_PORTE_CR |= GPIO_PE4_U5RX | GPIO_PE5_U5TX;              //eneble committing
                GPIO_PORTE_AFSEL |= GPIO_PE4_U5RX | GPIO_PE5_U5TX;           //set pins 4,5 to operate in alternate mode
                GPIO_PORTE_PCTL |= GPIO_PCTL_PE4_U5RX | GPIO_PCTL_PE5_U5TX;  //select UART as alternate function
                GPIO_PORTE_DIR |= GPIO_PE5_U5TX;                             //set TX to be output
                GPIO_PORTE_DIR &= ~GPIO_PE4_U5RX;                            //set RX to be input
                GPIO_PORTE_AMSEL &= ~(GPIO_PE4_U5RX | GPIO_PE5_U5TX);        //disable analog function
                GPIO_PORTE_DEN |= GPIO_PE4_U5RX | GPIO_PE5_U5TX;             //eneble digital function
            break;
                
                //******************************************* < UART_6 > *********************************************
                
            case UART6:
                GPIO_PORTD_CR |= GPIO_PD4_U6RX | GPIO_PD5_U6TX;              //eneble committing
                GPIO_PORTD_AFSEL |= GPIO_PD4_U6RX | GPIO_PD5_U6TX;           //set pins 4,5 to operate in alternate mode
                GPIO_PORTD_PCTL |= GPIO_PCTL_PD4_U6RX | GPIO_PCTL_PD5_U6TX;  //select UART as alternate function
                GPIO_PORTD_DIR |= GPIO_PD5_U6TX;                             //set TX to be output
                GPIO_PORTD_DIR &= ~GPIO_PD4_U6RX;                            //set RX to be input
                GPIO_PORTD_AMSEL &= ~(GPIO_PD4_U6RX | GPIO_PD5_U6TX);        //disable analog function
                GPIO_PORTD_DEN |= GPIO_PD4_U6RX | GPIO_PD5_U6TX;             //eneble digital function
            break;
                
                //******************************************* < UART_7 > *********************************************
                
            case UART7:
                GPIO_PORTE_CR |= GPIO_PE0_U7RX | GPIO_PE1_U7TX;              //eneble committing
                GPIO_PORTE_AFSEL |= GPIO_PE0_U7RX | GPIO_PE1_U7TX;           //set pins 0,1 to operate in alternate mode
                GPIO_PORTE_PCTL |= GPIO_PCTL_PE0_U7RX | GPIO_PCTL_PE1_U7TX;  //select UART as alternate function
                GPIO_PORTE_DIR |= GPIO_PE1_U7TX;                             //set TX to be output
                GPIO_PORTE_DIR &= ~GPIO_PE0_U7RX;                            //set RX to be input
                GPIO_PORTE_AMSEL &= ~(GPIO_PE0_U7RX | GPIO_PE1_U7TX);        //disable analog function
                GPIO_PORTE_DEN |= GPIO_PE0_U7RX | GPIO_PE1_U7TX;             //eneble digital function
            break;
                
                //********************************************** < END > *********************************************
            default:
                break;
        }
    
}

//*******************************************************************************************************************************

//****************************************************** < UART CONFIG > ********************************************************

void MCAL_UART_CONFIG(UART_Select UART_NO, uint8_t DATA_BITS, uint8_t PARITY, uint8_t STOP_BITS, uint32_t BAUD_RATE, uint8_t CLK_DIV){
    
    switch (UART_NO) {
            
            //******************************************* < UART_0 > *********************************************
            
        case UART0:
            SET_BIT(SYSCTL_RCGCUART, UART_NO);  //eneble UART clk
            
            //pin configurations for pins 0,1 PORT A:
            MCAL_GPIO_Init(PORTA);                                  //enable port clk
            MCAL_UART_INIT(UART0);                                  //configure port for UART
            UART0_CTL &= ~UARTEN;                                   //disable UART
            MCAL_UART_SETBRD(BAUD_RATE, CLK_DIV);                   //calculate baud rate
            UART0_IBRD &= ~(uint32_t)IBRD;                          //reset before write
            UART0_IBRD |= (uint32_t)IBRD;                           //write claculated baud rate int
            
            UART0_FBRD &= ~(uint32_t)FBRD;                          //reset before write
            UART0_FBRD |= (uint32_t)FBRD;                           //write claculated baud rate float
            
            UART0_LCRH &= ~((DATA_BITS - 5) << UART_LCRH_WLEN);     //clear before write
            UART0_LCRH |= (DATA_BITS - 5) << UART_LCRH_WLEN;        //set data format
            
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
                UART0_LCRH &= ~UART_LCRH_STP2;
            }
            else if(STOP_BITS == 2)
            {
                UART0_LCRH |= UART_LCRH_STP2;
            }
            else{}
            
            UART0_CTL |= UARTEN;                                   //re-enable UART
            
            break;
          
            //******************************************* < UART_1 > *********************************************

        case UART1:
            SET_BIT(SYSCTL_RCGCUART, UART_NO);  //eneble UART clk
            
            //pin configurations for pins 0,1 PORT B:
            MCAL_GPIO_Init(PORTB);                                  //enable port clk
            MCAL_UART_INIT(UART1);                                  //configure port for UART
            UART1_CTL &= ~UARTEN;                                   //disable UART
            MCAL_UART_SETBRD(BAUD_RATE, CLK_DIV);                   //calculate baud rate
            UART1_IBRD &= ~(uint32_t)IBRD;                          //reset before write
            UART1_IBRD |= (uint32_t)IBRD;                           //write claculated baud rate int
            
            UART1_FBRD &= ~(uint32_t)FBRD;                          //reset before write
            UART1_FBRD |= (uint32_t)FBRD;                           //write claculated baud rate float
            
            UART1_LCRH &= ~((DATA_BITS - 5) << UART_LCRH_WLEN);     //clear before write
            UART1_LCRH |= (DATA_BITS - 5) << UART_LCRH_WLEN;        //set data format         //set data format
            
            if(PARITY == UART_PARITY_DISABLE)                       //PARITY = 0 --> disable stick parity
            {
                UART1_LCRH &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
            }
            else if(PARITY == UART_PARITY_ODD)                      //PARITY = 1 --> enable odd stick parity
            {
                UART1_LCRH |= (UART_LCRH_PEN | UART_LCRH_SPS)&(~UART_LCRH_EPS);
            }
            else if(PARITY == UART_PARITY_EVEN)                     //PARITY = 1 --> enable even stick parity
            {
                UART1_LCRH |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
            }
            else{}
            
            if(STOP_BITS == 1)                                      //stop bit configuration
            {
                UART1_LCRH &= ~UART_LCRH_STP2;
            }
            else if(STOP_BITS == 2)
            {
                UART1_LCRH |= UART_LCRH_STP2;
            }
            else{}
            
            UART1_CTL |= UARTEN;                                   //re-enable UART
            
            break;
            
            //******************************************* < UART_2 > *********************************************

        case UART2:
            SET_BIT(SYSCTL_RCGCUART, UART_NO);  //eneble UART clk
            
            //pin configurations for pins 6,7 PORT D:
            MCAL_GPIO_Init(PORTD);                                  //enable port clk
            MCAL_UART_INIT(UART2);                                  //configure port for UART
            UART2_CTL &= ~UARTEN;                                   //disable UART
            MCAL_UART_SETBRD(BAUD_RATE, CLK_DIV);                   //calculate baud rate
            UART2_IBRD &= ~(uint32_t)IBRD;                          //reset before write
            UART2_IBRD |= (uint32_t)IBRD;                           //write claculated baud rate int
            
            UART2_FBRD &= ~(uint32_t)FBRD;                          //reset before write
            UART2_FBRD |= (uint32_t)FBRD;                           //write claculated baud rate float
            
            UART2_LCRH &= ~((DATA_BITS - 5) << UART_LCRH_WLEN);     //clear before write
            UART2_LCRH |= (DATA_BITS - 5) << UART_LCRH_WLEN;        //set data format
            
            if(PARITY == UART_PARITY_DISABLE)                       //PARITY = 0 --> disable stick parity
            {
                UART2_LCRH &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
            }
            else if(PARITY == UART_PARITY_ODD)                      //PARITY = 1 --> enable odd stick parity
            {
                UART2_LCRH |= (UART_LCRH_PEN | UART_LCRH_SPS)&(~UART_LCRH_EPS);
            }
            else if(PARITY == UART_PARITY_EVEN)                     //PARITY = 1 --> enable even stick parity
            {
                UART2_LCRH |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
            }
            else{}
            
            if(STOP_BITS == 1)                                      //stop bit configuration
            {
                UART2_LCRH &= ~UART_LCRH_STP2;
            }
            else if(STOP_BITS == 2)
            {
                UART2_LCRH |= UART_LCRH_STP2;
            }
            else{}
            
            UART2_CTL |= UARTEN;                                   //re-enable UART
            
            break;
            
            //******************************************* < UART_3 > *********************************************

        case UART3:
            SET_BIT(SYSCTL_RCGCUART, UART_NO);  //eneble UART clk
            
            //pin configurations for pins 6,7 PORT C:
            MCAL_GPIO_Init(PORTC);                                  //enable port clk
            MCAL_UART_INIT(UART3);                                  //configure port for UART
            UART3_CTL &= ~UARTEN;                                   //disable UART
            MCAL_UART_SETBRD(BAUD_RATE, CLK_DIV);                   //calculate baud rate
            UART3_IBRD &= ~(uint32_t)IBRD;                          //reset before write
            UART3_IBRD |= (uint32_t)IBRD;                           //write claculated baud rate int
            
            UART3_FBRD &= ~(uint32_t)FBRD;                          //reset before write
            UART3_FBRD |= (uint32_t)FBRD;                           //write claculated baud rate float
            
            UART3_LCRH &= ~((DATA_BITS - 5) << UART_LCRH_WLEN);     //clear before write
            UART3_LCRH |= (DATA_BITS - 5) << UART_LCRH_WLEN;        //set data format
            
            if(PARITY == UART_PARITY_DISABLE)                       //PARITY = 0 --> disable stick parity
            {
                UART3_LCRH &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
            }
            else if(PARITY == UART_PARITY_ODD)                      //PARITY = 1 --> enable odd stick parity
            {
                UART3_LCRH |= (UART_LCRH_PEN | UART_LCRH_SPS)&(~UART_LCRH_EPS);
            }
            else if(PARITY == UART_PARITY_EVEN)                     //PARITY = 1 --> enable even stick parity
            {
                UART3_LCRH |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
            }
            else{}
            
            if(STOP_BITS == 1)                                      //stop bit configuration
            {
                UART3_LCRH &= ~UART_LCRH_STP2;
            }
            else if(STOP_BITS == 2)
            {
                UART3_LCRH |= UART_LCRH_STP2;
            }
            else{}
            
            UART3_CTL |= UARTEN;                                   //re-enable UART
            
            break;
            
            //******************************************* < UART_4 > *********************************************

        case UART4:
            SET_BIT(SYSCTL_RCGCUART, UART_NO);  //eneble UART clk
            
            //pin configurations for pins 4,5 PORT C:
            MCAL_GPIO_Init(PORTC);                                  //enable port clk
            MCAL_UART_INIT(UART4);                                  //configure port for UART
            UART4_CTL &= ~UARTEN;                                   //disable UART
            MCAL_UART_SETBRD(BAUD_RATE, CLK_DIV);                   //calculate baud rate
            UART4_IBRD &= ~(uint32_t)IBRD;                          //reset before write
            UART4_IBRD |= (uint32_t)IBRD;                           //write claculated
            
            UART4_FBRD &= ~(uint32_t)FBRD;                          //reset before write
            UART4_FBRD |= (uint32_t)FBRD;                           //write claculated b
            
            UART4_LCRH &= ~((DATA_BITS - 5) << UART_LCRH_WLEN);     //clear before write
            UART4_LCRH |= (DATA_BITS - 5) << UART_LCRH_WLEN;        //set data format
            
            if(PARITY == UART_PARITY_DISABLE)                       //PARITY = 0 --> disable stick parity
            {
                UART4_LCRH &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
            }
            else if(PARITY == UART_PARITY_ODD)                      //PARITY = 1 --> enable odd stick parity
            {
                UART4_LCRH |= (UART_LCRH_PEN | UART_LCRH_SPS)&(~UART_LCRH_EPS);
            }
            else if(PARITY == UART_PARITY_EVEN)                     //PARITY = 1 --> enable even stick parity
            {
                UART4_LCRH |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
            }
            else{}
            
            if(STOP_BITS == 1)                                      //stop bit configuration
            {
                UART4_LCRH &= ~UART_LCRH_STP2;
            }
            else if(STOP_BITS == 2)
            {
                UART4_LCRH |= UART_LCRH_STP2;
            }
            else{}
            
            UART4_CTL |= UARTEN;                                   //re-enable UART
            
            break;
            
            //******************************************* < UART_5 > *********************************************

        case UART5:
            SET_BIT(SYSCTL_RCGCUART, UART_NO);  //eneble UART clk
            
            //pin configurations for pins 4,5 PORT E:
            MCAL_GPIO_Init(PORTE);                                  //enable port clk
            MCAL_UART_INIT(UART5);                                  //configure port for UART
            UART5_CTL &= ~UARTEN;                                   //disable UART
            MCAL_UART_SETBRD(BAUD_RATE, CLK_DIV);                   //calculate baud rate
            UART5_IBRD &= ~(uint32_t)IBRD;                          //reset before write
            UART5_IBRD |= (uint32_t)IBRD;                           //write claculated baud rate int
            
            UART5_FBRD &= ~(uint32_t)FBRD;                          //reset before write
            UART5_FBRD |= (uint32_t)FBRD;                           //write claculated baud rate float
            
            UART5_LCRH &= ~((DATA_BITS - 5) << UART_LCRH_WLEN);     //clear before write
            UART5_LCRH |= (DATA_BITS - 5) << UART_LCRH_WLEN;        //set data format
            
            if(PARITY == UART_PARITY_DISABLE)                       //PARITY = 0 --> disable stick parity
            {
                UART5_LCRH &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
            }
            else if(PARITY == UART_PARITY_ODD)                      //PARITY = 1 --> enable odd stick parity
            {
                UART5_LCRH |= (UART_LCRH_PEN | UART_LCRH_SPS)&(~UART_LCRH_EPS);
            }
            else if(PARITY == UART_PARITY_EVEN)                     //PARITY = 1 --> enable even stick parity
            {
                UART5_LCRH |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
            }
            else{}
            
            if(STOP_BITS == 1)                                      //stop bit configuration
            {
                UART5_LCRH &= ~UART_LCRH_STP2;
            }
            else if(STOP_BITS == 2)
            {
                UART5_LCRH |= UART_LCRH_STP2;
            }
            else{}
            
            UART5_CTL |= UARTEN;                                   //re-enable UART
            
            break;
            
            //******************************************* < UART_6 > *********************************************

        case UART6:
            SET_BIT(SYSCTL_RCGCUART, UART_NO);  //eneble UART clk
            
            //pin configurations for pins 4,5 PORT D:
            MCAL_GPIO_Init(PORTD);                                  //enable port clk
            MCAL_UART_INIT(UART6);                                  //configure port for UART
            UART6_CTL &= ~UARTEN;                                   //disable UART
            MCAL_UART_SETBRD(BAUD_RATE, CLK_DIV);                   //calculate baud rate
            UART6_IBRD &= ~(uint32_t)IBRD;                          //reset before write
            UART6_IBRD |= (uint32_t)IBRD;                           //write claculated baud rate int
            
            UART6_FBRD &= ~(uint32_t)FBRD;                          //reset before write
            UART6_FBRD |= (uint32_t)FBRD;                           //write claculated baud rate float
            
            UART6_LCRH &= ~((DATA_BITS - 5) << UART_LCRH_WLEN);     //clear before write
            UART6_LCRH |= (DATA_BITS - 5) << UART_LCRH_WLEN;        //set data format
            
            if(PARITY == UART_PARITY_DISABLE)                       //PARITY = 0 --> disable stick parity
            {
                UART6_LCRH &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
            }
            else if(PARITY == UART_PARITY_ODD)                      //PARITY = 1 --> enable odd stick parity
            {
                UART6_LCRH |= (UART_LCRH_PEN | UART_LCRH_SPS)&(~UART_LCRH_EPS);
            }
            else if(PARITY == UART_PARITY_EVEN)                     //PARITY = 1 --> enable even stick parity
            {
                UART6_LCRH |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
            }
            else{}
            
            if(STOP_BITS == 1)                                      //stop bit configuration
            {
                UART6_LCRH &= ~UART_LCRH_STP2;
            }
            else if(STOP_BITS == 2)
            {
                UART6_LCRH |= UART_LCRH_STP2;
            }
            else{}
            
            UART6_CTL |= UARTEN;                                   //re-enable UART
            
            break;
            
            //******************************************* < UART_7 > *********************************************

        case UART7:
            SET_BIT(SYSCTL_RCGCUART, UART_NO);  //eneble UART clk
            
            //pin configurations for pins 0,1 PORT E:
            MCAL_GPIO_Init(PORTE);                                  //enable port clk
            MCAL_UART_INIT(UART7);                                  //configure port for UART
            UART7_CTL &= ~UARTEN;                                   //disable UART
            MCAL_UART_SETBRD(BAUD_RATE, CLK_DIV);                   //calculate baud rate
            UART7_IBRD &= ~(uint32_t)IBRD;                          //reset before write
            UART7_IBRD |= (uint32_t)IBRD;                           //write claculated baud rate int
            
            UART7_FBRD &= ~(uint32_t)FBRD;                          //reset before write
            UART7_FBRD |= (uint32_t)FBRD;                           //write claculated baud rate float
            
            UART7_LCRH &= ~((DATA_BITS - 5) << UART_LCRH_WLEN);     //clear before write
            UART7_LCRH |= (DATA_BITS - 5) << UART_LCRH_WLEN;        //set data format
            
            if(PARITY == UART_PARITY_DISABLE)                       //PARITY = 0 --> disable stick parity
            {
                UART7_LCRH &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
            }
            else if(PARITY == UART_PARITY_ODD)                      //PARITY = 1 --> enable odd stick parity
            {
                UART7_LCRH |= (UART_LCRH_PEN | UART_LCRH_SPS)&(~UART_LCRH_EPS);
            }
            else if(PARITY == UART_PARITY_EVEN)                     //PARITY = 1 --> enable even stick parity
            {
                UART7_LCRH |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
            }
            else{}
            
            if(STOP_BITS == 1)                                      //stop bit configuration
            {
                UART7_LCRH &= ~UART_LCRH_STP2;
            }
            else if(STOP_BITS == 2)
            {
                UART7_LCRH |= UART_LCRH_STP2;
            }
            else{}
            
            UART7_CTL |= UARTEN;                                   //re-enable UART
            
            break;

            //********************************************** < END > *********************************************

        default:
            break;
    }
    
}

//*******************************************************************************************************************************

//****************************************************** < RX TX CONFIG > *******************************************************

unsigned char MCAL_UART_ReadAvailable(UART_Select UART_NO){
    switch(UART_NO)
    {
        case UART0:
        return ((UART0_FR & UART_FR_RXFE) == UART_FR_RXFE) ? 1 : 0;  //empty = 1 , 0 otherwise
        break;
        
        case UART1:
        return ((UART1_FR & UART_FR_RXFE) == UART_FR_RXFE) ? 1 : 0;
        break;
        
        case UART2:
        return ((UART2_FR & UART_FR_RXFE) == UART_FR_RXFE) ? 1 : 0;
        break;
        
        case UART3:
        return ((UART3_FR & UART_FR_RXFE) == UART_FR_RXFE) ? 1 : 0;;
        break;
        
        case UART4:
        return ((UART4_FR & UART_FR_RXFE) == UART_FR_RXFE) ? 1 : 0;
        break;
        
        case UART5:
        return ((UART5_FR & UART_FR_RXFE) == UART_FR_RXFE) ? 1 : 0;
        break;
        
        case UART6:
        return ((UART6_FR & UART_FR_RXFE) == UART_FR_RXFE) ? 1 : 0;
        break;
        
        case UART7:
        return ((UART7_FR & UART_FR_RXFE) == UART_FR_RXFE) ? 1 : 0;
        break;
        
        default : return 0; break;
    }
}




unsigned char MCAL_UART_SendAvailable(UART_Select UART_NO){
    switch(UART_NO)
    {
        case UART0:
        return ((UART0_FR & UART_FR_TXFF) == UART_FR_TXFF) ? 1 : 0;  //full = 1 , 0 otherwise
        break;
        
        case UART1:
        return ((UART1_FR & UART_FR_TXFF) == UART_FR_TXFF) ? 1 : 0;
        break;
        
        case UART2:
        return ((UART2_FR & UART_FR_TXFF) == UART_FR_TXFF) ? 1 : 0;
        break;
        
        case UART3:
        return ((UART3_FR & UART_FR_TXFF) == UART_FR_TXFF) ? 1 : 0;
        break;
        
        case UART4:
        return ((UART4_FR & UART_FR_TXFF) == UART_FR_TXFF) ? 1 : 0;
        break;
        
        case UART5:
        return ((UART5_FR & UART_FR_TXFF) == UART_FR_TXFF) ? 1 : 0;
        break;
        
        case UART6:
      return ((UART6_FR & UART_FR_TXFF) == UART_FR_TXFF) ? 1 : 0;
        break;
        
        case UART7:
        return ((UART7_FR & UART_FR_TXFF) == UART_FR_TXFF) ? 1 : 0;
        break;
        
        default :  return 0; break;
    }
}


void MCAL_UART_SendChar(UART_Select UART_NO , uint8_t Data){
    
    switch(UART_NO)
    {
        case UART0:
        while(MCAL_UART_SendAvailable(UART_NO));
        UART0_DR = Data;
        break;
        
        case UART1:
        while(MCAL_UART_SendAvailable(UART_NO));
        UART1_DR = Data;
        break;
        
        case UART2:
        while(MCAL_UART_SendAvailable(UART_NO));
        UART2_DR = Data;
        break;
        
        case UART3:
        while(MCAL_UART_SendAvailable(UART_NO));
        UART3_DR = Data;
        break;
        
        case UART4:
        while(MCAL_UART_SendAvailable(UART_NO));
        UART4_DR = Data;
        break;
        
        case UART5:
        while(MCAL_UART_SendAvailable(UART_NO));
        UART5_DR = Data;
        break;
        
        case UART6:
        while(MCAL_UART_SendAvailable(UART_NO));
        UART6_DR = Data;
        break;
        
        case UART7:
        while(MCAL_UART_SendAvailable(UART_NO));
        UART7_DR = Data;
        break;
        
        default : break;
    }
}

uint8_t MCAL_UART_ReadChar(UART_Select UART_NO){

    switch(UART_NO)
    {
        case UART0:
        while(MCAL_UART_ReadAvailable(UART_NO));
        return (uint8_t)(UART0_DR &= UART_MASK) ;
        break;
        
        case UART1:
        while(MCAL_UART_ReadAvailable(UART_NO));
        return (uint8_t)(UART1_DR &= UART_MASK) ;
        break;
        
        case UART2:
        while(MCAL_UART_ReadAvailable(UART_NO));
        return (uint8_t)(UART2_DR &= UART_MASK) ;
        break;
        
        case UART3:
        while(MCAL_UART_ReadAvailable(UART_NO));
        return (uint8_t)(UART3_DR &= UART_MASK) ;
        break;
        
        case UART4:
        while(MCAL_UART_ReadAvailable(UART_NO));
        return (uint8_t)(UART4_DR &= UART_MASK) ;
        break;
        
        case UART5:
        while(MCAL_UART_ReadAvailable(UART_NO));
        return (uint8_t)(UART5_DR &= UART_MASK) ;
        break;
        
        case UART6:
        while(MCAL_UART_ReadAvailable(UART_NO));
        return (uint8_t)(UART6_DR &= UART_MASK) ;
        break;
        
        case UART7:
        while(MCAL_UART_ReadAvailable(UART_NO));
        return (uint8_t)(UART7_DR &= UART_MASK) ;
        break;
        
        default : break;
    }
}


void MCAL_UART_SendString(UART_Select UART_NO, uint8_t *str) {
    while (*str != '\0') {
        MCAL_UART_SendChar(UART_NO, *str);
        str++;
    }
}

void MCAL_UART_ReadString(uint8_t UART_NO, uint8_t *buffer) {
    int i = 0;
    while (1) {  // Continue indefinitely
        char c = MCAL_UART_ReadChar(UART_NO);
        if (c == '\0') {
            break;  // Break if null terminator is received
        }
        buffer[i++] = c;
    }
    buffer[i] = '\0';  // Null-terminate the string
}

