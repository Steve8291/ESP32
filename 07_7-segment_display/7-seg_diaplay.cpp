#include <Arduino.h>

// Pin definitions for ESP32 and 74HC595
const int latchPin = 22;  // Pin connected to the ST_CP pin of the 74HC595
const int clockPin = 23;  // Pin connected to the SH_CP pin of the 74HC595
const int dataPin = 21;   // Pin connected to the DS pin of the 74HC595

// Array to store the segment patterns for digits 0-9 and a blank (all off)
// For a common cathode (+) a '0' (LOW) turns on a segment, a '1' (HIGH) turns it off.
  // a  b  c  d  e  f  g DP
  // 0  1  0  0  1  0  0  1
byte digits[] = {
  B00000011, // 0
  B10011111, // 1
  B00100101, // 2
  B00001101, // 3
  B10011001, // 4
  B01001001, // 5
  B01000001, // 6
  B00011111, // 7
  B00000001, // 8
  B00001001 // 9
  };

byte blank = B11111111; // All segments off


// byte digits_array[11] = {0x3, 0x9F, 0x25, 0xD, 0x99, 0x49, 0x41, 0x1F, 0x1, 0x9}; // Hex values for digits 0-9

// byte blank = 0xFF; // All segments off

// Function to update the shift register with byte patterns.
void updateShiftRegister(byte pattern) {
  digitalWrite(latchPin, LOW);  // Set latch pin LOW to prevent changes while shifting
  shiftOut(dataPin, clockPin, MSBFIRST, pattern); // Send the byte to the shift register
  digitalWrite(latchPin, HIGH); // Set latch pin HIGH to update the output pins
}


void countup() {
  for (int i = 0; i <= 9; i++) {
    updateShiftRegister(digits[i]); // Display digit
    delay(1000); // Wait for 1 second
  }
  updateShiftRegister(blank); // Turn off all segments
}


void countdown() {
  for (int i = 9; i >= 0; i--) {
    updateShiftRegister(digits[i]); // Display digit
    delay(1000); // Wait for 1 second
  }
  updateShiftRegister(blank); // Turn off all segments
}


void setup() {
  // Initialize the pins as outputs
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  updateShiftRegister(blank);
}

void loop() {
  countdown();
  // updateShiftRegister(digits[0]); // Display '0'
  // delay(1000);
  // updateShiftRegister(digits[1]); // Display '1'
  // delay(1000);
}