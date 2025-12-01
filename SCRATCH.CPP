#include <Arduino.h>

// Pin definitions for ESP32 and 74HC595
const int latchPin = 22;  // Pin connected to the ST_CP pin of the 74HC595
const int clockPin = 23;  // Pin connected to the SH_CP pin of the 74HC595
const int dataPin = 21;   // Pin connected to the DS pin of the 74HC595

// Array to store the segment patterns for digits 0-9 and a blank (all off)
// For a common cathode (+) a '0' (LOW) turns on a segment, a '1' (HIGH) turns it off.
byte digits[] = {
  // a  b  c  d  e  f  g  DP
  B00111110, // 0
  B11111001 // 1
  };



// Function to update the shift register with byte patterns.
void updateShiftRegister(byte pattern) {
  digitalWrite(latchPin, LOW);  // Set latch pin LOW to prevent changes while shifting
  shiftOut(dataPin, clockPin, MSBFIRST, pattern); // Send the byte to the shift register
  digitalWrite(latchPin, HIGH); // Set latch pin HIGH to update the output pins
}

void setup() {
  // Initialize the pins as outputs
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  // updateShiftRegister(blank);
}

void loop() {
  updateShiftRegister(digits[0]); // Display '0'
}