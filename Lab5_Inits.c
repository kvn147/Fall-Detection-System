/**
 * Copyright (c) 2025 Kevin Nguyen and Patrick Rungruengwatanachai.
 * EE/CSE 474: Lab 5 drivers starter code
 */

 #include "PLL_Header.h"
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
 
 void ADCReadPot_Init(void) {
   // STEP 2: Initialize ADC0 SS3.
   // 2.1: Enable the ADC0 clock
   RCGCADC |= 0x1; // Enable ADC0 clock
   // 2.2: Delay for RCGCADC (Refer to page 1073)
   volatile unsigned short delay = 0;
   delay++, delay++;
   // 2.3: Power up the PLL (if not already)
   PLLFREQ0 |= 0x00800000; // we did this for you
   // 2.4: Wait for the PLL to lock
   while (PLLSTAT != 0x1); // we did this for you
   // 2.5: Configure ADCCC to use the clock source defined by ALTCLKCFG
   ADCCC = 0x1; // Set ADC clock to use system clock (60 MHz)
   // 2.6: Enable clock to the appropriate GPIO Modules (Hint: Table 15-1)
   RCGCGPIO |= (1<<4); // Enable clock for Port E
   delay++, delay++;
   // 2.7: Delay for RCGCGPIO
   delay++, delay++;
   // 2.8: Set the GPIOAFSEL bits for the ADC input pins
   GPIOAFSEL_E |= (1<<3);
   // 2.9: Clear the GPIODEN bits for the ADC input pins
   GPIODEN_E &= ~(1<<3); // Disable digital function for PE3 (AIN0)
   // 2.10: Disable the analog isolation circuit for ADC input pins (GPIOAMSEL)
   GPIOAMSEL_E |= (1<<3); // Enable analog function for PE3 (AIN0)
   // 2.11: Disable sample sequencer 3 (SS3)
   ADC0_ACTSS &= ~0x8; // Disable SS3 (bit 3)
   // 2.12: Select timer as the trigger for SS3
   ADC0_EMUX = (ADC0_EMUX & ~0xF000) | (0x5 << 12); // Set bits 15-12 to 0x5 (timer trigger)
   // 2.13: Select the analog input channel for SS3 (Hint: Table 15-1)
   ADC0_SSMUX3 = 0x0;
   // 2.14: Configure ADCSSCTL3 register
   ADC0_SSCTL3 = 0x4; // sample 0 and 1, end of sequence, no interrupts
   // 2.15: Set the SS3 interrupt mask
   ADC0_IM |= 0x8; // Enable SS3 interrupt (bit 3)
   // 2.16: Set the corresponding bit for ADC0 SS3 in NVIC
   NVIC_EN0 |= (1 << 17); // Enable ADC0 SS3 interrupt in NVIC (bit 17)
   // 2.17: Enable ADC0 SS3
   ADC0_ACTSS |= 0x8; // Enable SS3
 }
 
void TimerADCTriger_Init(void) {
  // STEP 3: Initialize Timer0A to trigger ADC0 at 1 HZ.
  // Hint: Refer to section 13.3.7 of the datasheet

  // YOUR CODE HERE
  RCGCTIMER |= 0x1; // enable clock for Timer 0 (GPTM0)
  while ((RCGCTIMER & 0x1) == 0) {}
    
  GPTMCTL = 0x0; // Disable timer A for initialization 
  GPTMCTL |= 0x20;
  GPTMCFG = 0x0; // 32-bit timer configuration
  GPTMTAMR |= 0x12; // set to periodic mode and count down
  GPTMAILR = 16000000; // Load for 1 Hz
  GPTMICR |= 0x1; // Clear any timeout flag
  GPTMIMR |= 0x1; // GPTM interupt mask
  GPTMCC |= 0x1; // Hooks up to PLL
  GPTMCTL |= 0x1; // Enable timer A
  GPTMADCEV |= 0x1; 
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
  PWM0LOAD = 0x0000018F;  
  PWM0CMPA = 0x0000012B;  // set duty cycle for pin 1
  PWM0CMPB = 0x00000063;  // set duty cycle for pin 2
  PWM0CTL = 0x00000001;
  PWMENABLE = 0x00000003; // latch fault PWM
}

void PWM_Change_Duty(int cycle) {
  PWM0CTL = 0x00000000; // Disable PWM0

  /*
  PWM0CMPA = 0x0000012B;  // set duty cycle for pin 1
  PWM0CMPB = 0x00000063;  // set duty cycle for pin 2
  PWM0CTL = 0x00000003;
  */
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
 
 