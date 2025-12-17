#include <Arduino.h>
#include "pitches.h"

// https://www.espboards.dev/blog/buzzer-with-esp32-s3/
// Uses Passive 5v Buzzer (CYT1008) connected to BUZZER_PIN

const int BUZZER_PIN = 14; // the buzzer pin

// PWM Settings (for ESP32)
const int PWM_CHANNEL = 0; // Use Channel 0
// Matching pwm frequency to resonant frequency increases loudness
const int PWM_FREQ = 2048; // CYT1008 resonant frequency is 2kHz - 4kHz
const int PWM_RESOLUTION = 8; // 8-bit resolution (0-255)

void setup()
{
  // Configure LEDC for buzzer
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(BUZZER_PIN, PWM_CHANNEL);
}

void loop()
{
  ledcWriteTone(PWM_CHANNEL, NOTE_E4);
  delay(500); // Wait for 500 milliseconds
  ledcWriteTone(PWM_CHANNEL, 0); // Stop the tone
  delay(500); // Wait for 500 milliseconds

  ledcWriteTone(PWM_CHANNEL, NOTE_D4);
  delay(500); // Wait for 500 milliseconds
  ledcWriteTone(PWM_CHANNEL, 0); // Stop the tone
  delay(500); // Wait for 500 milliseconds
}
