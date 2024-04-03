#include <ESP8266WiFi.h>
#include "ThingSpeak.h"  // always include thingspeak header file after other header files and custom macros
#include "PMS.h"
#include "SoftwareSerial.h"

const char *ssid = "Hotspot";            // replace with your WiFi SSID
const char *pass = "W63838}h";            // replace with your WiFi password
unsigned long myChannelNumber = 2422128;
const char * myWriteAPIKey = "X1FECRQ15FQ5Y2TG";
WiFiClient  client;

int temperature;
int humidity;
int airQuality;
String windDirection;
float windSpeed;
float PM1;
float PM25;
float PM10;

unsigned long previousMillis = 0;
const long interval = 15000;  // 15 seconds

// PMS
SoftwareSerial pmsSerial(D2, D3); // RX, TX
PMS pms(pmsSerial);
PMS::DATA data;

void sendToThingSpeak() {
  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.setField(3, airQuality);
  ThingSpeak.setField(4, windSpeed);
  ThingSpeak.setField(6, PM1);
  ThingSpeak.setField(7, PM25);
  ThingSpeak.setField(8, PM10);
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if (x == 200) {
    Serial.println("Channel update successful.");
  } else {
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
}

void setup() {
  Serial.begin(9600);
  pmsSerial.begin(9600);   
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  ThingSpeak.begin(client);
  Serial.println("WiFi connected");
  pms.passiveMode();   
  delay(500);
}

void loop() {
  PMS();
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    if (command.startsWith("T: ")) {
      temperature = command.substring(3).toInt();
    } 
    if (command.startsWith("H: ")) {
      humidity = command.substring(3).toInt();
    }
    if (command.startsWith("A: ")) {
      airQuality = command.substring(3).toInt();
    }
    if (command.startsWith("D: ")) {
      windDirection = command.substring(3).toInt();
    }
    if (command.startsWith("S: ")) {
      windSpeed = command.substring(3).toFloat();
    }
    Serial.print("temperature: ");
    Serial.print(temperature);
    Serial.print("  humidity: ");
    Serial.print(humidity);
    Serial.print("  airQuality: ");
    Serial.print(airQuality);
    Serial.print("  windSpeed: ");
    Serial.print(windSpeed);
    Serial.print("  PM1: ");
    Serial.print(PM1);
    Serial.print("  PM2.5: ");
    Serial.print(PM25);
    Serial.print("  PM10: ");
    Serial.println(PM10);
  }
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    sendToThingSpeak();
  }
}
void PMS(){
  pms.wakeUp();
  delay(1000);
  pms.requestRead();
  if (pms.readUntil(data)){
    PM1 = data.PM_AE_UG_1_0;
    PM25 = data.PM_AE_UG_2_5;
    PM10 = data.PM_AE_UG_10_0;
    
    Serial.print("PM1: ");
    Serial.println(data.PM_AE_UG_1_0);
    Serial.print("PM2.5: ");
    Serial.println(data.PM_AE_UG_2_5);
    Serial.print("PM10: ");
    Serial.println(data.PM_AE_UG_10_0);
  }else{
    Serial.println("No data from PMS device.");
  }
  pms.sleep();
  
}