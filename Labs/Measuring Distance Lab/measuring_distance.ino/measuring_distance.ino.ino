/* HC-SR04 Ultrasound Sensor Connection with Arduino:
VCC => Arduino +5v
GND => Arduino GND
Echo => Digital Pin 11
Trig => Digital Pin 12
*/
#define echo 11 // Echo Pin
#define trig 12 // Trigger Pin
long travel_time, distance; // Duration used to calculate distance
void setup() {
 Serial.begin (9600);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
}
void loop() {
digitalWrite(trig, LOW);
 delayMicroseconds(2);
//Sending a high pulse to trigger the Ultrasound Module
digitalWrite(trig, HIGH);
 delayMicroseconds(10);

digitalWrite(trig, LOW);
 travel_time = pulseIn(echo, HIGH);

//Calculating the distance
 distance = (travel_time*0.034)/2;

// Sending the distance to computer
 Serial.println(distance);

//Delay for next reading.
 delay(30);
} 