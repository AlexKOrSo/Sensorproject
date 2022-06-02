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
 // Uart_Init(BAUD);
  uint8_t const text_length = 39;
  uint8_t recievedChCts = 0;
  char text[text_length+1]; 
  
  //Configuring PWM Pins
  DDRB |= (1<<PB1)|(1<<PB2)|(1<<PB5);

  TCCR1A |= (1<<COM1B1)|(1<<WGM10)|(1<<WGM11);
  TCCR1B |= (1<<WGM13)|(1<<WGM12)|(1<<CS11);
  OCR1A = 39999;
  uint16_t timer = 4500;
  OCR1B = timer;

  //TCCR2A = (1<<COM2B1) + (1<<WGM20); // Set OC2A at bottom, clear OC2B at compare match
  //TCCR2B = (1<<CS22) +(1<<CS20)+ (1<<WGM22); // prescaler = 64; 
  //OCR2A = 249;
  //OCR2B = 10;
  //DDRD |= (1<<PD3);

  //TCCR1A |= (1<<COM1B1)|(1<<WGM10)|(1<<WGM11);
  //TCCR1B |= (1<<CS11)|(1<<WGM12)|(1<<WGM13);


  //OCR1A = 20000;
  
 // uint8_t timer = 2;
 //  OCR1B = timer;
  //ADC_Config configuration = ADC_Init(PRSC_128,AVCC,MUX_ADC0);
 
  //volatile uint16_t value = 0;
  //DDRB |= (1 << PORTB5);
  //volatile float distancevalue = 10.0F;
  while (1)
  {
    for (uint16_t i = 8000; i > 6500; i-=200)
    {
     
      _delay_ms(1000);
      PINB = (1 << PB5);
    }
    
    
    
    /*for (uint16_t i = 2000; i < 38000; i++)
    {
       OCR1B = i;
       _delay_ms(1);
    }
    PINB=(1<<PORTB5);
    for (uint16_t i = 38000; i > 2000; i--)
    {
       OCR1B = i;
       _delay_ms(1);
    }*/
    
  //    Uart_RecieveString(text,text_length);
    /*  if (*text=='A')
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
      */
  }
  #endif
  
  

}