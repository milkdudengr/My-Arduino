/*
  First Obstacle Avoidance Sketch HC-SR04
  
  This is the first attempt at programming the obstacle 
  avoidance robot. Takes input from an HC-SR04 ultrasonic
  sensor to stear the robot around obstacles.
 */

#include <NewPing.h>

#define TRIGGER_PIN      12     //Trigger Pin
#define ECHO_PIN         11     //Echo pin
#define in1Pin           5      //Left motor input 1
#define in2Pin           4      //Left motor input 2
#define in3Pin           3      //Right motor input 1
#define in4Pin           2      //Right motor input 2

#define BOUNDARY         20     //(cm) Avoid objects closer than 20cm
#define INTERVAL         33     //(ms) Interval between distance readings

NewPing sonar(12,11);

void setup()
{
  pinMode(in1Pin, OUTPUT);      //Left motor pin 1
  pinMode(in2Pin, OUTPUT);      //Left motor pin 2
  pinMode(in3Pin, OUTPUT);      //Right motor pin 1
  pinMode(in4Pin, OUTPUT);      //Right motor pin 2
  Serial.begin(9600);
}

//Roam around while avoiding objects
//
//Set motors to move forward
//Take distance readings over and over
//as long as no objects are too close (determined by BOUNDARY)
//If object is too close, avoid it -- back up and turn

void loop()
{
  forward();                    //Robot moves forward continuously
  do
  {
    sonar.ping_cm(); //Take a distance reading
    Serial.println(sonar.ping_cm());   //Print it out
    delay(INTERVAL);            //Delay between readings
  }
  while(sonar.ping_cm() >= BOUNDARY);  //Loop while no objects are close
  
  //Robot has sensed a nearby object and exited the while loop
  //Avoid object
  backward();                   //Move backward 1000ms
  delay(1000);
  rightTurn(1200);               //Turn right
}

//forward
//
//Move the robot forward by setting both motors forward
//Continues until something changes the direction

void forward()
{
  digitalWrite(in1Pin, LOW);     //Left motor forward
  digitalWrite(in2Pin, HIGH);
  digitalWrite(in3Pin, LOW);     //Right motor forward
  digitalWrite(in4Pin, HIGH);
}

//backward
//
//Move the robot backward by setting both motors backward
//Continues until something changes the direction

void backward()
{
  digitalWrite(in1Pin, HIGH);    //Left motor backward
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, HIGH);    //Right motor backward
  digitalWrite(in4Pin, LOW);
}

//rightTurn
//
//Turn the robot to the right by moving motors in opposite directions
//Turning amount determined by duration

void rightTurn(int duration)
{
  digitalWrite(in1Pin, HIGH);    //Left motor backward
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, LOW);     //Right motor forward
  digitalWrite(in4Pin, HIGH);
  delay(duration);               //Turning time (ms)
}

//readDistance
//
//Take a distance reading from PING ultrasonic rangefinder

long readDistance()
{
  long duration, inches, cm;
  
  //The PING is triggered by a HIGH impulse of 2 or more microseconds
  //Give a short LOW pulse before to ensure a clean HIGH pulse
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIGGER_PIN, LOW);
  
  //The echo pin is used to read the signal from the pin
  pinMode(ECHO_PIN, INPUT);
  sonar.ping();
  
  //Convert the time into distance
  cm = sonar.convert_cm(duration);
  return(cm);
}

