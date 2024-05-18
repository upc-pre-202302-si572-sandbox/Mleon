#include <Arduino.h>
#include "DisplayActuator.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

DisplayActuator::DisplayActuator() {

}
void DisplayActuator::init() {
    lcd.init();
    lcd.backlight();
    lcd.print("Initializating...");
    delay(3000);
    lcd.clear();
    lcd.print("Ready");
    delay(3000);
    lcd.clear();
  }  

void DisplayActuator::setCursor(int row, int column) {
  lcd.setCursor(row, column);
}

void DisplayActuator::printDistance(float distance) {
  lcd.print(distance, 1);
}

void DisplayActuator::printText(String text) {
  lcd.print(text);
}

void DisplayActuator::clear() {
  lcd.clear();
}