/* 7 SEGMENT NAME PALADA*/ 
int segmentA = 2;
int segmentB = 3;
int segmentC = 4;
int segmentD = 5;
int segmentE = 6;
int segmentF = 7;
int segmentG = 8;

void setup() {
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
}

void loop() {
   /*P*/ 
  digitalWrite(segmentG, HIGH);
  digitalWrite(segmentF, HIGH);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentA, HIGH);
  digitalWrite(segmentD, HIGH);
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentE, LOW);
  delay(1000);
  
  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentC, LOW);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, LOW);
  delay(1000);

  /*A*/ 
  digitalWrite(segmentG, HIGH);
  digitalWrite(segmentF, HIGH);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentA, HIGH);
  digitalWrite(segmentB, HIGH);
  digitalWrite(segmentD, HIGH);
  digitalWrite(segmentE, LOW);
  delay(1000);

  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentC, LOW);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, LOW);
  delay(1000);

  /*L*/ 
  digitalWrite(segmentF, HIGH);
  digitalWrite(segmentG, HIGH);
  digitalWrite(segmentE, HIGH);
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentA, LOW);
  digitalWrite(segmentC, LOW);
  digitalWrite(segmentD, LOW);
  delay(1000);

  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentC, LOW);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, LOW);
  delay(1000);

  /*A*/ 
  digitalWrite(segmentG, HIGH);
  digitalWrite(segmentF, HIGH);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentA, HIGH);
  digitalWrite(segmentB, HIGH);
  digitalWrite(segmentD, HIGH);
  digitalWrite(segmentE, LOW);
  delay(1000);

  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentC, LOW);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, LOW);
  delay(1000);

  /*D*/ 
  digitalWrite(segmentG, HIGH);
  digitalWrite(segmentF, HIGH);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentA, HIGH);
  digitalWrite(segmentB, HIGH);
  digitalWrite(segmentE, HIGH);
  digitalWrite(segmentD, LOW);
  delay(1000);

  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentC, LOW);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, LOW);
  delay(1000);

  /*A*/ 
  digitalWrite(segmentG, HIGH);
  digitalWrite(segmentF, HIGH);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentA, HIGH);
  digitalWrite(segmentB, HIGH);
  digitalWrite(segmentD, HIGH);
  digitalWrite(segmentE, LOW);
  delay(1000);

  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentC, LOW);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, LOW);
  delay(1000);


}