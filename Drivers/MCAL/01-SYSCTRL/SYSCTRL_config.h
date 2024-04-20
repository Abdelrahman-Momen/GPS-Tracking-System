#ifndef SYSCTRL_CONFIG_H
#define SYSCTRL_CONFIG_H
/*********** RCC *************/
/* clock source options:
						SYSCTRL_MOSC
						SYSCTRL_PIOSC
						SYSCTRL_PIOSC_DIV_4
						SYSCTRL_LFIOSC
*/
#define SYSCTRL_RCC_OSCSRC SYSCTRL_MOSC

/* 
	0: Enable Main Oscillator
	1: Disable Main Oscillator
*/
#define SYSCTRL_RCC_MOSCDIS 0

/*
    PLL Bypass:
                0: Use PLL
                1: Don't Use PLL (PLL Power Down must be 1)
*/
#define SYSCTRL_RCC_BYPASS 0

/*
    PLL Power Down:
                    0: Use PLL
                    1: Don't Use PLL (PLL Bypass must be 1)
*/
#define SYSCTRL_RCC_PWRDN 0

/*XTAL: Crystal Value:
                        SYSCTRL_XTAL_4_MHZ:         4.0000 MHz      (can not be used with PLL)
                        SYSCTRL_XTAL_4_096_MHZ:     4.096 MHz       (can not be used with PLL)
                        SYSCTRL_XTAL_4_9152_MHZ:    4.9152 MHz      (can not be used with PLL)
                        SYSCTRL_XTAL_5_MHZ:         5.0000 MHz
                        SYSCTRL_XTAL_5_12_MHZ:      5.12 MHz
                        SYSCTRL_XTAL_6_MHZ:         6.0000 MHz
                        SYSCTRL_XTAL_6_144_MHZ:     6.144 MHz
                        SYSCTRL_XTAL_7_3728_MHZ:    7.3728 MHz
                        SYSCTRL_XTAL_8_MHZ:         8.0000 MHz
                        SYSCTRL_XTAL_8_192_MHZ:     8.192 MHz
                        SYSCTRL_XTAL_10_MHZ:        10.0 MHz
                        SYSCTRL_XTAL_12_MHZ:        12.0 MHz
                        SYSCTRL_XTAL_12_288_MHZ:    12.288 MHz
                        SYSCTRL_XTAL_13_56_MHZ:     13.56 MHz
                        SYSCTRL_XTAL_14_31818_MHZ:  14.31818 MHz
                        SYSCTRL_XTAL_16_MHZ:        16.0 MHz
                        SYSCTRL_XTAL_16_384_MHZ:    16.384 MHz
                        SYSCTRL_XTAL_18_MHZ:        18.0 MHz
                        SYSCTRL_XTAL_20_MHZ:        20.0 MHz
                        SYSCTRL_XTAL_24_MHZ:        24.0 MHz
                        SYSCTRL_XTAL_25_MHZ:        25.0 MHz
                        This is the crystal frequency used for the main oscillator
*/
#define SYSCTRL_RCC_XTAL SYSCTRL_16_MHZ

/*
    0: Disable System Clock Divider
    1: Enable System Clock Divider
*/
#define SYSCTRL_RCC_USESYSDIV 1

/*
    System Clock Divisor Ranges from <2-16>
*/
#define SYSCTRL_RCC_SYSDIV 4

/*
    0: Disable PWM Divider
    1: Enable PWM Divider
*/
#define SYSCTRL_RCC_USEPWMDIV 1

/*
    PWM Unit Clock Divisor:
                              SYSCTRL_PWMIV_2  SysClk / 2
                              SYSCTRL_PWMIV_4  SysClk / 4
                              SYSCTRL_PWMIV_8  SysClk / 8
                              SYSCTRL_PWMIV_16 SysClk / 16
                              SYSCTRL_PWMIV_32 SysClk / 32
                              SYSCTRL_PWMIV_64 SysClk / 64
*/
#define SYSCTRL_RCC_USEPWMDIV SYSCTRL_PWMIV_64

/*********** RCC2 *************/
/*
    0: Disable RCC2
    1: Enable RCC2
*/
#define SYSCTRL_RCC2_USERCC2 0

/* clock source options:
                        SYSCTRL_MOSC
                        SYSCTRL_PIOSC
                        SYSCTRL_PIOSC_DIV_4
                        SYSCTRL_LFIOSC
                        SYSCTRL_32_768_KHZ
*/
#define SYSCTRL_RCC2_OSCSRC2 SYSCTRL_MOSC

/*
    PLL Bypass:
                0: Use PLL
                1: Don't Use PLL (PLL Power Down must be 1)
*/
#define SYSCTRL_RCC2_BYPASS2 0

/*
    PLL Power Down:
                    0: Use PLL
                    1: Don't Use PLL (PLL Bypass must be 1)
*/
#define SYSCTRL_RCC2_PWRDN2 0



#endif
