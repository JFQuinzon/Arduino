#include <Servo.h>
const int servoBase = 13;
const int servoClaw = 7;
const int joystickY = A0;
const int joystickX = A1;

Servo baseServo;
Servo clawServo;

int servoPosition = 90; 
int servoPositionClaw1 = 90; 
int servoPositionClaw2 = 90; 

int m1a = 2;
int m1b = 3;
int m2a = 4;
int m2b = 5;

int roller1 = 9;
int roller2 = 10;
int claw = 12;

int buttonRollerState1 = HIGH;
int buttonRollerState2 = HIGH;
int buttonClamState = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(m1a, OUTPUT);  
  pinMode(m1b, OUTPUT);  
  pinMode(m2a, OUTPUT); 
  pinMode(m2b, OUTPUT);

  pinMode(roller1, INPUT_PULLUP);
  pinMode(roller2, INPUT_PULLUP);
  pinMode(claw, INPUT_PULLUP);
  
  baseServo.attach(servoBase);
  clawServo.attach(servoClaw);

  clawServo.write(50);
}

void loop() {

  int joystickXValue = analogRead(joystickX);
  int joystickYValue = analogRead(joystickY);

  if (joystickXValue == 0) {
    servoPosition = servoPosition - 1;
    delay(20);
  } else if (joystickXValue == 1023) {
    servoPosition = servoPosition + 1;
    delay(20);
  } else {
    baseServo.write(servoPosition);
  }

  // Control the servo motor
  baseServo.write(servoPosition);

  if (joystickYValue == 0) {
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, HIGH);
  } else if (joystickYValue == 1023) {
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
  } else {
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
  }
  buttonRollerState1 = digitalRead(roller1);
  buttonRollerState2 = digitalRead(roller2);
  int bts1 = (buttonRollerState1 == LOW) ? 1 : 0;  // Button press
  int bts2 = (buttonRollerState2 == LOW) ? 1 : 0;  // Button press
  
  if (bts1) {
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    Serial.print("bts1");
    Serial.println(bts1);
  } else {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
  }

  if (bts2) {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, HIGH);
    Serial.print("bts2");
    Serial.println(bts2);
  } else {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
  }

  buttonClamState = digitalRead(claw);
  int claw1 = (buttonClamState == LOW) ? 1 : 0;  // Button press
  
  if (claw1) {
    clawServo.write(50);
    Serial.println("claw");
  } else {
    clawServo.write(20);
    Serial.println("unclaw");
  }
  
}
