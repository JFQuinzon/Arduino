#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);


#define delay50 100

int myled[] = {3, 4, 5, 6, 7, 8, 9,10,11,12};
int num_of_leds;
int counter = 0;
int soundPin = A2;
String previousText = "";

void setup() {
  pinMode(13, INPUT_PULLUP);
  pinMode(soundPin, INPUT);
  Serial.begin(9600);

  num_of_leds = sizeof(myled) / sizeof(int);
  for (int i = 0; i < num_of_leds; i++) {
    pinMode(myled[i], OUTPUT);
  }
  
  // initialize the LCD
	lcd.begin();

	// Turn on the blacklight and print a message.
	lcd.backlight();
}

void loop() {
  int buttonState = digitalRead(13);
  Serial.println(counter);
  if (buttonState == LOW) {
    counter++;
    delay(250);
  }
  //Serial.println(counter);

  if (counter >= 12) {
    counter = 0; // reset the counter to 0
  }

  if (counter == 0){
    SoundSensor();
  }else if (counter == 1){
    ledon();
  }else if (counter == 2){
    pattern1();
  }else if (counter == 3){
    pattern2();
  }else if (counter == 4){
    pattern3();
  }else if (counter == 5){
    pattern4();
  }else if (counter == 6){
    pattern5();
  }else if (counter == 7){
    pattern6();
  }else if (counter == 8){
    pattern7();
  }else if (counter == 9){
    pattern8();
  }else if (counter == 10){
    pattern9();
  }else if (counter == 11){
    pattern10();
  }

}

//SOUND SENSOR
void SoundSensor() {
  String newText = "SOUND METER";
  if (previousText != newText){
    lcd.clear();
    lcd.print(newText);
    previousText = newText;
  } 
  
  int soundValue = analogRead(soundPin);
  int mappedValue = map(soundValue, 0, 100, 0, 5);
  for (int i = 0; i < 10; i++) {
    if (i < mappedValue) {
      digitalWrite(myled[i], HIGH);
    } else {
      digitalWrite(myled[i], LOW);
    }
  }

}

//TURN ON ALL LEDs
void ledon() {
  String newText = "LED ON";
  if (previousText != newText){
    lcd.clear();
    lcd.print(newText);
    previousText = newText;
  } 

  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], HIGH);
    if (digitalRead(13) == LOW) {
      return; // exit the function if the button is clicked
    }
  }
}

//TURN OFF ALL LEDs
void  ledoff(){
  String newText = "LED OFF";
  if (previousText != newText){
    lcd.clear();
    lcd.print(newText);
    previousText = newText;
  } 

  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], LOW);
    if (digitalRead(13) == LOW) {
      return; // exit the function if the button is clicked
    }
  }
}

//LEFT TO RIGHT
void pattern1() {
  lcd.clear();
  lcd.print("LEFT TO RIGHT");
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], HIGH);
    delay(delay50);
    digitalWrite(myled[i], LOW);
    if (digitalRead(13) == LOW) {
      return; // exit the function if the button is clicked
    }
  }
}

//RIGHT TO LEFT
void pattern2() {
  lcd.clear();
  lcd.print("RIGHT TO LEFT");
  for (int i = num_of_leds; i > 0; i--) {
    digitalWrite(myled[i - 1], HIGH);
    delay(delay50);
    digitalWrite(myled[i - 1], LOW);
    if (digitalRead(13) == LOW) {
      return; // exit the function if the button is clicked
    }
  }
}

//LEFT TO RIGHT FILL
void pattern3() {
  lcd.clear();
  lcd.print("LEFT TO");
  lcd.setCursor(3,1);
  lcd.print("RIGHT FILL");
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], HIGH);
    delay(delay50);
    if (digitalRead(13) == LOW) {
      return; // exit the function if the button is clicked
    }
  }
  for (int i = num_of_leds; i > 0; i--) {
    digitalWrite(myled[i - 1], LOW);
    delay(delay50);
    if (digitalRead(13) == LOW) {
      return; // exit the function if the button is clicked
    }
  }
}

//RIGHT TO LEFT FILL
void pattern4() {
  lcd.clear();
  lcd.print("RIGHT TO");
  lcd.setCursor(3,1);
  lcd.print("LEFT FILL");
  ledon();
  delay(delay50);
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], LOW);
    delay(delay50);
    if (digitalRead(13) == LOW) {
      return; // exit the function if the button is clicked
    }
  }
  for (int i = num_of_leds; i > 0; i--) {
    digitalWrite(myled[i - 1], HIGH);
    delay(delay50);
    if (digitalRead(13) == LOW) {
      return; // exit the function if the button is clicked
    }
  }
  ledoff();
}

//ALTERNATE LEDs
void pattern5() {
  lcd.clear();
  lcd.print("ALTERNATE LEDs");
  for (int i = 0; i < num_of_leds; i = i + 2) {
    digitalWrite(myled[i], HIGH);
    digitalWrite(myled[i + 1], LOW);
    if (digitalRead(13) == LOW) {
      return; // exit the function if the button is clicked
    }
  }
  delay(delay50);
  for (int i = 0; i < num_of_leds; i = i + 2) {
    digitalWrite(myled[i], LOW);
    digitalWrite(myled[i + 1], HIGH);
    if (digitalRead(13) == LOW) {
      return; // exit the function if the button is clicked
    }
  }
  delay(delay50);
}

//OSCILLATING LEDs
void pattern6() {   //osc
  lcd.clear();
  lcd.print("OSCILLATING LEDs");
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], HIGH);
    delay(delay50);
    digitalWrite(myled[i], LOW);
    if (digitalRead(13) == LOW) {
      return; // exit the function if the button is clicked
    }
  }
  delay(delay50);
  for (int i = num_of_leds; i > 0; i--) {
    digitalWrite(myled[i - 1], HIGH);
    delay(delay50);
    digitalWrite(myled[i - 1], LOW);
    if (digitalRead(13) == LOW) {
      return; // exit the function if the button is clicked
    }
  }
}

//INSIDE
void pattern7() {
  lcd.clear();
  lcd.setCursor(4,1);
  lcd.print("INSIDE");
  for (int i = 0; i < num_of_leds / 2; i++) {
    digitalWrite(myled[i], HIGH);
    digitalWrite(myled[num_of_leds - 1 - i], HIGH);
    delay(delay50);
    digitalWrite(myled[i], LOW);
    digitalWrite(myled[num_of_leds - 1 - i], LOW);
    if (digitalRead(13) == LOW) {
      return; // exit the function if the button is clicked
    }
  }
}

//OUTSIDE
void pattern8() { 
  lcd.clear();
  lcd.setCursor(4,1);
  lcd.print("OUTSIDE");
  for (int i = (num_of_leds / 2) - 1; i >= 0 ; i--)
  {
    digitalWrite(myled[i], HIGH);
    digitalWrite(myled[num_of_leds - 1 - i], HIGH);
    delay(delay50);
    digitalWrite(myled[i], LOW);
    digitalWrite(myled[num_of_leds - 1 - i], LOW);
    if (digitalRead(13) == LOW) {
      return; // exit the function if the button is clicked
    }
  }
}

//LEFT TO RIGHT 3 LEDs
void pattern9() {
  lcd.clear();
  lcd.print("LEFT TO ");
  lcd.setCursor(2,1);
  lcd.print("RIGHT 3 LEDs");
  for (int i = 0; i < num_of_leds + 3; i++) {
    if (i <= num_of_leds) {
      digitalWrite(myled[i], HIGH);
    }
    if (i > 2) {
      digitalWrite(myled[i - 3], LOW);
    }
    delay(delay50);
    if (digitalRead(13) == LOW) {
      return; // exit the function if the button is clicked
    }
  }
}

//OSCILLATING 3 LEDs
void pattern10() {
  lcd.clear();
  lcd.print("OSCILLATING ");
  lcd.setCursor(3,1);
  lcd.print("3 LEDs");
  for (int i = 2; i < num_of_leds; i++) {
    if (i == 2) {
      digitalWrite(myled[0], HIGH);
      digitalWrite(myled[1], HIGH);
    }
    digitalWrite(myled[i], HIGH);
    digitalWrite(myled[i - 3], LOW);
    delay(delay50);
    if (digitalRead(13) == LOW) {
      return; // exit the function if the button is clicked
    }
  }
  for (int i = num_of_leds - 4; i > -1; i--) {
    digitalWrite(myled[i], HIGH);
    digitalWrite(myled[i + 3], LOW);
    delay(delay50);
    if (digitalRead(13) == LOW) {
      return; // exit the function if the button is clicked
    }
  }
}



