#include <SoftwareSerial.h>
String data;
SoftwareSerial bt(7,8);

void setup()
{
// put your setup code here, to run once:
Serial.begin(115200);
bt.begin(115200);
pinMode(13,OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
if(bt.available()>0)
{
  data=bt.read();
  bt.print(data);
  bt.print("\n");
  if(data=='1')
   digitalWrite(13,HIGH);
  else if(data=='0')
   digitalWrite(13,LOW);
}
}
