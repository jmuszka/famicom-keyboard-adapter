// Code to alternate blinking of the left and right board lights using AVR library
// Pro Micro ATmega32u4 board

#include <avr/io.h>
#include <util/delay.h>

#undef F_CPU
#define F_CPU 16000000UL // 16 MHz microprocessor

int main()
{

  // Select which bits to output to
  DDRB = 0x01; // RX LED on pro micro board is bit 0 of port B
  DDRD = 0x20; // TX LED on pro micro board is bit 5 of port D

  // Toggle left light
  PORTB ^= 0xFF;

  for (;;)
  {
    _delay_ms(250);
    PORTB ^= 0xFF; // Toggle left light
    PORTD ^= 0xFF; // Toggle right light
  }

  return 0;
}
