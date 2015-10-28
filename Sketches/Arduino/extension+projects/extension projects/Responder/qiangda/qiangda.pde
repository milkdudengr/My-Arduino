int redled=10;
int yellowled=9;
int greenled=8;
int redpin=7;
int yellowpin=6;
int greenpin=5;
int red;
int yellow;
int green;
void setup()
{
pinMode(redled,OUTPUT);
pinMode(yellowled,OUTPUT);
pinMode(greenled,OUTPUT);
pinMode(redpin,INPUT);
pinMode(yellowpin,INPUT);
pinMode(greenpin,INPUT);
}
void loop()
{
red=digitalRead(redpin);
if(red==LOW)
{ digitalWrite(redled,LOW);}
else
{ digitalWrite(redled,HIGH);}
yellow=digitalRead(yellowpin);
if(yellow==LOW)
{ digitalWrite(yellowled,LOW);}
else
{ digitalWrite(yellowled,HIGH);}
green=digitalRead(greenpin);
if(green==LOW)
{ digitalWrite(greenled,LOW);}
else
{ digitalWrite(greenled,HIGH);}
}

