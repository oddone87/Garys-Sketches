#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
  
Adafruit_BNO055 bno = Adafruit_BNO055(55);

float AccelTotal = 0;
int x = 0;
int y = 0;
int z = 0;
int repcount = 0;
int count1 = 0;
int count2 = 0;
int count3 = 0;
int count4 = 0;
int count5 = 0;
int count6 = 0;
int count7 = 0;
int count8 = 0;
int count9 = 0;
int count10 = 0;
int counttotal = 0;
int counttotalavg = 0;
 
void setup(void) 
{
  Serial.begin(9600);
  Serial.println("Orientation Sensor Test"); Serial.println("");
  
  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  delay(1000);
    
  bno.setExtCrystalUse(true);
}
 
void loop(void) 
{
  /* Get a new sensor event */ 
  sensors_event_t event; 
  bno.getEvent(&event);
  
 // Possible vector values can be:
  // - VECTOR_ACCELEROMETER - m/s^2
  // - VECTOR_MAGNETOMETER  - uT
  // - VECTOR_GYROSCOPE     - rad/s
  // - VECTOR_EULER         - degrees
  // - VECTOR_LINEARACCEL   - m/s^2
  // - VECTOR_GRAVITY       - m/s^2
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_LINEARACCEL);
  
  /* Display the floating point data */
  x = ((euler.x())*100);
  y = ((euler.y())*100);
  z = ((euler.z())*100);

  if (x < 0) {
  x = x*-1;
  }

    if (y < 0) {
  y = y*-1;
  }

    if (z < 0) {
  z = z*-1;
  }

    AccelTotal = ((x)+(y)+(z));


      if (repcount == 1) {
    count1=AccelTotal;
    }

      if (repcount == 2) {
    count2=AccelTotal;
    }

      if (repcount == 3) {
    count3=AccelTotal;
    }

      if (repcount == 4) {
    count4=AccelTotal;
    }

      if (repcount == 5) {
    count5=AccelTotal;
    }

      if (repcount == 6) {
    count6=AccelTotal;
    }

      if (repcount == 7) {
    count7=AccelTotal;
    }

      if (repcount == 8) {
    count8=AccelTotal;
    }

      if (repcount == 9) {
    count9=AccelTotal;
    }

      if (repcount == 10) {
    count10=AccelTotal;
    repcount=1;
    }

    counttotal = (count1) + (count2) + (count3) + (count4) + (count5) + (count6) + (count7) + (count8) + (count9) + (count10);
    counttotalavg = counttotal/10;

  Serial.print(repcount);
  Serial.print("\t");
  Serial.print(counttotal);
    Serial.print("\t");
      Serial.print(counttotalavg);
    Serial.print("\t");

  
  Serial.print(x);
  Serial.print("\t");
  Serial.print(y);
  Serial.print("\t");
  Serial.print(z);
  Serial.print("\t");

  Serial.print("Accel Total: ");
  Serial.print(AccelTotal);

  Serial.println("");
  delay(10);
  repcount++;
}
