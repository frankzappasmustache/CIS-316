#include <LiquidCrystal.h>
#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 466
#define b 494
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880
// Defining each note along with its corresponding frequency in hz

int pirPin = 9;
// pin for pir sensor

int buzzPin = 10;
// pin for piezo buzzer

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int state = LOW;
int val = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(pirPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  tone(buzzPin, 1000, 500);
}

void loop() {
  val = digitalRead(pirPin);
  // read current value of pirPin

  // 
  if (val == HIGH) {
    if (state == LOW) {
      state = HIGH;
      lcd.setCursor(0, 0);
      lcd.print("Door Open");
      imperialMarch();
      noTone(buzzPin);
    }
  } else {
    val = LOW;
    if (state == HIGH) {
      state = LOW;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Door Closed");
      noTone(buzzPin);
      state = LOW;
    }
  }
}

void note (unsigned char buzzPin, int frequencyInHertz, long timeInMilliseconds)
{ 
    digitalWrite(LED_BUILTIN, HIGH);	 
    // set LED to high at beginning of note loop to show note is playing
    
    int i;
    // counter data member
    long delayAmount = (long)(1000000/frequencyInHertz);
    // set amount of time to play note by delaying between high and low
    long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
    // set length of loop for each note

    // for loop that sets the pin value to HIGH for each note
    // delays for delayAmount time before setting pin value back to LOW(off) and delays again
    // before playing next note
    for (i=0;i<loopTime;i++)
    { 	 
        digitalWrite(buzzPin,HIGH);
        delayMicroseconds(delayAmount);
        digitalWrite(buzzPin,LOW);
        delayMicroseconds(delayAmount);
    } 	 
    
    digitalWrite(LED_BUILTIN, LOW);
    // set LED to low to show note has ended
    
    delay(20);
    //a little delay to make all notes sound separate
}

// notes of imperial march with their corresponding frequencies and time in milliseconds
void imperialMarch()
{
    
    note(buzzPin, a, 500); 
    note(buzzPin, a, 500);     
    note(buzzPin, a, 500); 
    note(buzzPin, f, 350); 
    note(buzzPin, cH, 150);
    
    note(buzzPin, a, 500);
    note(buzzPin, f, 350);
    note(buzzPin, cH, 150);
    note(buzzPin, a, 1000);
    
    note(buzzPin, eH, 500);
    note(buzzPin, eH, 500);
    note(buzzPin, eH, 500);    
    note(buzzPin, fH, 350); 
    note(buzzPin, cH, 150);
    
    note(buzzPin, gS, 500);
    note(buzzPin, f, 350);
    note(buzzPin, cH, 150);
    note(buzzPin, a, 1000);
    
    note(buzzPin, aH, 500);
    note(buzzPin, a, 350); 
    note(buzzPin, a, 150);
    note(buzzPin, aH, 500);
    note(buzzPin, gSH, 250); 
    note(buzzPin, gH, 250);
    
    note(buzzPin, fSH, 125);
    note(buzzPin, fH, 125);    
    note(buzzPin, fSH, 250);
    delay(250);
    note(buzzPin, aS, 250);    
    note(buzzPin, dSH, 500);  
    note(buzzPin, dH, 250);  
    note(buzzPin, cSH, 250);
    
    note(buzzPin, cH, 125);  
    note(buzzPin, b, 125);  
    note(buzzPin, cH, 250);      
    delay(250);
    note(buzzPin, f, 125);  
    note(buzzPin, gS, 500);  
    note(buzzPin, f, 375);  
    note(buzzPin, a, 125); 
    
    note(buzzPin, cH, 500); 
    note(buzzPin, a, 375);  
    note(buzzPin, cH, 125); 
    note(buzzPin, eH, 1000); 
    
    note(buzzPin, aH, 500);
    note(buzzPin, a, 350); 
    note(buzzPin, a, 150);
    note(buzzPin, aH, 500);
    note(buzzPin, gSH, 250); 
    note(buzzPin, gH, 250);
    
    note(buzzPin, fSH, 125);
    note(buzzPin, fH, 125);    
    note(buzzPin, fSH, 250);
    delay(250);
    note(buzzPin, aS, 250);    
    note(buzzPin, dSH, 500);  
    note(buzzPin, dH, 250);  
    note(buzzPin, cSH, 250);  
    
    note(buzzPin, cH, 125);  
    note(buzzPin, b, 125);  
    note(buzzPin, cH, 250);      
    delay(250);
    note(buzzPin, f, 250);  
    note(buzzPin, gS, 500);  
    note(buzzPin, f, 375);  
    note(buzzPin, cH, 125); 
           
    note(buzzPin, a, 500);            
    note(buzzPin, f, 375);            
    note(buzzPin, c, 125);            
    note(buzzPin, a, 1000);       
}