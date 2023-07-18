
### Structural

This component of the Agrofelis Motors hub driver, deals with the structural elements of the composite module.
The structural component is formed by two parts enclosing and mounting the related sub elements. Moreover the structural component  serves for guiding the air flow efficiently to 
cool down the electronics during their operation. The structure body, is composed of layers of ply-wood and 3d printed air fins, glued and painted.


The top part of the structural body, creates sockets to host two temperature sensors, sockets to host the two power modules vertically, sockets to attach the analog drivers, as well as holes indicating exactly where the PCB boards are mounted and a socket for an 80mm fan.

Bellow find photos showcasing the top and bottom parts of the structure, manufactured using a low end CNC, equipped with with laser.

![motors_hub_structure_laser](_figures/structure_laser.jpg)

![motors_hub_structure_body_bottom.jpg](_figures/structure_body_bottom.jpg)
![motors_hub_structure_body_top.jpg](_figures/structure_body_top.jpg)

The 3d printed air fins glued on the bottom part of the structure and how the part fit together using the motor drivers as building blocks are captured by the following photos.

![motors_hub_structure_fins_1.jpg)](_figures/structure_fins_1.jpg)
![motors_hub_structure_fins_2.jpg](_figures/structure_fins_2.jpg)

The Motors Hub structure sub-module, is implemented using of the following components :

1. Five 4 mm ply-wood layers cut using a laser cutter. The layers are glued together forming the bottom part using the 1-3 layers and the top part using the layers 4 and 5. 
2. Four 3d printed elements guiding the air flow across the sides of the analog motor drivers as well providing extra support to the top layer.
3. Wood glue
4. A spray paint 
5. Capton tape to secure the temperature sensors in the top wood layer slot.
6. Eight Standoff, Bolts and screws 2m to mount the controller and ADAC into the wooden layer
7. Two 2.8mm X 16mm screws securing the top layer with the outer fins.

The schematics and source files to cut and 3d print the parts 1. and 2. are located within the following folders respectively.

- structural\box_wood_layers\laser_cut
- structural\box_fins\3d_print
