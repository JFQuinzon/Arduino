#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include "DHT.h"
#define DHTTYPE DHT11 
#include <Servo.h>

// PINS
const int led=13;
const int soil=A0;
const int sound=A1;
const int greenLed = 10;  
const int redLed = 11;    
const int DHTPin = 2;
const int BuzzerPIN = 3;

int cm = 0;

DHT dht(DHTPin, DHTTYPE);

Servo servo_9;

bool lightMode = false; // INITIALIZE LIGHT STATUS to OFF

long readUltrasonicDistance(int triggerPin, int echoPin){
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  servo_9.attach(9, 500, 2500);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
   
  lcd.begin();
  lcd.backlight();
  
  pinMode(BuzzerPIN, OUTPUT);
  dht.begin();
  pinMode(led, OUTPUT);
  pinMode(sound, INPUT);
}

void loop()
{
  int level;
  level = analogRead(soil); 
  
  Serial.print("Water: ");
  Serial.println(level);
  // IF LEVEL is lessthan 50 HYDRATED
  if (level <= 50){
    lcd.setCursor(0, 0);
    lcd.print("    Hydrated    ");
    digitalWrite(BuzzerPIN, LOW);
  }else if(level >= 1000){ 
  // IF LEVEL is greater 1000 DEHYDRATED
    lcd.setCursor(0, 0);
    lcd.print("   Dehydrated   ");
    digitalWrite(BuzzerPIN, HIGH);
    delay(50);
    digitalWrite(BuzzerPIN, LOW);
    delay(50);
  }

  int humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // FOR SETTING CURSOR POSITION AND PRINT TEXT
  lcd.setCursor(0, 1);
  lcd.print("H: ");
  lcd.setCursor(2, 1);
  lcd.print(humidity);
  lcd.setCursor(4, 1);
  lcd.print("%");
  lcd.setCursor(11, 1);
  lcd.print("T: ");
  lcd.setCursor(13, 1);
  lcd.print(temperature);
  lcd.setCursor(15, 1);
  lcd.print("C");


  int soundsens = analogRead(sound);
  Serial.print("Sound: ");
  Serial.println(soundsens);
  if (soundsens >= 100){
    lightMode = !lightMode;
  }
  if (lightMode) {
    digitalWrite(led, HIGH);
  }else{ 
    digitalWrite(led, LOW);
  }

  cm = 0.12523 * readUltrasonicDistance(7, 6);
  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.println("cm");

  // Display distance on LEDs
  if (cm > 50) {
    digitalWrite(greenLed, HIGH);  // Green LED on for high distance
    digitalWrite(redLed, LOW);     // Red LED off
    servo_9.write(150);            // SET ANGLE to 150
  } else {
    digitalWrite(greenLed, LOW);   // Green LED off
    digitalWrite(redLed, HIGH);    // Red LED on for low distance
    servo_9.write(110);            // SET ANGLE to 110
    delay(1000);
  }
}
  