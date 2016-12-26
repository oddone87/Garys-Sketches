int analogPinL = 5;  // one side of copper tape connected to anolog pin 5 other side connected to ground
int analogPinR = 4;
                       // outside leads to ground and +5V

int valL = 0;           // variable to store the value read
int valR = 0; 


void setup()

{

  Serial.begin(9600);          //  setup serial
  pinMode(13, OUTPUT);          //sets the pin of the LH led
  pinMode(11, OUTPUT);          //RH LED
  pinMode(12, OUTPUT);        //sets the pin of the Optoisolator
digitalWrite(13, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);

}



void loop()

{

  valL = analogRead(analogPinL);    // read the input pin
  valR = analogRead(analogPinR);

  Serial.print("LH Val = ");
  Serial.print(valL);             // debug value
    Serial.print("   RH Val = ");
  Serial.println(valR);  

  if ((valL < 400) && (valR > 400)) //LH down RH Up
{
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
}


  if ((valL > 400) && (valR < 400))  //LH up RH Down
{
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
}


  if ((valL > 400) && (valR > 400))   //LH & RH Up
{
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
}


  if ((valL < 400) && (valR < 400))
{
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
}





}

  
