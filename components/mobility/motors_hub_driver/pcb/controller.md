This sub-module of the Motors Hub Driver integrates all components of the overall module.
The controller decomposes the functionality of processing the signals, of broadcasting the sensors impulses and for controlling the actuators via wireless means. The module digitally drives the two motor hubs via an ESP32 and read/intercepts the hall sensors of the analog drivers using the Adac module. The module senses the current drawn by the motors, reads the individual temperature of the analog drivers and controls the power and spin direction of the motors.

The module establishes the means of individual and synchronized motion of motors. Moreover, the module meets the micro-controlling mechanisms necessary in precision farming and the safety mechanisms for protecting dynamically the various components of the system, based on excessive current or temperature sensed to alert and cut off the power.

The Motors Hub controller is composed of the following components :

1. A PCB board, with its schematics located within PCB.CNC.controller\ folder.
2. The PCB top side printed cover located within PCB.PRINT.Stickers.
3. One ESP32 with 38 pins. 
4. Two twenty pin female headers
5. One two pin female header
6. One four pin female header
7. One 2pin JST male connector for the 5v supply
8. One 3pin JST male connector used to connect two temperature sensors via the one wire protocol
9. Two Green 5mm Screw terminal PCB Connector, one for the speed link of both motors and one for the 12v input.
10. Two five wire ribbon cable 7 cm, used to connect the power modules.
11. One three wire ribbon cable 7 cm, used to connect the temperature sensors.
12. One Seven pin ribbon cable for connecting with the ADAC module.
13. Two temperature sensors DS18B20 connected via one wire.
14. Pieces of wire for the implementing the PCB bridges as indicated by the yellow color in the PCB.PRINT.Stickers schematic.
15. Two Agrofelis Motors Hub Power Drivers and an ADAC module. 

Remarks 

- One pin is trimmed off the twenty pin female headers.

/agrofelis/components/mobility/motors_hub_driver/pcb/controller.md