/*
  Morse Code
  Blinks LED to Morse Code
 */
 
#include <Morse.h>

Morse morse(13);

void setup()
{
}

void loop()
{
  morse.dot();morse.dot();//The letter I
  delay(750);
  morse.dot();morse.dash();morse.dot();morse.dot();//The letter L
  morse.dash();morse.dash();morse.dash();//The letter O
  morse.dot();morse.dot();morse.dot();morse.dash();//The letter V
  morse.dot();//The letter E
  delay(750);
  morse.dash();morse.dot();morse.dash();morse.dash();///The letter Y
  morse.dash();morse.dash();morse.dash();//The letter O
  morse.dot();morse.dot();morse.dash();//The letter U
  delay(3000);
}
