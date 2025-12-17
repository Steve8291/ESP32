#include <Arduino.h>
#include "pitches.h"

// https://www.espboards.dev/blog/buzzer-with-esp32-s3/

/*
Using newer `ledcAttach` and `ledcWrite` functions for ESP32 PWM control.
Requires newer arduino core 3.x supporting these functions.
Install in `platformio.ini`:
  platform = https://github.com/pioarduino/platform-espressif32/releases/download/stable/platform-espressif32.zip
*/

const int buzzerPin = 14; // the buzzer pin

void setup()
{
  // ledcAttachPin(buzzerPin, 0); // Attach the buzzer pin to channel 0
  ledcAttach(buzzerPin, 2000, 8); // Attach with 2kHz frequency and 8-bit resolution
}

void loop()
{
  // tone() function is used specifically in arduino. For ESP32, use ledcWrite() to generate tones.
  // tone(buzzerPin, 1000); // Play a 1000 Hz tone
  // delay(500); // For 500 milliseconds
  // noTone(buzzerPin); // Stop the tone
  // delay(500); // Wait for 500 milliseconds
  
  // tone(buzzerPin, NOTE_E4, 250); // Play a 2000 Hz tone for 250 milliseconds
  ledcWriteTone(buzzerPin, NOTE_E4);
  delay(500); // Wait for 500 milliseconds
  ledcWriteTone(buzzerPin, 0); // Stop the tone
  delay(500); // Wait for 500 milliseconds

  // tone(buzzerPin, NOTE_D4, 250); // Play a 2000 Hz tone for 250 milliseconds
  ledcWriteTone(buzzerPin, NOTE_D4);
  delay(500); // Wait for 500 milliseconds
  ledcWriteTone(buzzerPin, 0); // Stop the tone
  delay(500); // Wait for 500 milliseconds
}
