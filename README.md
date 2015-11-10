# photon-at86rf233
A basic driver that allows ATMEL's AT86RF233 radio to be used with the Photon or Electron.

[firmware/examples/photon-at86rf233.ino](https://github.com/msolters/photon-at86rf233/blob/master/firmware/examples/photon-at86rf233.ino) demonstrates the simplest example application -- a Photon application that scans for nearby 802.15.4 traffic and prints incoming frames over serial (115200 baud).

## Radio Hardware
Designed to be used with ATMEL's AT86RF233 802.15.4 radio, [available as a $30USB radio extension board (REB)](http://www.mouser.com/ProductDetail/Atmel/ATREB233-XPRO/?qs=HVbQlW5zcXX%2FEgqNxRIBfA%3D%3D).

![](http://media.digikey.com/Photos/Atmel%20Photos/ATREB233-XPRO.JPG)

## Connect the AT86RF233 to the Photon
You are free to use any MCU with a sufficient clock speed, and at least:

*  1 SPI bus
*  VCC (3.3V) & GND
*  3 GPIO ouput
*  1 interruptible GPIO input

Here's the wiring setup.  You may find the Photon pinout reference helpful (included below).

Purpose | AT86RF233 (REB X-Pro Extension Header) | Photon
---|---|---
Reset | 7 | D6
Interrupt | 9 | D2
Sleep | 10 | D5
Slave Select | 15 | D0
MOSI | 16 | A5
MISO | 17 | A4
SCK | 18 | A3
Ground | 19 | GND
Power | 20 | 3V3

![](https://community.particle.io/uploads/default/original/6/3/6304cd3d83d1fbd30ccc262215569161de58bd34.png)

## Driver Configuration
Without further configuration, this library will use the default AT86RF2xx parameters contained in `at86rf2xx-defaults.h`.  Most radio parameters can be updated manually by using the set/getters enumerated in `at86rf2xx-getset.c`.  For example, to change the radio channel to `25`, simply call `set_chan(25)` on the at86rf2xx device after initialization:

```cpp
  at86rf2xx.init(SEL, IRQ, SLP_TR, RESET);
  at86rf2xx.set_chan(25); // set channel to 25
```
