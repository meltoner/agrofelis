# Agrofelis remote controller design and fabrication

# Abstract

The document, presents the details of fabricating a basic remote controller for actuating the wheels, the steering, the breaks and the power of the Agrofelis Robot. Accounting for ergonomics, low cost and readily available components a simple extendable design is presented, rapidly prototyping the minimum number of sensors and components needed for booting and controlling the mobility functions of the vehicle. The module is decomposed to its  using design plans encoded with crucial metrics and is recompiled using photos taken during the fabrication process. The software source code running on the remote micro-controller is presented following approaches implemented in other Agrofelis modules. The document concludes with a list of the components used and assorted with indicative suppliers, aiding in the replication of the module.

# Introduction

The scope of this module was to implement a minimum viable remote controller of the Agrofelis Robot. Serving its purpose to conduct the first round of on the field testings, the module acts as a baseline remote controller, that can be extended with additional modules such as a TFT monitor, additional sensors and interface indicators. The following photo depicts the remote controller operating the Agrofelis Robot in a vineyard. 

![Remote control and vehicle](_figures/remote-control-00-view-using.jpg)

In the following sections the Agrofelis Robot basic remote controller prototype, is documented.

## Agrofelis Remote Controller

The Remote controller is composed of a reversed drawer like structure, about the size of usual person chest span promoting a more comfortable user experience. Moreover, the holding sides of the structure fit conveniently within the palm of the user offering a firm grip to the module. The controller's input sensors are arranged within thumb distance allowing to easily access and engage the controls, while on holding the module. The controller employs an ESP32, a battery, a step down converter, a joystick with an embedded switch, two potentiometers, two switches, arranged in the sides of wooden structure. 

Although controllers used in game engines are often employed in such projects, prototyping from the ground up leads to important know how enabling to consequently extend the modules accordingly, based the acquainted experience. The implementation reuses established patterns and practices employed in the Agrogelis Motors Hub Driver and Front Sensors Lidar modules, testing even further the decisions leading to more robust software. The key difference between other Agrofelis modules and the remote controller, is that the latter is composed of control sensors only. 

The controller detects momentary button presses, prolonged presses, combinations of presses. Moreover, the controller quantizes the sensors outputs range suppressing noise or accidental movements. The software listens for changes in the joystick's internal potentiometers, mapping the forward and backward movement with its y axis while the steering with the x axis. The controller uses an indirect way to control the speed based on how much time the stick is lifted or is left at rest. The controller fades-in the y axis input values slower when actuated and fades-out them faster when un-engaged. The first potentiometer limits the speed signal sent to the robot via the joystic vehicle. The second potentiometer controls the maximum degree sent to the disk brakes controlling how hard or soft they will be actuated. The first switch powers up or down the Agrofelis robot mobility system when its pressed prolonged. The second switch actuates the brakes. The joystick's button when pressed prolonged switched on or off, the maximum steering radius of the vehicle.

The software features developed implement a smooth start and a fast slow down control of the vehicle promoting safer maneuverability of the module. The speed of the vehicle limits can be set to four speed states ranging from zero to the maximum programmed. Likewise when on an slope or not the brakes can be adapted to consume less energy. The remote controller was programmed and adapted on the field, in order to optimise its responsiveness such that the corresponding vehicle movements are smooth, safe as well as forgiving. 

The following diagram depicts the Remote controller module.

![Module schematics](_figures/remote-control-01-module-schematics.png)

The module component are enumerated by the consequent schematic.

![Module exploded view](_figures/remote-control-02-module-exploded.png)

The figure indexes the following components composing the remote controller module :

1. ESP32 38 pin on an ESP32 terminal adapter
2. 5v Step down converter
3. Wooden structure
4. Two Limit switches
5. Two 10k metallic potentiometers 
6. Cartesian Joystick with press down switch
7. Battery

### Structure

To prototype the body of the remote controller the module utilised pieces of wood due to their lightweight density and because they can be easily drilled and machined. The structure is composed of four pieces of wood glued together to form a solid structure all components are attached to.
Although the body and finishing is not the envisaged end look and feel of the remote controller, the rapid prototype implement confirmed the module's approximate size, the components arrangement, their connectivity and establishing a functional remote controller.

The following diagram encodes the dimensions of the wooden pieces assembling the structure of the module. 

![Structure schematics](_figures/remote-control-03-structure-schematics.png)

The figure moreover encodes on the top left side of the diagram two holes to pass the potentiometer cables and three smaller holes matching the pins of the limit switches layout. Another two holes can be seen in center of the top side, used to secure the battery of the remote controller using a strap. The following photo, shows the fabricated structure underside hosting the ESP32 terminal adapter attached using two screws. 

![Structure actual](_figures/remote-control-04-frame.jpg)

The subsequent photo depicts the top side of the structure hosting the joystick, the battery positioned in the top middle, above the ESP32 terminal adapter pinned on the underside of the structure.

![Structure battery and joystick](_figures/remote-control-05-frame-battery-joystic.jpg)

The following photo provides a side view of the module, at the same fabrication step as of the previous figure.

![Module side](_figures/remote-control-06-side.jpg)

The consequent photo, focuses on the left side of the remote controller where two limit switches and two potentiometers have been attached using hot glue. The cables of the input sensors pass through the structure, on the electronics side, using holes made following the layout of the components. The four input sensors, connect with the ESP32 GPIO using a four pin and a two pin ribbon cable, used for their signals pins as well as for powering them. 

![Switches and potentiometers](_figures/remote-control-07-switch-potetiometer.jpg)

The fabricated remote controller is shown via the following photograph.

![Top side view of module](_figures/remote-control-08-top-side-sensors.jpg)

The side view of the fabricated module, is attached next.

![Side view of module](_figures/remote-control-09-side.jpg)


### Electronics

The following photo snapshots the underside of the module, its electronics and their connections.

![Underside view of electronics](_figures/remote-control-10-under-electronics.jpg)

The consequent photograph focuses the left underside of the controller where the limit switches and the potentiometer are linked with the ESP32. 
All sensors input pin are connected with the 3.3v output of the controller, their output pins connected to the digital or analogue respective ESP32 ports and the potentiometer are additionally linked with the ground.

![Under left side view of electronics](_figures/remote-control-11-imder-left-side.jpg)

The following image depicts the right underside of the structure where the 5v step down converter and the right side of the ESP32 terminal pin connections can be seen.

![Under right side view of electronics](_figures/remote-control-12-uner-right-side.jpg)

The Joystick x and y sensors are connected to 34 and 39 GPIO ports, while its tactile switch on port 36. The left side potentiometers are connected to ports 35 and 32. Last the two limit switches are linked with ports 16 and 33. 


## Software

## Components

# Conclusion

![Remote control being held](_figures/remote-control-13-held.jpg)

