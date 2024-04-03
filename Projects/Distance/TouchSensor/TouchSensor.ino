const int touch1Pin = 2; // SIG pin connected to digital pin 2
bool touch1  = false;

void setup() {
  Serial.begin(9600);
  pinMode(touch1Pin, INPUT_PULLUP);
}

void loop() {
  int touch1State = digitalRead(touch1Pin);

  if (touch1State == 1 && !touch1Detected) {
    Serial.println("Touch detected!");
    touch1Detected = true;
    delay(100); 
  } else {
      touch1Detected = (touch1State == 1);
  }

  delay(100); 
}
