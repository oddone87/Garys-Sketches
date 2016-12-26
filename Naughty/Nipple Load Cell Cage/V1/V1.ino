#include "HX711.h"

// HX711.DOUT	- pin #A1
// HX711.PD_SCK	- pin #A0

HX711 scale(A1, A0);		// parameter "gain" is ommited; the default value 128 is used by the library
long int scaleActual = 0;
const int switchPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;
const int ledPin2 = 4;
long int scaleGoal = 0;


void setup() {
  pinMode(switchPin, INPUT); //Switch 1 For Nipple load Cell
pinMode(ledPin, OUTPUT); //LED1
pinMode(ledPin2, OUTPUT); //LED2
  
  Serial.begin(38400);
  Serial.println("HX711 Demo");

  Serial.println("Before setting up the scale:");
  Serial.print("read: \t\t");
  Serial.println(scale.read());			// print a raw reading from the ADC

}

void loop() {
    int buttonState = digitalRead(switchPin);

       scaleActual = scale.read();

Serial.print("scale Actual \t\t");
Serial.print(scaleActual);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
      if (scaleGoal == 0) {
        scaleGoal = scaleActual;
      } else if (scaleActual < scaleGoal) {
        digitalWrite(ledPin2, HIGH);
      } else {
        digitalWrite(ledPin2, LOW);
      }
    
  }

  else {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, LOW);
    scaleGoal = 0;
  }
  Serial.print ("\t\t Scale Goal - ");
  Serial.println(scaleGoal);
  
  delay(10);


}


