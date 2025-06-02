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
  enum frequency freq = PRESET2; // 60 MHz
  PLL_Init(freq);        // Set system clock frequency to 60 MHz
  LED_Init();            // Initialize the 4 onboard LEDs (GPIO)
  ADCReadPot_Init();     // Initialize ADC0 to read from the potentiometer
  TimerADCTriger_Init(); // Initialize Timer0A to trigger ADC0
  PWM_Init();            // Initialize PWM

  float resistance;
  while(1) {
  }
  return 0;
}

void ADC0SS3_Handler(void) {
  // STEP 4: Implement the ADC ISR.
  // 4.1: Clear the ADC0 interrupt flag
  ADC0_ISC |= 0x1;
  // 4.2: Save the ADC value to global variable ADC_value
  ADC_value = ADC0_SSFIFO3;
}
