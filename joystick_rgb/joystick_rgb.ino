int joyPin1 = A0;
int joyPin2 = A1;

int redLed = 7;
int greenLed = 8;
int blueLed = 9;

void setup() {
  Serial.begin(9600);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop() {
  int joy1Value = analogRead(joyPin1);
  int joy2Value = analogRead(joyPin2);

  analogWrite(redLed, joy1Value/4);
  analogWrite(greenLed, joy2Value/4);
  delay(100);
}
