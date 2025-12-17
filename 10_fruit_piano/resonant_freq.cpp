#include <Arduino.h>
/*
  ESP32 Passive Buzzer Resonant Frequency Finder
  - Sweeps frequencies from 500 Hz to 5000 Hz
  - Prints current frequency to Serial Monitor
  - You can listen for the loudest tone (resonant frequency)
*/

int startFreq = 500;   // Starting frequency in Hz
int endFreq = 5000;    // Ending frequency in Hz
int stepFreq = 100;    // Frequency step in Hz

int BUZZER_PIN = 25;   // GPIO pin connected to buzzer
int LEDC_CHANNEL = 0;    // PWM channel (0–15 available)
int LEDC_RES     = 8;    // Resolution in bits (8 = 256 steps)
int LEDC_BASEFREQ = 2000; // Base frequency for PWM setup

void setup() {
  Serial.begin(115200);

  // Attach buzzer pin to LEDC channel with base frequency and resolution
  ledcSetup(LEDC_CHANNEL, LEDC_BASEFREQ, LEDC_RES);
  ledcAttachPin(BUZZER_PIN, LEDC_CHANNEL);
}

void loop() {
  // Sweep frequencies from 500 Hz to 5000 Hz
  for (int freq = startFreq; freq <= endFreq; freq += stepFreq) {
    Serial.print("Testing frequency: ");
    Serial.print(freq);
    Serial.println(" Hz");

    // Play tone at current frequency
    ledcWriteTone(LEDC_CHANNEL, freq);

    delay(500); // Hold tone for half a second
  }

  // Stop tone after sweep
  ledcWriteTone(LEDC_CHANNEL, 0);
  Serial.println("Sweep complete. Listen for the loudest tone!");
  delay(3000); // Pause before repeating
}
