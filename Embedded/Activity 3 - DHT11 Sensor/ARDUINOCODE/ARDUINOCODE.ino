#include "DHT.h"
#define DHTTYPE DHT11
const int DHTPin = 2;
DHT dht(DHTPin, DHTTYPE);

void setup() {
  Serial.begin(9600);
  delay(100);
  dht.begin();
}

void loop() {
  int humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)){
    Serial.println("Failed to read from DHT Sensor");
  }else{
    Serial.print("H");
    Serial.println(humidity); 
    Serial.print("T");
    Serial.println(temperature);
  }
  delay(2000);
}
