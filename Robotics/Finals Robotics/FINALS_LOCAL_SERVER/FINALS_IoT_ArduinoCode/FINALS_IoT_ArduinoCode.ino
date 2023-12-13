#include <SoftwareSerial.h>
SoftwareSerial ArduinoUno(A4,A5);

const int motorIn1 = 11;
const int motorIn2 = 12;

void setup() {
  Serial.begin(9600);
  ArduinoUno.begin(4800);
  
  pinMode(motorIn1, OUTPUT);  
  pinMode(motorIn2, OUTPUT);  

}

void loop() {
  if (ArduinoUno.available() > 0) {
    String command = ArduinoUno.readStringUntil('\n');
    // Serial.println(command);
    if (command.startsWith("FORWARD")) {
      digitalWrite(motorIn1, HIGH);
      digitalWrite(motorIn2, LOW);
    } else if (command.startsWith("BACKWARD")) {
      digitalWrite(motorIn1, LOW);
      digitalWrite(motorIn2, HIGH);
    } else if (command.startsWith("STOP")) {
      digitalWrite(motorIn1, LOW);
      digitalWrite(motorIn2, LOW);
    }
  }
}
