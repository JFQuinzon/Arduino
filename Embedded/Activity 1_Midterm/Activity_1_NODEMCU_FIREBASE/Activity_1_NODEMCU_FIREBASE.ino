#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "midterm-activity-1-c5c44-default-rtdb.asia-southeast1.firebasedatabase.app"
#define FIREBASE_AUTH "vsIwTmSnYGrY84uCLpIm0Y1pMJkxdT2yau03SXQO"
#define WIFI_SSID "JFRANCISQ-PC"
#define WIFI_PASSWORD "12345678"

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    digitalWrite(D2, HIGH); 
    delay(250);
    digitalWrite(D2, LOW); 
    delay(250); 
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.set("LED1_STATUS", "Off");
  Firebase.set("LED2_STATUS", "Off");
}

String led1 = "Off";
String led2 = "Off";

void loop() {
  // set value
  led1=Firebase.getString("LED1_STATUS");
  led2=Firebase.getString("LED2_STATUS");
  //For Bulb
  if (led1=="On") {
      Serial.println("LED1 On");
      digitalWrite(D2,HIGH);  
  }else if(led1=="Off"){
    Serial.println("LED1 Off");
    digitalWrite(D2,LOW); 
  }

  if (led2=="On") {
      Serial.println("LED2 On");
      digitalWrite(D3,HIGH);  
  }else if(led2=="Off"){
    Serial.println("LED2 Off");
    digitalWrite(D3,LOW); 
  }
  delay(500);
}





