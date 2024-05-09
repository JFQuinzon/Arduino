#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>
#include <EEPROM.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

ThreeWire myWire(2, 3, 4); // DAT, CLK, RST
RtcDS1302<ThreeWire> Rtc(myWire);

const uint8_t buttonBack = 5;
const uint8_t buttonEnter = 6;
const uint8_t buttonMode = 7;
const uint8_t buttonDown = 8;
const uint8_t buttonUp = 9;

const uint8_t buzzerPin = 10;

const uint8_t sunLedPin = A3;
const uint8_t monLedPin = A2;
const uint8_t tueLedPin = A1;
const uint8_t wedLedPin = A0;
const uint8_t thuLedPin = 11;
const uint8_t friLedPin = 12;
const uint8_t satLedPin = 13;

uint8_t setDateTimeMode = 0;
int year; 
uint8_t month;
uint8_t day;
uint8_t hour;
uint8_t minute;
uint8_t second;


uint8_t setAlarmMode = 0;
uint8_t setAlarmSubmode = 0;

uint8_t alarmTime1Day; 
uint8_t alarmTime1Hour; 
uint8_t alarmTime1Minute; 
uint8_t alarmTime1Second; 
uint8_t alarm1Status;
uint8_t alarm1Mode = 0;

uint8_t alarmTime2Day; 
uint8_t alarmTime2Hour; 
uint8_t alarmTime2Minute; 
uint8_t alarmTime2Second; 
uint8_t alarm2Status;
uint8_t alarm2Mode = 0;

uint8_t alarmTime3Day; 
uint8_t alarmTime3Hour; 
uint8_t alarmTime3Minute; 
uint8_t alarmTime3Second; 
uint8_t alarm3Status;
uint8_t alarm3Mode = 0;

uint8_t alarmTime4Day; 
uint8_t alarmTime4Hour; 
uint8_t alarmTime4Minute; 
uint8_t alarmTime4Second; 
uint8_t alarm4Status;
uint8_t alarm4Mode = 0;

uint8_t alarmTime5Day; 
uint8_t alarmTime5Hour; 
uint8_t alarmTime5Minute;
uint8_t alarmTime5Second;  
uint8_t alarm5Status;
uint8_t alarm5Mode = 0;

uint8_t alarmTime6Day; 
uint8_t alarmTime6Hour; 
uint8_t alarmTime6Minute; 
uint8_t alarmTime6Second; 
uint8_t alarm6Status;
uint8_t alarm6Mode = 0;

uint8_t alarmTime7Day; 
uint8_t alarmTime7Hour; 
uint8_t alarmTime7Minute; 
uint8_t alarmTime7Second; 
uint8_t alarm7Status;
uint8_t alarm7Mode = 0;

uint8_t previousButtonBackState = 0;

struct Alarm {
  uint8_t day;
  uint8_t hour;
  uint8_t minute;
  uint8_t second; 
  uint8_t status;
  uint8_t number;
};

uint8_t alarmNo = 0;
uint8_t alarmDay = 0;
uint8_t alarmHour = 0;
uint8_t alarmMinute = 0;
uint8_t alarmSecond = 0;
uint8_t isAlarmsAvailable = 0;

uint8_t prevAlarmNo = 0;
uint8_t prevAlarmDay = 0;

uint8_t alarmStopDay = 0;
uint8_t alarmStopHour = 0;
uint8_t alarmStopMinute = 0;
uint8_t alarmStopSecond = 0;

uint8_t alarmDuration = 1;


bool alarmTriggered = false;
uint8_t pushButtonCount = 0;

uint8_t mode = 3;

void setup() {
  Serial.begin(9600);
  pinMode(buttonBack, INPUT_PULLUP);
  pinMode(buttonEnter, INPUT_PULLUP);
  pinMode(buttonMode, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);
  pinMode(buttonUp, INPUT_PULLUP);

  pinMode(buzzerPin, OUTPUT);
  pinMode(monLedPin, OUTPUT);
  pinMode(tueLedPin, OUTPUT);
  pinMode(wedLedPin, OUTPUT);
  pinMode(thuLedPin, OUTPUT);
  pinMode(friLedPin, OUTPUT);
  pinMode(satLedPin, OUTPUT);
  pinMode(sunLedPin, OUTPUT);

  lcd.begin();
  lcd.setBacklight(1);
  loadTime();

  restoreValuesFromEEPROM();

  // DUMMY ALARMS UNCOMMENT AFTER THE FIRST UPLOAD
    // // ALARM 1
    // EEPROM.write(10, 1);
    // EEPROM.write(11, 1);
    // EEPROM.write(12, 10);
    // EEPROM.write(13, 1);
    // // ALARM 2
    // EEPROM.write(20, 2);
    // EEPROM.write(21, 2);
    // EEPROM.write(22, 20);
    // EEPROM.write(23, 0);
    // // ALARM 3
    // EEPROM.write(30, 3);
    // EEPROM.write(31, 3);
    // EEPROM.write(32, 30);
    // EEPROM.write(33, 0);
    // // ALARM 4
    // EEPROM.write(40, 4);
    // EEPROM.write(41, 4);
    // EEPROM.write(42, 40);
    // EEPROM.write(43, 1);
    // // ALARM 5
    // EEPROM.write(50, 5);
    // EEPROM.write(51, 5);
    // EEPROM.write(52, 50);
    // EEPROM.write(53, 1);
    // // ALARM 6
    // EEPROM.write(60, 6);
    // EEPROM.write(61, 6);
    // EEPROM.write(62, 56);
    // EEPROM.write(63, 0);
    // // ALARM 7
    // EEPROM.write(70, 7);
    // EEPROM.write(71, 0);
    // EEPROM.write(72, 0);
    // EEPROM.write(73, 0);
}
void loop() {
  uint8_t buttonDownState = digitalRead(buttonDown);
  uint8_t buttonUpState = digitalRead(buttonUp);
  uint8_t buttonBackState = digitalRead(buttonBack);
  uint8_t buttonMenuState = digitalRead(buttonMode);
  if (buttonMenuState == 0){
    delay(500); // Debounce
    mode = 0;
    setAlarmMode = 0;
    setAlarmSubmode = 0;
    alarm1Mode = 0;
    alarm2Mode = 0;
    alarm3Mode = 0;
    alarm4Mode = 0;
    alarm5Mode = 0;
    alarm6Mode = 0;
    alarm7Mode = 0;
    restoreValuesFromEEPROM();
    lcd.clear();
  }
  switch(mode){
    case 0:
      lcd.setCursor(0,0);
      lcd.print("      MODE      ");
      lcd.setCursor(0,1);
      lcd.print(" Date  |  Alarm ");
      
      if (buttonDownState == 0){
        delay(500); // Debounce
        mode = 2;
        lcd.clear();
        restoreValuesFromEEPROM();
      }
      if (buttonUpState == 0){
        delay(500); // Debounce
        mode = 1;
        lcd.clear();
        restoreValuesFromEEPROM();
      }
      if (buttonBackState == 0){
        delay(500); // Debounce
        mode = 3;
        lcd.clear();
        restoreValuesFromEEPROM();
      }
      break;
    case 1: 
      setAlarm();
      break;
    case 2: 
      setDate();
      break;
    case 3:
      MonitorAlarms();
      break;
    default: 
      break;
  }
  

}


void MonitorAlarms(){
  checkNearestAlarm();
  RtcDateTime now = Rtc.GetDateTime();  
  // Triggers Alarm
  if (now.DayOfWeek() == alarmDay && now.Hour() == alarmHour && now.Minute() == alarmMinute && now.Second() == alarmSecond && alarmTriggered == false){
    prevAlarmNo = alarmNo;
    prevAlarmDay = alarmDay;
    alarmTriggered = true;

    restoreValuesFromEEPROM();
    // Set Stop time
    alarmStopDay = alarmDay;
    alarmStopHour = alarmHour;
    alarmStopMinute = alarmMinute + alarmDuration;
    alarmStopSecond = alarmSecond;
    if (alarmStopMinute >= 60) {
      alarmStopMinute -= 60; 
      alarmStopHour++; 
      if (alarmStopHour >= 24) {
        alarmStopHour -= 24; 
        alarmStopDay++; 
      }
    }
  }

  if (alarmTriggered == true){
    triggerBuzzerLED(prevAlarmDay);
    lcd.setCursor(0,0);
    lcd.print(" ALARM ");
    lcd.print(prevAlarmNo);
    lcd.print(" | ");
    lcd.print(dayOfWeekToString(prevAlarmDay));
    lcd.print("  ");
    lcd.setCursor(0,1);
    lcd.print(" ENTER  =  STOP ");
  }else{
    lcd.setCursor(0,0);
    lcd.print(" ");
    lcd.print(dayOfWeekToString(now.DayOfWeek()));
    lcd.print(" | ");
    lcd.print(formatTime12hr(now.Hour()));
    lcd.print(":");
    lcd.print(formatTime(now.Minute()));
    formatAMPM(now.Hour());


    if (isAlarmsAvailable == 1){
      lcd.setCursor(0,1);
      lcd.print("A: ");
      lcd.print(dayOfWeekToString(alarmDay));
      lcd.print(" | ");
      lcd.print(formatTime12hr(alarmHour));
      lcd.print(":");
      lcd.print(formatTime(alarmMinute));
      formatAMPM(alarmHour);
    }else{
      lcd.setCursor(0,1);
      lcd.print("No active alarms");
    }
    offLEDs();
    noTone(buzzerPin);
  }

  // Stop via Button
  uint8_t buttonEnterState = digitalRead(buttonEnter);
  
  static bool buttonPressed = false;
  static unsigned long buttonPressTime = 0;

  if (buttonEnterState == LOW && !buttonPressed) {
    buttonPressed = true;
    buttonPressTime = millis();
  }

  if (buttonPressed && (millis() - buttonPressTime >= 1000)) { // Check for long press (1 second)
    alarmStopDay = 0;
    alarmStopHour = 0;
    alarmStopMinute = 0;
    alarmStopSecond = 0;
    alarmTriggered = false;
    offLEDs();
    noTone(buzzerPin);
    updateAlarmStatus(prevAlarmNo);
    buttonPressed = false; // Reset button state
  }
  if (buttonEnterState == HIGH) {
    buttonPressed = false; // Reset button state if button is released
  }

  // Stop via duration
  if (now.DayOfWeek() == alarmStopDay && now.Hour() == alarmStopHour && now.Minute() == alarmStopMinute && now.Second() == alarmStopSecond){
    alarmTriggered = false;
    alarm1Status = 0;
    updateAlarmStatus(prevAlarmNo);
  }
}

void updateAlarmStatus(uint8_t alarmNumber){
  switch (alarmNumber){
    case 1:
      EEPROM.write(13, 0);
      break;
    case 2:
      EEPROM.write(23, 0);
      break;
    case 3:
      EEPROM.write(33, 0);
      break;
    case 4:
      EEPROM.write(43, 0);
      break;
    case 5:
      EEPROM.write(53, 0);
      break;
    case 6:
      EEPROM.write(63, 0);
      break;
    case 7:
      EEPROM.write(73, 0);
      break;
    default:
      break;
  }
  restoreValuesFromEEPROM();
    
}
void triggerBuzzerLED(uint8_t alarmDay){
  offLEDs();
  tone(buzzerPin, 1000);
  switch (alarmDay) {
    case 1:
      digitalWrite(monLedPin, HIGH);
      break;
    case 2:
      digitalWrite(tueLedPin, HIGH);
      break;
    case 3:
      digitalWrite(wedLedPin, HIGH);
      break;
    case 4:
      digitalWrite(thuLedPin, HIGH);
      break;
    case 5:
      digitalWrite(friLedPin, HIGH);
      break;
    case 6:
      digitalWrite(satLedPin, HIGH);
      break;
    case 7:
      digitalWrite(sunLedPin, HIGH);
      break;
    default:
      break;
  }
  delay(200);
  noTone(buzzerPin);
}

void offLEDs(){
  digitalWrite(monLedPin, LOW);
  digitalWrite(tueLedPin, LOW);
  digitalWrite(wedLedPin, LOW);
  digitalWrite(thuLedPin, LOW);
  digitalWrite(friLedPin, LOW);
  digitalWrite(satLedPin, LOW);
  digitalWrite(sunLedPin, LOW);
}

void checkNearestAlarm() {
  RtcDateTime now = Rtc.GetDateTime();

  Alarm alarms[] = {
    {alarmTime1Day, alarmTime1Hour, alarmTime1Minute, alarmTime1Second, alarm1Status, 1},
    {alarmTime2Day, alarmTime2Hour, alarmTime2Minute, alarmTime2Second, alarm2Status, 2},
    {alarmTime3Day, alarmTime3Hour, alarmTime3Minute, alarmTime3Second, alarm3Status, 3},
    {alarmTime4Day, alarmTime4Hour, alarmTime4Minute, alarmTime4Second, alarm4Status, 4},
    {alarmTime5Day, alarmTime5Hour, alarmTime5Minute, alarmTime5Second, alarm5Status, 5},
    {alarmTime6Day, alarmTime6Hour, alarmTime6Minute, alarmTime6Second, alarm6Status, 6},
    {alarmTime7Day, alarmTime7Hour, alarmTime7Minute, alarmTime7Second, alarm7Status, 7}
  };

  uint8_t currentDay = now.DayOfWeek();
  uint8_t currentHour = now.Hour();
  uint8_t currentMinute = now.Minute();
  uint8_t currentSecond = now.Second();

  uint32_t currentTotalSeconds = currentDay * 86400UL + currentHour * 3600UL + currentMinute * 60UL + currentSecond;

  uint32_t nearestDifference = UINT32_MAX; // Initialize with maximum possible value
  int nearestAlarmIndex = -1;
  
  for (int i = 0; i < sizeof(alarms) / sizeof(alarms[0]); i++) {
    uint32_t alarmTotalSeconds = alarms[i].day * 86400UL + alarms[i].hour * 3600UL + alarms[i].minute * 60UL + alarms[i].second;
    if (alarms[i].status) {
      if (alarmTotalSeconds >= currentTotalSeconds) {
        uint32_t difference = alarmTotalSeconds - currentTotalSeconds;
        if (difference < nearestDifference) {
          nearestDifference = difference;
          nearestAlarmIndex = i;
        }
      }
    }
  }

  if (nearestAlarmIndex != -1) {
    alarmDay = alarms[nearestAlarmIndex].day;
    alarmHour = alarms[nearestAlarmIndex].hour;
    alarmMinute = alarms[nearestAlarmIndex].minute;
    alarmSecond = alarms[nearestAlarmIndex].second; // Store seconds for display
    alarmNo = alarms[nearestAlarmIndex].number;
    isAlarmsAvailable = 1;
  } else {
    isAlarmsAvailable = 0;
  }
}

void setAlarm(){
  uint8_t buttonBackState = digitalRead(buttonBack);
  uint8_t buttonEnterState = digitalRead(buttonEnter);
  uint8_t buttonDownState = digitalRead(buttonDown);
  uint8_t buttonUpState = digitalRead(buttonUp);
  RtcDateTime now = Rtc.GetDateTime();
  if (setAlarmSubmode > 0){
    if (buttonBackState != previousButtonBackState) { 
      previousButtonBackState = buttonBackState;
      if (buttonBackState == 0) {
        delay(500); // Debounce
        setAlarmSubmode = 0;
        alarm1Mode = 0;
        alarm2Mode = 0;
        alarm3Mode = 0;
        alarm4Mode = 0;
        alarm5Mode = 0;
        alarm6Mode = 0;
        alarm7Mode = 0;
        restoreValuesFromEEPROM();
        lcd.clear();
      }
    }
    switch (setAlarmSubmode){
      case 1:
        switch (alarm1Mode){
          case 0:
            displayAlarmData(1, alarmTime1Day, alarmTime1Hour, alarmTime1Minute);
            displayAlarmStatus(alarm1Status);        
            if (buttonDownState == 0){
              alarm1Mode = 2;
              delay(500); // Debounce
              alarmTime1Day = EEPROM.read(10);
              if (alarmTime1Day < 1 || alarmTime1Day > 7) {
                alarmTime1Day = 1;
                EEPROM.write(10, alarmTime1Day);
                restoreValuesFromEEPROM();
              }
              lcd.clear();
            }
            if (buttonUpState == 0){
              delay(500); // Debounce
              alarm1Mode = 1;
              lcd.clear();
            }
            break;
          case 1:
            lcd.setCursor(0, 0);
            lcd.print("Activate Alarm? ");
            lcd.setCursor(0, 1);
            lcd.print("    YES | NO    ");
            if (buttonDownState == 0){
              alarm1Status = 1;
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("    Alarm 1     ");
              lcd.setCursor(0, 1);
              lcd.print("   Activated    ");
              EEPROM.write(13, alarm1Status);
              restoreValuesFromEEPROM();
              delay(1000);
              alarm1Mode = 0;
            }
            if (buttonUpState == 0){
              alarm1Status = 0;
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("    Alarm 1     ");
              lcd.setCursor(0, 1);
              lcd.print("  Deactivated   ");
              EEPROM.write(13, alarm1Status);
              restoreValuesFromEEPROM();
              delay(1000);
              alarm1Mode = 0;
            }
            break;
          case 2:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 1  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Day: " + dayOfWeekToString(alarmTime1Day));
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime1Day = (alarmTime1Day == 1) ? 7 : alarmTime1Day - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime1Day = (alarmTime1Day == 7) ? 1 : alarmTime1Day + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) { 
              alarm1Mode = 3;
              delay(500); // Debounce
              lcd.clear();
            }
            break;
          case 3:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 1  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Hour: " + String(formatTime12hr(alarmTime1Hour)) );
            formatAMPM(alarmTime1Hour);
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime1Hour = (alarmTime1Hour == 0) ? 23 : alarmTime1Hour - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime1Hour = (alarmTime1Hour == 23) ? 0 : alarmTime1Hour + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) { 
              alarm1Mode = 4;
              delay(500); // Debounce
              lcd.clear();
            }
            break;
          case 4:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 1  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Minute: " + String(alarmTime1Minute));
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime1Minute = (alarmTime1Minute == 0) ? 59 : alarmTime1Minute - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime1Minute = (alarmTime1Minute == 59) ? 0 : alarmTime1Minute + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) {
              lcd.clear();
              EEPROM.write(10, alarmTime1Day);
              EEPROM.write(11, alarmTime1Hour);
              EEPROM.write(12, alarmTime1Minute);
              EEPROM.write(14, now.Second());
              restoreValuesFromEEPROM();
              lcd.setCursor(0, 0);
              lcd.print("  ALARM SAVED!  ");
              delay(1000); // Debounce
              lcd.clear();
              alarm1Mode = 0;
            }
            break;
          default:
            break;
        }
        break;
      case 2:
        switch (alarm2Mode){
          case 0:
            displayAlarmData(2, alarmTime2Day, alarmTime2Hour, alarmTime2Minute);
            displayAlarmStatus(alarm2Status);        
            if (buttonDownState == 0){
              alarm2Mode = 2;
              delay(500); // Debounce
              alarmTime2Day = EEPROM.read(20);
              if (alarmTime2Day < 1 || alarmTime2Day > 7) {
                alarmTime2Day = 1;
                EEPROM.write(20, alarmTime2Day);
                restoreValuesFromEEPROM();
              }
              lcd.clear();
            }
            if (buttonUpState == 0){
              delay(500); // Debounce
              alarm2Mode = 1;
              lcd.clear();
            }
            break;
          case 1:
            lcd.setCursor(0, 0);
            lcd.print("Activate Alarm? ");
            lcd.setCursor(0, 1);
            lcd.print("    YES | NO    ");
            if (buttonDownState == 0){
              alarm2Status = 1;
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("    Alarm 2     ");
              lcd.setCursor(0, 1);
              lcd.print("   Activated    ");
              delay(1000);
              EEPROM.write(23, alarm2Status);
              restoreValuesFromEEPROM();
              alarm2Mode = 0;
            }
            if (buttonUpState == 0){
              alarm2Status = 0;
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("    Alarm 2     ");
              lcd.setCursor(0, 1);
              lcd.print("  Deactivated   ");
              delay(1000);
              EEPROM.write(23, alarm2Status);
              restoreValuesFromEEPROM();
              alarm2Mode = 0;
            }
            break;
          case 2:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 2  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Day: " + dayOfWeekToString(alarmTime2Day));
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime2Day = (alarmTime2Day == 1) ? 7 : alarmTime2Day - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime2Day = (alarmTime2Day == 7) ? 1 : alarmTime2Day + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) { 
              alarm2Mode = 3;
              delay(500); // Debounce
              lcd.clear();
            }
            break;
          case 3:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 2  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Hour: " + String(formatTime12hr(alarmTime2Hour)) );
            formatAMPM(alarmTime2Hour);
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime2Hour = (alarmTime2Hour == 0) ? 23 : alarmTime2Hour - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime2Hour = (alarmTime2Hour == 23) ? 0 : alarmTime2Hour + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) { 
              alarm2Mode = 4;
              delay(500); // Debounce
              lcd.clear();
            }
            break;
          case 4:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 2  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Minute: " + String(alarmTime2Minute));
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime2Minute = (alarmTime2Minute == 0) ? 59 : alarmTime2Minute - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime2Minute = (alarmTime2Minute == 59) ? 0 : alarmTime2Minute + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) {
              lcd.clear();
              EEPROM.write(20, alarmTime2Day);
              EEPROM.write(21, alarmTime2Hour);
              EEPROM.write(22, alarmTime2Minute);
              EEPROM.write(24, now.Second());
              restoreValuesFromEEPROM();
              lcd.setCursor(0, 0);
              lcd.print("  ALARM SAVED!  ");
              delay(1000); // Debounce
              lcd.clear();
              alarm2Mode = 0;
            }
            break;
          default:
            break;
        }
        break;
      case 3:
        switch (alarm3Mode){
          case 0:
            displayAlarmData(3, alarmTime3Day, alarmTime3Hour, alarmTime3Minute);
            displayAlarmStatus(alarm3Status);        
            if (buttonDownState == 0){
              alarm3Mode = 2;
              delay(500); // Debounce
              alarmTime3Day = EEPROM.read(30);
              if (alarmTime3Day < 1 || alarmTime3Day > 7) {
                alarmTime3Day = 1;
                EEPROM.write(30, alarmTime3Day);
                restoreValuesFromEEPROM();
              }
              lcd.clear();
            }
            if (buttonUpState == 0){
              delay(500); // Debounce
              alarm3Mode = 1;
              lcd.clear();
            }
            break;
          case 1:
            lcd.setCursor(0, 0);
            lcd.print("Activate Alarm? ");
            lcd.setCursor(0, 1);
            lcd.print("    YES | NO    ");
            if (buttonDownState == 0){
              alarm3Status = 1;
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("    Alarm 3     ");
              lcd.setCursor(0, 1);
              lcd.print("   Activated    ");
              delay(1000);
              EEPROM.write(33, alarm3Status);
              restoreValuesFromEEPROM();
              alarm3Mode = 0;
            }
            if (buttonUpState == 0){
              alarm3Status = 0;
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("    Alarm 3     ");
              lcd.setCursor(0, 1);
              lcd.print("  Deactivated   ");
              delay(1000);
              EEPROM.write(33, alarm3Status);
              restoreValuesFromEEPROM();
              alarm3Mode = 0;
            }
            break;
          case 2:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 3  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Day: " + dayOfWeekToString(alarmTime3Day));
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime3Day = (alarmTime3Day == 1) ? 7 : alarmTime3Day - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime3Day = (alarmTime3Day == 7) ? 1 : alarmTime3Day + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) { 
              alarm3Mode = 3;
              delay(500); // Debounce
              lcd.clear();
            }
            break;
          case 3:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 3  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Hour: " + String(formatTime12hr(alarmTime3Hour)) );
            formatAMPM(alarmTime3Hour);
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime3Hour = (alarmTime3Hour == 0) ? 23 : alarmTime3Hour - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime3Hour = (alarmTime3Hour == 23) ? 0 : alarmTime3Hour + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) { 
              alarm3Mode = 4;
              delay(500); // Debounce
              lcd.clear();
            }
            break;
          case 4:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 3  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Minute: " + String(alarmTime3Minute));
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime3Minute = (alarmTime3Minute == 0) ? 59 : alarmTime3Minute - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime3Minute = (alarmTime3Minute == 59) ? 0 : alarmTime3Minute + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) {
              lcd.clear();
              EEPROM.write(30, alarmTime3Day);
              EEPROM.write(31, alarmTime3Hour);
              EEPROM.write(32, alarmTime3Minute);
              EEPROM.write(34, now.Second());
              restoreValuesFromEEPROM();
              lcd.setCursor(0, 0);
              lcd.print("  ALARM SAVED!  ");
              delay(1000); // Debounce
              lcd.clear();
              alarm3Mode = 0;
            }
            break;
          default:
            break;
        }
        break;
      case 4:
        switch (alarm4Mode){
          case 0:
            displayAlarmData(4, alarmTime4Day, alarmTime4Hour, alarmTime4Minute);
            displayAlarmStatus(alarm4Status);        
            if (buttonDownState == 0){
              alarm4Mode = 2;
              delay(500); // Debounce
              alarmTime4Day = EEPROM.read(40);
              if (alarmTime4Day < 1 || alarmTime4Day > 7) {
                alarmTime4Day = 1;
                EEPROM.write(40, alarmTime4Day);
                restoreValuesFromEEPROM();
              }
              lcd.clear();
            }
            if (buttonUpState == 0){
              delay(500); // Debounce
              alarm4Mode = 1;
              lcd.clear();
            }
            break;
          case 1:
            lcd.setCursor(0, 0);
            lcd.print("Activate Alarm? ");
            lcd.setCursor(0, 1);
            lcd.print("    YES | NO    ");
            if (buttonDownState == 0){
              alarm4Status = 1;
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("    Alarm 4     ");
              lcd.setCursor(0, 1);
              lcd.print("   Activated    ");
              delay(1000);
              EEPROM.write(43, alarm4Status);
              restoreValuesFromEEPROM();
              alarm4Mode = 0;
            }
            if (buttonUpState == 0){
              alarm4Status = 0;
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("    Alarm 4     ");
              lcd.setCursor(0, 1);
              lcd.print("  Deactivated   ");
              delay(1000);
              EEPROM.write(43, alarm4Status);
              restoreValuesFromEEPROM();
              alarm4Mode = 0;
            }
            break;
          case 2:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 4  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Day: " + dayOfWeekToString(alarmTime4Day));
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime4Day = (alarmTime4Day == 1) ? 7 : alarmTime4Day - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime4Day = (alarmTime4Day == 7) ? 1 : alarmTime4Day + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) { 
              alarm4Mode = 3;
              delay(500); // Debounce
              lcd.clear();
            }
            break;
          case 3:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 4  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Hour: " + String(formatTime12hr(alarmTime4Hour)) );
            formatAMPM(alarmTime4Hour);
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime4Hour = (alarmTime4Hour == 0) ? 23 : alarmTime4Hour - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime4Hour = (alarmTime4Hour == 23) ? 0 : alarmTime4Hour + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) { 
              alarm4Mode = 4;
              delay(500); // Debounce
              lcd.clear();
            }
            break;
          case 4:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 4  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Minute: " + String(alarmTime4Minute));
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime4Minute = (alarmTime4Minute == 0) ? 59 : alarmTime4Minute - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime4Minute = (alarmTime4Minute == 59) ? 0 : alarmTime4Minute + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) {
              lcd.clear();
              EEPROM.write(40, alarmTime4Day);
              EEPROM.write(41, alarmTime4Hour);
              EEPROM.write(42, alarmTime4Minute);
              EEPROM.write(44, now.Second());
              restoreValuesFromEEPROM();
              lcd.setCursor(0, 0);
              lcd.print("  ALARM SAVED!  ");
              delay(1000); // Debounce
              lcd.clear();
              alarm4Mode = 0;
            }
            break;
          default:
            break;
        }
        break;
      case 5:
        switch (alarm5Mode){
          case 0:
            displayAlarmData(5, alarmTime5Day, alarmTime5Hour, alarmTime5Minute);
            displayAlarmStatus(alarm5Status);        
            if (buttonDownState == 0){
              alarm5Mode = 2;
              delay(500); // Debounce
              alarmTime5Day = EEPROM.read(50);
              if (alarmTime5Day < 1 || alarmTime5Day > 7) {
                alarmTime5Day = 1;
                EEPROM.write(50, alarmTime5Day);
                restoreValuesFromEEPROM();
              }
              lcd.clear();
            }
            if (buttonUpState == 0){
              delay(500); // Debounce
              alarm5Mode = 1;
              lcd.clear();
            }
            break;
          case 1:
            lcd.setCursor(0, 0);
            lcd.print("Activate Alarm? ");
            lcd.setCursor(0, 1);
            lcd.print("    YES | NO    ");
            if (buttonDownState == 0){
              alarm5Status = 1;
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("    Alarm 5     ");
              lcd.setCursor(0, 1);
              lcd.print("   Activated    ");
              delay(1000);
              EEPROM.write(53, alarm5Status);
              restoreValuesFromEEPROM();
              alarm5Mode = 0;
            }
            if (buttonUpState == 0){
              alarm5Status = 0;
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("    Alarm 5     ");
              lcd.setCursor(0, 1);
              lcd.print("  Deactivated   ");
              delay(1000);
              EEPROM.write(53, alarm5Status);
              restoreValuesFromEEPROM();
              alarm5Mode = 0;
            }
            break;
          case 2:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 5  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Day: " + dayOfWeekToString(alarmTime5Day));
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime5Day = (alarmTime5Day == 1) ? 7 : alarmTime5Day - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime5Day = (alarmTime5Day == 7) ? 1 : alarmTime5Day + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) { 
              alarm5Mode = 3;
              delay(500); // Debounce
              lcd.clear();
            }
            break;
          case 3:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 5  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Hour: " + String(formatTime12hr(alarmTime5Hour)) );
            formatAMPM(alarmTime5Hour);
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime5Hour = (alarmTime5Hour == 0) ? 23 : alarmTime5Hour - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime5Hour = (alarmTime5Hour == 23) ? 0 : alarmTime5Hour + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) { 
              alarm5Mode = 4;
              delay(500); // Debounce
              lcd.clear();
            }
            break;
          case 4:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 5  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Minute: " + String(alarmTime5Minute));
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime5Minute = (alarmTime5Minute == 0) ? 59 : alarmTime5Minute - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime5Minute = (alarmTime5Minute == 59) ? 0 : alarmTime5Minute + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) {
              lcd.clear();
              EEPROM.write(50, alarmTime5Day);
              EEPROM.write(51, alarmTime5Hour);
              EEPROM.write(52, alarmTime5Minute);
              EEPROM.write(54, now.Second());
              restoreValuesFromEEPROM();
              lcd.setCursor(0, 0);
              lcd.print("  ALARM SAVED!  ");
              delay(1000); // Debounce
              lcd.clear();
              alarm5Mode = 0;
            }
            break;
          default:
            break;
        }
        break;
      case 6:
        switch (alarm6Mode){
          case 0:
            displayAlarmData(6, alarmTime6Day, alarmTime6Hour, alarmTime6Minute);
            displayAlarmStatus(alarm6Status);        
            if (buttonDownState == 0){
              alarm6Mode = 2;
              delay(500); // Debounce
              alarmTime6Day = EEPROM.read(60);
              if (alarmTime6Day < 1 || alarmTime6Day > 7) {
                alarmTime6Day = 1;
                EEPROM.write(60, alarmTime6Day);
                restoreValuesFromEEPROM();
              }
              lcd.clear();
            }
            if (buttonUpState == 0){
              delay(500); // Debounce
              alarm6Mode = 1;
              lcd.clear();
            }
            break;
          case 1:
            lcd.setCursor(0, 0);
            lcd.print("Activate Alarm? ");
            lcd.setCursor(0, 1);
            lcd.print("    YES | NO    ");
            if (buttonDownState == 0){
              alarm6Status = 1;
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("    Alarm 6     ");
              lcd.setCursor(0, 1);
              lcd.print("   Activated    ");
              delay(1000);
              EEPROM.write(63, alarm6Status);
              restoreValuesFromEEPROM();
              alarm6Mode = 0;
            }
            if (buttonUpState == 0){
              alarm6Status = 0;
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("    Alarm 6     ");
              lcd.setCursor(0, 1);
              lcd.print("  Deactivated   ");
              delay(1000);
              EEPROM.write(63, alarm6Status);
              restoreValuesFromEEPROM();
              alarm6Mode = 0;
            }
            break;
          case 2:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 6  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Day: " + dayOfWeekToString(alarmTime6Day));
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime6Day = (alarmTime6Day == 1) ? 7 : alarmTime6Day - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime6Day = (alarmTime6Day == 7) ? 1 : alarmTime6Day + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) { 
              alarm6Mode = 3;
              delay(500); // Debounce
              lcd.clear();
            }
            break;
          case 3:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 6  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Hour: " + String(formatTime12hr(alarmTime6Hour)) );
            formatAMPM(alarmTime6Hour);
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime6Hour = (alarmTime6Hour == 0) ? 23 : alarmTime6Hour - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime6Hour = (alarmTime6Hour == 23) ? 0 : alarmTime6Hour + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) { 
              alarm6Mode = 4;
              delay(500); // Debounce
              lcd.clear();
            }
            break;
          case 4:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 6  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Minute: " + String(alarmTime6Minute));
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime6Minute = (alarmTime6Minute == 0) ? 59 : alarmTime6Minute - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime6Minute = (alarmTime6Minute == 59) ? 0 : alarmTime6Minute + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) {
              lcd.clear();
              EEPROM.write(60, alarmTime6Day);
              EEPROM.write(61, alarmTime6Hour);
              EEPROM.write(62, alarmTime6Minute);
              EEPROM.write(64, now.Second());
              restoreValuesFromEEPROM();
              lcd.setCursor(0, 0);
              lcd.print("  ALARM SAVED!  ");
              delay(1000); // Debounce
              lcd.clear();
              alarm6Mode = 0;
            }
            break;
          default:
            break;
        }
        break;
      case 7:
        switch (alarm7Mode){
          case 0:
            displayAlarmData(7, alarmTime7Day, alarmTime7Hour, alarmTime7Minute);
            displayAlarmStatus(alarm7Status);        
            if (buttonDownState == 0){
              alarm7Mode = 2;
              delay(500); // Debounce
              alarmTime7Day = EEPROM.read(70);
              if (alarmTime7Day < 1 || alarmTime7Day > 7) {
                alarmTime7Day = 1;
                EEPROM.write(70, alarmTime7Day);
                restoreValuesFromEEPROM();
              }
              lcd.clear();
            }
            if (buttonUpState == 0){
              delay(500); // Debounce
              alarm7Mode = 1;
              lcd.clear();
            }
            break;
          case 1:
            lcd.setCursor(0, 0);
            lcd.print("Activate Alarm? ");
            lcd.setCursor(0, 1);
            lcd.print("    YES | NO    ");
            if (buttonDownState == 0){
              alarm7Status = 1;
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("    Alarm 7     ");
              lcd.setCursor(0, 1);
              lcd.print("   Activated    ");
              delay(1000);
              EEPROM.write(73, alarm7Status);
              restoreValuesFromEEPROM();
              alarm7Mode = 0;
            }
            if (buttonUpState == 0){
              alarm7Status = 0;
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("    Alarm 7     ");
              lcd.setCursor(0, 1);
              lcd.print("  Deactivated   ");
              delay(1000);
              EEPROM.write(73, alarm7Status);
              restoreValuesFromEEPROM();
              alarm7Mode = 0;
            }
            break;
          case 2:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 7  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Day: " + dayOfWeekToString(alarmTime7Day));
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime7Day = (alarmTime7Day == 1) ? 7 : alarmTime7Day - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime7Day = (alarmTime7Day == 7) ? 1 : alarmTime7Day + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) { 
              alarm7Mode = 3;
              delay(500); // Debounce
              lcd.clear();
            }
            break;
          case 3:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 7  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Hour: " + String(formatTime12hr(alarmTime7Hour)) );
            formatAMPM(alarmTime7Hour);
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime7Hour = (alarmTime7Hour == 0) ? 23 : alarmTime7Hour - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime7Hour = (alarmTime7Hour == 23) ? 0 : alarmTime7Hour + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) { 
              alarm7Mode = 4;
              delay(500); // Debounce
              lcd.clear();
            }
            break;
          case 4:
            lcd.setCursor(0, 0);
            lcd.print("  Edit Alarm 7  ");
            lcd.setCursor(0, 1);
            lcd.print("Enter Minute: " + String(alarmTime7Minute));
            lcd.print("   ");
            if (buttonDownState == 0) {
              alarmTime7Minute = (alarmTime7Minute == 0) ? 59 : alarmTime7Minute - 1;
              delay(200); // Debounce
            }
            if (buttonUpState == 0) {
              alarmTime7Minute = (alarmTime7Minute == 59) ? 0 : alarmTime7Minute + 1;
              delay(200); // Debounce
            }
            if (buttonEnterState == 0) {
              lcd.clear();
              EEPROM.write(70, alarmTime7Day);
              EEPROM.write(71, alarmTime7Hour);
              EEPROM.write(72, alarmTime7Minute);
              EEPROM.write(74, now.Second());
              restoreValuesFromEEPROM();
              lcd.setCursor(0, 0);
              lcd.print("  ALARM SAVED!  ");
              delay(1000); // Debounce
              lcd.clear();
              alarm7Mode = 0;
            }
            break;
          default:
            break;
        }
        break;
      default:
        break;
    }
  }

  if (setAlarmSubmode == 0){
    if (buttonBackState != previousButtonBackState) { 
      previousButtonBackState = buttonBackState;
      if (buttonBackState == 0) {
        delay(500); // Debounce
        setAlarmMode = 0;
        restoreValuesFromEEPROM();
        lcd.clear();
      }
    }
    switch (setAlarmMode) {
      case 0:
        lcd.setCursor(0, 0);
        lcd.print("   Set Alarm    ");
        lcd.setCursor(0, 1);
        lcd.print("  PRESS ENTER   ");
        if (buttonEnterState == 0) { 
          delay(1000); // Debounce
          setAlarmMode = 1;
          lcd.clear();
        }
        break;
      case 1:
        lcd.setCursor(0, 0);
        lcd.print(" Alarm 01 | ");
        if (alarm1Status == 0){
          lcd.print("OFF ");
        }else{
          lcd.print("ON  ");
        }
        displayAlarm(alarmTime1Day, alarmTime1Hour, alarmTime1Minute);

        if (buttonEnterState == 0) { 
          delay(500); // Debounce
          setAlarmSubmode = 1;
          lcd.clear();
        }
        if (buttonDownState == 0) { 
          delay(500); // Debounce
          setAlarmMode = 7;
          lcd.clear();
        }
        if (buttonUpState == 0) { 
          delay(500); // Debounce
          setAlarmMode = 2;
          lcd.clear();
        }
        break;
      case 2:
        lcd.setCursor(0, 0);
        lcd.print(" Alarm 02 | ");
        if (alarm2Status == 0){
          lcd.print("OFF ");
        }else{
          lcd.print("ON  ");
        }
        displayAlarm(alarmTime2Day, alarmTime2Hour, alarmTime2Minute);
        if (buttonEnterState == 0) { 
          delay(500); // Debounce
          setAlarmSubmode = 2;
          lcd.clear();
        }
        if (buttonDownState == 0) { 
          delay(500); // Debounce
          setAlarmMode = 1;
          lcd.clear();
        }
        if (buttonUpState == 0) { 
          delay(500); // Debounce
          setAlarmMode = 3;
          lcd.clear();
        }
        break;
      case 3:
        lcd.setCursor(0, 0);
        lcd.print(" Alarm 03 | ");
        if (alarm3Status == 0){
          lcd.print("OFF ");
        }else{
          lcd.print("ON  ");
        }
        displayAlarm(alarmTime3Day, alarmTime3Hour, alarmTime3Minute);
        if (buttonEnterState == 0) { 
          delay(500); // Debounce
          setAlarmSubmode = 3;
          lcd.clear();
        }
        if (buttonDownState == 0) { 
          delay(500); // Debounce
          setAlarmMode = 2;
          lcd.clear();
        }
        if (buttonUpState == 0) { 
          delay(500); // Debounce
          setAlarmMode = 4;
          lcd.clear();
        }
        break;
      case 4:
        lcd.setCursor(0, 0);
        lcd.print(" Alarm 04 | ");
        if (alarm4Status == 0){
          lcd.print("OFF ");
        }else{
          lcd.print("ON  ");
        }
        displayAlarm(alarmTime4Day, alarmTime4Hour, alarmTime4Minute);
        if (buttonEnterState == 0) { 
          delay(500); // Debounce
          setAlarmSubmode = 4;
          lcd.clear();
        }
        if (buttonDownState == 0) { 
          delay(500); // Debounce
          setAlarmMode = 3;
          lcd.clear();
        }
        if (buttonUpState == 0) { 
          delay(500); // Debounce
          setAlarmMode = 5;
          lcd.clear();
        }
        break;
      case 5:
        lcd.setCursor(0, 0);
        lcd.print(" Alarm 05 | ");
        if (alarm5Status == 0){
          lcd.print("OFF ");
        }else{
          lcd.print("ON  ");
        }
        displayAlarm(alarmTime5Day, alarmTime5Hour, alarmTime5Minute);
        if (buttonEnterState == 0) { 
          delay(500); // Debounce
          setAlarmSubmode = 5;
          lcd.clear();
        }
        if (buttonDownState == 0) { 
          delay(500); // Debounce
          setAlarmMode = 4;
          lcd.clear();
        }
        if (buttonUpState == 0) { 
          delay(500); // Debounce
          setAlarmMode = 6;
          lcd.clear();
        }
        break;
      case 6:
        lcd.setCursor(0, 0);
        lcd.print(" Alarm 06 | ");
        if (alarm6Status == 0){
          lcd.print("OFF ");
        }else{
          lcd.print("ON  ");
        }
        displayAlarm(alarmTime6Day, alarmTime6Hour, alarmTime6Minute);
        if (buttonEnterState == 0) { 
          delay(500); // Debounce
          setAlarmSubmode = 6;
          lcd.clear();
        }
        if (buttonDownState == 0) { 
          delay(500); // Debounce
          setAlarmMode = 5;
          lcd.clear();
        }
        if (buttonUpState == 0) { 
          delay(500); // Debounce
          setAlarmMode = 7;
          lcd.clear();
        }
        break;
      case 7:
        lcd.setCursor(0, 0);
        lcd.print(" Alarm 07 | ");
        if (alarm7Status == 0){
          lcd.print("OFF ");
        }else{
          lcd.print("ON  ");
        }
        displayAlarm(alarmTime7Day, alarmTime7Hour, alarmTime7Minute);
        if (buttonEnterState == 0) { 
          delay(500); // Debounce
          setAlarmSubmode = 7;
          lcd.clear();
        }
        if (buttonDownState == 0) { 
          delay(500); // Debounce
          setAlarmMode = 6;
          lcd.clear();
        }
        if (buttonUpState == 0) { 
          delay(500); // Debounce
          setAlarmMode = 1;
          lcd.clear();
        }
        break;
      default:
        break;
    } 
  }
}

void displayAlarmStatus(bool status){
  lcd.setCursor(0, 1);
  lcd.print("   EDIT | ");
  if (status == false){
    lcd.print("OFF   ");
  }else{
    lcd.print("ON    ");
  }
}

void displayAlarm(uint8_t alarmTimeDay, uint8_t alarmTimeHour, uint8_t alarmTimeMinute){
  lcd.setCursor(0,1);
  lcd.print(" ");
  lcd.print(dayOfWeekToString(alarmTimeDay));
  lcd.print(" | ");
  lcd.print(formatTime12hr(alarmTimeHour));
  lcd.print(":");
  lcd.print(formatTime(alarmTimeMinute));
  formatAMPM(alarmTimeHour);
  lcd.print("       ");
}

void displayAlarmData(uint8_t alarmNumber, uint8_t alarmTimeDay, uint8_t alarmTimeHour, uint8_t alarmTimeMinute){
  lcd.setCursor(0, 0);
  lcd.print(" A:" + String(alarmNumber) + " ");
  lcd.print(dayOfWeekToString(alarmTimeDay));
  lcd.print(" ");
  lcd.print(formatTime12hr(alarmTimeHour));
  lcd.print(":");
  lcd.print(formatTime(alarmTimeMinute));
  formatAMPM(alarmTimeDay);
  lcd.print("    ");
}



void setDate() {
  uint8_t buttonEnterState = digitalRead(buttonEnter);
  uint8_t buttonDownState = digitalRead(buttonDown);
  uint8_t buttonUpState = digitalRead(buttonUp);
  uint8_t buttonBackState = digitalRead(buttonBack);
  RtcDateTime now = Rtc.GetDateTime();
  if (buttonBackState == 0) { 
      delay(500); // Debounce
      setDateTimeMode = 0;
      restoreValuesFromEEPROM();
      lcd.clear();
    }
  switch (setDateTimeMode) {
    case 0:
      lcd.setCursor(0, 0);
      lcd.print(" Set Date-Time  ");
      lcd.setCursor(0, 1);
      lcd.print("  PRESS ENTER   ");
      if (buttonEnterState == 0) { 
        delay(1000); // Debounce
        setDateTimeMode = 1;
        year = now.Year();
      }
      break;
    case 1:
      lcd.setCursor(0, 0);
      lcd.print("    Set Date    ");
      lcd.setCursor(0, 1);
      lcd.print("Enter Year: " + String(year));
      lcd.print("   ");
      if (buttonDownState == 0) {
        year--;
        delay(200); // Debounce
      }
      if (buttonUpState == 0) {
        year++;
        delay(200); // Debounce
      }
      if (buttonEnterState == 0) { 
        setDateTimeMode = 2;
        delay(500); // Debounce
        lcd.clear(); 
        month = now.Month();
      }
      break;
    case 2:
      lcd.setCursor(0, 1);
      lcd.print("Enter Month: " + String(month));
      lcd.print("   ");
      lcd.setCursor(0, 0);
      lcd.print("    Set Date    ");
      if (buttonDownState == 0) {
        month = (month == 1) ? 12 : month - 1;
        delay(200); // Debounce
      }
      if (buttonUpState == 0) {
        month = (month == 12) ? 1 : month + 1;
        delay(200); // Debounce
      }
      if (buttonEnterState == 0) { 
        setDateTimeMode = 3;
        delay(500); // Debounce
        lcd.clear();
        day = now.Day();
      }
      break;
    case 3:
      lcd.setCursor(0, 1);
      lcd.print(" Enter Day: " + String(day));
      lcd.print("   ");
      lcd.setCursor(0, 0);
      lcd.print("    Set Date    ");
      if (buttonDownState == 0) {
        day = (day == 1) ? 31 : day - 1;
        delay(200); // Debounce
      }
      if (buttonUpState == 0) {
        day = (day == 31) ? 1 : day + 1;
        delay(200); // Debounce
      }
      if (buttonEnterState == 0) { 
        setDateTimeMode = 4;
        delay(500); // Debounce
        lcd.clear();
        hour = now.Hour();
      }
      break;
    case 4:
      lcd.setCursor(0, 1);
      lcd.print("Enter Hour: " + String(formatTime12hr(hour)) );
      formatAMPM(hour);
      lcd.print("   ");
      lcd.setCursor(0, 0);
      lcd.print("    Set Time    ");
      if (buttonDownState == 0) {
        hour = (hour == 0) ? 23 : hour - 1;
        delay(200); // Debounce
      }
      if (buttonUpState == 0) {
        hour = (hour == 23) ? 0 : hour + 1;
        delay(200); // Debounce
      }
      if (buttonEnterState == 0) { 
        setDateTimeMode = 5;
        delay(500); // Debounce
        lcd.clear();
        minute = now.Minute();
      }
      break;
    case 5:
      lcd.setCursor(0, 1);
      lcd.print("Enter Minute: " + String(minute));
      lcd.print("   ");
      lcd.setCursor(0, 0);
      lcd.print("    Set Time    ");
      if (buttonDownState == 0) {
        minute = (minute == 0) ? 59 : minute - 1;
        delay(200); // Debounce
      }
      if (buttonUpState == 0) {
        minute = (minute == 59) ? 0 : minute + 1;
        delay(200); // Debounce
      }
      if (buttonEnterState == 0) { 
        setDateTimeMode = 6;
        delay(500); // Debounce
        lcd.clear();
        second = now.Second();
      }
      break;
    case 6:
      lcd.setCursor(0, 1);
      lcd.print("Enter Second: " + String(second));
      lcd.print("   ");
      lcd.setCursor(0, 0);
      lcd.print("    Set Time    ");
      if (buttonDownState == 0) {
        second = (second == 0) ? 59 : second - 1;
        delay(200); // Debounce
      }
      if (buttonUpState == 0) {
        second = (second == 59) ? 0 : second + 1;
        delay(200); // Debounce
      }
      if (buttonEnterState == 0) { 
        setDateTimeMode = 7;
        delay(500); // Debounce
        lcd.clear();
      }
      break;
    case 7:
      lcd.setCursor(0, 0);
      lcd.print("  Date & Time   ");
      lcd.setCursor(0, 1);
      lcd.print("    Updated!    ");
      RtcDateTime newTime = RtcDateTime(year, month, day, hour, minute, second);
      Rtc.SetDateTime(newTime);
      delay(1000);
      setDateTimeMode = 0;
      lcd.clear();
      break;
    default:
      break;
  }
}

void restoreValuesFromEEPROM() {

  
  alarmTime1Day = EEPROM.read(10);
  alarmTime1Hour = EEPROM.read(11);
  alarmTime1Minute = EEPROM.read(12);
  alarm1Status = EEPROM.read(13);
  alarmTime1Second = EEPROM.read(14);

  alarmTime2Day = EEPROM.read(20);
  alarmTime2Hour = EEPROM.read(21);
  alarmTime2Minute = EEPROM.read(22);
  alarm2Status = EEPROM.read(23);
  alarmTime2Second = EEPROM.read(24);

  alarmTime3Day = EEPROM.read(30);
  alarmTime3Hour = EEPROM.read(31);
  alarmTime3Minute = EEPROM.read(32);
  alarm3Status = EEPROM.read(33);
  alarmTime3Second = EEPROM.read(34);

  alarmTime4Day = EEPROM.read(40);
  alarmTime4Hour = EEPROM.read(41);
  alarmTime4Minute = EEPROM.read(42);
  alarm4Status = EEPROM.read(43);
  alarmTime4Second = EEPROM.read(44);

  alarmTime5Day = EEPROM.read(50);
  alarmTime5Hour = EEPROM.read(51);
  alarmTime5Minute = EEPROM.read(52);
  alarm5Status = EEPROM.read(53);
  alarmTime5Second = EEPROM.read(54);

  alarmTime6Day = EEPROM.read(60);
  alarmTime6Hour = EEPROM.read(61);
  alarmTime6Minute = EEPROM.read(62);
  alarm6Status = EEPROM.read(63);
  alarmTime6Second = EEPROM.read(64);

  alarmTime7Day = EEPROM.read(70);
  alarmTime7Hour = EEPROM.read(71);
  alarmTime7Minute = EEPROM.read(72);
  alarm7Status = EEPROM.read(73);
  alarmTime7Second = EEPROM.read(74);
}

// Time Formats
  String dayOfWeekToString(uint8_t dayOfWeek) {
    switch (dayOfWeek) {
      case 1: return "MON";
      case 2: return "TUE";
      case 3: return "WED";
      case 4: return "THU";
      case 5: return "FRI";
      case 6: return "SAT";
      case 7: return "SUN";
      default: return "";
    }
  }

  String formatTime(int time){
    char formattedtime[3];
    sprintf(formattedtime, "%02d", time);
    return formattedtime;
  }

  String formatTime12hr(int time) {
    time = (time == 0 || time == 12) ? 12 : time % 12;
    char formattedtime[3];
    sprintf(formattedtime, "%02d", time);
    return formattedtime;
  }

  void formatAMPM(int time) {
    String period = (time < 12) ? "AM" : "PM";
      if (period == "AM") {
        lcd.print("am");
      } else {
        lcd.print("pm");
      }
    }
  void loadTime(){
    RtcDateTime currentTime = RtcDateTime(__DATE__, __TIME__);
    // Rtc.SetDateTime(currentTime);
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