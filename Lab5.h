/*
 * Copyright (c) 2025 Kevin Nguyen and Patrick Rungruengwatanachai.
 * Header file for Lab 5. Defines registers including
 * timer, I2R, Accelerometer.
 */
#ifndef _LAB5_H_
#define _LAB5_H_

#include <stdint.h>

// Port N registers (for LED1 and LED2)
#define GPIODIR_N (*((volatile uint32_t *)0x40064400))
#define GPIODEN_N (*((volatile uint32_t *)0x4006451C))
#define GPIODATA_N (*((volatile uint32_t *)0x400643FC))
// Port F registers (for LED3 and LED4)
#define GPIODIR_F (*((volatile uint32_t *)0x4005D400)) 
#define GPIODEN_F (*((volatile uint32_t *)0x4005D51C))
#define GPIODATA_F (*((volatile uint32_t *)0x4005D3FC))

#define GPIOAFSEL (*((volatile uint32_t *)0x4005D420)) 
#define GPIODEN (*((volatile uint32_t *)0x4005D51C)) 
#define GPIOAMSEL (*((volatile uint32_t *)0x4005D528))

// Clock control register
#define RCGCGPIO (*((volatile uint32_t *)0x400FE608))

// Timer 0A register
#define RCGCTIMER (*((volatile uint32_t *)0x400FE604)) // Enables timer
#define GPTMCFG (*((volatile uint32_t *)0x40030000)) // Configure register
#define GPTMCTL (*((volatile uint32_t *)0x4003000C)) // Control (on/off)
#define GPTMTAMR (*((volatile uint32_t *)0x40030004)) // Timer A mode
#define GPTMAILR (*((volatile uint32_t *)0x40030028)) // Interval load
#define GPTMRIS (*((volatile uint32_t *)0x4003001C)) // Monitor flag
#define GPTMICR (*((volatile uint32_t *)0x40030024)) // Clear flag
#define GPTMIMR (*((volatile uint32_t *)0x40030018)) // Interupt mask
#define GPTMCC  (*((volatile uint32_t *)0x40030FC8)) // 
#define GPTMADCEV (*((volatile uint32_t *)0x40030070)) 

#define NVIC_EN0 (*((volatile uint32_t *)0xE000E100)) // Enable interrupt in NVIC

// Port E registers (for AIN0 pin wired to potentiometer)
#define RCGCGPIO_E (*((volatile uint32_t *)0x400FE618))
#define GPIODIR_E (*((volatile uint32_t *)0x4005C400))
#define GPIODATA_E (*((volatile uint32_t *)0x4005C3FC))
#define GPIODEN_E (*((volatile uint32_t *)0x4005C51C))
#define GPIOAFSEL_E (*((volatile uint32_t *)0x4005C420))
#define GPIOAMSEL_E (*((volatile uint32_t *)0x4005C528))

// ADC registers
#define ADCCC (*((volatile uint32_t *)0x40038FC8)) // ADC Clock configuration
#define RCGCADC (*((volatile uint32_t *)0x400FE638)) // ADC clock control

// ADC0 registers
#define ADC0_EMUX (*((volatile uint32_t *)0x40038014)) // Event multiplexer
#define ADC0_ACTSS (*((volatile uint32_t *)0x40038000)) // sample sequencer 3
#define ADC0_IM (*((volatile uint32_t *)0x40038008)) // Interrupt mask

// ADC0 sample sequencer 3 registers
#define ADC0_SSMUX3 (*((volatile uint32_t *)0x400380A0))
#define ADC0_SSCTL3 (*((volatile uint32_t *)0x400380A4))
#define ADC0_SSFIFO3 (*((volatile uint32_t *)0x400380A8))
#define ADC0_ISC (*((volatile uint32_t *)0x4003800C))
#define ADC0_SSTSH3 (*((volatile uint32_t *)0x400380BC))

// PWM registers
#define RCGCPWM (*((volatile uint32_t *)0x400FE640))
#define GPIOAFSEL_F (*((volatile uint32_t *)0x4005D420))
#define GPIOPCTL_F (*((volatile uint32_t *)0x4005D52C))
#define PWMCC (*((volatile uint32_t *)0x40028FC8))
#define PWM0CTL (*((volatile uint32_t *)0x40028040))

#define PWM0GENA (*((volatile uint32_t *)0x40028060))
#define PWM0GENB (*((volatile uint32_t *)0x40028064))
#define PWM0LOAD (*((volatile uint32_t *)0x40028050))
#define PWM0CMPA (*((volatile uint32_t *)0x40028058))
#define PWM0CMPB (*((volatile uint32_t *)0x4002805C))
#define PWMENABLE (*((volatile uint32_t *)0x40028008))
#define PWMCTL (*((volatile uint32_t *)0x40028000))

//#define PWMCC (*((volatile uint32_t *)0x40028020))


// All UART stuff below
#define RCGCUART_R  (*((volatile uint32_t *)0x400FE618)) // UART peripheral clock control
#define PRGPIO_R   (*((volatile uint32_t *)0x400FEA08)) // GPIO peripheral ready
#define PRUART_R   (*((volatile uint32_t *)0x400FEA18)) // UART peripheral ready

// GPIO A Registers for Port A
#define GPIO_PORTA_AFSEL_R (*((volatile uint32_t *)0x40058420)) // GPIO Alternate Function Select
#define GPIO_PORTA_PCTL_R  (*((volatile uint32_t *)0x4005852C)) // GPIO Port Control
#define GPIO_PORTA_DEN_R   (*((volatile uint32_t *)0x4005851C)) // GPIO Digital Enable
#define GPIO_PORTA_AMSEL_R  (*((volatile uint32_t *)0x40058528)) // GPIO Analog Mode Select

// UART2 Registers
#define UART2_DR_R   (*((volatile uint32_t *)0x4000E000)) // UART2 Data Register
#define UART2_FR_R   (*((volatile uint32_t *)0x4000E018)) // UART2 Flag Register
#define UART2_IBRD_R (*((volatile uint32_t *)0x4000E024)) // UART2 Integer Baud Rate Divisor
#define UART2_FBRD_R (*((volatile uint32_t *)0x4000E028)) // UART2 Fractional Baud Rate Divisor
#define UART2_LCRH_R (*((volatile uint32_t *)0x4000E02C)) // UART2 Line Control
#define UART2_CTL_R  (*((volatile uint32_t *)0x4000E030)) // UART2 Control
#define UART2_CC_R   (*((volatile uint32_t *)0x4000EFC8)) // UART2 Clock Configuration

// UART Flags and Control
#define UART_FR_RXFE     0x00000010 // Receive FIFO Empty
#define UART_FR_TXFF     0x00000020 // Transmit FIFO Full
#define UART_CTL_UARTEN  0x00000001 // UART Enable
#define UART_CTL_TXE     0x00000100 // Transmit Enable
#define UART_CTL_RXE     0x00000004 // Receive Enable
#define UART_LCRH_WLEN_8 0x00000060 // 8-bit word length


// UART GPIO A ports
#define GPIOAFSEL_A (*((volatile uint32_t *)0x40058420))
#define GPIOPCTL_A  (*((volatile uint32_t *)0x4005852C))
#define GPIODEN_A   (*((volatile uint32_t *)0x4005851C))
#define RCGCUART_A  (*((volatile uint32_t *)0x400FE618))  // RCGCUART
#define GPIODR2R_A  (*((volatile uint32_t *)0x40058500))  // Drive Select
#define UARTIBRD_A  (*((volatile uint32_t *)0x4000C024))  // Drive Select
#define UARTFBRD_A  (*((volatile uint32_t *)0x4000C028))  // Drive Select
#define UARTLCRH_A  (*((volatile uint32_t *)0x4000C02C))
#define UARTCC_A    (*((volatile uint32_t *)0x4000CFC8))  // UART clock config
#define UARTDR_A    (*((volatile uint32_t *)0x4000C000))  // UART data
#define UARTFR_A    (*((volatile uint32_t *)0x4000C018))  // UART data transmit flags

// UART Register setup for UART0
#define UART0_CTL (*((volatile uint32_t *)0x4000C030))  // UARTCTL reg

#endif // _LAB5_H_