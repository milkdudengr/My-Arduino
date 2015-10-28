/*
 *Brushed H Bridge simple sketch
 *commands from serial port control motor direction
 *+ or - set the direction, any other key stops the motor
 */
 
const int in1Pin = 5;  //H-Bridge input pins
const int in2Pin = 4;
const int in3Pin = 3;
const int in4Pin = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  Serial.println("+ - to set direction, any other key stops motor");
}
void loop()
{
  if ( Serial.available()) {
    char ch = Serial.read();
    if (ch == '+')
    {
      Serial.println("CW");
      digitalWrite(in1Pin,LOW);
      digitalWrite(in2Pin,HIGH);
      digitalWrite(in3Pin,HIGH);
      digitalWrite(in4Pin,LOW);
    }
    else if (ch == '-')
    {
      Serial.println("CCW");
      digitalWrite(in1Pin,HIGH);
      digitalWrite(in2Pin,LOW);
      digitalWrite(in3Pin,LOW);
      digitalWrite(in4Pin,HIGH);
    }
  }
}
