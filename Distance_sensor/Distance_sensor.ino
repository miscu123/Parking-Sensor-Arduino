// sensor PINS
const int trigPin = 7;
const int echoPin = 2;  

// led PINS
const int greenLED = 9;
const int yellowLED = 10;
const int redLED = 11;

volatile unsigned long startTime = 0;
volatile unsigned long duration = 0;
volatile bool newData = false;
unsigned long lastTrigger = 0;
const unsigned long triggerInterval = 60000; 

// setup the trigger, echo and leds for output / input
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(echoPin), echoISR, CHANGE);
}

void loop() {
  unsigned long now = micros();

  // send triggers after 60ms (triggerInterval)
  if (now - lastTrigger >= triggerInterval) {
    lastTrigger = now;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
  }

  if (newData) {
    newData = false;
    long cm = microsecondsToCentimeters(duration);

    // leds ON / OFF based on distance to object in front 
    if (cm > 30) {
      digitalWrite(greenLED, HIGH);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, LOW);
    } else if (cm > 15 && cm <= 30) {
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(redLED, LOW);
    } else {
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, HIGH);
    }
  }
}

void echoISR() {
  if (digitalRead(echoPin) == HIGH) {
    startTime = micros();
  } else {
    duration = micros() - startTime;
    newData = true;
  }
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
