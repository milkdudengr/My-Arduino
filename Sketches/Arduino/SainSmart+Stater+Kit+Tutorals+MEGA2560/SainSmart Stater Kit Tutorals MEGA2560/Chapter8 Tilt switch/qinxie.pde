
void setup()
{
    pinMode(13,OUTPUT);
}
void loop()
{
    int i;
    while(1)
    {
       i=analogRead(5);
       if(i>200)
       {
          digitalWrite(13,HIGH);
       }
       else
       {
          digitalWrite(13,LOW);
       }
    }
}
