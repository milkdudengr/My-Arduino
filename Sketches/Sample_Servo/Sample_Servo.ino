/*
  Sample servo sketch
  Controlling the position of a servo
 */
 
#include <Servo.h>

Servo myservo;  //create servo object to control a servo

int angle = 0;  //varable stores the servo position

void setup()
{
  myservo.attach(9,380,2220);  //attaches the servo on pin 9 to the servo object
  //leg 3 start position, leg 2 center
  //min pos. - 380, max pos. - 2220:  180 deg rotation 
}

void loop()
{
  for(angle = 0; angle < 180; angle += 1)  //goes from 0 degrees to 180 degrees
  {                                        //in steps of 1 degree
    myservo.write(angle);   //tell servo to go to position in variable 'angle'
    delay(20);              //wait 20ms between servo commands
  }
  for(angle = 180; angle >= 1; angle -= 1) ////goes from 180 degrees to 0 degrees
  {
    myservo.write(angle);  //move servo in oposite direction
    delay(20);             //waits 20ms between servo commands
  }
}
