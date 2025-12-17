#include <Arduino.h>

int motor1A = 13;
int motor2A = 14;


void setup() {
  // initialize digital pin as an output.
  pinMode(motor1A, OUTPUT);
  pinMode(motor2A, OUTPUT);  
}


void loop() {
  
  // Rotate
  digitalWrite(motor1A, HIGH);     
  digitalWrite(motor2A, LOW);   
  delay(2000); 

  // Rotate in the opposite direction
  digitalWrite(motor1A, LOW);     
  digitalWrite(motor2A, HIGH);    
  delay(2000); 

  // Stop
  digitalWrite(motor1A, LOW);     
  digitalWrite(motor2A, LOW);    
  delay(3000);
}

