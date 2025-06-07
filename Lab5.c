/**
 * Copyright (c) 2025 Kevin Nguyen and Patrick Rungruengwatanachai.
 * EE/CSE 474: Lab 5 main program which allows the user to adjust
 * the brightness of a lightbulb based on the input from the user
 */

#include <stdint.h>
#include <stdio.h>

#include "Lab5_Inits.h"
#include "Lab5.h"

int main(void) {
  LED_Init();            // Initialize the 4 onboard LEDs (GPIO)
  PWM_Init();            // Initialize PWM
  UART_Init();           // Initialize UART0

  while (1) {
    while (!(UARTFR_A & UART_FR_RXFE)) {
      char c = (char)(UARTDR_A & 0xFF); // Read the character from UART2
      if (c == '0') {
        PWM_Change_Duty(318); // off
      }
      else if (c == '1') {
        PWM_Change_Duty(300); // low
      }
      else if (c == '2') {
        PWM_Change_Duty(150); // medium
      }
      else if (c == '3') {
        PWM_Change_Duty(0); // high
      }
    }
  }
  return 0;
}