/**
 * Copyright (c) 2025 Kevin Nguyen and Patrick Rungruengwatanachai.
 * EE/CSE 474: Lab 5 drivers header file
 */

#ifndef _LAB5_INITS_H_
#define _LAB5_INITS_H_

// Initializes the 4 onboard LEDs.
void LED_Init(void);

// Initialize PWM
void PWM_Init(void);

void PWM_Change_Duty(int cycle);

// Initialize UART0
void UART_Init(void);

#endif  // _LAB5_INITS_H_
