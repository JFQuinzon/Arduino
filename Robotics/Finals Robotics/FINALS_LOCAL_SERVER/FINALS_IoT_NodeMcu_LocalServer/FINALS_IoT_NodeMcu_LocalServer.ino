#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <SoftwareSerial.h>
#include <Servo.h>
#include "PageIndex.h"

const char* ssid = "WobotWarm";  // your SSID
const char* password = "12345678"; // WIFI Password

ESP8266WebServer server(80);  // Server on port 80

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

void handleRoot() {
  String s = MAIN_page; // Read HTML contents from PageIndex.h
  server.send(200, "text/html", s); // Send web page
}

void setup() {
  Serial.begin(9600);
	NodeMCU.begin(4800);	
	pinMode(D2,INPUT);
	pinMode(D3,OUTPUT);

  delay(500);
  Serial.print("Configuring access point...");

  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  
  // Initialize Webserver
  server.on("/", HTTP_GET, handleRoot); 
  server.on("/setActuator", HTTP_GET, controlActuator);
  server.on("/setClaw", HTTP_GET,controlClaw);
  server.on("/setBase", HTTP_GET,controlBaseServo);
  server.on("/set2Servo", HTTP_GET,controlSecondServo);
  server.on("/set3Servo", HTTP_GET,controlThirdServo);
  server.begin();

  Serial.println("HTTP server started");

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
  server.handleClient();
}

void controlActuator() {
  String t_state = server.arg("ActStatus");
  if (t_state == "FORWARD") {
    currentActuator = "FORWARD";
  } else if (t_state == "STOP") {
    currentActuator = "STOP";
  } else if (t_state == "BACKWARD") {
    currentActuator = "BACKWARD";
  }

  if (currentActuator != prevActuator) {
    NodeMCU.println(currentActuator);
    prevActuator = currentActuator;
  }
   server.send(200, "text/plain", "");
}

void controlClaw() {
  String t_state = server.arg("ClawStatus");
  if (t_state == "GRAB") {
    clawServo.write(50);
  } else if (t_state == "RELEASE") {
    clawServo.write(0);
  }
  server.send(200, "text/plain", "");
}

void controlBaseServo() {
  String t_state = server.arg("BaseServoStatus");
  int val = t_state.toInt();
  if (val == -100 && servoBasePosition < 180) {
    servoBasePosition = servoBasePosition + 3;
    baseServo.write(servoBasePosition);
    delay(15);
  } else if (val == 100 && servoBasePosition > 0) {
    servoBasePosition = servoBasePosition - 3;
    baseServo.write(servoBasePosition);
    delay(15);
  } else {
    baseServo.write(servoBasePosition);
  }
  String response = String(servoBasePosition);
  Serial.println(val);
  server.send(200, "text/plain", response);
}

void controlSecondServo() {
  String t_state = server.arg("SecondServoStatus");
  int val = t_state.toInt();
  if (val == -100 && servo2Position < 180) {
    servo2Position = servo2Position + 3;
    twoServo.write(servo2Position);
    delay(15);
  } else if (val == 100 && servo2Position > 0) {
    servo2Position = servo2Position - 3;
    twoServo.write(servo2Position);
    delay(15);
  } else {
    twoServo.write(servo2Position);
  }
  String response = String(servo2Position);
  server.send(200, "text/plain", response);
}

void controlThirdServo() {
  String t_state = server.arg("ThirdServoStatus");
  int val = t_state.toInt();
  if (val == -100 && servo3Position > 0) {
    servo3Position = servo3Position - 3;
    threeServo.write(servo3Position);
    delay(15);
  } else if (val == 100 && servo3Position < 180) {
    servo3Position = servo3Position + 3;
    threeServo.write(servo3Position);
    delay(15);
  } else {
    threeServo.write(servo3Position);
  }
  String response = String(servo3Position);
  server.send(200, "text/plain", response);
}






