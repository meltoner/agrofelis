### Motors hub controller

This sub-module of the Motors Hub Driver integrates all components of the overall module.
The controller decomposes the functionality of processing the signals, of broadcasting the sensors impulses and for controlling the actuators via wireless means. The module digitally drives the two motor hubs via an ESP32 and read/intercepts the hall sensors of the analog drivers using the ADAC module. The module senses the current drawn by the motors, reads the individual temperature of the analog drivers and controls the power and spin direction of the motors.

The module establishes the means of individual and synchronized motion of motors. Moreover, the module meets the micro-controlling mechanisms necessary in precision farming and the safety mechanisms for protecting dynamically the various components of the system, based on excessive current or temperature sensed to alert and cut off the power.

The Motors Hub controller is composed of the following components :

1. A PCB board, with its schematics located within PCB.CNC.controller\ folder.
2. The PCB top side printed cover located within PCB.PRINT.Stickers.
3. One ESP32 with 38 pins. 
4. Two twenty pin female headers.
5. One two pin female header.
6. One four pin female header.
7. One 2 pin JST male connector for the 5v supply.
8. One 3 pin JST male and female connector used to connect two temperature sensors via the one wire protocol.
9. Two Green 5 mm Screw terminal PCB Connector, one for the speed link of both motors and one for the 12v input.
10. Two five wire ribbon cable 7 cm, used to connect the power modules.
11. Two five ping female headers used to connect the power modules at the end of ribbon cable.
12. One three wire ribbon cable 7 cm, used to connect the temperature sensors.
13. Two temperature sensors DS18B20 connected via one wire.
14. Pieces of wire for the implementing the PCB bridges as indicated by the yellow color in the PCB.PRINT.Stickers schematic.
15. A case cooler 8 cm LogiLink FAN101 at 12V
16. Two Agrofelis Motor Hub Power Drivers and the Agrofelis Motors hub ADAC module. 
17. Non mandatory connectors, two 2 pin terminal, high current red an black wire, male and female connectors to power the analog motor drivers with.
18. Glue gun to secure the copper side of the pcb from extrernal factors applied after its function has been verified.
19. The software https://github.com/meltoner/agrofelis/tree/main/components/mobility/motors_hub_driver/src/DualMotorDriver

Remarks :

- One pin is trimmed off the twenty pin female headers.
- The temperature sensor male headers are removed and connected with the 3 wire ribbon cable, to keep a lower profile.

Document location : /agrofelis/components/mobility/motors_hub_driver/pcb/controller.md