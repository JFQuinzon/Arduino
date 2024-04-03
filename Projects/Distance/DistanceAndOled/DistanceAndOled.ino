#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <NewPing.h>

#define TRIGGER_PIN  3  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     2  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

#define i2c_Address 0x3c 
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET -1    
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

float distanceCm;

void setup() {

  Serial.begin(9600);

  delay(250);
  display.begin(i2c_Address, true);
  display.display();
  delay(2000);

  
}

void loop() {
  
  getDistance();
  // Text display tests
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 0);
  
  // Display distance in different units
  display.print("Distance: ");
  display.print(distanceCm);
  display.println(" cm");

  display.print("In mm: ");
  display.println(distanceCm * 10);

  display.print("In inch: ");
  display.println(distanceCm * 0.393701);

  display.print("In meter: ");
  display.println(distanceCm * 0.01);

  display.display();
  delay(1000);
  display.clearDisplay();
}


void getDistance(){
  distanceCm = sonar.ping_cm();
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
}