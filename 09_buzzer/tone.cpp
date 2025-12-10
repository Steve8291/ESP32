#include <Arduino.h>
#include "pitches.h"

const int buzzerPin = 14; // the buzzer pin

void setup()
{
  ledcAttachPin(buzzerPin, 0); // Attach the buzzer pin to channel 0
}

void loop()
{
  // tone(buzzerPin, 1000); // Play a 1000 Hz tone
  // delay(500); // For 500 milliseconds
  // noTone(buzzerPin); // Stop the tone
  // delay(500); // Wait for 500 milliseconds
  
  tone(buzzerPin, NOTE_E4, 250); // Play a 2000 Hz tone for 250 milliseconds
  delay(500); // Wait for 500 milliseconds

  tone(buzzerPin, NOTE_D4, 250); // Play a 2000 Hz tone for 250 milliseconds
  delay(500); // Wait for 500 milliseconds
}
