#include <Arduino.h>
#include "pitches.h"

const int BUZZER_PIN = 25; // the buzzer pin
const int TOUCH_PINS[] = { 4, 15, 13, 12, 14, 27, 33, 32 };

// PWM Settings (for ESP32)
const int PWM_CHANNEL = 0; // Use Channel 0
const int PWM_FREQ = 2000; // 2kHz frequency
const int PWM_RESOLUTION = 8; // 8-bit resolution (0-255)

// Define the musical notes
const int TONE[] = { NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, 
  NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5 }; 

int threshold = 30;

void setup() {
  Serial.begin(115200);

    // Set the touch pins as inputs
  for (int i = 0; i < 8; i++) {
    pinMode(TOUCH_PINS[i], INPUT);
  }

  // Configure LEDC for buzzer
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(BUZZER_PIN, PWM_CHANNEL); // Attach the buzzer pin to channel 0
}

void loop() {
  // Loop through each touch pin
  for (int i = 0; i < 8; i++) {

    // Read and print the touch value
    int touchValue = touchRead(TOUCH_PINS[i]);
    Serial.print(i);
    Serial.print(": ");
    Serial.println(touchValue);

    // Check if the current touch pin is being touched
    if (touchValue < threshold) {
      // ledcWrite(BUZZER_PIN, TONE[i]);
      tone(BUZZER_PIN, TONE[i], 150);
      delay(150);
      ledcWrite(BUZZER_PIN, 0); // Stop the tone after duration
    }
  }
}
