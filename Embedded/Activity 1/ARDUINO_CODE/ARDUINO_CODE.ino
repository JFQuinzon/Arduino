void setup() {
  Serial.begin (9600);
  pinMode(13,OUTPUT);
}

void loop() {
  String readString;
  String Q;
  
  while (Serial.available()){
   delay(1);
   
   if (Serial.available()>0){
      char c = Serial.read();
      if (isControl(c)){
        break;
      }
      readString += c;
    }
  }
  
  
  Q = readString ;
  if (Q=="on")
  {
    digitalWrite(13,HIGH);
  }
 
  if (Q=="off")
  {
    digitalWrite(13,LOW);
  }
  
}
