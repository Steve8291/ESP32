#include <Arduino.h>
#include <LiquidCrystal_I2C.h>  // https://github.com/johnrickman/LiquidCrystal_I2C.git

// https://maxpromer.github.io/LCD-Character-Creator/
// LCD's can store up to 8 custom characters in memory (0-7)

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

// Define a custom character as an 8 byte array
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
  // Store custom character in the LCD's memory at index 0
  lcd.createChar(0, heart);
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
