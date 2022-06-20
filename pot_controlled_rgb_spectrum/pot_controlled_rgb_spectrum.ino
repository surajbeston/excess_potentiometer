
int maxPotValue = 1024;
int quarterPotValue = maxPotValue/4;
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
  Serial.println(potValue);
  Serial.println("\n");

  if (potValue >= maxPotValue*2/3){
    //red section
    redOut = potValue - maxPotValue*2/3;
    greenOut = quarterPotValue - redOut;
    blueOut = 0;
    
  }
  else if (potValue >= maxPotValue*1/3){
    //green section
    redOut = 0;
    greenOut = potValue - maxPotValue*1/3;
    blueOut = quarterPotValue - greenOut;
  }
  else {
    //blue section
    greenOut = 0;
    blueOut = potValue;
    redOut = quarterPotValue - blueOut;
  }
  Serial.println( redOut);
  Serial.println(greenOut);
  Serial.println(blueOut);
  Serial.println("\n\n\n");
  analogWrite(redPin, redOut);
  analogWrite(greenPin, greenOut);
  analogWrite(bluePin, blueOut);
  delay(50);
}
