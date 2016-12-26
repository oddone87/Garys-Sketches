#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

//Variables for the analog LED (PWM) and The Potentiometer 
int potPin= A0;
int potLEDPin= 9;
int potValue;
int potLEDValue;

//Variables for the digital switch and on/off LED
int switchLEDPin= 8;
int switchPin= 7;
int switchVal =0;

//Variables for digital LED
int digitalLEDPin= 6;
int digitalLEDStatus = 0;

//Variables for analog LED
int analogLEDPin= 5;
int analogLEDVal= 0;

void setup() {
//POT Setup  
pinMode(potPin, INPUT);
pinMode(potLEDPin, OUTPUT);

//SWITCH Setup
pinMode(switchLEDPin, OUTPUT);
pinMode(switchPin, INPUT);

//Digital LED Setup
pinMode(digitalLEDPin, OUTPUT);

//Analog LED Setup
pinMode(analogLEDPin, OUTPUT);

Serial.begin(9600);
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);

}


String command; //variable that stores the input from the serial
String button1 = "button01 pressed";
String button2 = "button02 pressed";
String pinNo = "0";

void loop() {

  
    if (mySerial.available()) {
       char c = mySerial.read(); //takes character in serial buffer and stores it into the variable c
       if(c == '\n') { //if c = newline do the following (newline tells arduino it is the end of the command
        Serial.println (command);
        command = "";
        }  else {
        command += c;
        }
    }

//Digital Write commands
//Code Breakdown DW = Digital Write, H = High, 06 = Pin number
          //DWH06 to turn LED on
          if(command.substring(0,2) == "DW") {
            if(command.substring(2,3) == "H") {
            digitalWrite(command.substring(4,5).toInt(), HIGH);
            digitalLEDStatus = 1;
            }

            //DWL06 to turn LED off
            if(command.substring(2,3) == "L") {
            digitalWrite(command.substring(4,5).toInt(), LOW);
             digitalLEDStatus = 0;
             }
            }

//Analog Write Commands
//AW05254E
//Code Break down AW = Analogue Write, 05 = Pin Number, 254 = PWM input, E = End of string(used to ensure function 
//doesn't run until all of the PWM number comes through the serial 
            
            if(command.substring(0,2) == "AW" && command.endsWith("E")) {
            analogLEDVal = command.substring(4,7).toInt(); 
            analogWrite(command.substring(3,4).toInt(), analogLEDVal);
            }
            



    

    

  //POT Function
potValue = analogRead(potPin);
potLEDValue = map(potValue,0,1023,0,255);
analogWrite(potLEDPin, potLEDValue);




//Switch Functions
switchVal = digitalRead(switchPin);
if (switchVal == LOW) {
  digitalWrite(switchLEDPin, LOW);
} else if (switchVal == HIGH) {
  digitalWrite(switchLEDPin, HIGH);
} else {}



//Serial.print("Pot Value: ");
//Serial.print(potLEDValue);

//Serial.print("  Switch Val: ");
//Serial.print(switchVal);

//Serial.print("  Analog LED Val: ");
//Serial.print(analogLEDVal);

//Serial.print("  Digital LED Val: ");
//Serial.println(digitalLEDStatus);
}
