#include <Arduino.h>

/*
 * BLINK LED
 * 
 * Turns an LED on for one second, then off for one second, repeatedly.
 */




void setup() {
  // put your setup code here, to run once:
  pinMode(GPIO_NUM_16, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(GPIO_NUM_16, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(1000);                    // wait for a second (value in milliseconds)
  digitalWrite(GPIO_NUM_16, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);

}