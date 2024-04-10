#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

ThreeWire myWire(2, 3, 4); // DAT, CLK, RST
RtcDS1302<ThreeWire> Rtc(myWire);

RtcDateTime alarmTime;
int minutes;
bool minutesSet = false;

int moisture = 0;
int targetMoisture = 11;

int buttonBack = 12;
int buttonNext = 11;
int buttonMain = 10;
int redLED = 9;
int greenLED = 8;
int buzzerPin = 7;

int relayPin = 6;

float sinVal;
int toneVal;

bool motorEnabled = false;

// 0 = Sensor
// 1 = Timer
// 2 = changeMode
int mode = 2;

int pushButtonCount = 0;

static unsigned long lastButtonPress = 0;
void setup() {
  Serial.begin(9600);

  pinMode(A1, INPUT);
  pinMode(buttonBack, INPUT_PULLUP);
  pinMode(buttonNext, INPUT_PULLUP);
  pinMode(buttonMain, INPUT_PULLUP);
  
  pinMode(A0, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
  
  lcd.begin();
  lcd.setBacklight(1);
  
  loadTime();
}

void loop() {
  motorActivate();
  if (mode == 0){
    sensorMode();
  }else if (mode == 1){
    timerMode();
  }else if (mode == 2){
    changeMode();
  }






  const unsigned long buttonDebounceDelay = 200;
  if (millis() - lastButtonPress < buttonDebounceDelay) {
    return;  // Ignore button presses within the debounce delay
  }
  int menuButtonState = digitalRead(buttonMain);
  if (menuButtonState == 0) {
    lcd.setBacklight(1);
    pushButtonCount++;
    if (pushButtonCount == 10){
      mode = 2;
    }else if (pushButtonCount > 10){
      pushButtonCount = 0;
    }
    lastButtonPress = millis();
  }else{
    pushButtonCount = 0;
  }

  delay(100); 
}

void motorActivate(){
  if (motorEnabled){
    digitalWrite(relayPin, LOW);
  }else{
    digitalWrite(relayPin, HIGH);
  }
}

void timerMode(){
  if (minutesSet){
    monitorTime();
  }else{
    setTime();
  }
}

String formatTime(int time){
  char formattedtime[3];
  sprintf(formattedtime, "%02d", time);
  return formattedtime;
}

void setTime(){
  const unsigned long buttonDebounceDelay = 200;
  if (millis() - lastButtonPress < buttonDebounceDelay) {
    return;  // Ignore button presses within the debounce delay
  }

  int minusButtonState = digitalRead(buttonBack);
  int plusButtonState = digitalRead(buttonNext);
  int saveButtonState = digitalRead(buttonMain);

  RtcDateTime now = Rtc.GetDateTime();
  lcd.setCursor(0,0);
  lcd.print(" ");
  lcd.print(formatTime(now.Month()));
  lcd.print("/");
  lcd.print(formatTime(now.Day()));
  lcd.print(" ");
  lcd.print(formatTime(now.Hour()));
  lcd.print(":");
  lcd.print(formatTime(now.Minute()));
  lcd.print(":");
  lcd.print(formatTime(now.Second()));
  lcd.print("       ");
  
  lcd.setCursor(0,1);
  lcd.print("  Set Alarm:    ");
  lcd.setCursor(13, 1);
  lcd.print(minutes);

  if (minusButtonState == 0 && minutes != 0) {
    minutes = minutes - 1;
    lastButtonPress = millis();
  }else if (plusButtonState == 0){
    minutes = minutes + 1;
    lastButtonPress = millis();
  }else if (saveButtonState == 0 && minutes != 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("   ALARM  SET   ");
    delay(1000);
    lcd.clear();
    minutesSet = true;
    alarmTime = now + minutes * 60; 
    lastButtonPress = millis();
  }
}

void monitorTime(){
  RtcDateTime now = Rtc.GetDateTime();
  if (now >= alarmTime){
    Serial.println("Alarm triggered!");
    lcd.setCursor(0,0); 
    lcd.print("  Moisture: 11% ");
    lcd.setCursor(0,1);
    lcd.print("Alarm: ");
    lcd.print(formatTime(alarmTime.Hour()));
    lcd.print(":");
    lcd.print(formatTime(alarmTime.Minute()));
    lcd.print(":");
    lcd.print(formatTime(alarmTime.Second()));
    lcd.print("                ");
    lcd.setBacklight(1);
  	digitalWrite(greenLED, HIGH);
  	digitalWrite(redLED, LOW);
    tone(buzzerPin, 1000);
    delay(200);
    noTone(buzzerPin);
  	digitalWrite(greenLED, LOW);
    motorEnabled = false;
    lcd.setBacklight(0);
  }else{
    lcd.setCursor(0,0);
    lcd.print(" ");
    lcd.print(formatTime(now.Month()));
    lcd.print("/");
    lcd.print(formatTime(now.Day()));
    lcd.print(" ");
    lcd.print(formatTime(now.Hour()));
    lcd.print(":");
    lcd.print(formatTime(now.Minute()));
    lcd.print(":");
    lcd.print(formatTime(now.Second()));
    lcd.print("       ");

    lcd.setCursor(0,1);
    lcd.print("Alarm: ");
    lcd.print(formatTime(alarmTime.Hour()));
    lcd.print(":");
    lcd.print(formatTime(alarmTime.Minute()));
    lcd.print(":");
    lcd.print(formatTime(alarmTime.Second()));
    lcd.print("                ");
  	digitalWrite(redLED, HIGH);
  	digitalWrite(greenLED, LOW);
    lcd.setBacklight(1);
    motorEnabled = true;
    
  }
}



void sensorMode(){
  digitalWrite(A0, HIGH);
  delay(10); 
  int moistureSensorValue = analogRead(A1);
  digitalWrite(A0, LOW);
  Serial.println(moistureSensorValue);
  
  int moisturePercentage = getMoisturePercentage(moistureSensorValue);
  displayMoisture(moisturePercentage);
  
  if (moisturePercentage <= targetMoisture){
    Serial.println("Alarm triggered!");
    lcd.setBacklight(1);
  	digitalWrite(greenLED, HIGH);
  	digitalWrite(redLED, LOW);
    tone(buzzerPin, 1000);
    delay(200);
    noTone(buzzerPin);
  	digitalWrite(greenLED, LOW);
    lcd.setBacklight(0);
    motorEnabled = false;
  }else{
  	digitalWrite(redLED, HIGH);
  	digitalWrite(greenLED, LOW);
    lcd.setBacklight(1);
    motorEnabled = true;
  }
}
int getMoisturePercentage(int sensorValue) {
  if (sensorValue > 600) {
    return 100; 
  }
  return map(sensorValue, 0, 600, 0, 100);
}
void displayMoisture(int moisturePercentage){
  lcd.setCursor(0,0);
  lcd.print("MOISTURE CONTENT");
  lcd.setCursor(0,1);
  int spaces = (16 - (String(moisturePercentage) + "%").length()) / 2;
  for (int i = 0; i < spaces; i++) {
    lcd.print(" ");
  }
  lcd.print(moisturePercentage);
  lcd.print("%       ");
  
}

void changeMode(){
  lcd.setBacklight(1);
  minutesSet = false;
  minutes = 0;
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
  const unsigned long buttonDebounceDelay = 200;
  if (millis() - lastButtonPress < buttonDebounceDelay) {
    return;  // Ignore button presses within the debounce delay
  }
  int sensorButtonState = digitalRead(buttonBack);
  int timerButtonState = digitalRead(buttonNext);
  lcd.setCursor(0,0);
  lcd.print("      MODE      ");
  lcd.setCursor(0,1);
  lcd.print(" Sensor | Timer ");
  if (sensorButtonState == 0) {
    mode = 0;
    lastButtonPress = millis();
  } else if (timerButtonState == 0) {
    mode = 1;
    lastButtonPress = millis();
  }
}

void loadTime(){
    RtcDateTime currentTime = RtcDateTime(__DATE__, __TIME__);
  if (!Rtc.IsDateTimeValid()){
    Serial.println("RTC lost confidence in the DateTime!");
    Rtc.SetDateTime(currentTime);
  }
  if (Rtc.GetIsWriteProtected()){
    Serial.println("RTC was write protected, enabling writing now");
    Rtc.SetIsWriteProtected(false);
  }
  if (!Rtc.GetIsRunning()){
    Serial.println("RTC was not actively running, starting now");
    Rtc.SetIsRunning(true);
  }
  RtcDateTime now = Rtc.GetDateTime();
  if (now < currentTime){
    Serial.println("RTC is older than compile time!  (Updating DateTime)");
    Rtc.SetDateTime(currentTime);
  }else if (now > currentTime){
    Serial.println("RTC is newer than compile time. (this is expected)");
  }else if (now == currentTime){
    Serial.println("RTC is the same as compile time! (not expected but all is fine)");
  }
}