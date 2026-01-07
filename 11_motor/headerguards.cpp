#include <Arduino.h>

// Check if we are on ESP32
#ifdef ESP32
  #include "esp_arduino_version.h"

  // Check if version is 3.0.0 or higher
  #if ESP_ARDUINO_VERSION >= ESP_ARDUINO_VERSION_VAL(3, 0, 0)
    #define USE_ARDUINO_V3
  #endif
#endif

void setup() {
  #ifdef USE_ARDUINO_V3
    // New Version 3.x Code
    ledcAttach(enable1Pin, freq, resolution); 
  #else
    // Legacy Version 2.x Code
    ledcSetup(pwmChannel, freq, resolution);
    ledcAttachPin(enable1Pin, pwmChannel);
  #endif
}