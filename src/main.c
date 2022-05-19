//#include <Arduino.h>
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#define BAUD 9600
#include "avr/io.h"
#include "UART.h"
#include "ADC.h"
#include "avr/delay.h"
#include "GP2Y.h"
#include <stdlib.h>
#include "toolbox.h"
#include <string.h>
//#define TESTING
#define LED PORTB5 

int main(void)
{
  #ifndef TESTING
  Uart_Init(BAUD);
  uint8_t const text_length = 39;
  uint8_t recievedChCts = 0;
  char text[text_length+1]; 

  
  ADC_Config configuration = ADC_Init(PRSC_128,AVCC,MUX_ADC0);
 
  volatile uint16_t value = 0;
  DDRB |= (1 << PORTB5);
  volatile float distancevalue = 10.0F;
  while (1)
  {
      Uart_RecieveString(text,text_length);
      if (*text=='A')
      {
        PINB = (1<<PORTB5);
        distancevalue = 0;
        //ADC_ReadInput(&configuration,&value);  
        readDistance(&configuration,&distancevalue); 
        //ftoa(distancevalue,text,4);
        //uart_puts(text);
        //memcpy(text,(char*)&distancevalue,4);
        //text[4]='\0';
        uart_puts_length((char*)&distancevalue,4);
        //uart_puts(text);
        //uart_puts(utoa(value,text,10));
        //uart_puts("\n");
      }
      

      
      //_delay_ms(1000);
  }
  #endif
  
  

}