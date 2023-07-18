## Motors Hub Driver

The Agrofelis Motors Hub Driver module purpose is to digitally control over the air, a pair of motors via two drivers, to monitor their thermal, current and positional indicators as well as to guide the air flow cooling the electronic components, to actuate their power, speed and direction. The module is composed by structural elements, PCB boards separating the different functionalities into simpler standalone sub modules and the software running on the micro controller. 

Two such modules are employed in the Agrofelis robot, to achieve four wheel drive and precision control. The following figure illustrates the schematics of the overall module.

![motors_hub_driver](_figures/motors_hub_driver_1.png)

Find below is a photo of the implemented module positioned within the front and the back part of the vehicle.

![motors_hub_driver](_figures/motors_hub_driver_1_real.jpg)


In the following sections the structural and electronics sub-component of the module are documented.


### Structural

This component of the Agrofelis Motors hub driver, deals with the structural elements of the composite module.
The structural component is formed by two parts enclosing and mounting the related sub elements. Moreover the structural component  serves for guiding the air flow efficiently to 
cool down the electronics during their operation. The structure body, is composed of layers of ply-wood and 3d printed air fins, glued and painted.

The individual elements forming the structural body is illustrated by the following figure.

![motors_hub_driver_2.png](_figures/motors_hub_driver_2.png)

The top part of the structural body, creates sockets to host two temperature sensors, sockets to host the two power modules vertically, sockets to attach the analog drivers, as well as holes indicating exactly where the PCB boards are mounted and a socket for an 80mm fan.

The following photos showcase the top and bottom parts of the structure, manufactured using a low end CNC, equipped with with laser.

![motors_hub_structure_laser](_figures/structure_laser.jpg)

![motors_hub_structure_body_bottom.jpg](_figures/structure_body_bottom.jpg)
![motors_hub_structure_body_top.jpg](_figures/structure_body_top.jpg)

The 3d printed air fins glued on the bottom part of the structure are illustrated below.

![motors_hub_structure_fins_1.jpg)](_figures/structure_fins_1.jpg)

The bottom and top part, and how these fit together using the motor drivers as building blocks, is captured by the following photo.

![motors_hub_structure_fins_2.jpg](_figures/structure_fins_2.jpg)

The Motors Hub structure sub-module, is implemented using of the following parts in detail :

1. Five 4 mm ply-wood layers cut using a laser cutter into 204.83 mm X 119.67 mm parts. The layers 1-3 layers form the bottom part and the remaining the top part. 
2. Four 3d printed elements guiding the air flow across the sides of the analog motor drivers as well providing extra support to the top layer.
3. Wood glue
4. A spray paint
5. Capton tape to secure the temperature sensors in the top wood layer slot.
6. Eight Standoff, Bolts and screws 2m to mount the controller and ADAC into the wooden layer
7. Two 2.8mm X 16mm screws securing the top layer with the outer fins.

The schematics and source files to cut and 3d print the parts 1. and 2. are located within the following folders respectively.

- structural\box_wood_layers\laser_cut
- structural\box_fins\3d_print

More specifically the laser cut folder, documents the procedure for exporting and transforming the Rhino diagrams into five SVG files and consequently to five NC instructions used to cut the related parts. The 3d print folder contains two stl files and two gcode instruction files for the inner and outer fins structural elements.


### Electronics

The electronics sub modules of the Agrofelis Motors hub driver sum into four PCB sub-modules, namely the :

1. Motors hub controller module.
2. Motors hub power module (A).
3. Motors hub power module (B).
4. Motors hub ADAC module.

Their compilation is illustrated by the following diagram.

![motors_hub_driver_3.png](_figures/motors_hub_driver_3.png)

In the following sections the three type of modules are documented in further detail.

### Motors hub controller

This sub-module of the Motors Hub Driver integrates all components of the overall module. The controller decomposes the functionality of processing the signals, of broadcasting the sensors impulses and for controlling the actuators via wireless means. The module digitally drives the two motor hubs via an ESP32 and reads and intercepts the hall sensors of the analog drivers using the ADAC module. The module senses the current drawn by the motors, reads the individual temperature of the analog drivers and controls the power and spin direction of the motors. It consists of the following components:
 
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

 