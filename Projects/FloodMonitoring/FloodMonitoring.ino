#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <ESP8266WebServer.h>
#include <Wire.h>
#include <NewPing.h>

// ULTRASONIC =======
  NewPing sonar(16, 15, 500); //trig 1, echo 11, max distance 500cm

const char* ssid = "NodeMCU_ESP8266";
const char* password = "goodluck";


unsigned int localPort = 2000;
IPAddress DestinationIP(192, 168, 4, 2);  //--> If the Destination IP is 192,168,4,2 then you can use the Destination 192,168,4,2 or 192,168,4,255
WiFiUDP udp;

String inString;
char replyBuffer[50];
String strCon;

#define sw1 13
#define sw2 12
#define sw3 2
#define rain 0

#define flow 3

#define Relay_1 14
#define Relay_2 4
#define Relay_3 5
// #define Relay_4 16

long flowmeter;

int tone1 = 0;
int tone2 = 0;
int tone3 = 0;

int X;
int Y;
float TIME = 0;
float FREQUENCY = 0;
float WATER = 0;
float LS = 0;
const float mmPerPulse = 0.173;  //put here the value of rain in mm for each movement of the bucket
String c = "";

float mmTotali = 0;
int sensore = 0;
int statoPrecedente = 0;

long prev;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  Serial.println("");
  IPAddress apip = WiFi.softAPIP();
  Serial.print("Connect your wifi laptop/mobile phone to this NodeMCU Access Point : ");
  Serial.println(ssid);
  Serial.print("NodeMCU IP : ");
  Serial.println(apip);
  //----------------------------------------
  udp.begin(localPort);
  Serial.print("Local Port : ");
  Serial.println(udp.localPort());
  delay(2000);

  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);
  pinMode(rain, INPUT);
  pinMode(flow, INPUT);
  pinMode(Relay_1, OUTPUT);
  pinMode(Relay_2, OUTPUT);
  pinMode(Relay_3, OUTPUT);
  // pinMode(Relay_4, OUTPUT);
  digitalWrite(Relay_1, HIGH);
  digitalWrite(Relay_2, HIGH);
  digitalWrite(Relay_3, HIGH);
  // digitalWrite(Relay_4, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensore = digitalRead(rain);
  int level1 = digitalRead(sw1);
  int level2 = digitalRead(sw2);
  int level3 = digitalRead(sw3);
  float distance_cm = sonar.ping_cm();
  float distance_m = distance_cm / 100.0; 

  if (level1 == 1 && level2 == 0 && level3 == 0) {
    flowmeter = random(11);
    digitalWrite(Relay_1, LOW);
    digitalWrite(Relay_2, HIGH);
    digitalWrite(Relay_3, HIGH);
    // digitalWrite(Relay_4, LOW);
    // delay(300);
    // digitalWrite(Relay_4, HIGH);
    // delay(5000);
    // digitalWrite(Relay_4, LOW);
    // delay(300);
    // digitalWrite(Relay_4, HIGH);
  }
  if (level1 == 1 && level2 == 1 && level3 == 0) {
    flowmeter = random(11);
    digitalWrite(Relay_2, LOW);
    digitalWrite(Relay_1, HIGH);
    digitalWrite(Relay_3, HIGH);
    // digitalWrite(Relay_4, LOW);
    // delay(300);
    // digitalWrite(Relay_4, HIGH);
    // delay(5000);
    // digitalWrite(Relay_4, LOW);
    // delay(300);
    // digitalWrite(Relay_4, HIGH);
  }
  if (level1 == 1 && level2 == 1 && level3 == 1) {
    flowmeter = random(11);
    digitalWrite(Relay_1, HIGH);
    digitalWrite(Relay_2, HIGH);

    digitalWrite(Relay_3, LOW);
    delay(5000);
    digitalWrite(Relay_3, HIGH);
    delay(300);
  }
  if (level1 == 0 && level2 == 0 && level3 == 0) {
    flowmeter = 0;
    digitalWrite(Relay_1, HIGH);
    digitalWrite(Relay_2, HIGH);
    digitalWrite(Relay_3, HIGH);
  }

  X = pulseIn(flow, HIGH);
  Y = pulseIn(flow, LOW);
  TIME = X + Y;
  FREQUENCY = 1000000 / TIME;
  WATER = FREQUENCY / 7.5;
  LS = WATER / 60;
  Serial.print(level1);
  Serial.print("-");
  Serial.print(level2);
  Serial.print("-");
  Serial.print(level3);
  Serial.print("-");
  Serial.print(flowmeter);
  Serial.print("-");
  if (sensore != statoPrecedente) {
    mmTotali = mmTotali + mmPerPulse;
  }
  Serial.print(mmTotali);
  Serial.print("-");
  Serial.println(distance_m);
  
  c = String(level1) + "," + String(level2) + "," + String(level3) + "," + String(flowmeter) + "," + String(mmTotali) + "," + String(distance_m)  ;
  c.toCharArray(replyBuffer, 50);
  udp.beginPacket(DestinationIP, 2000);
  udp.write(replyBuffer);
  udp.endPacket();



  delay(100);
  statoPrecedente = sensore;
}