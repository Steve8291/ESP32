#include <Arduino.h>

/*
 * FADE LED
 * 
 * Fades an LED using PWM (Pulse Width Modulation)
 */

const int ledPin = GPIO_NUM_16; // GPIO pin where the LED is connected
const int timeDelay = 15;      // Delay time in milliseconds

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop(){
  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){
    // changing the LED brightness with PWM
    analogWrite(ledPin, dutyCycle);
    delay(timeDelay);
  }

  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    analogWrite(ledPin, dutyCycle);
    delay(timeDelay);
  }
}