const unsigned char epd_bitmap_loading [] PROGMEM = {
	0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x7e, 0x00, 0xf0, 0x00, 
	0x00, 0x1f, 0x00, 0x01, 0xff, 0xc0, 0xf8, 0x00, 0x00, 0x3e, 0x00, 0x03, 0xff, 0xe0, 0x7c, 0x00, 
	0x00, 0x7c, 0x00, 0x07, 0xfa, 0x30, 0x3e, 0x00, 0x00, 0xf8, 0x00, 0x0b, 0xf7, 0xf0, 0x1f, 0x00, 
	0x01, 0xf0, 0x00, 0x0c, 0xfc, 0x38, 0x0f, 0x80, 0x03, 0xe0, 0x00, 0x1f, 0x18, 0x58, 0x07, 0xc0, 
	0x07, 0xc0, 0x00, 0x1f, 0x33, 0xc8, 0x03, 0xe0, 0x0f, 0x80, 0x00, 0x1f, 0x6f, 0xf8, 0x01, 0xf0, 
	0x1f, 0x00, 0x00, 0x3e, 0x5f, 0xf8, 0x00, 0xf8, 0x3e, 0x00, 0x00, 0x3e, 0x4d, 0xf8, 0x00, 0x7c, 
	0x7c, 0x00, 0x00, 0x3e, 0xdf, 0xf8, 0x00, 0x3e, 0xf8, 0x00, 0x00, 0x3e, 0xff, 0xf8, 0x00, 0x1f, 
	0xf8, 0x00, 0x00, 0x1e, 0xff, 0xf8, 0x00, 0x0f, 0x7c, 0x00, 0x00, 0x1e, 0x7f, 0xf8, 0x00, 0x1e, 
	0x3e, 0x00, 0x00, 0x0e, 0x7f, 0xf8, 0x00, 0x3c, 0x1f, 0x00, 0x00, 0x0f, 0x7f, 0xe0, 0x00, 0x78, 
	0x0f, 0x80, 0x00, 0x1f, 0xff, 0x80, 0x00, 0xf0, 0x07, 0xc0, 0x00, 0x7f, 0xfe, 0x00, 0x01, 0xe0, 
	0x03, 0xe0, 0x03, 0xd7, 0xf8, 0x00, 0x03, 0xc0, 0x01, 0xf0, 0x0f, 0x5f, 0xc0, 0x00, 0x07, 0x80, 
	0x00, 0xf8, 0x3f, 0x60, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x7c, 0x7f, 0x00, 0x00, 0x00, 0x1e, 0x00, 
	0x00, 0x3e, 0x7c, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x1f, 0x78, 0x00, 0x00, 0x00, 0x78, 0x00, 
	0x00, 0x0f, 0x30, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00
};
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

// #include <HCSR04.h>
#include <NewPing.h>

#include <MPU6050_light.h>
#include <EEPROM.h>

// ANGLESENSOR ======
MPU6050 mpu(Wire);
unsigned long timer = 0;    
// ==================

// ULTRASONIC =======
  NewPing sonar(12, 11, 500); //trig 12, echo 11, max distance 500
  // UltraSonicDistanceSensor distanceSensor(12, 11); //trig 12, echo 11
// ==================

// OLED =============
  #define i2c_Address 0x3c 
  #define SCREEN_WIDTH 128 
  #define SCREEN_HEIGHT 64 
  #define OLED_RESET -1    
  Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
// ==================

// LASER ==========
  const int laserPin = 6; 
  bool laserOn = false;
// ==================

// BUTTONS ==========
  const int touchPinSetting = 7; 
  const int touchPinBack = 10; 
  const int touchPinNext = 8; 
  const int touchPinSave = 9; 
// ==================

enum DisplayState {
  DISTANCE,
  ANGLE
};

DisplayState currentDisplay = DISTANCE;

int pressSetting = 0;
int pressSave = 0;
int pressNext = 0;
int pressBack = 0;

const int voltageSensorPin = A0;
// const float voltageDividerRatio = 21.1 / 1023.0; 
const float voltageDividerRatio = 0.0205; 
const float fullVoltage = 3.7; // Full voltage of the battery
const float lowBatVoltage = 3.0; // Low battery voltage threshold
int batteryPercentageVal;

void setup() {
  Serial.begin(9600);
  pinMode(touchPinSetting, INPUT_PULLUP);
  pinMode(touchPinBack, INPUT_PULLUP);
  pinMode(touchPinNext, INPUT_PULLUP);
  pinMode(touchPinSave, INPUT_PULLUP);
  pinMode(laserPin, OUTPUT);
  
  display.begin(i2c_Address, true);
  display.clearDisplay();
  display.drawBitmap(32, 15,  epd_bitmap_loading, 64, 28, 1);
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(1);
  display.setCursor(32, 50);
  display.print("Loading...");
  display.display();

  Wire.begin();     
  mpu.begin();
  mpu.setGyroOffsets(EEPROM.read(10), EEPROM.read(11), EEPROM.read(12));
  
  getBat();
  delay(500);
}


void loop() {
  buttonNext();
  buttonBack();
  switchDisplay();
  
}


void distanceDisplay(float distanceCm){
  saveDistance(distanceCm);
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(85, 0);
  display.print("B:");
  display.print(batteryPercentageVal);
  display.println("%");

  display.setCursor(16, 15);
  display.print("DISTANCE METRICS");
  display.setCursor(15, 25);
  display.print("- ");
  display.print(distanceCm);
  display.println(" cm");
  display.setCursor(15, 35);
  display.print("- ");
  display.print(distanceCm * 10);
  display.println(" mm");
  display.setCursor(15, 45);
  display.print("- ");
  display.print(distanceCm * 0.393701);
  display.println(" in");
  display.setCursor(15, 55);
  display.print("- ");
  display.print(distanceCm * 0.01);
  display.println(" m");
  display.display();
  display.clearDisplay();

  int touchStateLaser = digitalRead(touchPinSetting);
  if (touchStateLaser == 1) {
    pressSetting = pressSetting + 1;
    if (pressSetting == 5){
      laserOn = !laserOn;
    }
  } else {
    pressSetting = 0;
  }

  if (laserOn) {
    digitalWrite(laserPin, HIGH);
  } else{
    digitalWrite(laserPin, LOW);
  }
}
void angleDisplay(int angle){
  saveAngle(angle);
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(85, 0);
  display.print("B:");
  display.print(batteryPercentageVal);
  display.println("%");
  display.setCursor(16, 15);
  display.print("ANGLE IN DEGREES");

  printCenteredText(String(angle), 2, 28);

  display.display();
  display.clearDisplay();

  int touchStateCalibrate = digitalRead(touchPinSetting);
  if (touchStateCalibrate == 1) {
    pressSetting = pressSetting + 1;
    if (pressSetting == 30){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(16, 15);
      display.print("CALIBRATING ANGLE");
      display.display();
      display.clearDisplay();
      
      delay(3000);
      mpu.calcGyroOffsets();   
      EEPROM.write(10, mpu.getGyroXoffset());
      EEPROM.write(11, mpu.getGyroYoffset());
      EEPROM.write(12, mpu.getGyroZoffset());
      mpu.setGyroOffsets(EEPROM.read(10), EEPROM.read(11), EEPROM.read(12));
      delay(500);
      asm volatile ("  jmp 0");
    }
  } else {
    pressSetting = 0;
  }
}
void saveDistance(int centimter){
  int touchStateSave = digitalRead(touchPinSave);
  if (touchStateSave == 1) {
    pressSave = pressSave + 1;
    Serial.println(pressSave);
    if (pressSave == 10){
      Serial.print(F("savedistance: "));
      Serial.println(centimter);
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(16, 15);
      display.print("    Saving...   ");
      display.display();
      display.clearDisplay();
      delay(3000);
    }
  } else {
    pressSave = 0;
  }
}
void saveAngle(int angle){
  int touchStateSave = digitalRead(touchPinSave);
  if (touchStateSave == 1) {
    pressSave = pressSave + 1;
    Serial.println(pressSave);
    if (pressSave == 10){
      Serial.print(F("saveangle: "));
      Serial.println(angle);
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(16, 15);
      display.print("    Saving...   ");
      display.display();
      display.clearDisplay();
      delay(3000);
    }
  } else {
    pressSave = 0;
  }
}

void buttonNext(){
  int touchStateNext = digitalRead(touchPinNext);
  if (touchStateNext == 1) {
    pressNext = pressNext + 1;
    if (pressNext == 5){
      switch (currentDisplay) {
        case DISTANCE:
          currentDisplay = ANGLE;
          break;
        case ANGLE:
          currentDisplay = DISTANCE;
          break;
      }
    }
  } else {
    pressNext = 0;
  }
}
void buttonBack(){
  int touchStateBack = digitalRead(touchPinBack);
  if (touchStateBack == 1) {
    pressBack = pressBack + 1;
    if (pressBack == 5){
      switch (currentDisplay) {
        case DISTANCE:
          currentDisplay = ANGLE;
          break;
        case ANGLE:
          currentDisplay = DISTANCE;
          break;
      }
    }
  } else {
    pressBack = 0;
  }
}

const unsigned long interval = 1000;
unsigned long previousMillis = 0;
int totalDistance = 0;

void switchDisplay(){
  if (currentDisplay == DISTANCE){
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      totalDistance = sonar.ping_cm() + 12;
    }
    distanceDisplay(totalDistance);
    delay(100);
  }else if(currentDisplay == ANGLE){
    laserOn = false;
    digitalWrite(laserPin, LOW);
    mpu.update();
    int yAngle = mpu.getAngleZ();
    angleDisplay(yAngle);
    delay(100);
  }
}
void printCenteredText(const String& text, int textSize, int y) {
  display.setTextSize(textSize);
  int textWidth = text.length() * 6 * textSize;
  int textX = (display.width() - textWidth) / 2;
  display.setCursor(textX, y);
  display.print(text);
}
// GET BATTERY PERCENTAGE PER 1 SECOND
// unsigned long previousMillisBat = 0;
// unsigned long intervalBat = 1000;
// void getBat(){
//   unsigned long currentMillisBat = millis(); 
//   if (currentMillisBat - previousMillisBat >= intervalBat) { 
//     previousMillisBat = currentMillisBat; 
//     int sensorValue = analogRead(voltageSensorPin); // Read the analog voltage value
//     float voltage = sensorValue * voltageDividerRatio; // Convert analog reading to voltage
//     float voltageRange = fullVoltage - lowBatVoltage; // Calculate the voltage range
//     float remainingVoltage = voltage - lowBatVoltage; // Calculate the remaining voltage within the range
//     int batteryPercentage = (remainingVoltage / voltageRange) * 100;
//     batteryPercentage = constrain(batteryPercentage, 0, 100); // Ensure the percentage is within 0-100 range
//   batteryPercentageVal = batteryPercentage;
//   }
// }

// ONLY GET BATTERY PERCENTAGE ON-OPEN
void getBat() {
  unsigned long startMillis = millis(); // Record the start time
  unsigned long endMillis = startMillis + 3000; // Calculate the end time (1 second later)
  int readings = 0; // Initialize the number of readings
  float totalVoltage = 0; // Initialize the total voltage

  while (millis() < endMillis) { // Continue looping until 1 second has elapsed
    int sensorValue = analogRead(voltageSensorPin); // Read the analog voltage value
    float voltage = sensorValue * voltageDividerRatio; // Convert analog reading to voltage
    totalVoltage += voltage; // Add the current voltage to the total
    readings++; // Increment the number of readings
    delay(10); // Optional delay to avoid reading too fast
  }

  if (readings > 0) { // Ensure there were readings
    float averageVoltage = totalVoltage / readings; // Calculate the average
    float voltageRange = fullVoltage - lowBatVoltage; // Calculate the voltage range
    float remainingVoltage = averageVoltage - lowBatVoltage; // Calculate the remaining voltage within the range
    int batteryPercentage = (remainingVoltage / voltageRange) * 100;
    batteryPercentageVal = constrain(batteryPercentage, 0, 100);
  }
}
