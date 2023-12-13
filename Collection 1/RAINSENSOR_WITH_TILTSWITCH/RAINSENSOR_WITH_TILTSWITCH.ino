
int buzzerPin = 5; // connect the buzzer to pin 8

int tiltSwitchPin = A1; // connect the tilt switch to pin 2

int tiltThreshold = 1000; // set the threshold value for the tilt switch

void setup() {
  // Set the pin modes
  pinMode(buzzerPin, OUTPUT);
  pinMode(tiltSwitchPin, INPUT_PULLUP);
  
  // Start the serial monitor for debugging (optional)
  Serial.begin(9600);
}

void loop() {
  int tiltValue = analogRead(tiltSwitchPin);
  Serial.println(tiltValue); // print the analog value to the serial monitor
  
  if (tiltValue < tiltThreshold) { 
    Sound();
  }
  else {
    noTone(buzzerPin);
  }
}

unsigned long previousMillis = 0;
const long interval = 50; // blink interval in milliseconds
bool buzzerOn = false;
unsigned long previousStateChangeMillis = 0;
const long stateChangeInterval = 50; 

void Sound()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    buzzerOn = !buzzerOn;
    if (buzzerOn) {
      tone(buzzerPin, 1500);
    } else {
      // noTone(buzzerPin);
      tone(buzzerPin, 500);
    }
    previousStateChangeMillis = currentMillis;
  }
}