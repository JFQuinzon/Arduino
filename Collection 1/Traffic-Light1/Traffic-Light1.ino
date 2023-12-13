//int sensorPin = A0;
//int ledPin = 13;

void setup() 
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
}
void loop() 
{
  int sensorValue = analogRead(A0);
  if( sensorValue <= 300 )  // Change the value as per your requirement
  {
    digitalWrite(13, HIGH);
    Serial.print("LED ON ");
    Serial.println(sensorValue);
    delay(100);
  }
  else
  {
    digitalWrite(13, LOW);
    Serial.println("LED OFF");
  }
}