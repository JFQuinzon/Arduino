#include "LedControl.h"
#include "binary.h"
#include <Servo.h>

const int IR_PIN = 4;
const int SERVO_PIN = 5;
Servo servoMotor;

LedControl lc=LedControl(11,13,10,2);

int m1a = 6;
int m1b = 7;
int m2a = 8;
int m2b = 9;

int FrontLight = A4;
int BackLight = A5;
int BUZZER_PIN = 12;
int tiltSwitchPin = A1; // connect the tilt switch to pin 6
int waterSensorPinA0 = A0; // connect the water sensor to analog pin A0

int threshold = 500; // set the water level threshold
int tiltThreshold = 1000;
bool buzz = false;
bool eyes = false;
bool equip = false;
char command;


void setup() 
{       
  Serial.begin(9600);
  pinMode(m1a, OUTPUT);  // Digital pin 10 set as output Pin
  pinMode(m1b, OUTPUT);  // Digital pin 11 set as output Pin
  pinMode(m2a, OUTPUT);  // Digital pin 12 set as output Pin
  pinMode(m2b, OUTPUT);  // Digital pin 13 set as output Pin
  pinMode(FrontLight, OUTPUT);
  pinMode(BackLight, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(tiltSwitchPin, INPUT_PULLUP);

  analogWrite(FrontLight, 0);
  analogWrite(BackLight, 0);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW); 
  Stop();
  
  int devices=lc.getDeviceCount();
  for(int address=0;address<devices;address++) {
    lc.shutdown(address,false);
    lc.setIntensity(address,8);
    lc.clearDisplay(address);
  }

    // Set up the IR sensor pin as an input
  pinMode(IR_PIN, INPUT);

  // Set up the servo motor pin as an output
  servoMotor.attach(SERVO_PIN);
}

void loop(){
  if (eyes == false) {
    Idle();
  }
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Serial.println(command);
    if (command != 'S'){
      switch(command){
      case 'F':
        eyes = true;
        angry();
        forward();
        break;
      case 'B':
        eyes = true;
        lookBack();
        back();
        break;
      case 'L':
        eyes = true;
        lookLeft(); 
        left();
        break;
      case 'R':
        eyes = true;
        lookRight(); 
        right();
        break;
      case 'I':
        eyes = true;
        forwardRight();
        lookRight(); 
        right();
        break;
      case 'G':
        eyes = true;
        forwardLeft();
        lookLeft(); 
        break;
      case 'J':
        eyes = true;
        backwardRight();
        lookLeft(); 
        
        break;
      case 'H':
        eyes = true;
        backwardLeft();
        lookRight(); 
        break;
      }

    if (command == 'W'){
      // Front Lights on
      analogWrite(FrontLight, 255);
    }else if (command == 'w'){
      // Front Lights off
      analogWrite(FrontLight, 0);
    }
    // Back Light
    if (command == 'U'){
      // Back Lights on
      analogWrite(BackLight, 255);
    }else if (command == 'u'){
      // Back Lights off
      analogWrite(BackLight, 0);
    }

    // SIREN
    if (command == 'V') {
      // tone(BUZZER_PIN, 440);
      buzz = true;
    } else if (command == 'v') {
      // noTone(BUZZER_PIN); // turn off horn tone
      buzz = false;
    }

    if (command == 'X') {
      equip = true;
    } else if (command == 'x') {
      equip = false;
    }
    }else{
      Stop(); 
      Idle();
    }
  }

  if (buzz){
    tone(BUZZER_PIN, 440);
  }else{
    int waterLevel = analogRead(waterSensorPinA0);
    int tiltValue = analogRead(tiltSwitchPin);
    
    if (waterLevel > threshold) {
      Sound();
    }else if (tiltValue < tiltThreshold) { 
      Sound();
    }
    else {
      noTone(BUZZER_PIN);
    }    
  }

  if (equip){
    int irValue = digitalRead(IR_PIN);
    Serial.println(irValue);
    if (irValue == LOW) {
      servoMotor.write(90);
    }
  }else {
    servoMotor.write(0);
  }
  
}

byte idle[8] = {
  0x3c,0x42,0x42,0x42,0x5a,0x5a,0x42,0x3c
};

byte angryleft[8] = {
  0x40, 0x60, 0x50, 0x48, 0x54, 0x5A, 0x42, 0x3C
};
byte angryright[8] = {
  0x02,0x06,0x0a,0x12,0x2a,0x5a,0x42,0x3c
};

byte lookleft[8] = { 
  0x1e, 0x21, 0x21, 0x21, 0x27, 0x27, 0x21, 0x1e
};
byte lookright[8] = { 
  0x78, 0x84, 0x84, 0x84, 0xE4, 0xE4, 0x84, 0x78 
};
byte lookback[8] = {
  0x3c,0x42,0x5a,0x5a,0x42,0x42,0x42,0x3c
};



void angry() {
  for (int j = 0; j < 8; j++) {
    lc.setRow(0, j, angryleft[j]);
    lc.setRow(1, j, angryright[j]);
  }
}

void lookLeft() {
  for (int j = 0; j < 8; j++) {
    lc.setRow(0, j, lookleft[j]);
    lc.setRow(1, j, lookleft[j]);
  }
}
void lookRight() {
  for (int j = 0; j < 8; j++) {
    lc.setRow(0, j, lookright[j]);
    lc.setRow(1, j, lookright[j]);
  }
}
void lookBack() {
  for (int j = 0; j < 8; j++) {
    lc.setRow(0, j, lookback[j]);
    lc.setRow(1, j, lookback[j]);
  }
}
void Idle() {
  for (int j = 0; j < 8; j++) {
    lc.setRow(0, j, idle[j]);
    lc.setRow(1, j, idle[j]);
  }
}

void forward()
{
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW); 
}

void back()
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH); 
}

void left()
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
}

void right()
{
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW); 
} 

void Stop()
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW); 
}

void forwardRight()
{
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
}

void forwardLeft()
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW); 
}

void backwardRight()
{ 
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
}

void backwardLeft()
{ 
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW); 
}

unsigned long previousMillis = 0;
const long interval = 50; // blink interval in milliseconds
bool buzzerOn = false;
unsigned long previousStateChangeMillis = 0;
const long stateChangeInterval = 50; 

void Sound()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    buzzerOn = !buzzerOn;
    if (buzzerOn) {
      tone(BUZZER_PIN, 1500);
    } else {
      // noTone(buzzerPin);
      tone(BUZZER_PIN, 500);
    }
    previousStateChangeMillis = currentMillis;
  }
}
