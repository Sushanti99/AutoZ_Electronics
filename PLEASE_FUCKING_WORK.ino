#include<String.h>
#include<SoftwareSerial.h>

SoftwareSerial phone(17,18);//Bluetooth port for IMU,GPS
SoftwareSerial kill(19,20);//Bluetooth port for kill switch
String data;//String to store kill switch values . 
int control=0;
#define trigPin1 2
#define echoPin1 3
#define trigPin2 4
#define echoPin2 5
#define trigPin3 6
#define echoPin3 7
#define irSensorPin1 22
//#define irLedPin1 10
#define irSensorPin2 24
//#define irLedPin2 12
#define irSensorPin3 25
//#define irLedPin3 14
#define irSensorPin4 23
//#define irLedPin4 16
#define en1 46
#define en2 47
#define en3 52
#define en4 53

int i=0,j=0;
//String a[8];//JSON STRING WITH IMU values
String data1;
int duration,distance,distance1,distance2,distance3;
int irSensor1; 
int irSensor2;
int irSensor3;
int irSensor4;
#define motorA1 38
#define motorA2 39
#define motorB1 40
#define motorB2 41
#define motorC1 42
#define motorC2 43
#define motorD1 44
#define motorD2 45
void sensors();
int SonarSensor(int trigPin , int echoPin);
void finish();





long long a;
void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
Serial2.begin(9600);
pinMode(en1,OUTPUT);
pinMode(en2,OUTPUT);
pinMode(en3,OUTPUT);
pinMode(en4,OUTPUT);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
pinMode(irSensorPin1, INPUT);
//pinMode(irLedPin1, OUTPUT);
pinMode(irSensorPin2, INPUT);
//pinMode(irLedPin2, OUTPUT);
pinMode(irSensorPin3, INPUT);
//pinMode(irLedPin3, OUTPUT);
pinMode(irSensorPin4, INPUT);
//pinMode(irLedPin4, OUTPUT);
pinMode(motorA1,OUTPUT);
pinMode(motorA2,OUTPUT);
pinMode(motorB1,OUTPUT);
pinMode(motorB2,OUTPUT);
pinMode(motorC1,OUTPUT);
pinMode(motorC2,OUTPUT);
pinMode(motorD1,OUTPUT);
pinMode(motorD2,OUTPUT);
phone.begin(9600);
kill.begin(9600);
bool irSensor1= 0;
bool irSensor2= 0;
bool irSensor3= 0;
bool irSensor4= 0;
a=millis();
digitalWrite(en1,HIGH);
digitalWrite(en2,HIGH);
digitalWrite(en3,HIGH);
digitalWrite(en4,HIGH);
}






void loop() {


if(millis()-a>2000){
if(Serial2.available()>0){
  //Serial.print("1");
  data=Serial2.readString();
  Serial.print(data);
  a=millis();}
}

  Serial.println("YES");
if(kill.available()>0){
   data=kill.readString();
   if(data=='1')
    finish();//STOPS THE CAR
    
}
if(phone.available()>0)
{
 data1=phone.readString();
 Serial.println(data1);//JSON STRING WITH IMU,GPS VALUES , ID:2
 }
 
 sensors();// PRINTS JSON STRING WITH SENSOR VALUES.



 //MOTORS CRAP
 if(Serial.available()>0)
  int control=Serial.parseInt();
  int a=(192 & control)>>6;//192=11000000
  int b=(48 & control)>>4;//48=00110000
  int c=(12 & control)>>2;//12=00001100
  int d=(3 & control);//3=00000011
  if (a==0)//Stop Motor 1
  {
    digitalWrite(motorA1,LOW);
    digitalWrite(motorA2,LOW);
  }
  if (a==1)//Forward Motor 1
  {
    digitalWrite(motorA1,HIGH);
    digitalWrite(motorA2,LOW);
  }
  if (a==2)//Reverse Motor 1
  {
    digitalWrite(motorA1,LOW);
    digitalWrite(motorA2,HIGH);
  }
  if (b==0)//Stop Motor 2
  {
    digitalWrite(motorB1,LOW);
    digitalWrite(motorB2,LOW);
  }
  if (b==1)//Forward Motor 2
  {
    digitalWrite(motorB1,HIGH);
    digitalWrite(motorB2,LOW);
  }
  if (b==2)//Reverse Motor 2
  {
    digitalWrite(motorB1,LOW);
    digitalWrite(motorB2,HIGH);
  }
  if (c==0)//Stop Motor 3
  {
    digitalWrite(motorC1,LOW);
    digitalWrite(motorC2,LOW);
  }
  if (c==1)//Forward Motor 3
  {
    digitalWrite(motorC1,HIGH);
    digitalWrite(motorC2,LOW);
  }
  if (c==2)//Reverse Motor 3
  {
    digitalWrite(motorC1,LOW);
    digitalWrite(motorC2,HIGH);
  }
  if (d==0)//Stop Motor 4
  {
    digitalWrite(motorD1,LOW);
    digitalWrite(motorD2,LOW);
  }
  if (d==1)//Forward Motor 4
  {
    digitalWrite(motorD1,HIGH);
    digitalWrite(motorD2,LOW);
  }
  if (d==2)//Reverse Motor 4
  {
    digitalWrite(motorD1,LOW);
    digitalWrite(motorD2,HIGH);
  }

}




int SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
/*if((duration>0)&&(duration<5))
  finish();*/
return (duration/2)/29.1;

}




void sensors()
{
  
//start readiung sensor values
distance1=SonarSensor(trigPin1,echoPin1);
distance2=SonarSensor(trigPin2,echoPin2);
distance3=SonarSensor(trigPin3,echoPin3);
irSensor1=digitalRead(irSensorPin1);
irSensor2=digitalRead(irSensorPin2);
irSensor3=digitalRead(irSensorPin3);
irSensor4=digitalRead(irSensorPin4);
String json = "{\"ID\":\"1\",\"distance1\":\""+String(distance1)+"\"}";
String json2 = "distance2\":\""+String(distance2)+"\"";
json2 = ',' + json2;
String json3 = "distance3\":\""+String(distance3)+"\"";
json3 = ',' + json3;
String json4 = "IR1\":\""+String(irSensor1)+"\"";
json4 = ',' + json4;
String json5 = "IR2\":\""+String(irSensor2)+"\"";
json5 = ',' + json5;
String json6 ="IR3\":\""+String(irSensor3)+"\"";
json6 = ',' + json6;
String json7 = "IR4\":\""+String(irSensor4)+"\"";
json7 = ',' + json7;
String jsonFinal = json.substring(0,json.length()-1)+json2+json3+json4+json5+json6+json7+json.charAt(json.length()-1);//APPENDING ALL JSON STRINGS TO JSON
Serial.println(jsonFinal);//PRINT JSON STRING WITH ID = 1
Serial2.flush();
Serial.flush();
}


void finish()//BRAKE
{
  digitalWrite(motorA1,HIGH);
    digitalWrite(motorA2,HIGH);
    digitalWrite(motorB1,HIGH);
    digitalWrite(motorB2,HIGH);
    digitalWrite(motorC1,HIGH);
    digitalWrite(motorC2,HIGH);
    digitalWrite(motorD1,HIGH);
    digitalWrite(motorD2,HIGH);
    delay(500);
    digitalWrite(motorA1,LOW);
    digitalWrite(motorA2,LOW);
    digitalWrite(motorB1,LOW);
    digitalWrite(motorB2,LOW);
    digitalWrite(motorC1,LOW);
    digitalWrite(motorC2,LOW);
    digitalWrite(motorD1,LOW);
    digitalWrite(motorD2,LOW);
    
}
