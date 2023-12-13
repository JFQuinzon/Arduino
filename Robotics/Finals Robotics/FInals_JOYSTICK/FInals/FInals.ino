#include <Servo.h>
const int servoClaw = 2; //blue
const int servo3 = 3;    //green
const int servoBase = 4; //yellow
const int servo2 = 5;    //orange

const int motorIn1 = 11;
const int motorIn2 = 12;

const int joystickOneX = A0;
const int joystickOneY = A1;
const int joystickTwoY = A2;
const int joystickTwoGrab = 6;

const int buttonSwitch = 8;
const int buttonForward = 9;
const int buttonBackward = 10;

Servo baseServo;
Servo twoServo;
Servo threeServo;
Servo clawServo;

int buttonForwardState1 = HIGH;
int buttonBackwardState2 = HIGH;

int servoBasePosition = 90; 
int servo2Position = 90; 
int servo3Position = 90; 
int servoClawPosition = 50; 

void setup() {
  Serial.begin(9600);
  pinMode(motorIn1, OUTPUT);  
  pinMode(motorIn2, OUTPUT);  

  pinMode(buttonSwitch, INPUT_PULLUP);
  pinMode(buttonForward, INPUT_PULLUP);
  pinMode(buttonBackward, INPUT_PULLUP);
  pinMode(joystickTwoGrab, INPUT_PULLUP);

  baseServo.attach(servoBase);
  twoServo.attach(servo2);
  threeServo.attach(servo3);
  clawServo.attach(servoClaw);

  baseServo.write(servoBasePosition);
  twoServo.write(servo2Position);
  threeServo.write(servo3Position);
  clawServo.write(50);
}

void loop() {
  buttonForwardState1 = digitalRead(buttonForward);
  buttonBackwardState2 = digitalRead(buttonBackward);
  int bts1 = (buttonForwardState1 == LOW) ? 1 : 0;  // Button press
  int bts2 = (buttonBackwardState2 == LOW) ? 1 : 0;  // Button press
  
  if (bts1) {
    digitalWrite(motorIn1, HIGH);
    digitalWrite(motorIn2, LOW);
    Serial.println(bts1);
  } else {
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, LOW);
  }
  if (bts2) {
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, HIGH);
    Serial.println(bts2);
  } else {
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, LOW);
  }

  // BASE SERVO
  int joystickOneXValue = analogRead(joystickOneX);
  if (joystickOneXValue <= 10 && servoBasePosition < 180) {
    servoBasePosition = servoBasePosition + 1;
    baseServo.write(servoBasePosition);
    Serial.println(joystickOneXValue);
    delay(5);
  } else if (joystickOneXValue >= 1000 && servoBasePosition > 0) {
    servoBasePosition = servoBasePosition - 1;
    baseServo.write(servoBasePosition);
    Serial.println(joystickOneXValue);
    delay(5);
  } else {
    baseServo.write(servoBasePosition);
  }

  // 2nd SERVO
  int joystickOneYValue = analogRead(joystickOneY);
  if (joystickOneYValue <= 10 && servo2Position > 0) {
    servo2Position = servo2Position - 1;
    twoServo.write(servo2Position);
    Serial.println(joystickOneYValue);
    delay(5);
  } else if (joystickOneYValue >= 1000 && servo2Position < 180) {
    servo2Position = servo2Position + 1;
    twoServo.write(servo2Position);
    Serial.println(joystickOneYValue);
    delay(5);
  } else {
    twoServo.write(servo2Position);
  }

  // 3rd SERVO
  int joystickTwoYValue = analogRead(joystickTwoY);
  Serial.println(joystickTwoYValue);
  if (joystickTwoYValue <= 10 && servo3Position < 180) {
    servo3Position = servo3Position + 1;
    threeServo.write(servo3Position);
    Serial.println(joystickTwoYValue);
    delay(5);
  } else if (joystickTwoYValue >= 1000 && servo3Position > 0) {
    servo3Position = servo3Position - 1;
    threeServo.write(servo3Position);
    Serial.println(joystickTwoYValue);
    delay(5);
  } else {
    threeServo.write(servo3Position);
  }

  // Claw SERVO
  int joystickTwoGrabValue = digitalRead(buttonSwitch);
  int claw = (joystickTwoGrabValue == LOW) ? 1 : 0;  // Button press
  if (claw) {
    clawServo.write(0);
  } else {
    clawServo.write(50);
  }

}
