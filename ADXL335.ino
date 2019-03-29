const int xpin=A1;
const int ypin=A2;
const int zpin=A3;
int xaxis;
int yaxis;
int zaxis;

void setup() {
  Serial.begin(9600);
  pinMode(xpin,INPUT);
  pinMode(ypin,INPUT);
  pinMode(zpin,INPUT);
}

void loop() {
  xaxis=analogRead(xpin);
  yaxis=analogRead(ypin);
  zaxis=analogRead(zpin);
  Serial.print(xaxis);
  Serial.print(yaxis);
  Serial.print(zaxis);
  delay(100);
}
