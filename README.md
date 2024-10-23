## What is this?

Basically, im fed up with smart home devices and Arduino IoT custom builds that are on 2.4Ghz WiFi getting offline. The community that uses Ubiquiti in this manner all want to reach out to Ubiquiti to get this fixed up already.

A lot of prosumers are excited with using Ubiquiti ecosystem (I myself am a big fan) it is time for Ubiquiti to act on this. A lot of reddit posts, youtube "do not buy", and feedback directly on their release notes forum.

To Ubiquiti -- please do consider a product recall, right now. *This is embarassing.*

[mine](https://community.ui.com/releases/UniFi-Access-Point-7-0-66/edfb7cb4-c629-4e3b-a362-549eec2e0e1b#comment/0943066a-f70f-405e-b8e9-6cfb3f4e2ad7) 

[Ubiquiti's attempt fix, but pulled it out](https://community.ui.com/releases/UniFi-Access-Point-7-0-73/aa91657a-1df6-4fdb-813c-af9f603da5dc)

[Oct 22 attempt fix firmware 7.0.76](https://community.ui.com/releases/UniFi-Access-Point-7-0-76/75e6ab7f-a1f8-40d1-9cf2-be0ad75cb7ce)


#### UniFi APs in my environment
- 1x U7-Pro
- 1x U7-Pro-wall
- 2x U6 Pro

#### How many IoT devices?
while I perform this investigation, the ones active are 70+ devices on a 2.4Ghz SSID with *Enhanced IoT Connectivity Mode* Enabled, a good balance of these are homed on both U7-Pros and U6-Pros

These devices are a good mix of:
- Kasa smart light switches (HS210, KS200M), smart light dimmers (HS220, KS230, KS220M), smart plugs (HS103, KP303), light strip (KL400L5)
- Wiz bulbs (123140, 23011, 27281)
- Ring cameras and doorbell (non-Pro models)
- Samsung appliances
- Raspberry Pi Zero W
- Arduino boards ESP32 based and WiFiNina based

### Test Plan
1. Flash the Arduino code setting Core Debug Level (Debug) and CPU Frequency (80Ghz) on to an ESP32 board
2. Physically connect to a machine with serial monitor while being feet away from Access Point. Observe
3. Report output of serial monitor

#### Test devices and software
- an Espressif ESP32 board (mine is a SeeedStudio Xiao ESP32-C3)
- Arduino code (included in this repo) and arduino-esp32 board library
- U7-Pro (7.0.76)
- U7-Pro-Wall (7.0.76)
- U6-Pro (6.6.77 used to compare)
- UDM-Pro (UniFi OS 4.1.5)
- Network (8.6.3)

#### Test Plan A
- U7-Pro with firmware 7.0.76 and Enhanced IoT Connectivity Mode (Enabled)
- observe serial monitor while a few feet away from a U7-Pro

Result:

#### Test Plan B
- U7-Pro-wall with fimware 7.0.76 and Enhanced IoT Connectivity Mode (Enabled)
- observe serial monitor while a few feet away from a U7-Pro-Wall

Result: 

#### Test Plan C
- U6-Pro with firmware 6.6.77 and Enhanced IoT Connectivity Mode (Enabled)
- observe serial monitor while just a few feet away from a U6-Pro

Result: 

### Images

Simple Test results
[TestA - U7 Pro](results/esp32-to-u7pro.log)
[TestB - U7 Pro Wall](results/esp32-to-u7prowall.log)
[TestC - U6 Pro](results/esp32-to-u6pro.log)

Hardware
![board](images/esp32.JPG?raw=true "ESP32 board")
![prowall](images/pro-wall.JPG?raw=true "U7-Pro-Wall mounted")
