### Motors hub ADAC

This sub-module of the Motors Hub Driver allows to interface 5v sensors with ESP32, operating at 3.3v.
By doing so, it expands the number of channels the ESP32 can handle. Using this submodule the two current sensors and the six hall sensors of the two motors can be interfaced.

The Motors Hub controller is composed of the following components :

1. A PCB board, with its schematics located within PCB.CNC.adac\ folder.
2. The PCB top side printed cover located within PCB.PRINT.Stickers.
3. One MCP3008 8-channel 10 bit ADC
4. One 4-channel I2C-safe Bi-directional Logic Level Converter between 5V and 3.3V.
5. One Seven pin ribbon cable for connecting with the ADAC module.
6. One four pin male header
7. One six pin female header
8. Two one wire cable of 7 cm connecting the ADAC with the current sensors of the Agrogelis Motor Power driver.

Remarks 

- The first and second channel of the MPC3004 Adac are connected to the current sensors of the power module.
- The remaining channels of the ADAC are connected to the hall sensors of the motor. the 3d to fifth channels follow the yellow, green, blue connection and so on.
- The ground of the halls sensors is connected to the ground of the Motors hub ADAC module.
