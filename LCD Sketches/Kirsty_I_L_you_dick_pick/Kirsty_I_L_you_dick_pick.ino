

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);



void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.

}

void loop() {
             lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print ("       Hey");
             lcd.setCursor(0, 1);
             lcd.print ("     Gremlin");
             delay(1000);
             
 
             
             lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print ("In my Weird way");
             lcd.setCursor(0, 1);
             lcd.print ("I wanted to show");
             delay(1000);

             lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print (" That even when");
             lcd.setCursor(0, 1);
             lcd.print ("   TINKERING");
             delay(1000);

                lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print ("And getting lost");
             lcd.setCursor(0, 1);
             lcd.print ("In my own bubble");
             delay(1000);

                lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print ("half my brain");
             lcd.setCursor(0, 1);
             lcd.print ("is devoted...");
             delay(1000);

                lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print (" Completely to");
             lcd.setCursor(0, 1);
             lcd.print ("      YOU");
             delay(1000);

                lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print ("  Now Here's a ");
             lcd.setCursor(0, 1);
             lcd.print ("  **Dick Pic**");
             delay(1000);

             lcd.clear();


             lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print ("D");
             lcd.setCursor(0, 1);
             lcd.print ("");
             delay(200);

             lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print ("=D");
             lcd.setCursor(0, 1);
             lcd.print ("");
             delay(200);

             lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print ("==D");
             lcd.setCursor(0, 1);
             lcd.print ("");
             delay(200);

             lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print ("===D");
             lcd.setCursor(0, 1);
             lcd.print ("");
             delay(200);

             lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print ("====D");
             lcd.setCursor(0, 1);
             lcd.print ("");
             delay(200);

             lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print ("=====D");
             lcd.setCursor(0, 1);
             lcd.print ("");
             delay(200);

             lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print ("8=====D");
             lcd.setCursor(0, 1);
             lcd.print ("");
             delay(200);

             
             lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print (" 8=====D");
             lcd.setCursor(0, 1);
             lcd.print ("");
             delay(200);

             
             lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print ("  8=====D");
             lcd.setCursor(0, 1);
             lcd.print ("");
             delay(200);

             
             lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print ("   8=====D");
             lcd.setCursor(0, 1);
             lcd.print ("");
             delay(200);

             
             lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print ("    8=====D");
             lcd.setCursor(0, 1);
             lcd.print ("");
             delay(200);

             
             lcd.clear();
             lcd.setCursor(0, 0);
             lcd.print ("     8=====D");
             lcd.setCursor(0, 1);
             lcd.print ("");
             delay(2000);

  }



