#include <Arduino.h>
/*
Hardware Connections (ESP32 to L293D)
  * Motor A Enable (ENA): ESP32 GPIO Pin (e.g., Pin 18) for PWM.
  * Motor A Input 1 (IN1): ESP32 Digital Pin (e.g., Pin 8) for direction.
  * Motor A Input 2 (IN2): ESP32 Digital Pin (e.g., Pin 7) for direction.
  * Motor B ENA (Pin 9): Another ESP32 GPIO (e.g., Pin 22) for PWM.
  * Motor B IN3 & IN4: ESP32 Digital Pins (e.g., 5 & 4) for direction.
  * L293D GND: ESP32 GND.
  * L293D VCC1 (Pin 16): 5V (for IC logic).
  * L293D VCC2 (Pin 8): External Motor Power Supply.
  * Motor Output: Connect motor to Output 1 & 2 (Motor A) and Output 3 & 4 (Motor B). 
*/

// Define Pins for Motor A
const int ENA_PIN = 12; // Connect to L293D ENA (for pwm speed control)
const int IN1_PIN = 13;  // Connect to L293D IN1 (for direction control)
const int IN2_PIN = 14;  // Connect to L293D IN2 (for direction control)

// PWM Settings (for ESP32)
const int PWM_CHANNEL = 0; // Use Channel 0 for Motor A
const int PWM_FREQ = 5000; // 5kHz frequency
const int PWM_RESOLUTION = 8; // 8-bit resolution (0-255)

void setup() {
  Serial.begin(115200);
  
  // Set direction pins as outputs
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  
  // Configure LEDC for speed control (ENA_PIN)
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(ENA_PIN, PWM_CHANNEL); // Attach ENA_PIN to the PWM channel
  
  Serial.println("Setup Complete. Starting Motor Test.");
}

void loop() {
    



  // --- Move Forward (Slow to Fast) ---
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);
  for (int speed = 0; speed <= 255; speed += 10) {
    ledcWrite(PWM_CHANNEL, speed); // Write PWM value to the channel
    delay(100);
  }
  delay(1000); // Run forward for 1 second

  // --- Stop ---
  ledcWrite(PWM_CHANNEL, 0); // Set speed to 0
  delay(1000);

  // --- Move Backward (Fast to Slow) ---
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, HIGH);
  for (int speed = 255; speed >= 0; speed -= 10) {
    ledcWrite(PWM_CHANNEL, speed);
    delay(100);
  }
  delay(1000); // Run backward for 1 second

  // --- Stop ---
  ledcWrite(PWM_CHANNEL, 0);
  delay(1000);
}
