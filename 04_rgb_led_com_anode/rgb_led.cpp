#include <Arduino.h>

// RGB LED Common Anode (+)

const int RED_PIN = 16;
const int GREEN_PIN = 17;
const int BLUE_PIN = 5;


void redLight(int duration = 1000) {
  // Red (turn just the red LED on)
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
  delay(duration);
}


void greeenLight(int duration = 1000) {
  // Green (turn just the green LED on)
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
  delay(duration);
}


void blueLight(int duration = 1000) {
  // Green (turn just the green LED on)
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
  delay(duration);
}

void offLight(int duration = 1000) {
  // Off (all LEDs off)
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
  delay(duration);
}

void myColor(int duration = 1000) {
  // My Color
  analogWrite(RED_PIN, 150);
  analogWrite(GREEN_PIN, 200);
  analogWrite(BLUE_PIN, 150);
  delay(duration);
} 

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {

  offLight();
  blueLight(4000);
  greeenLight(4000);
  redLight(4000);
  // myColor(4000);

}