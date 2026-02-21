const int trigPin = 3;
const int echoPin = 2;  
const int vibratorPin = 5; 
const int buzzerPin = 4;   


const int shortDistance = 30;
const int lowerMediumDistance = 45;
const int higherMediumDistance = 60;
const int farDistance = 85; 
const int maxDistance = 100;
int frequency = 0;

void setup() {
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(vibratorPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  
  digitalWrite(buzzerPin, HIGH);
  delay(100);
  digitalWrite(buzzerPin, LOW);
}


int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH, 30000); 
  
  float speedOfSound = 0.034;
  int distance = duration * speedOfSound / 2;
  
  return distance;
}

void sendSignal(int frequency){
  digitalWrite(vibratorPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(50); 
    
    digitalWrite(vibratorPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(frequency);
}

void loop() {
  int distance = getDistance();

  
  if (distance > 0 && distance <= shortDistance) {

    digitalWrite(vibratorPin, HIGH); 
    digitalWrite(buzzerPin, HIGH); 
    delay(100);
  } 

  else if (distance > shortDistance && distance <= lowerMediumDistance) {
   
    frequency = 100;
    sendSignal(frequency);
  } 

  else if (distance > lowerMediumDistance && distance <= higherMediumDistance) {
   
    frequency = 200;
    sendSignal(frequency);
  } 

   else if (distance > higherMediumDistance && distance <= farDistance) {
   
    frequency = 300;
    sendSignal(frequency);
  } 

  else if (distance > farDistance && distance <= maxDistance) {
   
    frequency = 400;
    sendSignal(frequency);
  } 
 
  else {
    
    digitalWrite(vibratorPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(100); 
  }
}