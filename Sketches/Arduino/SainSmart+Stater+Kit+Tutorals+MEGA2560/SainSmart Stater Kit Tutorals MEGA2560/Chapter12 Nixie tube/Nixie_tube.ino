
int a=7; 
int b=6; 
int c=5; 
int d=11; 
int e=10; 
int f=8; 
int g=9; 
int dp=4; 
//display number 1
void digital_1(void) 
{ 
    unsigned char j; 
    digitalWrite(c,LOW);// pin5 low, light up c
    digitalWrite(b,LOW);//light up b
    for(j=7;j<=11;j++)//go out else
        digitalWrite(j,HIGH); 
    digitalWrite(dp,HIGH);//go out decimal point dp
} 
//display number2
void digital_2(void) 
{ 
    unsigned char j; 
    digitalWrite(b,LOW); 
    digitalWrite(a,LOW); 
    for(j=9;j<=11;j++) 
        digitalWrite(j,LOW); 
    digitalWrite(dp,HIGH); 
    digitalWrite(c,HIGH); 
digitalWrite(f,HIGH);
} 
// display number3
void digital_3(void) 
{ 
    unsigned char j; 
    digitalWrite(g,LOW); 
    digitalWrite(d,LOW); 
    for(j=5;j<=7;j++) 
        digitalWrite(j,LOW); 
    digitalWrite(dp,HIGH); 
    digitalWrite(f,HIGH); 
    digitalWrite(e,HIGH); 
} 
// display number4
void digital_4(void) 
{ 
    digitalWrite(c,LOW); 
    digitalWrite(b,LOW); 
    digitalWrite(f,LOW); 
    digitalWrite(g,LOW); 
    digitalWrite(dp,HIGH); 
    digitalWrite(a,HIGH); 
    digitalWrite(e,HIGH); 
    digitalWrite(d,HIGH);      
} 
// display number5
void digital_5(void) 
{ 
    unsigned char j; 
    for(j=7;j<=9;j++) 
    digitalWrite(j,LOW); 
    digitalWrite(c,LOW); 
    digitalWrite(d,LOW); 
    digitalWrite(dp,HIGH); 
    digitalWrite(b,HIGH); 
    digitalWrite(e,HIGH);  
} 
// display number6
void digital_6(void) 
{ 
    unsigned char j; 
    for(j=7;j<=11;j++) 
        digitalWrite(j,LOW); 
    digitalWrite(c,LOW); 
    digitalWrite(dp,HIGH); 
    digitalWrite(b,HIGH);      
} 
// display number7
void digital_7(void) 
{ 	
    unsigned char j; 
    for(j=5;j<=7;j++) 
        digitalWrite(j,LOW); 
    digitalWrite(dp,HIGH); 
    for(j=8;j<=11;j++) 
        digitalWrite(j,HIGH); 
} 
// display number8
void digital_8(void) 
{ 
    unsigned char j; 
    for(j=5;j<=11;j++) 
        digitalWrite(j,LOW); 
    digitalWrite(dp,HIGH); 
} 
void setup() 
{ 
    int i;//define i
    for(i=4;i<=11;i++) 
        pinMode(i,OUTPUT);//set pin4~pin11 output
} 
void loop() 
{     
    while(1) 
    { 
        digital_1();//number 1
        delay(2000);//delay 2s 
        digital_2(); 
        delay(2000); 
        digital_3(); 
        delay(2000); 
        digital_4(); 
        delay(2000); 
        digital_5(); 
        delay(2000); 
        digital_6(); 
        delay(2000); 
        digital_7(); 
        delay(2000); 
        digital_8(); 
        delay(2000);      
    }
}


