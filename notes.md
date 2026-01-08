## Fix clang-tidy flagging `#include <Arduino.h>`
To re-generate `compile_commands.json` for Clang-Tidy in VS Code, especially when working with Arduino projects that include `<Arduino.h>`, you need a method to capture the compilation commands used by the Arduino build system.
```bash
pio run -t compiledb
```
Note: This no longer works on pioArduino. To fix open the Command Pallette in vsCode and type `pioarduino: Rebuild IntelliSense Index`

## Install pioArduino
First you need to remove platformio:
1) Uninstall the extension
2) Delete the hidden directory: `sudo rm -r ~/.platformio`
3) Restart vsCode and install pioArduino

## Fix your `platformio.ini` file
To use the latest 3.x version of the Arduino core for the ESP32 change your platform as follows:  
`platform = https://github.com/pioarduino/platform-espressif32/releases/download/stable/platform-espressif32.zip`

To use Arduino 2.x:
`platform = espressif32 @ 6.12.0`
See this to figure out versions: https://github.com/sivar2311/platform-espressif32-versions/blob/main/README.md
