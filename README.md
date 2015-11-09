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
Without further configuration, this library will use the default AT86RF2xx parameters contained in `at86rf2xx_defaults.h`.  These defaults can be overridden inside `at86rf2xx_config.h`.  For example, to change the radio channel to `25`, you could use the following `at86rf2xx_config.h`:

```c
#define AT86RF2XX_CHANNEL               25  //AT86RF2XX_DEFAULT_CHANNEL
#define AT86RF2XX_TXPOWER               AT86RF2XX_DEFAULT_TXPOWER
#define AT86RF2XX_ADDR_LONG             AT86RF2XX_DEFAULT_ADDR_LONG
#define AT86RF2XX_ADDR_SHORT            AT86RF2XX_DEFAULT_ADDR_SHORT
#define AT86RF2XX_PANID                 AT86RF2XX_DEFAULT_PANID
```

Most radio parameters can also be modified after the fact using the set/getters enumerated in `at86rf2xx_getset.c`.
