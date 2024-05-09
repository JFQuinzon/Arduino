struct Alarm {
  uint8_t day;
  uint8_t hour;
  uint8_t minute;
  uint8_t second; 
  uint8_t status;
  uint8_t number;
};

void setup() {
  Serial.begin(9600);
}

void loop() {
  checkNearestAlarm();
  delay(1000);
}

void checkNearestAlarm() {

  Alarm alarms[] = {
    {1, 10, 15, 30, 1, 1}, //Mon, 10:15:30am On
    {2, 12, 30, 45, 0, 2}, //Tue, 12:30:45pm On
    {3, 3, 45, 20, 0, 3},  //Wed, 03:45:20am On
    {4, 18, 2, 0, 0, 4},    //Thu, 06:00:00pm On
    {5, 7, 20, 10, 1, 5},   //Fri, 07:20:10am On
    {6, 22, 45, 55, 1, 6},  //Sat, 10:45:55pm On
    {7, 9, 5, 35, 0, 7}     //Sun, 09:05:35am On
  };

  // Current Time: Thur, 06:01:00pm
  uint8_t currentDay = 2;
  uint8_t currentHour = 8;
  uint8_t currentMinute = 40;
  uint8_t currentSecond = 0;

  uint32_t currentTotalSeconds = currentDay * 86400UL + currentHour * 3600UL + currentMinute * 60UL + currentSecond;

  uint32_t nearestDifference = UINT32_MAX; // Initialize with maximum possible value
  int nearestAlarmIndex = -1;
  
  for (int i = 0; i < sizeof(alarms) / sizeof(alarms[0]); i++) {
    uint32_t alarmTotalSeconds = alarms[i].day * 86400UL + alarms[i].hour * 3600UL + alarms[i].minute * 60UL + alarms[i].second;
    if (alarms[i].status) {
      if (alarmTotalSeconds >= currentTotalSeconds) {
        uint32_t difference = alarmTotalSeconds - currentTotalSeconds;
        if (difference < nearestDifference) {
          nearestDifference = difference;
          nearestAlarmIndex = i;
        }
      }
    }
  }

  if (nearestAlarmIndex != -1) {
    Serial.print("New Alarm ");
    Serial.print(alarms[nearestAlarmIndex].number);
    Serial.print(": ");
    Serial.print(alarms[nearestAlarmIndex].day);
    Serial.print(", ");
    Serial.print(alarms[nearestAlarmIndex].hour);
    Serial.print(":");
    Serial.print(alarms[nearestAlarmIndex].minute);
    formatAMPM(alarms[nearestAlarmIndex].hour);
    Serial.println();
  }
}

void formatAMPM(int time) {
  if (time < 12) {
    Serial.print("am");
  } else {
    Serial.print("pm");
  }
}