int waterSensorPinA0 = A0; // connect the water sensor to analog pin A0
int buzzerPin = 8; // connect the buzzer to pin 8
int threshold = 500; // set the water level threshold

int tiltSwitchPin = 2; // connect the tilt switch to pin 2

void setup() {
  // Set the pin modes
  pinMode(buzzerPin, OUTPUT);
  pinMode(tiltSwitchPin, INPUT_PULLUP);
  
  // Start the serial monitor for debugging (optional)
  Serial.begin(9600);
}

void loop() {
  int waterLevel = analogRead(waterSensorPinA0);
  if (waterLevel > threshold) {
    Sound();
  }else if (digitalRead(tiltSwitchPin) == HIGH) { 
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