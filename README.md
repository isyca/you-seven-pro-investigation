## What is this?

 basically, im fed up with smart home devices getting offline and I want to reach out to Ubiquiti -- to get this fixed up already.

a lot of prosumers are excited with Ubiquiti ecosystem (I myself is a big fan) it's time for you guys to act on this.

I know there are workarounds of just having 2.4Ghz for IoT SSID -- but that's not acceptable. aAlot of reddit posts, youtube "do not buy", and feedback directly on your AP firmware release notes
[mine](https://community.ui.com/releases/UniFi-Access-Point-7-0-66/edfb7cb4-c629-4e3b-a362-549eec2e0e1b#comment/0943066a-f70f-405e-b8e9-6cfb3f4e2ad7) 

-- please do consider a product recall, right now. *This is embarassing.*

#### UniFi APs in my environment
- 1x U7-Pro
- 1x U7-Pro-wall
- 2x U6 Pro

#### How many IoT devices?
while I perform this investigation, the ones active are:
- 69 devices at 2.4Ghz
- 20 devices at 5Ghz
a good balance of these are homed balanced on both U7Pros and U6Pros

### Test Plan
1. flash an Arduino to an ESP32 board
2. physically connect to an observation laptop
3. observe using serial monitor
4. detach from serial monitor (effectively disconnecting power)
5. let it be for ~10 seconds
6. then reconnect, effectively viewing it again on serial monitior
7. repeat at least 5 times even if it connects or not

#### Test devices and software
- an Espressif ESP32 board (mine is a SeeedStudio Xiao ESP32-C3)
- Arduino code (included in this repo) and uploaded to board
- U7-Pro
- U7-Pro-Wall
- U6-Pro

#### Test Plan A
- U7-Pro on firmware 7.0.66
- observe serial monitor while a few feet away from a U7-Pro
Result: got connected *3x out of 5 times*

#### Test Plan B
- U7-Pro-wall downgraded to fimware 7.0.56
- observe serial monitor while a few feet away from a U7-Pro-Wall
Result: got connected *1x out of 5 times*

#### Test Plan C
- U6-Pro with (latest) firmware 6.6.77
- observe serial monitor while just a few feet away from a U6-Pro
Result: connected immedidately and consistently, *5 out of 5 times*

### Images
![TestA](images/test-case-A.png?raw=true "U7 Pro test")
![TestB](images/test-case-B.png?raw=true "U7 Pro-Wall test")
![TestC](images/test-case-C.png?raw=true "U6 Pro test")
![board](images/esp32.JPG?raw=true "ESP32 board")
![prowall](images/pro-wall.JPG?raw=true "U7-Pro-Wall mounted")
