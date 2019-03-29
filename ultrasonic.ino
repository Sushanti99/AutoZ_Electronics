#define trigPin1 23
#define echoPin1 22
//#define trigPin2 25
//#define echoPin2 24
//#define trigPin3 27
//#define echoPin3 26
//#define irSensorPin1 9
//#define irLedPin1 10
//#define irSensorPin2 11
//#define irLedPin2 12
int duration, distance, distance1,distance2,distance3;
//long value;
int irSensor1;
int irSensor2;

int SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(10);
digitalWrite(trigPin, HIGH);
delayMicroseconds(100);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
return (duration/2) / 29.1;
}

void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
//pinMode(trigPin2, OUTPUT);
//pinMode(echoPin2, INPUT);
//pinMode(trigPin3, OUTPUT);
//pinMode(echoPin3, INPUT);
//pinMode(irSensorPin1, INPUT);
//pinMode(irLedPin1, OUTPUT);
//pinMode(irSensorPin2, INPUT);
//pinMode(irLedPin2, OUTPUT);
//
}

void loop() 
{
distance1=SonarSensor(trigPin1, echoPin1);
//distance2=SonarSensor(trigPin2, echoPin2);
//distance3=SonarSensor(trigPin3, echoPin3);
//irSensor1=digitalRead(irSensorPin1);
//irSensor2=digitalRead(irSensorPin2);

Serial.println(distance1);
//Serial.println(distance2);
//Serial.println(distance3);
//Serial.println(irRead(irSensorPin1, irLedPin1));
//Serial.println(irRead(irSensorPin2, irLedPin2));
delay(2);

//char json[]="{\"sensor\":\"u1\",\"distance\":distance1,\"sensor\":\"u2\",\"distance\":distance2,\"sensor\":\"u3",\"distance\":distance3,\"sensor\":\"i1",\"output\":irSensor1,\"sensor\":\"i2",\"output\":irSensor2}";
//String json="{\"sensor\":\"u1\",\"distance\":distance1,\"sensor\":\"u2\",\"distance\":distance2,\"sensor\":\"u3",\"distance\":distance3,\"sensor\":\"i1",\"output\":irSensor1,\"sensor\":\"i2",\"output\":irSensor2}";}
}



//int irRead(int irSensorPin, int irLedPin)
//{
//digitalWrite(irLedPin, HIGH); 
//delayMicroseconds(2);
//digitalWrite(irLedPin, LOW); 
//delayMicroseconds(10);    
//return digitalRead(irSensorPin);
//}

