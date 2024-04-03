#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
  }else{
    Serial.println("initialization done.");
  }
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    if (command.startsWith("savedistance: ")) {
      float distance = command.substring(14).toFloat();
      Serial.println("Saving");
      saveDistance(distance);
      delay(300);
    }else if (command.startsWith("saveangle: ")) {
      float angle = command.substring(11).toFloat();
      Serial.println("Saving");
      saveAngle(angle);
      delay(300);
    }
  }
  
  delay(250);
}

void saveDistance(float distanceCm){
  myFile = SD.open("distance.csv", FILE_WRITE);
  
  if (myFile) {
    Serial.print(F("Writing to distance.csv..."));
    // myFile.println("DISTANCE");
    // myFile.println("Centimeter, Millimeter, Inch, Meter");
    Serial.println(distanceCm);
    myFile.print(String(distanceCm));
    myFile.print(",");
    myFile.print(String(distanceCm * 10));
    myFile.print(",");
    myFile.print(String(distanceCm * 0.393701));
    myFile.print(",");
    myFile.println(String(distanceCm * 0.01));

    myFile.close();
    Serial.println(F("done."));
  } else {
    Serial.println(F("error opening distance.csv"));
  }
}

void saveAngle(int angle){
  myFile = SD.open("angle.csv", FILE_WRITE);
  
  if (myFile) {
    Serial.print(F("Writing to angle.csv..."));
    // myFile.println("Angle");
    Serial.println(angle);
    myFile.print("Degree:, ");
    myFile.println(String(angle));

    myFile.close();
    Serial.println(F("done."));
  } else {
    Serial.println(F("error opening angle.csv"));
  }
}
