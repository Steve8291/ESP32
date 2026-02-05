# Install pioArduino and Remove platformio
First you need to remove platformio:
1) Uninstall the extension.
2) Delete `.pio/` and `.vscode/` and `compile_commands.json` from your projects.
3) Delete the hidden directory: `sudo rm -r ~/.platformio`
4) Restart vsCode and double check to be sure `~/.platformio` wasn't recreated and `platformio` didn't reinstall.
5) Install pioArduino extension.
6) Delete `.pio/` and `.vscode/` and `compile_commands.json` again and close and reopen your project.
7) Run a Full Clean after changing your "platform" in `platformio.ini`

# Fresh Install of vsCode and pioArduino
```bash
sudo snap install --classic code
sudo apt install git
# sudo apt install clang-tidy
sudo apt install python3-venv
curl -LsSf https://astral.sh/uv/install.sh | sh  # Install uv for VSCode pioArduino
git config --global user.name "$githubusername"
git config --global user.email "$githubemail"
# vsCode Extensions:
code --install-extension "ms-vscode.cpptools-extension-pack" # C and C++ coding language extension for VSCode
code --install-extension "pioarduino.pioarduino-ide" # PlatformIO Arduino extension for VSCode
code --install-extension "timonwong.shellcheck" # ShellCheck extension for VSCode
code --install-extension "CS128.cs128-clang-tidy" # Clang-Tidy extension for VSCode
```

# General Installation Fixes
## Fix Clang-Tidy flagging `#include <Arduino.h>`
Re-generate `compile_commands.json` for Clang-Tidy in VS Code, especially when working with Arduino projects that include `<Arduino.h>`, you need a method to capture the compilation commands used by the Arduino build system.
```bash
pio run -t compiledb
```
You should re-run this command every time you make changes to your `.platformio.ini` file's: platform, board, or framework. You do not need to delete `compile_commands.json` first.
Note: If `pio` commands fail with command not found you are probably in a "bash" terminal session with your system profile $PATH. You need to open a new terminal window that has "pioarduino CLI" as its profile. This will have the proper $PATH to pio set up.


## Fix your `platformio.ini` file
To use the latest 3.x version of the Arduino core for the ESP32 change your platform as follows:  
`platform = https://github.com/pioarduino/platform-espressif32/releases/download/stable/platform-espressif32.zip`
Note: This uses C++20

To use Arduino 2.x:
`platform = espressif32 @ 6.12.0`
See this to figure out versions: https://github.com/sivar2311/platform-espressif32-versions/blob/main/README.md


## Find Crystal Frequency:
In termainl run: `esptool -p /dev/ttyUSB0 chip-id`  
Note: you might need to replace /dev/ttyUSB0 with your ESP32 port.  
Then set the resulting Crystal frequency in your `platformio.ini`  
`board_xtal_freq = 40MHz`

## Remove files already tracked in git
If you have added a file to your `.gitignore` but it was previously uploaded to git, your `.gitignore` will not work. You must first run these example commands.
```bash
git rm --cached -r .vscode/
git rm --cached compile_commands.json
git commit -m "Remove .vscode and compile_commands.json from tracking"
```
Then push the commit in Source Control

## .gitignore File
```bash
.pio/
.vscode/
compile_commands.json
.DS_Store
```