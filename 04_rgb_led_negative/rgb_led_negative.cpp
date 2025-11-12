#include <Arduino.h>

/*
 * RGB LED Common Cathode (-)
 * 
 * Uses functions to control an RGB LED.
 */

// "const" indicates that this variable will never change.
const int RED_PIN = 11;
const int GREEN_PIN = 10;
const int BLUE_PIN = 9;

// Controls how fast we loop through the colors.
// Change this to fade faster or slower.
int DISPLAY_TIME = 100;   // In milliseconds


void mainColors() {
  // Off (all LEDs off)
  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 0);
  analogWrite(BLUE_PIN, 0);

  delay(1000);

  // Red (turn just the red LED on)
  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 0);
  analogWrite(BLUE_PIN, 0);

  delay(1000);

  // Green
  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 255);
  analogWrite(BLUE_PIN, 0);

  delay(1000);

  // Blue
  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 0);
  analogWrite(BLUE_PIN, 255);

  delay(1000);

  // Yellow
  analogWrite(RED_PIN, 255);
  analogWrite(GREEN_PIN, 255);
  analogWrite(BLUE_PIN, 0);

  delay(1000);

  // Cyan
  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 255);
  analogWrite(BLUE_PIN, 255);

  delay(1000);

  // Purple
  analogWrite(RED_PIN, 255);
  analogWrite(GREEN_PIN, 0);
  analogWrite(BLUE_PIN, 255);

  delay(1000);

  // White
  analogWrite(RED_PIN, 255);
  analogWrite(GREEN_PIN, 255);
  analogWrite(BLUE_PIN, 255);

  delay(1000);
  
}


void showRGB(int color) {
  int redIntensity;
  int greenIntensity;
  int blueIntensity;

  if (color <= 255) {
    redIntensity = 255 - color;   // red goes from on to off
    greenIntensity = color;       // green goes from off to on
    blueIntensity = 0;            // blue is always off
  }
  else if (color <= 511) {
    redIntensity = 0;                      // red is always off
    greenIntensity = 255 - (color - 256);  // green on to off
    blueIntensity = (color - 256);         // blue off to on
  }
  else {
    redIntensity = (color - 512);         // red off to on
    greenIntensity = 0;                   // green is always off
    blueIntensity = 255 - (color - 512);  // blue on to off
  }

  // Now that brightness values have been set, write those values to led's
  analogWrite(RED_PIN, redIntensity);
  analogWrite(BLUE_PIN, blueIntensity);
  analogWrite(GREEN_PIN, greenIntensity);

}

void showSpectrum() {
  int x;

  for (x = 0; x < 768; x++) {
    showRGB(x);   // Call RGBspectrum() with our new x
    delay(10);    // Delay 10 ms

  }
}

void setup() {
  // configure the Arduino pins we are using.
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

}

void loop() {
  // Function to step through all eight colors.
  mainColors();

  showSpectrum();

}