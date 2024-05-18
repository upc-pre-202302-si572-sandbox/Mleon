#include "blinker1.h"

void setup() {
  // put your setup code here, to run once:
  Blinker blinker;
  blinker.setupLed();
}
 
void loop() {
  // put your main code here, to run repeatedly:
  Blinker blinker;
  digitalWrite(4, HIGH);
  blinker.red();
  blinker.makePause();
  blinker.yellow();
  blinker.makePause();
  blinker.green();
  blinker.makePause();
}