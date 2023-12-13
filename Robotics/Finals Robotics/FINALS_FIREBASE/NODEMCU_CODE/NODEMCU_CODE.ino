#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <Servo.h>

#define FIREBASE_HOST "roboticsfinals-default-rtdb.asia-southeast1.firebasedatabase.app"
#define FIREBASE_AUTH "bykUJn1KMjrhq04zeg8aIgkewD1WqUbgPsyI9ak2"
#define WIFI_SSID "JFRANCISQ-PC"
#define WIFI_PASSWORD "12345678"

SoftwareSerial NodeMCU(D2,D3);

const int servoClaw = D5; //blue
const int servo3 = D6;    //green
const int servoBase = D7; //yellow
const int servo2 = D8;    //orange
Servo baseServo;
Servo twoServo;
Servo threeServo;
Servo clawServo;

String currentActuator = "STOP";
String prevActuator = "STOP";

String currentClaw = "GRAB";
String prevClaw = "GRAB";

int currentJoystick1X = 0;
int prevJoystick1X = 0;

int currentJoystick1Y = 0;
int prevJoystick1Y = 0;

int currentJoystick2Y = 0;
int prevJoystick2Y = 0;

int servoBasePosition = 90; 
int servo2Position = 90; 
int servo3Position = 90; 

void setup() {
  Serial.begin(9600);
	NodeMCU.begin(4800);	
	pinMode(D2,INPUT);
	pinMode(D3,OUTPUT);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to: ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.set("Actuator", "STOP");
  Firebase.set("Claw", "GRAB");
  Firebase.set("Joystick1X", 90);
  Firebase.set("Joystick1Y", 90);
  Firebase.set("Joystick2Y", 90);
  
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
  currentActuator = Firebase.getString("Actuator");
  currentClaw = Firebase.getString("Claw");
  currentJoystick1X = Firebase.getInt("Joystick1X");
  currentJoystick1Y = Firebase.getInt("Joystick1Y");
  currentJoystick2Y = Firebase.getInt("Joystick2Y");
  
  if (currentActuator != prevActuator) {
    NodeMCU.println(currentActuator);
    prevActuator = currentActuator;
  }

  if (currentClaw != prevClaw) {
    if (currentClaw == "GRAB") {
      clawServo.write(50);
    }else if (currentClaw == "RELEASE") {
      clawServo.write(0);
    } 
  }

  if (currentJoystick1X != prevJoystick1X ) {
    servoBasePosition = currentJoystick1X;
    baseServo.write(servoBasePosition);
  }

  if (currentJoystick1Y != prevJoystick1Y) {
    servo2Position = currentJoystick1Y;
    twoServo.write(servo2Position);
  }

  if (currentJoystick2Y != prevJoystick2Y) {
    servo3Position = currentJoystick2Y;
    threeServo.write(servo3Position);
  }

}











