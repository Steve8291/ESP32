#include <Arduino.h>

// POTENTIOMETER

  // Measure the position of a potentiometer and use it to
  // control the blink rate of an LED. Turn the knob to make
  // it blink faster or slower!

int sensorPin = GPIO_NUM_33;  // The potentiometer is connected to analog pin 33
int ledPin = GPIO_NUM_16;     // The LED is connected to digital pin 16


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() {
  int sensorValue;
  sensorValue = analogRead(sensorPin);

  digitalWrite(ledPin, HIGH);
  delay(sensorValue);

  digitalWrite(ledPin, LOW);
  delay(sensorValue);
}
