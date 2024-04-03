#include <SoftwareSerial.h>

#define RE 9
#define DE 8

const byte anemometer[] = {0x02, 0x03, 0x02, 0x00, 0x03, 0xF8, 0x45};
byte values[16];
SoftwareSerial mod(6, 7);

void setup()
{
  Serial.begin(9600);
  mod.begin(4800);
  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);
  delay(1000);
}

void loop()
{
  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(10);

  mod.write(anemometer, sizeof(anemometer));

  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);
  delay(10);
  unsigned long startTime = millis();
  while (mod.available() < 16 && millis() - startTime < 1000) {
    delay(1);
  }

  if (mod.available() >= 16){
    for (int i = 0; i < 16; i++) {
      values[i] = mod.read();
      Serial.print(values[i], HEX);
      Serial.print(" ");
    }
    Serial.println(); // Print a new line for better readability
  } else {
    Serial.println("Error");
  }
  delay(1000);
}
