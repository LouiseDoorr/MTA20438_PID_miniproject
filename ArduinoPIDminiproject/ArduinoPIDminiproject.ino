#include "SevSeg.h"

SevSeg numDis;

// Pins
const int redLED = 22;
const int yellowLED = 23;
const int greenLED = 24;
const int blueLED = 25;
const int redLEDsig = 31;
const int yellowLEDsig = 28;
const int greenLEDsig = 27;
const int blueLEDsig = 30;
const int pinSW = 26;
const int pinX = 0;
const int pinY = 1;

// Controlflow
int task;
int counter = 0;
bool taskDone = true;
bool gameOn;

void setup() {
  // Number display setup
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  numDis.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  numDis.setBrightness(30);

  // LEDs setup
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLEDsig, OUTPUT);
  pinMode(yellowLEDsig, OUTPUT);
  pinMode(greenLEDsig, OUTPUT);
  pinMode(blueLEDsig, OUTPUT);
  randomSeed(analogRead(A3));

  // Joystick setup
  pinMode(pinSW, INPUT);
  digitalWrite(pinSW, HIGH);
  Serial.begin(9600);
}

void loop() {
  // Task control
  if (counter != 20) {
    if (taskDone == true) {
      task = random(1, 5);
      taskDone = false;
      delay(500);
    }
    digitalWrite(redLEDsig, HIGH);
    digitalWrite(yellowLEDsig, HIGH);
    digitalWrite(greenLEDsig, HIGH);
    digitalWrite(blueLEDsig, HIGH);
    numDis.setNumber(counter);
    numDis.refreshDisplay();

    switch (task) {
      case 1:
        digitalWrite(redLED, HIGH);
        if (analogRead(pinX) > 900) {
          digitalWrite(redLED, LOW);
          counter ++;
          taskDone = true;
        }
        break;
      case 2:
        digitalWrite(yellowLED, HIGH);
        if (analogRead(pinX) < 300) {
          digitalWrite(yellowLED, LOW);
          counter ++;
          taskDone = true;
        }
        break;
      case 3:
        digitalWrite(greenLED, HIGH);
        if (analogRead(pinY) > 900) {
          digitalWrite(greenLED, LOW);
          counter ++;
          taskDone = true;
        }
        break;
      case 4:
        digitalWrite(blueLED, HIGH);
        if (analogRead(pinY) < 300) {
          digitalWrite(blueLED, LOW);
          counter ++;
          taskDone = true;
        }
        break;
    }
  }
  else {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
    digitalWrite(redLEDsig, LOW);
    digitalWrite(yellowLEDsig, LOW);
    digitalWrite(greenLEDsig, LOW);
    digitalWrite(blueLEDsig, LOW);
    numDis.setChars("END");
    numDis.refreshDisplay();
  }
}
