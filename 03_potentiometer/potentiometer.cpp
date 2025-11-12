#include <Arduino.h>

// POTENTIOMETER

  // Measure the position of a potentiometer and use it to
  // control the blink rate of an LED. Turn the knob to make
  // it blink faster or slower!

const int POTPIN = GPIO_NUM_33;  // The potentiometer is connected to analog pin 33
const int LEDPIN = GPIO_NUM_16;     // The LED is connected to digital pin 16
const int RESOLUTION = 12;         // 12-bit resolution for ESP32 ADC (0-4095)


void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(POTPIN, INPUT);
  analogWriteResolution(RESOLUTION); // Set the ADC resolution to 12 bits (0-4095)
}

void loop() {
  int sensorValue;
  sensorValue = analogRead(POTPIN); // Read the potentiometer

  digitalWrite(LEDPIN, HIGH);
  delay(sensorValue);

  digitalWrite(LEDPIN, LOW);
  delay(sensorValue);
}
