int m1a = 9;
int m1b = 10;
int m2a = 12;
int m2b = 11;

int FrontLight = 2;
int BackLight = 3;
int BUZZER_PIN = 5;

char command;


void setup() 
{       
  Serial.begin(9600);
  pinMode(m1a, OUTPUT);  // Digital pin 10 set as output Pin
  pinMode(m1b, OUTPUT);  // Digital pin 11 set as output Pin
  pinMode(m2a, OUTPUT);  // Digital pin 12 set as output Pin
  pinMode(m2b, OUTPUT);  // Digital pin 13 set as output Pin
  pinMode(FrontLight, OUTPUT);
  pinMode(BackLight, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(FrontLight, LOW);
  digitalWrite(BackLight, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  
}

void loop(){

  if(Serial.available() > 0){ 
    command = Serial.read(); 
    // Serial.println(command);
    if (command != 'S'){
    switch(command){
    case 'F':  
      forward();
      break;
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    case 'I':
      forwardRight();
      break;
    case 'J':
      backwardRight();
      break;
    case 'G':
      forwardLeft();
      break;
    case 'H':
      backwardLeft();
      break;
    }

    if (command == 'W'){
      // Front Lights on
      digitalWrite(FrontLight, HIGH);
    }else if (command == 'w'){
      // Front Lights off
      digitalWrite(FrontLight, LOW);
    }
    // Back Light
    if (command == 'U'){
      // Back Lights on
      digitalWrite(BackLight, HIGH);
    }else if (command == 'u'){
      // Back Lights off
      digitalWrite(BackLight, LOW);
    }

    // SIREN
    if (command == 'V') {
      tone(BUZZER_PIN, 440);
    } else if (command == 'v') {
      noTone(BUZZER_PIN); // turn off horn tone
    }

    if (command == 'X') {
      // Switch to line following
    } else if (command == 'x') {
      // switch to manual
    }
    }else{
      Stop(); 
    }
  }
}

void forward()
{
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW); 
}

void back()
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH); 
}

void left()
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
}

void right()
{
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW); 
} 

void Stop()
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW); 
}

void forwardRight()
{
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
}

void backwardRight()
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
}

void forwardLeft()
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);    
  digitalWrite(m2b, LOW);
}

void backwardLeft()
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH); 
}

