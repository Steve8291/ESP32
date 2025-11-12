#include <Arduino.h>
#include <Bounce2.h>

// PUSHBUTTON

const int BUTTON_PIN = 5;  // pushbutton pin
const int LED_PIN =  16;    // LED pin

int lastButtonState = HIGH; // Stores pushbutton status (HIGH = 1, LOW = 0)
int ledState = LOW;         // Tracks the current state of the LED.

Bounce2::Button button = Bounce2::Button();


// Light the LED when button is pressed (LOW)
// Turns off LED when button is relesed (HIGH)
void momentaryLight() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {
    digitalWrite(LED_PIN, HIGH);  // turn the LED on, button pressed
  }
  else {
    digitalWrite(LED_PIN, LOW);  // turn the LED off, button released
  }
}

void changeState() {
  if (ledState == LOW) {
    ledState = HIGH;
  }
  else {
    ledState = LOW;
  }
  digitalWrite(LED_PIN, ledState);
}


void lightSwitch(){
  int buttonState = digitalRead(BUTTON_PIN);  // Pressing button = LOW, releasing = HIGH

  if (buttonState != lastButtonState) {   // buttonState starts `HIGH`
    lastButtonState = buttonState;         // If button pressed `buttonState` is set `LOW`
    if (buttonState == HIGH) {             // Releasing button = HIGH and triggers event
      changeState();
    }
  }
}

void lightSwitchDebounced(){
  button.update();  // Update the button state

  if (button.released()) {  // Check if the button was released
    changeState();
  }
}

void setup() {
  // Set up the pushbutton pin to be an input.
  // Activate internal pull-up resistor on button pin.
  // pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Set up the LED pin to be an output:
  pinMode(LED_PIN, OUTPUT);

  button.attach(BUTTON_PIN, INPUT_PULLUP);
  button.interval(25); // Debounce interval in ms
}

void loop() {
  // momentaryLight();
  // lightSwitch();
  lightSwitchDebounced();
}
