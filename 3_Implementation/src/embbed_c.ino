#ifndef _AVR_ATmega328_
#define _AVR_ATmega328_
#endif
#include <avr/io.h>
int main(void)
{
  DDRB=DDRB&0b11111101;//fd
  DDRD=DDRD|0b00000100;//40
  while(1)
  {
if(PINB & 0b00000010)//02
  PORTD=PORTD|0b00000100;//40
    else
    PORTD=PORTD&0b11111011;//bf
  }
  return 0;
  }
