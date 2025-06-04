/**
 * Copyright (c) 2025 Kevin Nguyen and Patrick Rungruengwatanachai.
 * EE/CSE 474: Lab 5 main program
 */

// NOTE: This is the main function for Task 1a. You should start by
// implementing Lab3_Driver.c (STEP 0a, 1-3) and then come back to finish
// the ISR and the main function (STEP 0b, 4-5).

#include <stdint.h>
#include <stdio.h>
#include "Lab5_Inits.h"

// STEP 0b: Include your header file here
// YOUR CUSTOM HEADER FILE HERE
#include "Lab5.h"

uint32_t ADC_value;

int main(void) {
  // Select system clock frequency preset
  enum frequency freq = PRESET3; // 60 MHz
  PLL_Init(freq);        // Set system clock frequency to 60 MHz
  LED_Init();            // Initialize the 4 onboard LEDs (GPIO)
  ADCReadPot_Init();     // Initialize ADC0 to read from the potentiometer
  TimerADCTriger_Init(); // Initialize Timer0A to trigger ADC0
  PWM_Init();            // Initialize PWM
  UART_Init();

  /*
  float resistance;
     while(1) {
      if (PWMCC & 1) {
        while(1) {}
      }
    }
  */

  while (1) {
    while (!(UARTFR_A & UART_FR_RXFE)) {
      char c = (char)(UARTDR_A & 0xFF); // Read the character from UART2
      uint32_t duty = (UARTDR_A * PWM0LOAD) / 4095; // might need to tweak
      if (c == '0') {
        PWM_Change_Duty(1);
      }
      else if (c == '1') {
        PWM_Change_Duty(233);
      }
      else if (c == '2') {
        GPIODATA_F = 0x0;
      }
      printf("%c\n", c);
      volatile unsigned short delay = 0;
      delay++, delay++;
      while (UARTFR_A & UART_FR_TXFF) {}
    }
  }
  return 0;
}

void ADC0SS3_Handler(void) {
  // STEP 4: Implement the ADC ISR.
  // 4.1: Clear the ADC0 interrupt flag
  ADC0_ISC |= 0x1;
  // 4.2: Save the ADC value to global variable ADC_value
  ADC_value = ADC0_SSFIFO3;
  int duty = (ADC_value * PWM0LOAD) / 4095;
  // PWM_Change_Duty(duty);
  // printf("%i\n", duty);   
  // 399 HI
  // 233 MED
  // 0 LOW 
}
