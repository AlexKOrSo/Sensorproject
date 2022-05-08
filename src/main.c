//#include <Arduino.h>
#include "avr/io.h"


int main(void)
{
  ADMUX |= 0x3<<REFS0;  //
  ADMUX &= 0xF0;        // Set ADC 0 
  ADCSRA |= (1<<ADEN)||(1<<ADPS2)|(0<<ADPS1)|(0<<ADPS0);
  ADCSRA |= (1<<ADSC);
  while(ADCSRA & (1<<ADSC));
  return 0;
}