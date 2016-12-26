const byte ledPin = 12;
const byte interruptPin = 2;
int shockCount = 0;
int prevShockCount = 0;
int shockDelay = 4000;
unsigned long prevMillis = 0;


void setup() {
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), countfunc, RISING);
}

void loop() {
 Serial.println(shockCount);
  
  if (shockCount > 0) {
    prevShockCount = shockCount;
    delay(4000);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    shockCount--;
    }
}

void countfunc() {
  shockCount++;
}
