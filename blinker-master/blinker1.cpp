#include "blinker1.h"
#include "Arduino.h"
int i = 0;
Blinker::Blinker() {}

void Blinker::setupLed() {
  for (i = 2; i <= 4; i++ ){
    pinMode(i, OUTPUT);
  }
  
}
void Blinker::red() {
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
}
void Blinker::yellow() {
  digitalWrite(4, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(2, LOW);
}
void Blinker::green() {
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
}

void Blinker::makePause() {
  delay(1000);
}
