
int const trigPin = 12;
int const echoPin = 9;
int const buzzPin = 2;
const int ldrPin = A0;
int const Remote = A4;
int const led = 6;
int const led1 = 4;
int const led2 = 10;
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
int  Signal = analogRead(Remote);
  int temp = digitalRead(Remote);

int similar_count=0;
while(Signal==temp)
{
 Signal = digitalRead(Remote);
 similar_count++;
}
Serial.print(Signal);
if(Signal==0)
{
  Serial.print(Signal); 
  Serial.println("Remote Pressed");
  digitalWrite(buzzPin,HIGH);
  delay(3000);
  digitalWrite(buzzPin,LOW);
}
  int ldrStatus = analogRead(ldrPin);
  int duration, distance;
  digitalWrite(trigPin, HIGH); 
  delay(1);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1; 
  Serial.println("ldrStatus");
  Serial.println(ldrStatus);
  Serial.println("distance");
  Serial.println(distance);
   digitalWrite(led, HIGH);
    if (distance <= 50||ldrStatus<=1000) {
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
