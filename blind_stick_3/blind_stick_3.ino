
int const trigPin = 12;
int const echoPin = 9;
int const buzzPin = 2;
//  const int ldrPin = A0;
//int const remotePin = 5;
int const led = 6;
int const led1 = 4;
//int const led2 = 10; 
void setup()
{
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(buzzPin, OUTPUT); 
  pinMode(led, OUTPUT);
}

void loop()
{
  //int ldrStatus = analogRead(ldrPin);
  int duration, distance;
  digitalWrite(trigPin, HIGH); 
  delay(1);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1; 
 // Serial.println("ldrStatus");
  //Serial.println(ldrStatus);
  Serial.println("distance");
  Serial.println(distance);
   digitalWrite(led, HIGH);
    if (distance <= 30/*||ldrStatus<=1000*/) {
      digitalWrite(buzzPin, HIGH);
      digitalWrite(led1,HIGH);
       digitalWrite(led, LOW);
    } else 
    {
      digitalWrite(buzzPin, LOW);
      digitalWrite(led1,LOW);
         }
 
    delay(60);
}
