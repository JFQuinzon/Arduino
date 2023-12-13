#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#include "DHT.h"

#define FIREBASE_HOST "midtermactivity-2-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "jH4KtjAkLIeGl7GW4pO5Qaof5PwW6lTVO67jzlBo"
#define WIFI_SSID "JFRANCISQ-PC"
#define WIFI_PASSWORD "12345678"

#define DHTPIN D2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);       

void setup() {
  Serial.begin(9600);
  delay(100);
  dht.begin();

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
  Firebase.set("/DHT11/Humidity", "0");
  Firebase.set("/DHT11/Temperature", "0");
}

void loop() {
  float h = dht.readHumidity();                                 // Read Humidity
  float t = dht.readTemperature();                              // Read temperature
  
  if (isnan(h) || isnan(t))                                     // Checking sensor working
  {                                   
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  } 

  Serial.print("Humidity: ");  
  Serial.print(h);
  String fireHumid = String(h) + String("%");                   //Humidity integer to string conversion
  
  Serial.print("%  Temperature: ");  
  Serial.print(t);  
  Serial.println("°C ");
  String fireTemp = String(t) + String("°C");                  //Temperature integer to string conversion
  delay(5000);
 
 
  Firebase.setString("/DHT11/Humidity", fireHumid);            //setup path to send Humidity readings
  Firebase.setString("/DHT11/Temperature", fireTemp);         //setup path to send Temperature readings
    if (Firebase.failed()) 
    {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error()); 
      return;
  }
}
