#include <Arduino.h>

int motor1A = 13;
int motor2A = 14;
int enableA = 12;

// PWM settings
const int freq = 5000; // PWM frequency: 5 kHz (Adjust 2-20 kHz as needed)
const int resolution = 8; // PWM resolution: 8 bits (dutyCycle: 0-255)
const int pwmChannel = 0; // Use channel 0 for both motors
int dutyCycle = 200;

void setup() {
  // Set up PWM
  ledcSetup(pwmChannel, freq, resolution);
  ledcAttachPin(enableA, pwmChannel);

  pinMode(motor1A, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(enableA, OUTPUT);

  ledcWrite(enableA, dutyCycle);  // Enable motor with initial duty cycle
  Serial.begin(115200);
  Serial.println("Testing DC Motor...");
}

void loop() {
  // Move the DC motor forward at maximum speed
  Serial.println("Moving Forward");
  digitalWrite(motor1A, LOW);
  digitalWrite(motor2A, HIGH); 
  delay(2000);

  // Stop the DC motor
  Serial.println("Motor stopped");
  digitalWrite(motor1A, LOW);
  digitalWrite(motor2A, LOW);
  delay(1000);

  // Move DC motor backwards at maximum speed
  Serial.println("Moving Backwards");
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor2A, LOW); 
  delay(2000);

  // Stop the DC motor
  Serial.println("Motor stopped");
  digitalWrite(motor1A, LOW);
  digitalWrite(motor2A, LOW);
  delay(1000);

  // Move DC motor forward with increasing speed
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor2A, LOW);
  while (dutyCycle <= 255){
    ledcWrite(enableA, dutyCycle);
    // ledcWrite(pwmChannel, dutyCycle);
    Serial.print("Forward with duty cycle: ");
    Serial.println(dutyCycle);
    dutyCycle = dutyCycle + 5;
    delay(500);
  }
  dutyCycle = 200;
}