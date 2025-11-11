#include <Arduino.h>

// RGB LED Common Anode (+)

const int RED_PIN = 16;
const int GREEN_PIN = 17;
const int BLUE_PIN = 5;


void redLight(int duration = 1000) {
  // Red (turn just the red LED on)
  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 255);
  analogWrite(BLUE_PIN, 255);
  delay(duration);
}


void greeenLight(int duration = 1000) {
  // Green (turn just the green LED on)
  analogWrite(RED_PIN, 255);
  analogWrite(GREEN_PIN, 0);
  analogWrite(BLUE_PIN, 255);
  delay(duration);
}


void blueLight(int duration = 1000) {
  // Green (turn just the green LED on)
  analogWrite(RED_PIN, 255);
  analogWrite(GREEN_PIN, 255);
  analogWrite(BLUE_PIN, 0);
  delay(duration);
}

void offLight(int duration = 1000) {
  // Off (all LEDs off)
  analogWrite(RED_PIN, 255);
  analogWrite(GREEN_PIN, 255);
  analogWrite(BLUE_PIN, 255);
  delay(duration);
}

void purpleLight(int duration = 1000) {
  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 255);
  analogWrite(BLUE_PIN, 0);
  delay(duration);
} 

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {

  offLight();
  redLight(4000);
  greeenLight(4000);
  blueLight(4000);
  purpleLight(4000);

}