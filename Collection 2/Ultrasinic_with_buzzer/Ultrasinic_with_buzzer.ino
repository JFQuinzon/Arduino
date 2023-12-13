const int trigPin = 9;
const int echoPin = 10;

const int buzzer = 2;
const int red = 3;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(red, OUTPUT);
  
  Serial.begin(9600);


}

void loop() {

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;

  Serial.println(distance);
  if (distance  < 10){
    digitalWrite(buzzer, HIGH);
    digitalWrite(red, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(red, LOW);
  }
  
}




