// EEPROM MEMORY
// 0 = for timeduration
// 1 = if 9am is already run
// 2 = if 3pm is already run
// 3 = for demohour
// 4 = for demominute
// 5 = for demosecond
// 6 = for demoduration
// 7 = if alarm is already run

#include <Wire.h> 
#include <ThreeWire.h> 
#include <LiquidCrystal_I2C.h>
#include <RtcDS1302.h>
#include "DHT.h"
#include <EEPROM.h>

// Button pin definitions
#define BUTTON_PREV_PIN 3
#define BUTTON_NEXT_PIN 4
#define BUTTON_ENTER_PIN 5

#define RELAY_PIN 9

#define DHTPIN 10
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

// Menu options
enum MenuOption {
  SET_TIMER,
  ACTIVATE_TIMER,
  MANUAL_CONTROL,
  DEMO_SETUP,
  ACTIVATE_DEMO
};

LiquidCrystal_I2C lcd(0x27, 16, 2);

MenuOption currentOption = SET_TIMER;

bool optionSelected = false;
int chosenOption = 0;

// Set Timer
int prevDecrementButtonState = HIGH;
int prevIncrementButtonState = HIGH;
int timerDuration = 0;

int isClickedOFFON = 2; //0=OFFclicked, 1 = ONclicked

// Activate Timer
int minutes = 0;
int seconds = 0;
unsigned long previousMillis = 0;  // Stores the last time the countdown was updated
unsigned long interval = 1000;

// Demo settings
int demohour = 0; 
int demominute = 0;
int demosecond = 0;
int demoduration = 1;
int dminutes = 0;
int dseconds = 0;
enum State {
  HOUR,
  MINUTE,
  SECOND,
  DURATION,
  SAVED
};
State currentState = HOUR;

bool motorState = false;
bool isSprinklerRun[2] = {false, false}; 

ThreeWire myWire(7, 6, 8);
RtcDS1302<ThreeWire> Rtc(myWire);

void setup() {
  // Initialize buttons as inputs with pull-up resistors
  pinMode(BUTTON_PREV_PIN, INPUT_PULLUP);
  pinMode(BUTTON_NEXT_PIN, INPUT_PULLUP);
  pinMode(BUTTON_ENTER_PIN, INPUT_PULLUP);
  pinMode(RELAY_PIN, OUTPUT);

  Serial.begin(9600);
  Rtc.Begin();
  lcd.begin();
  lcd.backlight();
  dht.begin();
  
  // >                         RtcDateTime(year, month, day, hour, minute, second)
  // RtcDateTime currentTime = RtcDateTime(2023, 7, 18, 23, 59, 50); // Manual Time
  
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
  if (now < currentTime) {
    Serial.println("RTC is older than compile time!  (Updating DateTime)");
    Rtc.SetDateTime(currentTime);
  }else if (now > currentTime) {
    Serial.println("RTC is newer than compile time. (this is expected)");
  }else if (now == currentTime) {
    Serial.println("RTC is the same as compile time! (not expected but all is fine)");
  }

  restoreSettingsFromEEPROM();
}

void loop() {
  if (!optionSelected){
    handleButtons();
    handleNavigations();
  } 
  else{
    if (chosenOption == 0){
      setTimerDuration();
    }else if (chosenOption == 1){
      activateTimer();
    }else if (chosenOption == 2){
      manualControl();
    }else if (chosenOption == 3){
      setDemoSetup();
    }else if (chosenOption == 4){
      activateDemo();
    }
  }

  motorActivate();
  // Serial.print("9am: ");
  // Serial.print(isSprinklerRun[0]);
  // Serial.print(" 3pm: ");
  // Serial.println(isSprinklerRun[1]);

  // Reset the sprinkler run status at midnight
  RtcDateTime time = Rtc.GetDateTime();
  int currentTime = time.Hour();
  if (currentTime == 0) {
    isSprinklerRun[0] = false;
    isSprinklerRun[1] = false;
    EEPROM.write(1, isSprinklerRun[0]);
    EEPROM.write(2, isSprinklerRun[1]);
    restoreSettingsFromEEPROM(); //update the variables
  }
}

void handleNavigations() {
  switch (currentOption) {
    case SET_TIMER:
      TimeTempHumidDisplay();
      lcd.setCursor(0, 1);
      lcd.print("   Set Timer    ");
      break;
    case ACTIVATE_TIMER:
      TimeTempHumidDisplay();
      lcd.setCursor(0, 1);
      lcd.print(" Activate Timer ");
      break;
    case MANUAL_CONTROL:
      TimeTempHumidDisplay();
      lcd.setCursor(0, 1);
      lcd.print(" Manual Control ");
      break;
    case DEMO_SETUP:
      TimeTempHumidDisplay();
      lcd.setCursor(0, 1);
      lcd.print("   Demo Setup   ");
      break;
    case ACTIVATE_DEMO:
      TimeTempHumidDisplay();
      lcd.setCursor(0, 1);
      lcd.print("  Activate Demo ");
      break;
  }
}

static unsigned long lastButtonPress = 0;
void handleButtons() {
  const unsigned long buttonDebounceDelay = 200;
  
  if (millis() - lastButtonPress < buttonDebounceDelay) {
    return;  // Ignore button presses within the debounce delay
  }
  
  // Check button states
  int prevButtonState = digitalRead(BUTTON_PREV_PIN);
  int nextButtonState = digitalRead(BUTTON_NEXT_PIN);
  int enterButtonState = digitalRead(BUTTON_ENTER_PIN);
  
  if (enterButtonState == LOW) {
    lcd.clear();
    handleEnterButton();
    optionSelected = true;
    lastButtonPress = millis();
  } else if (prevButtonState == LOW) {
    lcd.clear();  
    navigateMenu(false);  // Go to previous option
    lastButtonPress = millis();
  } else if (nextButtonState == LOW) {
    lcd.clear();  
    navigateMenu(true);  // Go to next option
    lastButtonPress = millis();
  }
}

void navigateMenu(bool forward) {
  int numOptions = 5;  // Adjust if more options are added
  
  if (forward) {
    currentOption = static_cast<MenuOption>((currentOption + 1) % numOptions);
  } else {
    currentOption = static_cast<MenuOption>((currentOption + numOptions - 1) % numOptions);
  }
}

void handleEnterButton() {
  switch (currentOption) {
    case SET_TIMER:
      delay(200);
      chosenOption = 0;
      break;
    case ACTIVATE_TIMER:
      delay(200);
      chosenOption = 1;
      break;
    case MANUAL_CONTROL:
      delay(200);
      chosenOption = 2;
      break;
    case DEMO_SETUP:
      chosenOption = 3;
      delay(200);
      break;
    case ACTIVATE_DEMO:
      delay(200);
      chosenOption = 4;
      break;
  }
}

void restoreSettingsFromEEPROM() {
  timerDuration = EEPROM.read(0); // Read the duration value from EEPROM
  minutes = timerDuration;
  isSprinklerRun[0] = EEPROM.read(1); //9am
  isSprinklerRun[1] = EEPROM.read(2); //3pm
  demohour = EEPROM.read(3); //demohour
  demominute = EEPROM.read(4); //demominute
  demosecond = EEPROM.read(5); //demosecond
  demoduration = EEPROM.read(6); //demoduration
  dminutes = demoduration;
}

void setTimerDuration() {
  int decrementButtonState = digitalRead(BUTTON_PREV_PIN);
  int incrementButtonState = digitalRead(BUTTON_NEXT_PIN);
  int enterButtonState = digitalRead(BUTTON_ENTER_PIN);
  bool ischanged = false;
  lcd.setCursor(0, 0);
  lcd.print("Time:9am and 3pm");
  lcd.setCursor(0, 1);
  lcd.print("Duration min:");
  printDigitsLCD(timerDuration);

  if (incrementButtonState == LOW && prevIncrementButtonState == HIGH) {
    if (timerDuration == 60) {
      timerDuration = 1; // Wrap around to 1 when reaching 60
    } else {
      timerDuration++;
    }
  }

  if (decrementButtonState == LOW && prevDecrementButtonState == HIGH) {
    if (timerDuration == 1) {
      timerDuration = 60; // Wrap around to 60 when reaching 1
    } else {
      timerDuration--;
    }
  }

  if (timerDuration != EEPROM.read(0)) {
    ischanged = true;
  } else {
    ischanged = false;
  }

  if (enterButtonState == LOW && ischanged) {
    EEPROM.write(0, timerDuration); // Save the number to EEPROM
    minutes = timerDuration;
    lcd.clear();
    lcd.setCursor(0, 0);
    TimeTempHumidDisplay();
    lcd.setCursor(2, 1);
    lcd.print("Data saved!");
    delay(1000);
    lcd.clear();
    optionSelected = false;
    restoreSettingsFromEEPROM(); //update the variables
  }

  if (enterButtonState == LOW && !ischanged) {
    delay(200);
    lcd.clear();
    optionSelected = false;
  }

  prevIncrementButtonState = incrementButtonState;
  prevDecrementButtonState = decrementButtonState;
}

void activateTimer() {
  unsigned long currentMillis = millis(); 
  RtcDateTime now = Rtc.GetDateTime();
  int currentHour = now.Hour();
  int backButtonState = digitalRead(BUTTON_ENTER_PIN);

  if (isClickedOFFON == 1){
    motorState = true;
    lcd.setCursor(0, 0);
    lcd.print("  Sprinkler ON  ");
    if (currentMillis - previousMillis >= interval) {
      if (seconds > 0) {
        seconds--;
      } else {
        if (minutes > 0) {
          minutes--;
          seconds = 59;
        }
      }
      previousMillis = currentMillis;
    } 
    // Display the countdown on the LCD
    lcd.setCursor(0, 1);
    lcd.print("      ");
    printDigitsLCD(minutes);
    lcd.print(":");
    printDigitsLCD(seconds);
    lcd.setCursor(11, 1);
    lcd.print("      ");
    if (minutes == 0 && seconds == 0) {
      isClickedOFFON = 2;
      lcd.setCursor(0, 0);
      lcd.print("  Sprinkler OFF ");
      if (currentHour == 9) {
        isSprinklerRun[0] = true;
        EEPROM.write(1, isSprinklerRun[0]);
        restoreSettingsFromEEPROM(); //update the variables
      } else if (currentHour == 15) {
        isSprinklerRun[1] = true;
        EEPROM.write(2, isSprinklerRun[1]);
        restoreSettingsFromEEPROM(); //update the variables
      }
      delay(1000);
    }
  } else {
    motorState = false;
    lcd.setCursor(0, 0);
    TimeTempHumidDisplay();
    lcd.setCursor(0, 1);
    lcd.print("Time:");
    printDigitsLCD(timerDuration);
    lcd.setCursor(7, 1);
    lcd.print("  9am 3pm");
  }

  if ((currentHour == 9 && !isSprinklerRun[0]) ||
      (currentHour == 15 && !isSprinklerRun[1])) {
    isClickedOFFON = 1;
  } else {
    isClickedOFFON = 2;
  }

  if (backButtonState == LOW) {
    delay(200);
    minutes = timerDuration;
    seconds = 0;
    previousMillis = 0;  // Stores the last time the countdown was updated
    lcd.clear();
    motorState = false;
    isClickedOFFON = 2;
    optionSelected = false;
  }
}

void manualControl() {
  int offButtonState = digitalRead(BUTTON_PREV_PIN);
  int onButtonState = digitalRead(BUTTON_NEXT_PIN);
  int backButtonState = digitalRead(BUTTON_ENTER_PIN);
  lcd.setCursor(0, 0);
  TimeTempHumidDisplay();
  if (isClickedOFFON == 0){
    lcd.setCursor(0, 1);
    lcd.print(" Motor Pump OFF  ");
  }else if (isClickedOFFON == 1){
    lcd.setCursor(0, 1);
    lcd.print(" Motor Pump ON   ");
  }else{
    lcd.setCursor(0, 1);
    lcd.print("Press OFF and ON");
  }

  if (offButtonState == LOW) {
    isClickedOFFON = 0;
    motorState = false;
  }
  if (onButtonState == LOW) {
    isClickedOFFON = 1;
    motorState = true;
  }
  if (backButtonState == LOW) {
    delay(200);
    lcd.clear();
    motorState = false;
    isClickedOFFON = 2;
    optionSelected = false;
  }
}

void setDemoSetup() {
  if (currentState != SAVED) {
    displayCurrentState();   
    if (digitalRead(BUTTON_NEXT_PIN) == LOW) {      // If "Up" button is pressed
      increaseCurrentValue();                   // Increase the current value
      displayCurrentState();                     // Update the display
      delay(200);                                // Delay for button debounce
    }

    if (digitalRead(BUTTON_PREV_PIN) == LOW) {    // If "Down" button is pressed
      decreaseCurrentValue();                   // Decrease the current value
      displayCurrentState();                     // Update the display
      delay(200);                                // Delay for button debounce
    }
  }
  if (digitalRead(BUTTON_ENTER_PIN) == LOW) {    // If "Enter" button is pressed
    if (currentState == DURATION) {
      currentState = SAVED;
      saveSettings();                          // Save the settings
      delay(200);                               // Delay for button debounce
    } else {
      nextState();                              // Move to the next state
      displayCurrentState();                    // Update the display
      delay(200);                               // Delay for button debounce
    }
  }
}

void activateDemo() {
  unsigned long currentMillis = millis();
  int backButtonState = digitalRead(BUTTON_ENTER_PIN);
  RtcDateTime now = Rtc.GetDateTime();
  int currentHour = now.Hour();
  int currentMinute = now.Minute();
  int currentSecond = now.Second();

  if (isClickedOFFON == 1){
    motorState = true;
    lcd.setCursor(0, 0);
    lcd.print("  Sprinkler ON  ");
    if (currentMillis - previousMillis >= interval) {
      if (dseconds > 0) {
        dseconds--;
      } else {
        if (dminutes > 0) {
          dminutes--;
          dseconds = 59;
        }
      }
      previousMillis = currentMillis;
    } 
    // Display the countdown on the LCD
    lcd.setCursor(0, 1);
    lcd.print("      ");
    printDigitsLCD(dminutes);
    lcd.print(":");
    printDigitsLCD(dseconds);
    lcd.setCursor(11, 1);
    lcd.print("      ");
    if (dminutes == 0 && dseconds == 0) {
      isClickedOFFON = 2;
      lcd.setCursor(0, 0);
      lcd.print("  Sprinkler OFF ");
      delay(1000);
    }
  } else {
    motorState = false;
    lcd.setCursor(0, 0);
    lcd.print("Time: ");
    printDigitsLCD(demohour);
    lcd.print(":");
    printDigitsLCD(demominute);
    lcd.print(":");
    printDigitsLCD(demosecond);
    lcd.setCursor(14, 0);
    lcd.print("  ");
    lcd.setCursor(0, 1);
    lcd.print("Duration min: ");
    printDigitsLCD(demoduration);
  }

  if (currentHour == demohour && currentMinute == demominute && currentSecond == demosecond) {
    isClickedOFFON = 1;
  } 

  if (backButtonState == LOW) {
    delay(200);
    dminutes = demoduration;
    dseconds = 0;
    previousMillis = 0;  // Stores the last time the countdown was updated
    lcd.clear();
    motorState = false;
    isClickedOFFON = 2;
    optionSelected = false;
  }
}

void printDigitsLCD(int digits) {
  if (digits < 10)
    lcd.print("0");
  lcd.print(digits);
}
// DEMO SETUP
void increaseCurrentValue() {
  switch (currentState) {
    case HOUR:
      demohour = (demohour + 1) % 24;    // Ensure hour rolls over to 0 when reaching 23
      break;
    case MINUTE:
      demominute = (demominute + 1) % 60;  // Ensure minute rolls over to 0 when reaching 59
      break;
    case SECOND:
      demosecond = (demosecond + 1) % 60;  // Ensure second rolls over to 0 when reaching 59
      break;
    case DURATION:
      demoduration = (demoduration % 60) + 1; // Ensure duration stays within 1 to 60 range
      break;
    default:
      break;
  }
}

void decreaseCurrentValue() {
  switch (currentState) {
    case HOUR:
      demohour = (demohour + 23) % 24;   // Ensure hour rolls over to 23 when reaching 0
      break;
    case MINUTE:
      demominute = (demominute + 59) % 60; // Ensure minute rolls over to 59 when reaching 0
      break;
    case SECOND:
      demosecond = (demosecond + 59) % 60; // Ensure second rolls over to 59 when reaching 0
      break;
    case DURATION:
      if (demoduration == 1) {
        demoduration = 60; // Set to 60 when reaching 1 to ensure no value of 0
      } else {
        demoduration = (demoduration + 59) % 60; // Ensure duration rolls over to 59 when reaching 1
      }
      break;
    default:
      break;
  }
}

void nextState() {
  switch (currentState) {
    case HOUR:
      currentState = MINUTE;
      break;
    case MINUTE:
      currentState = SECOND;
      break;
    case SECOND:
      currentState = DURATION;
      break;
    default:
      break;
  }
}

void displayTime(int col, int row, bool blink, int val) {
  if (blink && millis() % 1000 < 500) {
    lcd.setCursor(col, row);
    lcd.print("  ");
  } else {
    lcd.setCursor(col, row);
    printDigitsLCD(val);
  }
}

void displayCurrentState() {
  lcd.setCursor(0, 0);
  lcd.print("Time: ");

  bool blinkHour = currentState == HOUR && millis() % 1000 < 500;
  bool blinkMinute = currentState == MINUTE && millis() % 1000 < 500;
  bool blinkSecond = currentState == SECOND && millis() % 1000 < 500;
  bool blinkDuration = currentState == DURATION && millis() % 1000 < 500;

  displayTime(6, 0, blinkHour, demohour);
  lcd.print(":");
  displayTime(9, 0, blinkMinute, demominute);
  lcd.print(":");
  displayTime(12, 0, blinkSecond, demosecond);
  lcd.setCursor(14, 0);
  lcd.print("  ");
  lcd.setCursor(0, 1);
  lcd.print("Duration min: ");
  displayTime(14, 1, blinkDuration, demoduration);
}

void saveSettings() {
  EEPROM.write(3, demohour); // Save the demohour to EEPROM
  EEPROM.write(4, demominute); // Save the demominute to EEPROM
  EEPROM.write(5, demosecond); // Save the demosecond to EEPROM
  EEPROM.write(6, demoduration); // Save the demoduration to EEPROM
  lcd.clear();                               // Clear the LCD display
  lcd.setCursor(2, 1);
  lcd.print("Data saved!");
  delay(1000);
  lcd.clear();
  currentState = HOUR;
  optionSelected = false;
  restoreSettingsFromEEPROM(); //update the variables
} 

void motorActivate(){
  if (motorState){
    digitalWrite(RELAY_PIN, HIGH);
  }else{
    digitalWrite(RELAY_PIN, LOW);
  }
}

void TimeTempHumidDisplay() {
  int humidity = dht.readHumidity();
  int temperature = dht.readTemperature();
  RtcDateTime now = Rtc.GetDateTime();

  lcd.setCursor(4, 0);
  printDigitsLCD(now.Hour());
  lcd.print(":");
  printDigitsLCD(now.Minute());
  lcd.print(":");
  printDigitsLCD(now.Second());
  lcd.print(" ");
  lcd.setCursor(0, 0);
  lcd.print("H");
  lcd.print(humidity);
  lcd.print(" ");
  lcd.setCursor(13, 0);
  lcd.print("T");
  lcd.print(temperature);
}