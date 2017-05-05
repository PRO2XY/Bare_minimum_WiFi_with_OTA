#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino

// For WiFiManager
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager

// For ArduinoOTA
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
uint8_t OTAProgressIndicator;

// For heartbeat LED
#include <Ticker.h>
Ticker heartbeat_Tick;

#define LEDPIN  2   // LED pin to show heartbeat on; 2 is internal on ESP-12

void setup() {
  Serial.begin(115200);
  Serial.println("Booting");

  pinMode(LEDPIN, OUTPUT);
  heartbeat_Tick.attach(0.5, heartbeat);
  
  setup_wifi(); // in setup_functions tab
  setup_OTA();

  // Do the rest of setup work here
  // ...


  // Setup done. Turn off heartbeat LED (change this to suit your application)
  heartbeat_Tick.detach();
  digitalWrite(LEDPIN, HIGH);


}

void loop() {
  ArduinoOTA.handle();
  
  // Rest of loop code goes here
  // ...
}
