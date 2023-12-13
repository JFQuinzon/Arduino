#define BLYNK_TEMPLATE_ID "TMPL6yU1aDdts"
#define BLYNK_TEMPLATE_NAME "NOdemcu"
#define BLYNK_AUTH_TOKEN "KQj9eUrWVa8_P02B_8R4MiTxQcmqvTGC"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "JFRANCISQ-PC";
char pass[] = "12345678";

Servo baseservo;
Servo secondservo;
Servo thirdservo;
Servo clawservo;

BLYNK_WRITE(V0)
{
  baseservo.write(param.asInt());
}
BLYNK_WRITE(V1)
{
  secondservo.write(param.asInt());
}

BLYNK_WRITE(V2)
{
  thirdservo.write(param.asInt());
}

BLYNK_WRITE(V3)
{
  clawservo.write(param.asInt());
}



void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  baseservo.attach(D5);
  secondservo.attach(D6);
  thirdservo.attach(D7);
  clawservo.attach(D8);
}

void loop()
{
  Blynk.run();
}
