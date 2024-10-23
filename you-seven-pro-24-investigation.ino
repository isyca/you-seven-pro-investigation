// SoC: ESP32-C3
// Board: XIAO_ESP32_C3

// https://github.com/espressif/arduino-esp32/blob/master/libraries/WiFi/src/WiFi.h
#include <WiFi.h>
// https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/log.html
#include <esp_log.h>

#define LOG_LOCAL_LEVEL             ESP_LOG_VERBOSE
#define ARDUHAL_LOG_LEVEL           ARDUHAL_LOG_LEVEL_VERBOSE

#define WIFI_SSID                   "myiotSSID"       // not my SSID
#define WIFI_PASS                   "Password123"     // not my password
#define DELAY_RETRY_MS              10000             // delay 10 seconds before trying again
#define DELAY_LOOP_MS               30000             // restart every 30-seconds

static const char* TAG = "you-seven-pro-24-investigation";

void connectWifi() {
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  delay(DELAY_RETRY_MS);

  while (WiFi.status() != WL_CONNECTED) {
    WiFi.reconnect();
    delay(DELAY_RETRY_MS);
    ESP_LOGI(TAG, "WiFi connecting.");
  }

  ESP_LOGI(TAG, "Wifi Connected");
}

void setup() {
  ESP_LOGI(TAG, "First WiFI connect at setup.");
  connectWifi();
}


void loop() {
  ESP_LOGW(TAG, "WiFi Connected. Board paused, awaiting restart.");
  delay(DELAY_LOOP_MS);
  ESP.restart();
}