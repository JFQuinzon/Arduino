#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int moisture = 0;

int redLED = 9;
int greenLED = 8;
int buzzerPin = 7;
int GNDLed = 6;
int GNDBuzzer = 5;

float sinVal;
int toneVal;

void setup()
{
  Serial.begin(9600);
  
  pinMode(A1, INPUT);
  
  pinMode(A0, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(GNDLed, OUTPUT);
  pinMode(GNDBuzzer, OUTPUT);
  
  lcd.begin();
  lcd.setBacklight(1);
}

void loop()
{
  digitalWrite(GNDLed, LOW);
  digitalWrite(GNDBuzzer, LOW);

  digitalWrite(A0, HIGH);
  delay(10); 
  int moistureSensorValue = analogRead(A1);
  digitalWrite(A0, LOW);
  Serial.println(moistureSensorValue);
  
  int moisturePercentage = getMoisturePercentage(moistureSensorValue);
  displayMoisture(moisturePercentage);

  
  if (moisturePercentage <= 9){
  	digitalWrite(greenLED, HIGH);
  	digitalWrite(redLED, LOW);
    tone(buzzerPin, 1000);
    delay(200);
    noTone(buzzerPin);
  }else{
  	digitalWrite(redLED, HIGH);
  	digitalWrite(greenLED, LOW);
  }
  
  
  delay(100); 
}

int getMoisturePercentage(int sensorValue) {
  if (sensorValue > 600) {
    return 100; 
  }
  return map(sensorValue, 0, 600, 0, 100);
}

void displayMoisture(int moisturePercentage){
  lcd.setCursor(0,0);
  lcd.print("MOISTURE CONTENT");
  lcd.setCursor(0,1);
  int spaces = (16 - (String(moisturePercentage) + "%").length()) / 2;
  for (int i = 0; i < spaces; i++) {
    lcd.print(" ");
  }
  lcd.print(moisturePercentage);
  lcd.print("%       ");
  
}