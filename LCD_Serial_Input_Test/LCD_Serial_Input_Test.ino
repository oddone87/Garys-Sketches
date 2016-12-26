

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String Data;

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.

}

void loop() {
             lcd.setCursor(0, 1);
       lcd.print(millis() / 1000);
  while (Serial.available() >0) {
    char recieved = Serial.read();
    Data += recieved;

    if (recieved == '\n') {
     
      Serial.print("Arduino Recieved: ");
      Serial.print(Data);
      lcd.clear();
       Data.replace("\n","");
                 lcd.setCursor(0, 0);
        lcd.print(Data);

       
      Data = "";
    }

  }
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
 
  // print the number of seconds since reset:
  
}

