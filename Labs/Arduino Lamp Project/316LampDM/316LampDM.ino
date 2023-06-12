//Input user defined variables. Think of variables like containers they are used to store information.

int pulseSpeed = 5;
//  This value controls how fast the mood lamp runs. You can replace this with any whole number. 
int ldrPin = 0;   // LDR in Analog Input 0 to read the surrounding light.
int redLed = 11;  // red LED in Digital Pin 11.
int greenLed = 10; // green LED in Digital Pin 10.
int yellowLed = 9; // yellow LED in DIgital Pin 9.
//  These are the pins we are using with the Arduino. You can see the numbers on the board itself.
int ambientLight; 
// This variable stores the value of the light in the room.
int power = 150;
// This variable controls the brightness of the lamp (2-255).
float RGB[3];
// This is an ‘array’. It can hold 3 values: RGB[0], RGB[1], and RGB[2].We’ll use this to store the values of the Red, Yellow, and Green LEDs.
float CommonMathVariable = 180/PI;
/* We will be using the value of 180/PI a lot in the main loop, so to
save time, we will calculate it once here in the setup and store it 
in  CommonMathVariable. Note: it is PI, not P1 */

/* Step 2: Create Setup Loop
This ‘loop’ is not really a loop. It runs once in the beginning to create
the default values for our LEDs. */

void setup () {

pinMode (redLed,OUTPUT);
pinMode (greenLed,OUTPUT);
pinMode (yellowLed,OUTPUT);
// This tells the Arduino to send data out to the LEDs.

digitalWrite (redLed,LOW);
digitalWrite (greenLed,LOW);
digitalWrite (yellowLed,LOW);
//  This sets all the outputs (LEDs) to low (as in off), so that they do not turn on during startup.

}   // Opening brackets must be accompanied by closing brackets.

/* Step 3: Create Main Loop
The previous sections are where we set up the variables. This section is 
where we put them to work! This part of the program is a ‘loop’. It 
repeats itself over and over again, making a small change in the 
brightness of the LEDs each time - this creates a smooth transition in 
color. */

void loop () {

for (float x = 0; x < PI; x = x + 0.00001) {
RGB[0] = power * abs(cos(x * (CommonMathVariable))); // Red LED.
RGB[1] = power * abs(cos((x + PI/3) * (CommonMathVariable))); // Green LED.
RGB[2] = power * abs(tan((x + (2 * PI) / 3) * (CommonMathVariable))); // Yellow LED.
ambientLight = analogRead(ldrPin);
// This reads the light in the room and stores it as a number.

if (ambientLight > 600) {
// This ‘if statement’ will make the lamp turn on only if it is dark. The darker it is, the higher the number. 
analogWrite (redLed,RGB[0]);
analogWrite (greenLed,RGB[1]);
analogWrite (yellowLed,RGB[2]);
// These ‘analogWrite’ statements will send the values calculated above to the LEDs. 
} // Don’t forget to close this ‘if statement’ with a bracket!

else {
digitalWrite (redLed,LOW);
digitalWrite (greenLed,LOW);
digitalWrite (yellowLed,LOW);
}
// This ‘else statement’ will only activate if the ‘if statement’ above does not (ie. If it is too bright in the room). The LEDs will turn off. 

for (int i = 0; i < 3; i++) {
// This loop calculates the delay for each color depending on its current brightness. Brighter LEDs will change color slower and vice versa.

if (RGB[i] < 1) {
delay (20 * pulseSpeed);
}
  
else if (RGB[i] < 5) {
delay (10 * pulseSpeed);
}

else if (RGB[i] < 10) {
delay (2 * pulseSpeed);
}

else if (RGB[i] < 100) {
delay (1 * pulseSpeed);
} 
// ’else if’ means only one of these conditions can activate at a time.    

else {}
// This blank ‘else statement’ is a fail-safe mechanism. It instructs the program to do nothing if the conditions above do not activate. This prevents the program from generating errors when calculating delays. 
}

delay(1);
// This delay gives the light dependent resistor time to settle and give accurate readings. 
}
} // Don’t forget to close with these brackets!
