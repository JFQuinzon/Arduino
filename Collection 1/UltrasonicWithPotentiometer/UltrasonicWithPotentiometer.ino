#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// PINS
int triggerPin = 2; 
int echoPin = 3;
int potPin = A0;

int cm = 0;
int minDistance = 0;
int maxDistance = 500;

long readUltrasonicDistance(int triggerPin, int echoPin){
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  lcd.begin();
  lcd.backlight();
}

void loop() {
  int distanceLimit = map(analogRead(potPin), 0, 1023, minDistance,maxDistance);
  cm = 0.12523 * readUltrasonicDistance(triggerPin, echoPin);

  lcd.setCursor(3, 1);
  lcd.print("Limit:       ");
  lcd.setCursor(10, 1);
  lcd.print(distanceLimit);
  lcd.setCursor(14, 1);
  lcd.print("cm");

  if (cm <= distanceLimit) {
    lcd.setCursor(0, 0);
    lcd.print("Distance:       ");
    lcd.setCursor(10, 0);
    lcd.print(cm);
    lcd.setCursor(14, 0);
    lcd.print("cm");
  }else {
    lcd.setCursor(0, 0);
    lcd.print("Distance: XXX");
  }
  delay(250);
}
