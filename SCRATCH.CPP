/*
Control multiple LEDs with an ESP32 and a 74HC595 shift register.
Define the data, latch, and clock pins.
Use the `shiftOut()` function to send a byte to the shift register.
In the `loop()` function, create patterns for the LEDs in a `byte` variable,
update the register, and add a delay to see the effect.
*/

#include <Arduino.h>

// Pin definitions for ESP32 and 74HC595
const int latchPin = 22;  // Pin connected to the ST_CP pin of the 74HC595
const int clockPin = 23;  // Pin connected to the SH_CP pin of the 74HC595
const int dataPin = 21;   // Pin connected to the DS pin of the 74HC595

// Variable to hold the state of the LEDs (8 bits for 8 LEDs)
byte leds = 0;

// Function to update the shift register with the current state of the leds byte
void updateShiftRegister() {
  digitalWrite(latchPin, LOW);  // Set latch pin LOW to prevent changes while shifting
  shiftOut(dataPin, clockPin, MSBFIRST, leds); // Send the byte to the shift register
  digitalWrite(latchPin, HIGH); // Set latch pin HIGH to update the output pins
}

void setup() {
  // Initialize the pins as outputs
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  updateShiftRegister();
}

void loop() {
  // Example 1: Light up all LEDs one by one
  for (int i = 0; i < 8; i++) {
    bitSet(leds, i); // Set the i-th bit to HIGH
    updateShiftRegister();
    delay(500); // Wait before turning on the next LED
  }


  // Example 2: Turn off all LEDs
  leds = 0; // Reset all bits to LOW
  updateShiftRegister();
  delay(1000);

  // bitClear(leds, i);
}