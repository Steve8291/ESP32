#include <Arduino.h>

int motor1A = 13;
int motor2A = 14;

// PWM settings
const int freq = 500; // PWM frequency: 500 Hz
const int resolution = 8; // PWM resolution: 8 bits
const int ledChannel = 0; // Use channel 0 for both motors


void setup() {
  // Set up PWM
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(motor1A, ledChannel);
  ledcAttachPin(motor2A, ledChannel);

  Serial.begin(115200);
}

void loop() {
  // Increase speed gradually
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    Serial.println(dutyCycle);
    ledcWrite(motor1A, dutyCycle);
    ledcWrite(motor2A, 0);
    delay(50);
  }

  delay(2000);

  // Decrease speed gradually
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    Serial.println(dutyCycle);
    ledcWrite(motor1A, dutyCycle);
    ledcWrite(motor2A, 0);
    delay(50);
  }
  
  delay(2000);
}