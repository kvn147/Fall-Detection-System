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

// I2C0 registers
#define RCGCI2C (*((volatile uint32_t *)0x400FE620)) // I2C clock control
#define I2C_MSA (*((volatile uint32_t *)0x40020000)) // Master slave address: select slave address and read/write bit
#define I2C_MCS (*((volatile uint32_t *)0x40020004)) // Master control/status: indicates status of bus controller when read, controls I2C operations (start, stop, read) when written
#define I2C_MDR (*((volatile uint32_t *)0x40020008)) // Master data: Stores data to be sent/received
#define I2C_MCR (*((volatile uint32_t *)0x40020020)) // Master control: enables I2C in master mode
#define I2C_MTPR (*((volatile uint32_t *)0x4002000C)) // Master timing

// Port B registers (for accelerometer gyroscope - I2C0SCL and I2C0SDA)
#define GPIODIR_B (*((volatile uint32_t *)0x40059400)) // Direction register
#define GPIODEN_B (*((volatile uint32_t *)0x4005951C)) // Digital enable
#define GPIOAFSEL_B (*((volatile uint32_t *)0x40059420)) // Alternate function select
#define GPIOAMSEL_B (*((volatile uint32_t *)0x40059428)) // Analog mode select
#define GPIOPCTL_B (*((volatile uint32_t *)0x4005952C)) // Port control
#define GPIOODR_B (*((volatile uint32_t *)0x4005950C)) // Open drain select

// MPU-6050


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

#define PWMCC (*((volatile uint32_t *)0x40028020))


#endif // _LAB5_H_