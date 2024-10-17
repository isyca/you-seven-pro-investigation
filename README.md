## What is this?

basically, im fed up with smart home devices that are on 2.4Ghz getting offline and we all want to reach out to Ubiquiti -- to get this fixed up already.

a lot of prosumers are excited with Ubiquiti ecosystem (I myself am a big fan) it is time for Ubiquiti to act on this. A lot of reddit posts, youtube "do not buy", and feedback directly on your AP firmware release notes forum

[mine](https://community.ui.com/releases/UniFi-Access-Point-7-0-66/edfb7cb4-c629-4e3b-a362-549eec2e0e1b#comment/0943066a-f70f-405e-b8e9-6cfb3f4e2ad7) 


[Ubiquiti's attempt but pulled it out](https://community.ui.com/releases/UniFi-Access-Point-7-0-73/aa91657a-1df6-4fdb-813c-af9f603da5dc)

-- please do consider a product recall, right now. *This is embarassing.*

#### UniFi APs in my environment
- 1x U7-Pro
- 1x U7-Pro-wall
- 2x U6 Pro

#### How many IoT devices?
while I perform this investigation, the ones active are:
- 60+ devices at 2.4Ghz
- 20 or so devices at 5Ghz
a good balance of these are homed balanced on both U7Pros and U6Pros

### Test Plan
1. flash the Arduino code (setting Core Debug Level to Debug) on to an ESP32 board
2. physically connect to a machine with serial monitor, then observe
3. detach from serial monitor (effectively disconnecting power)
4. let it be for ~10 seconds
5. then reconnect, effectively viewing it again on serial monitior
6. repeat at least 5 times regardless if it connects or not

#### Test devices and software
- an Espressif ESP32 board (mine is a SeeedStudio Xiao ESP32-C3)
- Arduino code (included in this repo) and uploaded to board
- arduino-esp32 board library
- U7-Pro
- U7-Pro-Wall
- U6-Pro (used to compare)

#### Test Plan A
- U7-Pro on firmware 7.0.66
- observe serial monitor while a few feet away from a U7-Pro

Result: got connected *three out of 5 times*

#### Test Plan B
- U7-Pro-wall downgraded to fimware 7.0.56
- observe serial monitor while a few feet away from a U7-Pro-Wall

Result: got connected *one out of 5 times*

#### Test Plan C
- U6-Pro with (latest) firmware 6.6.77
- observe serial monitor while just a few feet away from a U6-Pro

Result: connected immedidately and consistently, *five out of 5 times*

### Images

Simple Test results
![TestA](images/test-case-A.png?raw=true "U7 Pro test")
![TestB](images/test-case-B.png?raw=true "U7 Pro-Wall test")
![TestC](images/test-case-C.png?raw=true "U6 Pro test")

Hardware
![board](images/esp32.JPG?raw=true "ESP32 board")
![prowall](images/pro-wall.JPG?raw=true "U7-Pro-Wall mounted")
