int flame=A5;//定义火焰接口为模拟0 接口
int Beep=8;//定义蜂鸣器接口为数字7 接口
int val=0;//定义数字变量
void setup() 
{
 pinMode(Beep,OUTPUT);//定义LED 为输出接口
 pinMode(flame,INPUT);//定义蜂鸣器为输入接口
 Serial.begin(9600);//设定波特率为9600
} 


void loop()
{ 
val=analogRead(flame);//读取火焰传感器的模拟值 
Serial.println(val);//输出模拟值，并将其打印出来
 
 if(val>=600)//当模拟值大于600 时蜂鸣器鸣响
 { digitalWrite(Beep,HIGH);} 
 else
 { digitalWrite(Beep,LOW); }
 }
 




