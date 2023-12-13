int buzzerPin = 8; // connect the buzzer to pin 8
int tiltSwitchPin = 2; // connect the tilt switch to pin 2

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(tiltSwitchPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(tiltSwitchPin) == HIGH) { // check if the tilt switch is on
    // play the emergency sound
    tone(buzzerPin, 1000, 100); // 1000 Hz for 100ms
    delay(100);
    tone(buzzerPin, 1500, 100); // 1500 Hz for 100ms
    delay(100);
    tone(buzzerPin, 2000, 100); // 2000 Hz for 100ms
    delay(100);
    tone(buzzerPin, 2500, 100); // 2500 Hz for 100ms
    delay(100);
    tone(buzzerPin, 3000, 100); // 3000 Hz for 100ms
    delay(100);
    tone(buzzerPin, 3500, 100); // 3500 Hz for 100ms
    delay(100);
  }
}
