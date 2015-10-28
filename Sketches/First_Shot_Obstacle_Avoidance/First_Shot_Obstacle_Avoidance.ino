/*First shot at obstacle avoidance using a Seeed motor shield
 *and a Seeed PING sensor
 */

 const int pingPin =      3;      //Ultrasonic sensor to pin D3
 int in1Pin        =      8;      //Left motor direction 1 to pin D8
 int in2Pin        =     11;      //Left motor direction 2 to pin D11
 int speedpinA     =      9;      //Enable left motor
 int in3Pin        =     12;      //Right motor direction 1 to pin D12
 int in4Pin        =     13;      //Right motor direction 2 to pin D13
 int speedpinB     =     10;      //Enable right motor
 int spd           =    127;      //Define the speed of the motor
 
 # define BOUNDARY       20       //(cm) Avoid objects closer than 20cm
 # define INTERVAL       25       //(ms) Interval between distance readings
 
//setup
//set motor pins as OUTPUTS, initialize serial

void setup() 
{
  Serial.begin(9600);
  pinMode(in1Pin, OUTPUT);        //Left motor pin 1
  pinMode(in2Pin, OUTPUT);        //Left motor pin 2
  pinMode(speedpinA, OUTPUT);     
  pinMode(in3Pin, OUTPUT);        //Right motor pin 1
  pinMode(in4Pin, OUTPUT);        //Right motor pin 2
  pinMode(speedpinB, OUTPUT);
}

//Roam around while avoiding objects
//
//Set motors to move forward,
//Take distance readings over and over,
//as long as no objects are too close (determined by BOUNDARY).
//If object is too close, avoid it -- back up and turn.
//Repeat.

void loop() 
{
  long distance;                 //Distance reading from rangefinder
  
  forward();                     //Robot moves forward continuously
  do
  {
    distance = readDistance();   //Take a distance reading
	Serial.println(distance);    //Print it out
	delay(INTERVAL);             //Delay between readings
  }
  while(distance >= BOUNDARY);   //Loop while no objects are close by
  
  //Robot has sensed a nearby object and exited the while loop.
  //Take evasive action to avoid the object
  backward();                    //move backward 500ms
  delay(500);
  rightTurn(300);                //Turn right 300ms
}                                //End main program

//Forward
//
//Move robot forward by setting both wheels forward
//Will persist until something else changes the
//motors' directions

void forward()
{
  analogWrite(speedpinA, spd);    //Sets the speed of the left motor
  analogWrite(speedpinB, spd);    //Sets the speed of the right motor
  digitalWrite(in1Pin, HIGH);     //Left motor counter-clockwise
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, LOW);      //Right motor clockwise
  digitalWrite(in4Pin, HIGH); 
}

//backward
//
//Move robot backward by setting both wheels backward
//Will persist until something else changes the
//motors' directions

void backward()
{
  analogWrite(speedpinA, spd);    //Sets the speed of the left motor
  analogWrite(speedpinB, spd);    //Sets the speed of the right motor
  digitalWrite(in1Pin, LOW);     //Left motor backward
  digitalWrite(in2Pin, HIGH);
  digitalWrite(in3Pin, HIGH);     //Right motor backward
  digitalWrite(in4Pin, LOW);
}

//rightTurn
//
//Turn the robot to the right by moving the wheels in opposite directions
//Amount of turning is determined by duration argument (ms)

void rightTurn(int duration)
{
  analogWrite(speedpinA, spd);    //Sets the speed of the left motor
  analogWrite(speedpinB, spd);    //Sets the speed of the right motor
  digitalWrite(in1Pin, HIGH);     //Left motor backward
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, HIGH);      //Right motor forward
  digitalWrite(in4Pin, LOW);
  delay(duration);                //Turning time (ms)
}

//readDistance
//
//Take a distance reading from the ultrasonic rangefinder
//from http://arduino.cc/en/Tutorial/Ping?from=Tutorial.UltrasoundSensor

long readDistance()
{
  long duration, inches, cm;
  
  //The Ping is triggered by a HIGH pulse of 2 or more microseconds
  //We give a short LOW pulse beforehand to ensure a clean HIGH pulse
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  
  //The same pin is used to read the signal from the Ping:  a HIGH
  //pulse whose duration is the time (in microseconds) from the sending
  //of the ping to the reception of its echo off an object
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  
  //Convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  return(cm);
}

long microsecondsToCentimeters(long microseconds)
{
  //The speed of sound is 340 m/s or 29 microseconds per centimeter
  //The ping travels out and back, so to find the distance of the
  //object we take half of the distance traveled
  return microseconds / 29 / 2;
}