#include <SoftwareSerial.h>
SoftwareSerial ArduinoUno(A4,A5);

void setup(){
	
	Serial.begin(9600);
	ArduinoUno.begin(4800);
  pinMode(13, OUTPUT);
}

void loop(){
	
	while(ArduinoUno.available()>0){
    int val = ArduinoUno.parseInt();
    if (val == 1){
      digitalWrite(13, HIGH);
    }else if (val == 0){
      digitalWrite(13, LOW);
    }
    Serial.println(val);
  }
}