//#include <Arduino.h>
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#define BAUD 9600
#include "avr/io.h"
#include "UART.h"
#include "ADC.h"
#include "avr/delay.h"
#include <stdlib.h>

//#define TESTING
#define LED PORTB5 

int main(void)
{
  #ifndef TESTING
  Uart_Init(BAUD);
  uint8_t const text_length = 39;
  uint8_t recievedChCts = 0;
  char text[text_length+1]; 
  const char test[]={"Test\0"};
  
  
  DDRB |= (1 << LED); 

  
  uart_puts(test);
 
  
  
  ADC_Config configuration = ADC_Init(PRSC_4,INTERNAL,MUX_ADC0);
 
  volatile uint16_t value = 0;
  while (1)
  {
      ADC_ReadInput(&configuration,&value);   
      uart_puts(utoa(value,text,10));
      uart_puts("\n");
      _delay_ms(1000);
  }
  #endif
  
  

}