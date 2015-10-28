/*
  Traffic Light
  This is a simple traffic light controller
 */
 
int greenled = 8; //Led's and pins
int yellowled = 9;
int redled = 10;

void setup()
{
pinMode(greenled, OUTPUT); //Pinmodes of the leds
pinMode(yellowled, OUTPUT);
pinMode(redled, OUTPUT);
}

void loop()
{
digitalWrite(greenled, HIGH); //Green on for 5 seconds
delay(5000);
digitalWrite(greenled, LOW); //Green off, yellow on for 2 seconds
digitalWrite(yellowled, HIGH);
delay(2000);
digitalWrite(yellowled, LOW); //yellow off, red on for 5 seconds
digitalWrite(redled, HIGH);
delay(5000);
digitalWrite(redled, LOW); //Red and Yellow off 
digitalWrite(yellowled, LOW); 
}
