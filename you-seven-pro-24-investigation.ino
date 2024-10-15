// SoC: ESP32-C3
// Board: XIAO_ESP32_C3

// Arduino Board Library (w/c comes with its Network lib) https://github.com/espressif/arduino-esp32/blob/master/libraries/WiFi/src/WiFi.h

#include <WiFi.h>

#define WIFI_SSID                   "myiotSSID"
#define WIFI_PASS                   "Password123"
#define DELAY_RETRY_MS              5000              // delay 5 seconds before trying again
#define DELAY_LOOP_MS               60000             // check WiFi status every 1 min

void connectWifi() {
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(DELAY_RETRY_MS);
    Serial.println("INFO: WiFi connecting.");
  }

  Serial.print("INFO: IP address: ");
  Serial.print(WiFi.localIP());
  Serial.print("\tMAC: ");
  Serial.println(WiFi.macAddress());
}

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(100);
  }
  Serial.println("INFO: First WiFI connect at setup.");
  connectWifi();
}


void loop() {
  if  (WiFi.status() != WL_CONNECTED) {
    Serial.println("INFO: WiFI disconnected. Now retrying...");
    connectWifi();
  }

  Serial.println(".");
  sleep(DELAY_LOOP_MS);
}
