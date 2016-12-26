#include "HX711.h"

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);

// HX711.DOUT  - pin #A1
// HX711.PD_SCK - pin #A0

HX711 scale(A1, A0);    // parameter "gain" is ommited; the default value 128 is used by the library

int potPin = 2;

int redLedPin = 11;
int amberLedPin = 10;
int greenLedPin = 9;
int shockPin = 6;

unsigned long flashPreviousMillis = 0; //blink without delay timer for flashing function
const long flashInterval = 200;
int flashLEDState = LOW;

int LEDStart = 0; //used to see if the LEDStart func has alread ran

int powerPin = 7;   // pushbutton connected to digital pin 7
int powerVal = 0;     // variable to store the read value

int lockPin = 8;   // pushbutton connected to digital pin 7
int lockVal = 0;     // variable to store the read value

long int scaleActual = 0;
long int scaleGoal = 0;
long int scaleCal = 0;
long int scaleZero = 0;

int potVal = 0;       // variable to store the value coming from the sensor
int potZero = 0;     //varible to check if POT has been zero'd
int lockedPotVal = 1025;


void setup() {

pinMode(redLedPin, OUTPUT); 
pinMode(amberLedPin, OUTPUT); 
pinMode(greenLedPin, OUTPUT); 
pinMode(shockPin, OUTPUT);

digitalWrite (shockPin, LOW);


scaleZero = scale.read();

lcd.begin(16, 2);

}

void loop() {

  lockVal = digitalRead(lockPin);
  powerVal = digitalRead(powerPin);
  
  if (potZero == 0){
    if (powerVal == 1){
       if (lockVal == 1){
         LEDBlink_func();
         LEDStart = 0;
         lcd.clear();
         lcd.setCursor(0, 0);
         lcd.print ("Unlock me");
         lcd.setCursor(0, 1);
         lcd.print ("Moron!!");
         delay(100);
         }
       if (lockVal == 0){
         potVal_func();
         LEDStart_func();
       //  lcd.clear();
         lcd.setCursor(0, 0);
         lcd.print (potVal);
         lcd.print ("      ");     //White space test so I don't have to include lcd clear. helps with flicker issues
         lcd.setCursor(0, 1);
         lcd.print ("Turn dial to 0");
         delay(200);
         potZero_func();
         }
    }
     if (powerVal == 0) {
       if (lockVal == 1) {
        LEDBlink_func();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print ("Turn on Power");
        lcd.setCursor(0, 1);
        lcd.print ("Turn off Lock");
        delay(100);
      }
    }
  }

  if (potZero == 1) {
    if (lockVal == 0) {
       potVal_func();
         if ((lockedPotVal + 10) < potVal) {
           potZero = 0;
           lockedPotVal = 1025;
           LEDStart = 0;
           } else {
           lockedPotVal = 1025;
           loadRead_func();
           loadCompare_func();
           lcd.clear();
           lcd.setCursor(0, 0);
           lcd.print (potVal);
           lcd.setCursor(0, 1);
           lcd.print (scaleCal);
           delay(100);
           }
    }
   if (lockVal == 1) {
      loadRead_func();
      loadCompare_func();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print (potVal);
      lcd.setCursor(0, 1);
      lcd.print (scaleCal);
      lockedPotVal = potVal;
      delay(100);
    }
  }
}




void test_func()
{

       Serial.print(lockVal);
       Serial.print(powerVal);

       Serial.print("\t\tPOT Zero - \t\t");
Serial.print(potZero);

Serial.print("\t\t scale Actual \t\t");
Serial.print(scaleActual);

Serial.print("\t\t scale Cal \t\t");
Serial.print(scaleCal);


  Serial.print ("\t\t Scale Goal - ");
  Serial.println(scaleGoal);

               lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print (potVal);
             lcd.setCursor(0, 1);
             lcd.print (scaleCal);
             delay(100);
  
  delay(10);
    
}

void LEDBlink_func() {

  unsigned long flashCurrentMillis = millis();

  if (flashCurrentMillis - flashPreviousMillis >= flashInterval) {
    flashPreviousMillis = flashCurrentMillis;

    if (flashLEDState == LOW) {
      flashLEDState = HIGH;
    } else {
      flashLEDState = LOW;
    }
    
    digitalWrite (redLedPin,flashLEDState);
    digitalWrite (amberLedPin,flashLEDState);
    digitalWrite (greenLedPin,flashLEDState);

  }
}

void LEDStart_func() {
  if (LEDStart == 0) {
    digitalWrite (redLedPin,LOW);
    digitalWrite (amberLedPin,LOW);
    digitalWrite (greenLedPin,LOW);
    digitalWrite (redLedPin,HIGH);
    delay(200);
    digitalWrite (amberLedPin,HIGH);
    delay(200);
    digitalWrite (greenLedPin,HIGH);
    delay(1000);
    digitalWrite (redLedPin,LOW);
    digitalWrite (amberLedPin,LOW);
    digitalWrite (greenLedPin,LOW);
    LEDStart = 1;
  }
}



void loadRead_func() {
       scaleActual = scale.read();
       scaleCal = (scaleActual - scaleZero)/1000;
}

void potVal_func() {
    potVal = analogRead(potPin);
}

void potZero_func() {
  if (potVal ==0) {
    potZero = 1;
  }
}

void loadCompare_func() {
  if (scaleCal < potVal) {
    digitalWrite (redLedPin,HIGH);
    digitalWrite (amberLedPin,LOW);
    digitalWrite (greenLedPin,LOW);
    digitalWrite (shockPin, HIGH);
  } else if ((scaleCal >= potVal) && (scaleCal < (potVal + 50))) {
    digitalWrite (redLedPin,LOW);
    digitalWrite (amberLedPin,HIGH);
    digitalWrite (greenLedPin,LOW);
    digitalWrite (shockPin, LOW);
  } else if (scaleCal >= potVal) {
    digitalWrite (redLedPin,LOW);
    digitalWrite (amberLedPin,LOW);
    digitalWrite (greenLedPin,HIGH);
    digitalWrite (shockPin, LOW);
  }
}

