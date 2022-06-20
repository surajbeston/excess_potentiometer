
int maxPotValue = 1024;
int potPin = A0;
int redPin = 7;
int greenPin = 8;
int bluePin = 9;


int redOut = 0;
int blueOut = 0;
int greenOut = 0;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);
  Serial.print(potValue);
  Serial.print("\n");
  Serial.print(potValue >= maxPotValue*(2/3));
  Serial.print("\n");

  if (potValue >= maxPotValue*2/3){
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
  else if (potValue >= maxPotValue*1/3){
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  }
  else {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  }
  delay(200);
}
