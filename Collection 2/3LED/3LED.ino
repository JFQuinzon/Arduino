String data;
char d1;
char d2;
char d3;
void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    data = Serial.readString();
    d1 = data.charAt(0);
    if(d1 == 'A'){
      digitalWrite(6, HIGH);
      }
    else if (d1 == 'a'){
      digitalWrite(6,LOW);
      }
      
    if(d1 == 'B'){
      digitalWrite(4, HIGH);
      }
    else if (d1 == 'b'){
      digitalWrite(4,LOW);
      }
      
    if(d1 == 'C'){
      digitalWrite(2, HIGH);
      }
    else if (d1 == 'c'){
      digitalWrite(2,LOW);
      }
    }
}
