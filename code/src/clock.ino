// https://github.com/adafruit/Adafruit_NeoPixel
// Platformio lib number 28
#include <Adafruit_NeoPixel.h>

// https://github.com/PaulStoffregen/Time
// Platformio lib number 28
#include <TimeLib.h>

// https://github.com/esp8266/arduino
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiUdp.h>

// To avoid uploading my wifi password to github they are defeined in
// a separate file which is excluded form git in .gitignore
// If you wish you can comment out the #include and uncomment the lines below
#include "credentials.h"
//#define SSID "your SSID"
//#define PASSWD "your wifi password"

// Define the parameters for the neopixels
#define NEO_PIN 13
#define NEO_NUMPIXELS 13

// Create the Neopixel object
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NEO_NUMPIXELS, NEO_PIN, NEO_GRB + NEO_KHZ800);

// Create the wifi object
ESP8266WiFiMulti wifi;

void walk(uint32_t c, uint8_t wait){
  for(int i=0; i < strip.numPixels(); i++){
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
    strip.setPixelColor(i, 0);
  }
}
void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  wifi.addAP(SSID, PASSWD);
  walk(strip.Color(255,0,0), 200);
}

void loop() {
  if(wifi.run() == WL_CONNECTED){
    walk(strip.Color(0,255,0), 200);
  } else {
    walk(strip.Color(255,255,0), 200);
  }
}
