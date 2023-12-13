#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

SoftwareSerial NodeMCU(D2,D3);

void setup(){
	Serial.begin(9600);
	NodeMCU.begin(4800);	
	pinMode(D2,INPUT);
	pinMode(D3,OUTPUT);
}

void loop(){
	NodeMCU.println("1");
	delay(1000);
	NodeMCU.println("0");
	delay(1000);
}