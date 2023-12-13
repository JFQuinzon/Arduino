int motor1ena = 12;
int motor1pin1 = 9;
int motor1pin2 = 8;

int motor2ena = 13;
int motor2pin1 = 10;
int motor2pin2 = 11;

char command;

void setup() {
  Serial.begin(9600);

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  // pinMode(motor1ena, OUTPUT);
  // pinMode(motor2ena, OUTPUT);

}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Stop();
    Serial.print(command);
    Serial.print("\n");
    switch (command) {
      case 'F':
        Forward();
        break;
      case 'B':
        Backward();
        break;
      case 'L':
        Left();
        break;
      case 'R':
        Right();
        break;
    }
  }
}

void Forward() {
  // LEFT
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  analogWrite(motor1ena, 255);

  // RIGHT
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  analogWrite(motor2ena, 255);
}

void Backward() {
  // LEFT
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  analogWrite(motor1ena, 255);

  // RIGHT
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  analogWrite(motor2ena, 255);
}

void Left() {
  // LEFT
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  analogWrite(motor1ena, 255);

  // RIGHT
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  analogWrite(motor2ena, 255);
}

void Right() {
  // LEFT
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  analogWrite(motor1ena, 255);

  // RIGHT
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  analogWrite(motor2ena, 255);
}

void Stop() {
  // LEFT
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  analogWrite(motor1ena, 0);

  // RIGHT
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  analogWrite(motor2ena, 0);
}
