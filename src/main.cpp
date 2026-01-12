#include <Arduino.h>

int motor1A = 13;
int motor2A = 14;
int enableA = 12;

// PWM settings
const int freq = 20000; // PWM frequency: 20 kHz (Adjust 2-20 kHz as needed)
const int resolution = 8; // PWM resolution: 8 bits (dutyCycle: 0-255)
int speed = 0;




void stop(int rtime) {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor2A, LOW);
  ledcWrite(enableA, 0);
  delay(rtime);
}

void forward(int spd, int rtime) {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor2A, LOW);
  ledcWrite(enableA, spd);
}

void reverse(int spd, int rtime) {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor2A, HIGH);
  ledcWrite(enableA, spd);
  delay(rtime);
}



void setup() {
  Serial.begin(115200);
  pinMode(motor1A, OUTPUT);
  pinMode(motor2A, OUTPUT);

    // Set up PWM
  ledcAttach(enableA, freq, resolution);
  ledcWrite(enableA, speed);  // Enable motor with initial speed
}



void loop() {
  // forward(255, 2000); // Move forward at speed 200 for 2 seconds
  // stop(1000);         // Stop for 1 second
  reverse(195, 2000); // Move backward at speed 200 for 2 seconds
  // stop(1000);         // Stop for 1 second

  // Move DC motor forward with increasing speed
  // for (int spd = 0; spd <= 255; spd += 5) {
  //   Serial.println(spd);
  //   reverse(spd, 500);
  // }

  // stop(1000);
}