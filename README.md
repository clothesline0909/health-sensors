## Example Summary

Sample application to read temperature value from a TMP007 I2C temperature
sensor.

## Peripherals Exercised

* `Board_GPIO_LED0` - Indicator LED
* `Board_I2C_TMP` - I2C used to communicate with TMP007 sensor.
* The Sensors Boosterpack (http://www.ti.com/tool/boostxl-sensors) was used. It has
the TMP007 sensor along with several other nifty sensors.

## Resources & Jumper Settings

> If you're using an IDE (such as CCS or IAR), please refer to Board.html in your project
directory for resources used and board-specific jumper settings. Otherwise, you can find
Board.html in the directory &lt;SDK_INSTALL_DIR&gt;/source/ti/boards/&lt;BOARD&gt;.
Depending on your board, there will either be an onboard TMP007 sensor, or you will need
the Sensors Boosterpack.

## Example Usage

* Run the example. `Board_GPIO_LED0` turns ON to indicate driver
initialization is complete.

* The example will request temperature samples from the TMP007 and print them on
the console. A total of 20 temperature samples are read/printed before the
example exits. Console output should resemble:
```
        I2C Initialized!
        Sample 0: 24 (C)
        Sample 1: 24 (C)
        Sample 2: 24 (C)
        Sample 3: 24 (C)
```

## Application Design Details

This application uses one tasks:

`'getTempTask'` - performs the following actions:

1. Opens and initializes an I2C driver object.

2. Uses the I2C driver to get data from the TMP007 sensor.

3. Extracts the temperature (in Celsius) and prints the value on the console.

4. The task sleeps for 1000 system ticks.

5. After 20 temperature samples are recovered, the I2C peripheral is closed
and the example exits.

TI-RTOS:

* When building in Code Composer Studio, the kernel configuration project will be imported along with the example. The kernel configuration project is referenced by the example, so it will be built first. The "release" kernel configuration is the default project used. It has many debug features disabled. These feature include assert checking, logging and runtime stack checks. For a detailed difference between the "release" and "debug" kernel configurations and how to switch between them, please refer to the SimpleLink MCU SDK User's Guide. The "release" and "debug" kernel configuration projects can be found under &lt;SDK_INSTALL_DIR&gt;/kernel/tirtos/builds/&lt;BOARD&gt;/(release|debug)/(ccs|gcc).

FreeRTOS:

* Please view the `FreeRTOSConfig.h` header file for example configuration
information.
