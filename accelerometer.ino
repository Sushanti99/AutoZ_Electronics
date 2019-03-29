const int xpin=A1;
const int ypin=A2;
//const int zpin=A3;
int xaxis;
int yaxis;
int zaxis;
int LM1=5;
int LM2=6;
int RM1=7;
int RM2=8;
int En=10;

void setup() {
  Serial.begin(9600);
  pinMode(xpin,INPUT);
  pinMode(ypin,INPUT);
//  pinMode(zpin,INPUT);
  pinMode(En,OUTPUT);
  digitalWrite(En,HIGH);
}

void loop() {
  xaxis=analogRead(xpin);
  yaxis=analogRead(ypin);
 // zaxis=analogRead(zpin);
  Serial.print(xaxis);
  Serial.print("\t");
  Serial.print("\n");
  Serial.print(yaxis);
  Serial.print("\t");
  Serial.print("\n");
 // Serial.print(zaxis);
  
  if((xaxis<300) && (xaxis>250)&&(yaxis>300) && (yaxis<400))
  {
    //move the motor forward
    Serial.print("Move the bot forward\n");
    analogWrite(LM1,200);
    analogWrite(RM1,200);
    analogWrite(LM2,0);
    analogWrite(RM2,0);
    delay(100);
  }
  if((xaxis<400)&& (xaxis>350) && (yaxis>200) && (yaxis<400))
  {
    //move the motor backward
    Serial.print("Move the bot backward\n");
    analogWrite(LM2,200);
    analogWrite(RM2,200);
    analogWrite(LM2,0);
    analogWrite(RM2,0);
    delay(100);
  }
  if((yaxis<400)&&(yaxis>350) && (xaxis>300) && (xaxis<350))
  {
    //move the motor leftward
    Serial.print("Move the bot left\n");
    analogWrite(LM1,0);
    analogWrite(RM1,200);
    analogWrite(LM2,200);
    analogWrite(RM2,0);
    delay(100);
  }
  if((yaxis<300)&&(yaxis>250) && (xaxis>300) && (xaxis<350))
  {
    //move the motor rightward
    Serial.print("Move the bot right\n");
    analogWrite(LM1,200);
    analogWrite(RM1,0);
    analogWrite(LM2,0);
    analogWrite(RM2,200);
    delay(100);
  }
//  if((xaxis) && (yaxis) == 300)
//  {
//    //stationary position
//    Serial.print("Do not move the bot\n");
//  }
  delay(1000);
}
