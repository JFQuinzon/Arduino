#include <Servo.h>

// FOR SERVO1 BASE
const int servoPin1 = 5;       
const int potPin1 = A0;       
Servo myServo1;               
// FOR SERVO2 Middle
const int servoPin2 = 6;       
const int potPin2 = A1;       
Servo myServo2; 
// FOR SERVO3 Top
const int servoPin3 = 9;       
const int potPin3 = A2;  
Servo myServo3; 
// FOR SERVO4 Claw
const int servoPin4 = 10;       
const int potPin4 = A3;       
Servo myServo4; 

void setup() {
  Serial.begin(9600);
  myServo1.attach(servoPin1);  
  myServo2.attach(servoPin2);  
  myServo3.attach(servoPin3);  
  myServo4.attach(servoPin4);
}

void loop() {
  // FOR SERVO1 BASE
  int potValue1 = analogRead(potPin1); 
  int servoAngle1 = map(potValue1, 110, 800, 180, 0);  
  myServo1.write(servoAngle1);
  myServo1.write(servoAngle1);   

  // FOR SERVO2 MID1
  int potValue2 = analogRead(potPin2); 
  int servoAngle2 = map(potValue2, 1023, 600, 0, 180);  
  myServo2.write(servoAngle2);   
  myServo2.write(servoAngle2);   

  // FOR SERVO3 MID2 
  int potValue3 = analogRead(potPin3); 
  int servoAngle3 = map(potValue3, 170, 880, 180, 0);  
  myServo3.write(servoAngle3);   
  myServo3.write(servoAngle3); 

  // FOR SERVO4 Claw
  int potValue4 = analogRead(potPin4); 
  int value_claw;
  if(potValue4 > 511) {
    value_claw = 1;
  } else {
    value_claw = 0;
  }
  if(value_claw) {
    myServo4.write(0);
  } else {
    myServo4.write(50);
  }

}
