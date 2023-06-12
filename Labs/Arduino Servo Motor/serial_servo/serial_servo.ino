#include <Servo.h> 
 
// int potPin = 0;  
int servoPin = 9;
Servo servo; 
 
void setup() 
{ 
  servo.attach(servoPin);
  Serial.begin(9600);
} 
 
void loop() 
{ 
  int reading = Serial.parseInt(); // 0 to 180
  int angle = reading; // 0 to 170-ish
  servo.write(angle);  
} 
