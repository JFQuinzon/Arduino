
#include <Servo.h>

const int servoPin1 = 5;  // Servo for base
const int servoPin2 = 6;  // Servo for middle
const int servoPin3 = 9;  // Servo for top
const int servoPin4 = 10; // Servo for claw

  const int potPin1 = A0;
const int potPin2 = A1;
const int potPin3 = A2;
const int potPin4 = A3;

const int joyXPin = A4;       // Joystick X-axis pin
const int joyYPin = A5;       // Joystick Y-axis pin
const int joyButtonPin = 4;   // Joystick button pin
const int switchButtonPin = 7; // Button to switch control

int joyXValue, joyYValue, joyButtonState = HIGH;  

Servo myServo1;
Servo myServo2;
Servo myServo3;
Servo myServo4;

int currentServoAngle1 = 90; // Initial angle for servo1 (base)
int currentServoAngle2 = 90; // Initial angle for servo2 (middle)
int currentServoAngle3 = 65; // Initial angle for servo3 (top)
bool isJoystickControl = true; // Flag to track control method

void setup()
{
  Serial.begin(9600);
  myServo1.attach(servoPin1);
  myServo2.attach(servoPin2);
  myServo3.attach(servoPin3);
  myServo4.attach(servoPin4);

  pinMode(joyButtonPin, INPUT_PULLUP);   // Set joystick button pin as input with internal pull-up resistor
  pinMode(switchButtonPin, INPUT_PULLUP); // Set switch button pin as input with internal pull-up resistor
}

void loop()
{
  // Read joystick values
  joyXValue = analogRead(joyXPin);
  joyYValue = analogRead(joyYPin);
  joyButtonState = digitalRead(joyButtonPin);

  // Read switch button state
  int switchButtonState = digitalRead(switchButtonPin);

  Serial.print(joyXValue);
  Serial.println(joyYValue);

  // Check if the switch button is pressed
  if (switchButtonState == LOW)
  {
    // Change the control method when the switch button is pressed
    isJoystickControl = !isJoystickControl;
    delay(500); // Debounce delay
  }

  if (isJoystickControl)
  {
    // Control the arm using joystick

    // Map joystick values to servo angles
    int targetServoAngle1 = map(joyXValue, 0, 1023, 0, 180); // Map X to servo1 (base)
    int targetServoAngle2 = map(joyYValue, 0, 1023, 0, 180); // Map Y to servo2 (middle)
    int targetServoAngle3 = map(joyYValue, 0, 1023, 40, 90);  // Map Y to servo3 (top)

    // Gradually move towards the target angles
    currentServoAngle1 = moveToTargetAngle(currentServoAngle1, targetServoAngle1, 2);
    currentServoAngle2 = moveToTargetAngle(currentServoAngle2, targetServoAngle2, 2);
    currentServoAngle3 = moveToTargetAngle(currentServoAngle3, targetServoAngle3, 2);

    // Control servos with smoothed angles
    myServo1.write(currentServoAngle1);
    myServo2.write(currentServoAngle2);
    myServo3.write(currentServoAngle3);

    int value_claw = (joyButtonState == LOW) ? 1 : 0; // Button press
    if (value_claw)
    {
      myServo4.write(0);
    }
    else
    {
      myServo4.write(37);
    }

    delay(15); // Add a small delay to avoid jitter
  }
  else
  {
    // Control the arm using potentiometers

    // FOR SERVO1 BASE
    int potValue1 = analogRead(potPin1);
    int servoAngle1 = map(potValue1, 110, 800, 180, 0);
    myServo1.write(servoAngle1);

    // FOR SERVO2 MID1
    int potValue2 = analogRead(potPin2);
    int servoAngle2 = map(potValue2, 1023, 600, 0, 180);
    myServo2.write(servoAngle2);

    // FOR SERVO3 MID2
    int potValue3 = analogRead(potPin3);
    int servoAngle3 = map(potValue3, 170, 880, 180, 0);
    myServo3.write(servoAngle3);

    // FOR SERVO4 Claw
    int potValue4 = analogRead(potPin4);
    int value_claw = (potValue4 > 511) ? 1 : 0;

    if (value_claw)
    {
      myServo4.write(0);
    }
    else
    {
      myServo4.write(37);
    }
  }
}

// Function to smoothly move towards a target angle
int moveToTargetAngle(int currentAngle, int targetAngle, int stepSize)
{
  if (currentAngle < targetAngle)
  {
    currentAngle += stepSize;
  }
  else if (currentAngle > targetAngle)
  {
    currentAngle -= stepSize;
  }

  // Ensure the angle is within valid limits
  currentAngle = constrain(currentAngle, 0, 180);

  return currentAngle;
}
