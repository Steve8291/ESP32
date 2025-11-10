# Fix clang-tidy flagging `#include <Arduino.h>`
To re-generate `compile_commands.json` for Clang-Tidy in VS Code, especially when working with Arduino projects that include `<Arduino.h>`, you need a method to capture the compilation commands used by the Arduino build system.
```bash
pio run -t compiledb
```