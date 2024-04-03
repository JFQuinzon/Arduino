const int voltageSensorPin = A0; 
const float voltageDividerRatio = 21.1 / 1023.0; 
const float fullVoltage = 3.7; // Full voltage of the battery
const float lowBatVoltage = 3.0; // Low battery voltage threshold

void setup() {
  Serial.begin(9600); 
}

void loop() {
  int sensorValue = analogRead(voltageSensorPin); // Read the analog voltage value
  float voltage = sensorValue * voltageDividerRatio; // Convert analog reading to voltage

  Serial.print("Voltage: ");
  Serial.print(voltage, 2); 
  Serial.println(" V");

  float voltageRange = fullVoltage - lowBatVoltage; // Calculate the voltage range
  float remainingVoltage = voltage - lowBatVoltage; // Calculate the remaining voltage within the range

  // Calculate battery percentage
  int batteryPercentage = (remainingVoltage / voltageRange) * 100;
  batteryPercentage = constrain(batteryPercentage, 0, 100); // Ensure the percentage is within 0-100 range

  Serial.print("Battery Percentage: ");
  Serial.print(batteryPercentage);
  Serial.println("%");

  delay(1000); 
}
