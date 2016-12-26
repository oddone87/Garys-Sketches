int oneSecondInterval = 1000;
int tickInterval = 1000;
int slowTickCounter =0;

int acceleration = 75;
int firstSlowTickCounterStop = 30; //30
int accelerationTickCounterStop = 80; //30
int finalTickCounterStop = 240; //240

int buttonState = 0;
int prevButtonState = 0;
int buttonPin = 13;
int clock1Pin = 7;
int clock2Pin = 8;
int tickPin = clock1Pin;

int slowTimeRun = 0;

unsigned long startTime = 0;


void setup() {
  pinMode(clock1Pin, OUTPUT);
  pinMode(clock2Pin, OUTPUT);

  digitalWrite(clock1Pin, LOW);
  digitalWrite(clock2Pin, LOW);

  pinMode(buttonPin, INPUT);

  startTime = millis();

    Serial.begin(9600);
}

void loop() {

  buttonCheck_func();

    if (millis() > (startTime + tickInterval)) {
        if (slowTimeRun == 1) {
            slowTick_func();
            slowTickCounter++; 
       }
    doTick_func();
    startTime=millis();
    debug_func();
  }
}

void debug_func () {
  Serial.print (tickInterval);
  Serial.print ("\t");
  Serial.print (slowTimeRun);  
    Serial.print (prevButtonState);
  Serial.print (buttonState);
  Serial.println (slowTickCounter);
}

void doTick_func () {
  digitalWrite(tickPin, HIGH);
  delay(10);
  digitalWrite(tickPin, LOW);
  if (tickPin == clock1Pin) {
    tickPin = clock2Pin;
  } else {
    tickPin = clock1Pin;
  }
}

void buttonCheck_func () {
  buttonState = digitalRead(buttonPin);
  if (buttonState != prevButtonState) {
    if ((buttonState == HIGH) && (slowTimeRun == 0)) {
      slowTimeRun = 1;
    }
    prevButtonState = buttonState;
  }
}

void slowTick_func () {
  if (slowTickCounter < firstSlowTickCounterStop) {
    tickInterval = 1000;
  } else if ((slowTickCounter >= firstSlowTickCounterStop) && (slowTickCounter < accelerationTickCounterStop)) {
    tickInterval = (tickInterval + acceleration);
  }
  else if (slowTickCounter >= finalTickCounterStop) {
    tickInterval = 1000;
    slowTimeRun = 0;
    slowTickCounter = 0;
  }
}

