#include <HX711.h>

#define DOUT 3
#define PD_SCK 2 

HX711 scale (DOUT, PD_SCK); 

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:

}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:

  // print out the state of the button:
  Serial.println(millis()/1000);
  delay(100);        // delay in between reads for stability
}



