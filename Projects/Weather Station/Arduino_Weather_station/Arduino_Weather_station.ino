  #include <Wire.h> 
  #include <LiquidCrystal_I2C.h>
  #include <DHT.h>
  #include "SoftwareSerial.h"

  // Set the LCD address to 0x27 for a 16 chars and 2 line display
  LiquidCrystal_I2C lcd(0x27, 16, 2);

  // Pins
  int windSpeedPin = 2; //wind sensor pin
  int windDirectionPin = A0; // for Wind Direction
  int airQlty = A1; // for Air Quality

  // Wind Speed
  #define READ_TIME 1000 //ms
  #define WIND_SPEED_20_PULSE_SECOND 1.75  //in m/s this value depend on the sensor type
  #define ONE_ROTATION_SENSOR 20.0
  volatile unsigned long Rotations;
  float WindSpeed; 
  unsigned long gulStart_Read_Timer = 0;

  // Temperature & Humidity
  #define DHTPIN 3    
  #define DHTTYPE DHT11
  DHT dht(DHTPIN, DHTTYPE);

  void setup() {
    Serial.begin(9600);      
    
    pinMode(airQlty,INPUT);
    pinMode(windSpeedPin,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(windSpeedPin),isr_rotation, CHANGE); //Set up the interrupt
    sei(); 
    dht.begin();
    lcd.begin();
    lcd.backlight();
  }

  void loop() {
    windDirection();  
    windSpeed();
    tempHumid();
    airQuality();
    delay(1000);
  }

  // Temperature & Humidity =============================
    void tempHumid(){
      int humidity = dht.readHumidity();
      int temperature = dht.readTemperature();
      Serial.print("T: ");
      Serial.println(temperature);
      Serial.print("H: ");
      Serial.println(humidity);
      lcd.setCursor(0, 1);
      lcd.print("T:");
      lcd.print(temperature);
      lcd.print(" H:");
      lcd.print(humidity);
    }
  // ====================================================

  // Air Quality ========================================
    void airQuality(){
      int airQ = analogRead(A1);
      Serial.print("A: ");
      Serial.println(airQ);
      lcd.setCursor(10, 1);
      lcd.print("Q:");
      lcd.print(airQ);
    }
  // ====================================================

  // Wind Direction =====================================
    void windDirection() {
      // int sensorValue = analogRead(windDirectionPin);
      // float voltage = sensorValue * 5 / 1023.0;
      // int direction = map(sensorValue, 0, 1023, 0, 360);
      // String cardinalDirection;
      // if (direction < 45 || direction >= 315) {
      //     cardinalDirection = "N";
      // } else if (direction >= 45 && direction < 135) {
      //     cardinalDirection = "E";
      // } else if (direction >= 135 && direction < 225) {
      //     cardinalDirection = "S";  
      // } else if (direction >= 225 && direction < 315) {
      //     cardinalDirection = "W";
      // }
      // Serial.print("D: ");
      // Serial.println(direction);
      // lcd.setCursor(0, 0);
      // lcd.print("D:");
      // lcd.print(cardinalDirection);
      // lcd.print(" ");
    }
  // ====================================================

  // Wind Speed =========================================
    void isr_rotation()
    {
      Rotations++;
    }
    void windSpeed(){
      if((millis() - gulStart_Read_Timer) >= READ_TIME){
        cli(); 
        WindSpeed = WIND_SPEED_20_PULSE_SECOND/ONE_ROTATION_SENSOR*(float)Rotations;
        Serial.print("S: ");
        Serial.println(WindSpeed);
        sei(); 
        Rotations = 0; 
        gulStart_Read_Timer = millis();
        lcd.setCursor(4, 0);
        lcd.print("S:");
        lcd.print(WindSpeed);
        lcd.print("m/s");
      }
    }
  // ====================================================