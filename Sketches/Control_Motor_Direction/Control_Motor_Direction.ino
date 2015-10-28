/*
 *Brushed_H_Bridge_simple sketch
 *commands from serial port control motor direction
 *+ or - set the direction, any other key stops the motor
 */
 
const int in1Pin = 5;  //H-Bridge input pins
const int in2Pin = 4;

const int in3Pin = 3;  //H-Bridge for second motor
const int in4Pin = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  Serial.println("+ - to set direction, any other key stops motor");
}

void loop()
{
  if ( Serial.available()) {
    char ch = Serial.read();
    if (ch == '+')
    {
      Serial.println("CW");
      // first motor
      digitalWrite(in1Pin,LOW);
      digitalWrite(in2Pin,HIGH);
      // second motor
      digitalWrite(in3Pin,LOW);
      digitalWrite(in4Pin,HIGH);
    }
    else if (ch == '-')
    {
      Serial.println("CCW");
      digitalWrite(in1Pin,HIGH);
      digitalWrite(in2Pin,LOW);
      
      digitalWrite(in3Pin,HIGH);
      digitalWrite(in4Pin,LOW);
    }
    else
    {
      Serial.print("Stop Motors");
      digitalWrite(in1Pin,LOW);
      digitalWrite(in2Pin,LOW);
      digitalWrite(in3Pin,LOW);
      digitalWrite(in4Pin,LOW);
    }
  }
}
