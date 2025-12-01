#include <Arduino.h>

// Pin definitions for ESP32 and 74HC595
const int latchPin = 22;  // Pin connected to the ST_CP pin of the 74HC595
const int clockPin = 23;  // Pin connected to the SH_CP pin of the 74HC595
const int dataPin = 21;   // Pin connected to the DS pin of the 74HC595

// Array to store the segment patterns for digits 0-9 and a blank (all off)
// For a common cathode (+) a '0' (LOW) turns on a segment, a '1' (HIGH) turns it off.
// byte digits[11][8] = {
// // a  b  c  d  e  f  g  DP
//   {0, 0, 0, 0, 0, 0, 1, 1}, // 0
//   {1, 0, 0, 1, 1, 1, 1, 1}, // 1
//   {0, 0, 1, 0, 0, 1, 0, 1}, // 2
//   {0, 0, 0, 0, 1, 1, 0, 1}, // 3
//   {1, 0, 0, 1, 1, 0, 0, 1}, // 4
//   {0, 1, 0, 0, 1, 0, 0, 1}, // 5
//   {0, 1, 0, 0, 0, 0, 0, 1}, // 6
//   {0, 0, 0, 1, 1, 1, 1, 1}, // 7
//   {0, 0, 0, 0, 0, 0, 0, 1}, // 8
//   {0, 0, 0, 0, 1, 0, 0, 1}, // 9
//   {1, 1, 1, 1, 1, 1, 1, 1}  // Blank
// };

byte digits_array[11] = {0x3, 0x9F, 0x25, 0xD, 0x99, 0x49, 0x41, 0x1F, 0x1, 0x9}; // Hex values for digits 0-9

byte blank = 0xFF; // All segments off

// Function to update the shift register with the current state of the leds byte
void updateShiftRegister(byte pattern) {
  digitalWrite(latchPin, LOW);  // Set latch pin LOW to prevent changes while shifting
  shiftOut(dataPin, clockPin, MSBFIRST, pattern); // Send the byte to the shift register
  digitalWrite(latchPin, HIGH); // Set latch pin HIGH to update the output pins
}

void countdown() {
  // Cycle through digits 0-9
  for (int i = 0; i < 11; i++) {
    updateShiftRegister(digits_array[i]);
    delay(1000); // Display each digit for 1 second
  }
  updateShiftRegister(blank);
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
}



