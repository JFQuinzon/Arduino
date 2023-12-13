#include<Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

String data;
char d1;
String x;
int servoval;
int ledval;
Servo s1;
unsigned long lastDebounceTime = 0; // Last time output pin toggled
unsigned long debounceDelay = 5; 
int buttonState;
int lastButtonState = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(4, INPUT_PULLUP);
  s1.attach(9); //Servo Channel

  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    data = Serial.readString();
    
    d1 = data.charAt(0);
    
    switch(d1){
      case 'A': // LED13 ON
      digitalWrite(13, HIGH);
      break;
      case 'a': // LED13 OFF
      digitalWrite(13, LOW);
      break;
      
      case 'S': //Set servo angle
      x = data.substring(1); 
      servoval = x.toInt();
      s1.write(servoval);
      delay(100);
      break;
  
      case 'R': //Set RedLed val
      x = data.substring(1);
      ledval = x.toInt();
      analogWrite(3, ledval);
      break;
      
      case 'G': //Set GreenLed val
      x = data.substring(1);
      ledval = x.toInt();
      analogWrite(5, ledval);
      break;
      
      case 'Y': //Set YellowLed val
      x = data.substring(1);
      ledval = x.toInt();
      analogWrite(6, ledval);
      break;

      case 'T': 
      lcd.clear();
      x = data.substring(1);
      lcd.print(x);
      break;
    }
  }
  HandleButton();
  HandlePot();
}

void HandleButton(void){
  int reading = digitalRead(4);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
    
  if ((millis() - lastDebounceTime) > debounceDelay){
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH){
        Serial.println("p");
      }
    }
  }
  lastButtonState = reading;
} 
void HandlePot(void){
  String val;
  static int old = 0;
  int current = 0, upper, lower;
  current = analogRead(A0);
  upper = current + 2;
  lower = current - 2;
  if (current !=old){
    if((old <= lower) || (old >= upper)){
      val = String(current);
      Serial.print("v");
      Serial.println(val);
      old = current;
      }
    }
    
}
