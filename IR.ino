int IRsensor A0;
int value, led=6;
int intensity;



void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}


void loop() {
  value=digitalRead(irsen);
  value=constrain(value,700,900);
  intensity=map(value,700,900,255,0);
  digitalWrite(led,intensity);
}
