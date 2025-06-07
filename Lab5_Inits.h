/**
 * Copyright (c) 2025 Kevin Nguyen and Patrick Rungruengwatanachai.
 * EE/CSE 474: Lab 5 drivers header file
 */

#ifndef _LAB5_INITS_H_
#define _LAB5_INITS_H_

// Initializes the 4 onboard LEDs.
void LED_Init(void);

// Initializes ADC Module 0 Sample Sequencer 3. The module is triggered by
// Timer module 0 subtimer A at 1 HZ. The interupt of ADC0 SS3 will be
// generated whenever the A/D conversion is done.
void ADCReadPot_Init(void);

// Initializes Timer 0A to trigger ADC0 at 1 HZ.
void TimerADCTriger_Init(void);

// Initialize PWM
void PWM_Init(void);

void PWM_Change_Duty(int cycle);

// Initialize UART0
void UART_Init(void);

#endif  // _LAB5_INITS_H_
