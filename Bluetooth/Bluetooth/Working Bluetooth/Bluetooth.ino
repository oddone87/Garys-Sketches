#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

//suggested serial data structure "1 High" (pin 1, high) or 2 1023 (pin 2 1023) pin number then value


void setup() {
    pinMode(13, OUTPUT);
  
  Serial.begin(57600);
  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?");

}

String command; //variable that stores the input from the serial
String button1 = "button01 pressed";
String button2 = "button02 pressed";

void loop() {
  if (mySerial.available()) {
       //Serial.write(mySerial.read());

    char c = mySerial.read(); //takes character in serial buffer and stores it into the variable c

    if(c == '\n') { //if c = newline do the following (newline tells arduino it is the end of the command
      Serial.print (command);
     command = "";
    }

    else {
      command += c;
    }

          if(command == button1) {
       digitalWrite(13, HIGH);
      }

      if(command == button2) {
       digitalWrite(13, LOW);
      }
    

    
   // Serial.write(mySerial.read());
  }
 
 if (Serial.available()) {
    mySerial.write(Serial.read());
  }

}


  

