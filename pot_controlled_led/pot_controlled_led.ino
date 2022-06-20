
int potPin = A0;
int ledPin = 11;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}


void loop(){
  int potValue = analogRead(potPin);
  analogWrite(ledPin, potValue/4);
  delay(200);
}
