// EEPROM MEMORY
// 10 = for expDate
// 0 = for notif10Days
// 1 = for notif5Days
// 2 = for notif3Days
// 3 = for notifExpired
#include <ArduinoJson.h>        
#include <Wire.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>
#include <EEPROM.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

#define RELAY_PIN 10

ThreeWire myWire(12, 11, 13); // DAT, CLK, RST
RtcDS1302<ThreeWire> Rtc(myWire);

const byte ROWS = 4; // four rows
const byte COLS = 4; // three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}};
byte rowPins[ROWS] = {9, 8, 7, 6}; // connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; // connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Menu options
enum MenuOption
{
  SET_EXP_DATE,
  SET_DATE,
  SET_TIME,
  MANUAL,
  IDLEE,
  MENU,
  CHOOSE
};

MenuOption currentState = IDLEE;
int chosenOption = 5;
int daysRemaining = 99; 
 
bool deviceEnabled = true;
bool manualEnabled = false;
 
RtcDateTime expDate;
int expDateTotalDays;

bool notif10Days = false;
bool notif5Days = false;
bool notif3Days = false;
bool notifExpired = false;

void setup(){
  Serial.begin(115200);
  Rtc.Begin();
  lcd.begin();
  lcd.backlight();
  pinMode(RELAY_PIN, OUTPUT);

  RtcDateTime currentTime = RtcDateTime(__DATE__, __TIME__);
  if (!Rtc.IsDateTimeValid())
  {
    Serial.println("RTC lost confidence in the DateTime!");
    Rtc.SetDateTime(currentTime);
  }
  if (Rtc.GetIsWriteProtected())
  {
    Serial.println("RTC was write protected, enabling writing now");
    Rtc.SetIsWriteProtected(false);
  }
  if (!Rtc.GetIsRunning())
  {
    Serial.println("RTC was not actively running, starting now");
    Rtc.SetIsRunning(true);
  }
  RtcDateTime now = Rtc.GetDateTime();
  if (now < currentTime)
  {
    Serial.println("RTC is older than compile time!  (Updating DateTime)");
    Rtc.SetDateTime(currentTime);
  }
  else if (now > currentTime)
  {
    Serial.println("RTC is newer than compile time. (this is expected)");
  }
  else if (now == currentTime)
  {
    Serial.println("RTC is the same as compile time! (not expected but all is fine)");
  }
  Serial.println("restartNODEMCU");
  restoreSettingsFromEEPROM();
}

void loop(){
  notif();
  deviceActivate();

  char key = keypad.getKey();
  if (key){
    Serial.println(key);
  }

  switch (currentState){
    case IDLEE:
      if (key == '#'){
        currentState = MENU;
      }
      break;

    case MENU:
      lcd.setCursor(0, 0);
      lcd.print("      MENU      ");
      lcd.setCursor(0, 1);
      lcd.print("   A  B  C  D   ");

      switch (key){
        case 'A':
          chosenOption = SET_EXP_DATE;
          currentState = CHOOSE;
          break;
        case 'B':
          chosenOption = SET_DATE;
          currentState = CHOOSE;
          break;
        case 'C':
          chosenOption = SET_TIME;
          currentState = CHOOSE;
          break;
        case 'D':
          chosenOption = MANUAL;
          currentState = CHOOSE;
          break;
      }
      if (key == '*'){
        currentState = IDLEE;
      }
      break;

    case CHOOSE:
      switch (chosenOption){
        case SET_EXP_DATE:
          setExpDate();
          break;
        case SET_DATE:
          setDate();
          break;
        case SET_TIME:
          setTime();
          break;
        case MANUAL:
          manual();
          break;
      }

      break;
  }

  if (currentState == IDLEE){
    Idle();
  }
  
  if (!manualEnabled){
    RtcDateTime now = Rtc.GetDateTime();
    daysRemaining = expDate.TotalDays() - now.TotalDays() ;
    Serial.println("vendoExpDays: " + String(daysRemaining));
    if (daysRemaining <= 0 ){
      deviceEnabled = false;
      Serial.println("VendoOff");
    }else{
      deviceEnabled = true;
      Serial.println("VendoOn");
    }
  }

}

void setExpDate() {
  static String inputDays = "____"; // Placeholder for input
  static int digitCount = 0;

  lcd.setCursor(0, 0);
  lcd.print("  SET EXP DATE  ");
  lcd.setCursor(0, 1);
  lcd.print("  Current:      ");
  lcd.setCursor(11, 1);
  lcd.print(daysRemaining);


  char key = keypad.getKey();
  if (key == '#') {
    lcd.setCursor(0, 0);
    lcd.print("  SET EXP DATE  ");
    lcd.setCursor(0, 1);
    lcd.print("Enter Days: ____");
    int daysToAdd = getData(4, 12);
    addDays(daysToAdd);
    lcd.setCursor(0, 0);
    lcd.print("   DATA SAVED   ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    Serial.println("resetNotif");
    delay(500);
  }
  if (key == '*'){
    currentState = MENU;
  }
}

void setDate() {
  RtcDateTime now = Rtc.GetDateTime();
  lcd.setCursor(0, 0);
  lcd.print("    SET DATE    ");
  lcd.setCursor(0, 1);
  lcd.print("Date: ");
  lcd.print(now.Month());
  lcd.print("-");
  lcd.print(now.Day());
  lcd.print("-");
  lcd.print(now.Year());
  lcd.print("  ");

  //Set the Date and Time Manually when '*' key is pressed
  char key = keypad.getKey();
  if (key == '#') {
    lcd.setCursor(0, 1);
    lcd.print("Enter Year: ____");
    int year = getData(4, 12);

    lcd.setCursor(0, 1);
    lcd.print(" Enter Mon: __  ");
    int month = getData(2, 12);

    lcd.setCursor(0, 1);
    lcd.print(" Enter Day: __  ");
    int day = getData(2, 12);
    
    lcd.setCursor(0, 0);
    lcd.print("   DATA SAVED   ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    RtcDateTime newTime = RtcDateTime(year, month, day, now.Hour(), now.Minute(), now.Second());
    Rtc.SetDateTime(newTime);
    delay(500);
  }
  if (key == '*'){
    currentState = MENU;
  }
}

void setTime() {
  RtcDateTime now = Rtc.GetDateTime();
  lcd.setCursor(0, 0);
  lcd.print("    SET TIME    ");
  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  lcd.print(now.Hour());
  lcd.print(":");
  lcd.print(now.Minute());
  lcd.print(":");
  lcd.print(now.Second());
  lcd.print("    ");

  //Set the Date and Time Manually when '*' key is pressed
  char key = keypad.getKey();
  if (key == '#') {
    lcd.setCursor(0, 1);
    lcd.print(" Enter Hour: __ ");
    int hour = getData(2, 13);

    lcd.setCursor(0, 1);
    lcd.print("  Enter Min: __ ");
    int minutes = getData(2, 13);

    lcd.setCursor(0, 1);
    lcd.print("  Enter Sec: __ ");
    int seconds = getData(2, 13);
    
    lcd.setCursor(0, 0);
    lcd.print("   DATA SAVED   ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    RtcDateTime newTime = RtcDateTime(now.Year(), now.Month(), now.Day(), hour, minutes, seconds);
    Rtc.SetDateTime(newTime);
    delay(500);
  }
  if (key == '*'){
    currentState = MENU;
  }
}

void manual() {
  lcd.setCursor(0, 0);
  lcd.print(" MANUAL CONTROL ");
  lcd.setCursor(0, 1);
  lcd.print("1 = ON | 0 = OFF");
  char key = keypad.getKey();
  if (key == '1') {
    lcd.setCursor(0, 0);
    lcd.print("   SET DEVICE   ");
    lcd.setCursor(0, 1);
    lcd.print("  1=ON | 0=OFF  ");
    manualEnabled = true;
    deviceEnabled = setDevice();
    lcd.setCursor(0, 0);
    lcd.print(" MANUAL CNTRL ON");
    lcd.setCursor(0, 1);
    if (deviceEnabled){
      // Serial.println("VendoManualOn");
      lcd.print(" DEVICE ENABLED ");
    }else{
      // Serial.println("VendoManualOff");
      lcd.print("DEVICE  DISABLED");
    }
    
    delay(500);
  }else if (key == '0') {
    lcd.setCursor(0, 0);
    lcd.print("   DATA SAVED   ");
    lcd.setCursor(0, 1);
    lcd.print("MANUAL CNTRL OFF");
    deviceEnabled = false;
    manualEnabled = false;
    delay(500);
  }
  if (key == '*'){
    currentState = MENU;
  }
}

void Idle() {
  RtcDateTime now = Rtc.GetDateTime();
  int currentHour = now.Hour();
  int currentMinute = now.Minute();
  int currentSecond = now.Second();
  int currentYear = now.Year();
  int currentMonth = now.Month();
  int currentDay = now.Day();
  int lastTwoDigitsYear = currentYear % 100;
  lcd.setCursor(0, 0);
  printDigitsLCD(currentHour);
  lcd.print(":");
  printDigitsLCD(currentMinute);
  lcd.print("   ");

  lcd.setCursor(8, 0);
  printDigitsLCD(currentMonth);
  lcd.print("-");
  printDigitsLCD(currentDay);
  lcd.print("-");
  printDigitsLCD(lastTwoDigitsYear);

  if (manualEnabled){
    lcd.setCursor(0, 1);
    lcd.print("MANUAL    ");
  }else{
    lcd.setCursor(0, 1);
    lcd.print("DAYS:     ");
    lcd.setCursor(5, 1);
    lcd.print(daysRemaining);
  }

  if (deviceEnabled) {
    lcd.setCursor(11, 1);
    lcd.print("S:   ");
    lcd.setCursor(13, 1);
    lcd.print("ON");
  }else{
    lcd.setCursor(11, 1);
    lcd.print("S:   ");
    lcd.setCursor(13, 1);
    lcd.print("OFF");
  }

  

}

void notif(){
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    if (command.startsWith("Notif10: ")) {
      int notif10Val = command.substring(9).toInt();
      if (notif10Days != notif10Val){
        EEPROM.write(0, notif10Val);
        notif10Days = notif10Val;
      }
    }else if (command.startsWith("Notif5: ")) {
      int notif5Val = command.substring(8).toInt();
      if (notif5Days != notif5Val){
        EEPROM.write(1, notif5Val);
        notif5Days = notif5Val;
      }
    }else if (command.startsWith("Notif3: ")) {
      int notif3Val = command.substring(8).toInt();
      if (notif3Days != notif3Val){
        EEPROM.write(2, notif3Val);
        notif3Days = notif3Val;
      }
    }else if (command.startsWith("NotifX: ")) {
      int notifXVal = command.substring(8).toInt();
      if (notifExpired != notifXVal){
        EEPROM.write(3, notifXVal);
        notifExpired = notifXVal;
      }
    }
  }
  
  if (!notif10Days){
    if (daysRemaining == 10){
      Serial.println("tenDaysNotif");
    }
  }
  if (!notif5Days){
    if (daysRemaining == 5){
      Serial.println("fiveDaysNotif");
    }
  }
  if (!notif3Days){
    if (daysRemaining == 3){
      Serial.println("threeDaysNotif");
    }
  }
  if (!notifExpired){
    if (daysRemaining <= 0){
      Serial.println("expiredNotif");
    }
  }
}

int getData(int length, int curser) {
  String container = "";
  lcd.setCursor(curser, 1);
  while (true) {
    char key = keypad.getKey();
    if (key == '#') {
      Serial.println(container.length());
      break;
    } else if (isDigit(key) && container.length() < length) {
      container += key;
      lcd.print(key);
    } else {
      //Nothing
    }
  }
  return container.toInt();
}
void printDigitsLCD(int digits) {
  if (digits < 10)
    lcd.print("0");
  lcd.print(digits);
}
int setDevice() {
  char key = keypad.getKey();
  
  while (key != '1' && key != '0') {
    key = keypad.getKey();
  }
  return (key == '1');
}
void updateExpDate(int days) {
  RtcDateTime now = Rtc.GetDateTime();
  int currentYear = 2000;
  int currentMonth = 1;
  int currentDay = 1;
  
  for (int i = 0; i < days; i++) {
    currentDay++;

    if (currentDay > daysInMonth(currentMonth, currentYear)) {
      currentDay = 1; 
      currentMonth++; 
      if (currentMonth > 12) {
        currentMonth = 1; 
        currentYear++;   
      }
    }
  }
  expDate = RtcDateTime(currentYear, currentMonth,currentDay, now.Hour(), now.Minute(), now.Second());
}
void addDays(int days) {
  RtcDateTime now = Rtc.GetDateTime();
  int currentYear = now.Year();
  int currentMonth = now.Month();
  int currentDay = now.Day();
  
  for (int i = 0; i < days; i++) {
    currentDay++;

    if (currentDay > daysInMonth(currentMonth, currentYear)) {
      currentDay = 1; 
      currentMonth++; 
      if (currentMonth > 12) {
        currentMonth = 1; 
        currentYear++;   
      }
    }
  }
  expDate = RtcDateTime(currentYear, currentMonth,currentDay, now.Hour(), now.Minute(), now.Second());
  int expDateTotalDays = expDate.TotalDays();
  write2BytesIntIntoEEPROM(10, expDateTotalDays);
}
int daysInMonth(int month, int year) {
  int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    days[2] = 29; 
  }

  return days[month];
}
void write2BytesIntIntoEEPROM(int address, int number){
  byte byte1 = (number >> 8) & 0xFF;
  byte byte2 = number & 0xFF;

  EEPROM.write(address, byte1);
  EEPROM.write(address + 1, byte2);
}
int read2BytesIntFromEEPROM(int add){
  byte byte1 = EEPROM.read(add);
  byte byte2 = EEPROM.read(add + 1);

  int result = (byte1 << 8) + byte2;
  return result;
}
void deviceActivate(){
  if (deviceEnabled){
    digitalWrite(RELAY_PIN, LOW);
  }else{
    digitalWrite(RELAY_PIN, HIGH);
  }
}
void restoreSettingsFromEEPROM() {
  expDateTotalDays = read2BytesIntFromEEPROM(10);
  updateExpDate(expDateTotalDays);

  notif10Days = EEPROM.read(0);
  notif5Days = EEPROM.read(1);
  notif3Days = EEPROM.read(2);
  notifExpired = EEPROM.read(3);
}
