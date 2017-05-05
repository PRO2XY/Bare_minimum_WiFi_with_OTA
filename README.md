# Bare minimum sketch for WiFi and OTA on ESP8266

A template sketch that provides all required functions for ESP8266 to connect to a WiFi network (including configuration through a captive portal: thanks tzapu!) and Arduino OTA.
This serves as a one time serial upload to a new ESP8266 board, which can then be flashed through OTA thereafter. 

### How it works:
The ESP8266 boots into STA mode and tries to connect to a previously known WiFi network (if available). If successful it configures Arduino OTA, finishes rest of the setup funciton and runs loop. If WiFi connection fails or no known connection is available it runs the WiFiManager configuration portal. On successful configuration, the ESP restarts and goes through the above again. If unsuccessful, you have the option of either going to sleep, or restarting.

### How to use this template:
* Make sure all the prerequisites are installed
* Copy the setup_functions.ino to your sketch folder
* Copy - paste the contents of the Bare_minimim_WiFi_with_OTA.ino file to your main sketch
* Add your code to the relevant places in the sketch.
* Modify the sketch to your liking :-)


### Prerequisites:
* ESP8266 Arduino Core
* WiFiManager
* ArduinoOTA
* Ticker  - For Heartbeat LED
