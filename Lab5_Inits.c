/**
 * Copyright (c) 2025 Kevin Nguyen and Patrick Rungruengwatanachai.
 * EE/CSE 474: Lab 5 drivers containing functions for initializing
 * LED, PWM, UART and changing PWM cycles 
 */

#include "Lab5_Inits.h"

#include "Lab5.h"
 
void LED_Init(void) {
  RCGCGPIO |= (1<<5) | (1<<12); // Enable clock for LEDs
  volatile unsigned short delay = 0;
  delay++, delay++; 
  // Set LED pins as outputs
  GPIODIR_F |= 0x11;  // Set PF0 (LED4) and PF4 (LED3) as outputs
  GPIODIR_N |= 0x03;  // Set PN0 (LED2) and PN1 (LED1) as outputs
  // Set LED pins as digital pins
  GPIODEN_F |= 0x11;  // Enable digital for PF0 and PF4
  GPIODEN_N |= 0x03;  // Enable digital for PN0 and PN1
}

void PWM_Init(void) {
  volatile unsigned short delay = 0;
  RCGCPWM |= 0x1; // Enable PWM 0
  RCGCGPIO |= (1 << 5); // Enable port F
  delay++;
  delay++; 
  GPIOAFSEL_F |= (1 << 0) | (1 << 1);  // Alt function for port F 0 and 1
  GPIOPCTL_F = 0x00000000;
  GPIOPCTL_F = 0x6;  // Assign PWM functionality
  GPIOPCTL_F |= (0x6 << 4);
  GPIODEN_F |= 0x3;
  // to pins
  PWMCC = 0x0 | (1 << 8); // Divide and use timer by 2
  PWMCTL = 0x1;
  PWM0CTL = 0x00000000; // unlatch fault PWM
  PWM0GENA = 0x0000008C;  
  PWM0GENB = 0x0000080C;  
  PWM0LOAD = 0x00000140;
  PWM0CMPA = 0x0000012B;  // set duty cycle for pin 1
  PWM0CMPB = 0x00000063;  // set duty cycle for pin 2
  PWM0CTL = 0x00000001;
  PWMENABLE = 0x00000003; // latch fault PWM
}

void PWM_Change_Duty(int cycle) {
  PWM0CTL = 0x00000000; // Disable PWM0

  if (cycle > PWM0LOAD) {
    cycle = PWM0LOAD; // Ensure cycle does not exceed load
  } else if (cycle < 0) {
    cycle = 0; // Ensure cycle is not negative
  }
  PWM0CMPA = cycle;  // Update duty cycle for pin 1
  PWM0CMPB = cycle;  // Update duty cycle for pin 1
  PWM0CTL = 0x00000001; // Enable PWM0
}

void UART_Init(void) {
  RCGCUART_A |= (1 << 0);  // Enable UART module 0
  RCGCGPIO |= (1 << 0);    // Enable clock for A ports
  GPIOAFSEL_A |= (1 << 0) | (1 << 1); // Alternate port for pins 0 and 1
  GPIOPCTL_A |= (1 << 0) | (1 << 4); // Set pins 0 and 1 to UART mode
  GPIODEN_A |= (1 << 0) | (1 << 1);   // Enable digital for pins 0 and 1
  UART0_CTL |= (UART_CTL_UARTEN | UART_CTL_TXE | UART_CTL_RXE);       // Enable bit 8 for TXE for enabling transmitting
  // and bit 9 for recieving

  UART0_CTL &= ~0x1;        // Disable UART
  UARTIBRD_A = 104;          // remainder
  UARTFBRD_A = 11;         // fractional portion
  UARTLCRH_A = 0x70;        // Word length of 8 bits
  UARTCC_A = 0x5;          // Use system clock
  UART0_CTL |= 0x1;         // Enable port UART
  volatile unsigned short delay = 0;
  delay++;
  delay++;
  delay++;  // 3 clock cycles of delay before accessing UART data
}
