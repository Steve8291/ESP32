#include <Arduino.h>

/*
 * FADE LED
 * 
 * Faddes an LED using PWM (Pulse Width Modulation)
 */

const int ledPin = GPIO_NUM_16; // GPIO pin where the LED is connected


void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop(){
  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    analogWrite(ledPin, dutyCycle);
    delay(15);
  }

  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    analogWrite(ledPin, dutyCycle);
    delay(15);
  }
}