#include <Servo.h>
int servoPin = 9;
int trigPin = 6; 
int echoPin = 7; 
long duration;
Servo Servo1;


void setup() 
{
   Serial.begin(9600); 
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(servoPin,OUTPUT);
   Servo1.attach(servoPin);
}

void loop() 
{
   //Emitted USonic
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   
   //Detect USonic
   duration = pulseIn(echoPin, HIGH);
   int cm = duration/29/2;
  //  Serial.print(cm);
  //  Serial.println();
   delay(100);
   if (cm < 50){
    Serial.println("DUSTBIN OPEN");
    Servo1.write(140);
   }else{
    Serial.println("DUSTBIN CLOSE");
    Servo1.write(0);

   }
   delay(700);
}
