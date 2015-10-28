/*
  LED Fader
 */
 
//do not connect led's in sequential order
//note: pin 5 and 6 act weird in the beginning - an arduino bug
byte led1 = 3;
byte led2 = 5;
byte led3 = 6;
byte led4 = 9;
byte led5 = 10;
byte led6 = 11;
int x = 0;
int y = 0;
int steps = 1; //change if needed, defines the steps between 0 and 255, a lower number is smoother
//make sure the variable "steps" is a factor of 255; any of the below numbers
//factors of 255 are : 1,3,5,15,17,51,85,255
//sorry for a lot of notes, but remember to change variable "delaytime" according to variable "steps"

//delay is in milliseconds for below
int delaytime = 2; //change if needed, delay between increments of PWM
//850 milliseconds is on-off/off-on time, in 17 step increments of brightness
int delaytime2 = 5; //change if needed, delay between switching of leds
void setup (){
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (led4, OUTPUT);
  pinMode (led5, OUTPUT);
  pinMode (led6, OUTPUT);
  do {
    x = x + steps;
    analogWrite (led1, x);
    analogWrite (led2, x);
    delay (delaytime);
  }
  while (x != 255);
}
void loop (){
  y = 0;
  x = 255;
  delay (delaytime);
  do{
    y = y + steps;
    x = x - steps;
    analogWrite (led3, y);
    analogWrite (led1, x);
    delay (delaytime);
  }
  while (y != 255 && x != 0);
  delay (delaytime2);
  y = 0;
  x = 255;
  do{
    y = y + steps;
    x = x - steps;
    analogWrite (led4, y);
    analogWrite (led2, x);
    delay (delaytime);
  }
  while (y != 255 && x != 0);
  delay (delaytime2);
  y = 0;
  x = 255;
  do{
    y = y + steps;
    x = x - steps;
    analogWrite (led5, y);
    analogWrite (led3, x);
    delay (delaytime);
  }
  while (y != 255 && x != 0);
  delay (delaytime2);
  y = 0;
  x = 255;
  do{
    y = y + steps;
    x = x - steps;
    analogWrite (led6, y);
    analogWrite (led4, x);
    delay (delaytime);
  }
  while (y != 255 && x != 0);
  delay (delaytime2);
  y = 0;
  x = 255;
  do{
    y = y + steps;
    x = x - steps;
    analogWrite (led1, y);
    analogWrite (led5, x);
    delay (delaytime);
  }
  while (y != 255 && x != 0);
  delay (delaytime2);
  y = 0;
  x = 255;
  do{
    y = y + steps;
    x = x - steps;
    analogWrite (led2, y);
    analogWrite (led6, x);
    delay (delaytime);
  }
  while (y != 255 && x != 0);
  delay (delaytime2);
}
