#include <Arduino.h>
#include <LiquidCrystal_I2C.h>  // https://github.com/johnrickman/LiquidCrystal_I2C.git

// https://maxpromer.github.io/LCD-Character-Creator/

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

byte heart[] = {
  B00000,
  B00000,
  B00000,
  B01010,
  B10101,
  B10001,
  B01010,
  B00100
};






void setup(){
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
  lcd.createChar(0, heart); // create a custom character at position 0
}

void loop(){
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print("Hello, World!");
  delay(1000);
  // clears the display to print new message
  lcd.clear();
  // set cursor to first column, second row
  lcd.setCursor(0,1);
  lcd.write(byte(0)); // display the custom character
  delay(1000);
  lcd.clear(); 
}
