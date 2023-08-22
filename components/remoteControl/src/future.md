I see. According to the product description1, your board uses an ILI9341 display controller and an XPT2046 touch controller. You can find the pinout diagram for your board on the product page1. You can also use the lvgl_esp32_drivers library2 to configure the display and touch drivers for LVGL. You can follow the instructions on the LVGL Arduino documentation3 to get started with LVGL on Arduino. I hope this helps.

ESP32 Arduino LVGL WIFI&Bluetooth Development Board 2.8" 240*320 Smart Display Screen 2.8inch LCD TFT Module With Touch WROOM pinout


MISO (GPIO19)
MOSI (GPIO23)
SCK (GPIO18)
CS (GPIO5)
DC (GPIO4)
RST (GPIO2)
T_CS (GPIO14)

The rest of the pins are available for other purposes. You can check the ESP32 pinout reference for more details on the functions of each pin.

: https://randomnerdtutorials.com/esp32-pinout-reference-gpios/


---------------

Shoud start basic esp32 to connect the joystic and two potensiometers.
avoid using the above specified and prefer using those used by the motor hub driver.



Probably use wifi initially an then use the proper we have.
Should first create 
- power
- how to connect joystic and

According to the web search results, you can use most of the ESP32 GPIO pins as inputs when using the WiFi, but there are some exceptions and caveats. Here are some points to consider:

The ESP32 has two ADC (Analog to Digital Converter) modules: ADC1 and ADC2. ADC1 has 8 channels (GPIO32 to GPIO39), and ADC2 has 10 channels (GPIO0, GPIO2, GPIO4, GPIO12 to GPIO15, and GPIO25 to GPIO27). However, ADC2 is also used by the WiFi driver, which means that you cannot use ADC2 pins as analog inputs when using the WiFi1.
Some pins have special functions or behaviors at boot time that may interfere with your project. For example, GPIO0, GPIO2, and GPIO15 are strapping pins that determine the boot mode of the chip. They must be pulled low or left floating to enter the flashing mode. If they are pulled high, the boot will fail1. Similarly, GPIO12 is also a strapping pin that controls the flash voltage. If it is pulled high at boot, it will set the internal flash voltage regulator to 1.8V instead of the default 3.3V1.
Some pins are connected to the integrated SPI flash memory and are not recommended to use as inputs or outputs. These are GPIO6 to GPIO111.
Some pins are used by default for serial communication or debugging. These are GPIO1 (TX0), GPIO3 (RX0), and GPIO9 (TX1)2. You can use them as inputs or outputs, but you may lose the serial monitor or debug output functionality.
Some pins output a PWM signal at boot time. These are GPIO5, GPIO14, and GPIO151. You can use them as inputs or outputs after boot, but you may need to avoid connecting devices that are sensitive to PWM signals.
To summarize, the best pins to use as inputs in ESP32 when using the WiFi are:

GPIO4, GPIO13, GPIO16, GPIO17, GPIO18, GPIO19, GPIO21, GPIO22, and GPIO23 as digital inputs.
GPIO32 to GPIO39 as analog inputs (ADC1).
The pins that you can use as inputs with caution are:

GPIO0, GPIO2, and GPIO15 as digital inputs (strapping pins).
GPIO12 as digital input (flash voltage control).
GPIO1, GPIO3, and GPIO9 as digital inputs (serial pins).
GPIO5, GPIO14, and GPIO15 as digital inputs (PWM output at boot).
The pins that you should avoid using as inputs are:

GPIO6 to GPIO11 (connected to SPI flash).
GPIO0, GPIO2, GPIO4, and GPIO25 to GPIO27 as analog inputs (ADC2).
I hope this helps you understand which pins you can use as inputs in ESP32 when using the WiFi. For more information and details about the ESP32 pinout and features, you can check out these web pages345. Have a nice day! 😊


confirming using 

    int potentiometerPins[4] = {39, 34, 35, 32};
    int togglePins[3] = {36, 33, 16};

  33 and 16 using digital read instead of analog and connected with 3,3v