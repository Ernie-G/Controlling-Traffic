//Define buttons and pins
#define westButton 3
#define eastButton 13
#define wR 2
#define wY 1
#define wG 0
#define eR 12
#define eY 11
#define eG 10

#define yellowBlinkTime 500

boolean trafficWest = true; //west = true, east = false
int flowTime = 10000; //time to let traffic through bridge, 10s
int changeDelay = 3000; //time between light color changes

void setup() {
  // put your setup code here, to run once:
  //Set I/O Pins
  pinMode(westButton, INPUT);
  pinMode(eastButton, INPUT);
  pinMode(wR, OUTPUT);
  pinMode(wY, OUTPUT);
  pinMode(wG, OUTPUT);
  pinMode(eR, OUTPUT);
  pinMode(eY, OUTPUT);
  pinMode(eG, OUTPUT);
  //Set Defualt States
  digitalWrite(wR, LOW);
  digitalWrite(wY, LOW);
  digitalWrite(wG, HIGH);
  digitalWrite(eR, HIGH);
  digitalWrite(eY, LOW);
  digitalWrite(eG, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(westButton) == HIGH && digitalRead(wG) == HIGH) {
    
  } 
  else if(digitalRead(westButton) == HIGH) {
    trafficWest = true;
    delay(flowTime);
    digitalWrite(eG, LOW);
    digitalWrite(eY, HIGH);
    delay(changeDelay);
    digitalWrite(eY, LOW);
    digitalWrite(eR, HIGH);
    delay(changeDelay);
    for(int i = 0; i < 5; i++) {
      digitalWrite(wY, LOW);
      delay(yellowBlinkTime);
      digitalWrite(wY, HIGH);
      delay(yellowBlinkTime);
    }
    digitalWrite(wY, LOW);
    digitalWrite(wR, LOW);
    digitalWrite(wG, HIGH);
  }


if(digitalRead(eastButton) == HIGH && digitalRead(eG) == HIGH) {
    
  } 
  else if(digitalRead(eastButton) == HIGH) {
    trafficWest = false;
    delay(flowTime);
    digitalWrite(wG, LOW);
    digitalWrite(wY, HIGH);
    delay(changeDelay);
    digitalWrite(wY, LOW);
    digitalWrite(wR, HIGH);
    delay(changeDelay);
    for(int i = 0; i < 5; i++) {
      digitalWrite(eY, LOW);
      delay(yellowBlinkTime);
      digitalWrite(eY, HIGH);
      delay(yellowBlinkTime);
    }
    digitalWrite(eY, LOW);
    digitalWrite(eR, LOW);
    digitalWrite(eG, HIGH);
  }
}








