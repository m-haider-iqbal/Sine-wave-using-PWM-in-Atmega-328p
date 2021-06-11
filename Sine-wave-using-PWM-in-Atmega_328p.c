
#include <Arduino.h>
volatile uint8_t counter = 0;

void setup() 

{
//Timer Initialize
  TCCR0A = 0b10000011; //Fast PWM Mode
  TCCR0B = 0b00000001;
  OCR0A = 0; 
  SREG = (1 << 7);
  TIMSK0 = 0b00000010;
  DDRD = 1 << 6;
}
void loop() 
{

}
  
ISR (TIMER0_COMPA_vect)
{
    if(OCR0A == 255)
    {
      counter = 1;
    }
    else if(OCR0A == 0)
    {
      counter = 0;
    }
    if(counter == 0)
    {
      OCR0A = OCR0A + 15;
    }
    else if (counter ==1)
    {
      OCR0A = OCR0A - 15;
    }
}

// M Haider Iqbal
