#include <Arduino.h>

// Variables & Constants
const int boardVersion = 1; // Constant integer (cannot be changed)
int counter = 0; // Variable integer (can be changed) Whole Numbers only
float voltage = 4.95; // Variable float (can be changed) Decimal Numbers allowed
bool isReady = true; // Variable boolean (can be changed) True or False
int totalItems = 4;
String myName = "Steve"; // Variable String (can be changed) Textual data


// Arrays
int sensorReadings[] = {512, 1023, 256, 768}; // Array of integers


// Function takes a String parameter with no return value
void printGreeting(String userName) {
  Serial.print("Hello, ");
  Serial.println(userName);
}

// Function that takes an integer parameter and returns an integer
int sum(int a, int b) {
  Serial.print("The sum of ");
  Serial.print(a);
  Serial.print(" and ");
  Serial.print(b);
  return a + b;
}

void setup() {
  Serial.begin(115200);

  Serial.println();
  Serial.print("Board Version: ");
  Serial.println(boardVersion);
  Serial.print("Sensor Reading 1: ");
  Serial.println(sensorReadings[0]);
  Serial.print("Last Sensor Reading: ");
  Serial.println(sensorReadings[3]);

  // 'for' loop stepping through the array
  for (int i = 0; i < 4; i++) {
    Serial.println(i);
  }

  // for loop to iterate through the array and print each value
  for (int i = 0; i < totalItems; i++) {
    Serial.println(sensorReadings[i]);
  }

  // 'while' loop counting up to 3
  while (counter <= 3) {
    Serial.println(counter);
    counter++;
  }

  printGreeting("Bobby");
  printGreeting(myName);

  int result = sum(5, 10);
  Serial.print("\nResult: ");
  Serial.println(result);

  // if statement to check if result is greater than 10
  if (result > 10 && isReady) {
    Serial.println("Result is greater than 10");
  } else if (result == 10) {
    Serial.println("Result is equal to 10");
  } else if (result < 10) {
    Serial.println("Result is less than 10");
  } else if (!isReady) {
    Serial.println("System is not ready");
  }



}



void loop() {

}