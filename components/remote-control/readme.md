# Agrofelis remote controller design and fabrication

# Abstract

The document, presents the details of fabricating a baseline remote controller for actuating the wheels, the steering, the breaks and the power of the Agrofelis Robot. Accounting for ergonomics, low cost and readily available components a simple extendable design is presented, rapidly prototyping the minimum number of sensors and components needed for booting and controlling the mobility functions of the vehicle. The module is de-compiled using design plans annotated with crucial metrics and is re-compiled using photos taken during the fabrication process. The software source code running on the micro-controller is presented following alike approaches implemented in other Agrofelis modules. The document concludes with a list of components used and assorted with indicative suppliers, aiding in the replication of the module.

# Introduction

The scope of this module was to implement a minimum viable remote controller for the Agrofelis Robot. Fulfilling its purpose to conduct the first round of on the field testings, the module acts as a baseline remote controller, that can be extended with additional modules such as a TFT monitor, additional sensors and or / range extenders. The following photo depicts the remote controller and the Agrofelis Robot being operated in a vineyard. 

![Remote control and vehicle](_figures/remote-control-00-view-using.jpg)

In the following sections the Agrofelis Robot remote controller prototype, is documented.

## Agrofelis Remote Controller

Although the Agrofelis unificator software combining all Agrofelis modules stream of data with its corresponding web application, allows the system to be controlled through regular mobile phones and computers, the need to have a dedicated physical interface operated with your hands, offers a more natural and robust interface. A dedicated physical module moreover bypasses problems when compared with mobile phones, which are prone to program interruption in case someone calls, or need to have bare and clean hands, pose the necessity to look at the RC module instead of the vehicle, or their usability is influenced by the ambient luminosity levels of the environment. 

The Remote controller designed and implemented is composed of a reversed drawer like structure, about the size of a usual person's chest span offering a more comfortable user experience. Moreover, the holding sides of the structure fit conveniently within the palm of the user providing a firm grip of the module. The controller's input sensors are located within thumb distance enabling to easily reach and engage the input controls. The controller employs an ESP32, a battery, a 5v step down converter, a joystick with an embedded switch, two potentiometers, two switches, attached on the sides of wooden structure. 

Although controllers found in game engines are often employed in such projects, this choice eventually limits the flexibility one can have. Moreover, prototyping from the ground up builds know how enabling to consequently extend the baseline modules based on the acquainted experience. The implementation reuses established patterns and practices employed in the Agrogelis Motors Hub Driver and Front Sensors Lidar modules, testing further the decisions made which leads to more robust software. The key difference between other Agrofelis modules and the baseline remote controller, is that the latter is composed of input sensors, only.

The controller detects momentary button presses, prolonged presses, combinations of presses. Moreover, the controller quantizes the sensors signal ranges suppressing noise or accidental movements. The software listens for changes in the joystick's internal potentiometers, mapping the forward and backward movement with its y axis input sensor and the steering with its X axis. 

The controller uses an indirect way to control the speed based on the amount of time a sensor is excited or is at rest. The controller fades-in the y axis input values slower when actuated (acceleration) and fades-out them faster when un-engaged (deceleration). The first potentiometer located on the left side, limits the speed signal sent to the robot via the joystick. The second potentiometer controls the maximum rotation degree sent to the disk brakes servos, controlling how hard or soft they will be actuated. The first switch powers up or down the Agrofelis robot mobility system, when its pressed for a prolonged time. The second switch actuates the brakes based on the aforementioned second potentiometer signal. The joystick's button when pressed for a prolonged time, switches on or off the maximum or regular steering radius of the vehicle.

The software features developed implement a smooth acceleration and a fast deceleration control of the vehicle enabling the safe maneuverability of the module. The speed of the vehicle can be set to four speed states ranging from zero to the maximum programmed. Likewise when on an slope or not the brakes can be adapted to consume less energy when actuated. The remote controller was programmed and adapted on the field, in order to optimise its responsiveness such that the corresponding vehicle movements were smooth, safe and forgiving by providing sufficient time to the user to observe the outcomes of their movements. 

The following diagram depicts the remote controller module, encoding moreover distances of the component from the outer rim of the controller's body.

![Module schematics](_figures/remote-control-01-module-schematics.png)

The module's components are enumerated by the consequent exploded view schematic.

![Module exploded view](_figures/remote-control-02-module-exploded.png)

The figure indexed the following components making up the remote controller :

1. ESP32 38 pin on an ESP32 terminal adapter
2. 5v Step down converter
3. Wooden structure
4. Two Limit switches
5. Two 10k metallic potentiometers 
6. Cartesian Joystick with press down switch
7. Battery

### Structure

To prototype the body of the remote controller, the module utilised pieces of wood due to their lightweight density and because they can be easily drilled and machined. The structure is composed of four pieces of wood glued together to form a solid structure, components are attached to.
Although the body and finishing is not the envisaged end look and feel of the remote controller, the rapid prototype implement confirmed the module's approximate size, the components arrangement, connectivity and established a functional remote controller.

The following diagram encodes the dimensions of the wooden pieces, assembling the structure of the module. The figure moreover encodes on the top left side of the structure two holes to pass the potentiometer cables and three smaller holes matching the pins of the limit switches layout. Another two holes can be seen in center of the top side of the structure, used to secure the battery of the remote controller, using a strap or a tape. 


![Structure schematics](_figures/remote-control-03-structure-schematics.png)

The following photo, shows the fabricated structure underside, hosting the ESP32 terminal adapter using two screws. 

![Structure actual](_figures/remote-control-04-frame.jpg)

The subsequent photo depicts the top side of the structure facilitating the joystick, the battery positioned in the top middle side, above the ESP32 terminal adapter located on the underside of the module's body.

![Structure battery and joystick](_figures/remote-control-05-frame-battery-joystic.jpg)

The following photo provides a side view of the controller, at the same fabrication step shown in the previous figure.

![Module side](_figures/remote-control-06-side.jpg)

The consequent photo, focuses on the left side of the remote controller where the two limit switches and the two potentiometers have been attached using hot glue. The cables of the input sensors pass through the structure towards the electronics, using related holes following the layout of the components. The four input sensors, connect with the ESP32 GPIO ports using a four pin and a two pin ribbon cables, used to link their signals and supply them with power. 

![Switches and potentiometers](_figures/remote-control-07-switch-potetiometer.jpg)

The fabricated remote controller is shown via the following photograph.

![Top side view of module](_figures/remote-control-08-top-side-sensors.jpg)

The side view of the fabricated module, is attached next.

![Side view of module](_figures/remote-control-09-side.jpg)


### Electronics

The following photo snapshots the underside of the module, its electronics and their connections.

![Underside view of electronics](_figures/remote-control-10-under-electronics.jpg)

The consequent photograph focuses the left underside of the controller where the limit switches and the potentiometer are linked with the ESP32. 
All sensors input pins are connected with the 3.3v output of the controller. Their output pins are connected to the digital or analogue ESP32 GPIO ports and the potentiometers are additionally linked with the ground.

![Under left side view of electronics](_figures/remote-control-11-imder-left-side.jpg)

The following image depicts the right underside of the structure where the 5v step down converter and the right side of the ESP32 terminal pin connections, can be observed.

![Under right side view of electronics](_figures/remote-control-12-uner-right-side.jpg)

The Joystick X and Y axis sensors are connected to the 34th and 39th GPIO ports, while its tactile switch on port 36. The left side potentiometers are connected to ports 35 and 32. Last, the two limit switches are linked with ports 16 and 33. 
 
 
## Software

This *Agrofelis Base remote controller Software* adheres to a common baseline pattern that has been established in nearly all Agrofelis modules. This baseline pattern introduces a "context" class, which is passed to practically all classes as a common ground, enabling instances to exchange information when necessary. The second baseline pattern established refers to the frequency of execution, providing the facilities to trigger specific functionalities at desired intervals. This design consideration accommodates for components such as an MPU or a magnetometer sensors, which require much more frequent updates compared to components such as potentiometer sensors. As a bootstrap template, the software provides six different execution frequencies, ranging from 50 milliseconds to 5-second intervals. Using this approach, delays blocking the execution are avoided and the different calls can be organized based on their responsiveness requirements.

The software encodes easy to follow concrete implementations such as current sensors or motor(s), resulting in a one-to-one mapping between the physical element and its respective software counterpart. In this particular software prototype where the module contained only input sensors a Sensors module was defined implementing all sensor reading and processing in one class. The software utilises the web socket interface connecting with the Unificator software over the Wifi.

The following table indexes and summarizes the implemented classes of the Agrofelis remote controller software.

| Class | Description | 
|----|------------------|
|esp32RemoteController.ino | Boots the application, initialises the top classes and encodes the triggering frequencies of the functional elements. |
|Context | Provides a common ground for sharing information and encodes the triggering frequencies, helpful functions and a unique identifier of the model. |
|Invoker | Tracks the execution frequencies so these are called at the right time. |
|Sensors | The class defines the pin ports of all input sensors. The software reads all input sensors based on their type in one step and a second step evaluates their conbinatorial state and and amount of time being actuated, triggering accordingly a respective command action to be sent to the Agrofelis Robot. |
 
## Remote controller components

The following table lists the individual components employed for prototyping the Agrofelis remote controller. The index table includes moreover the product URLs, the indicative suppliers, as well as unit prices and total cost estimates.

<div align="center">

| No. |  Product | Product URL | Supplier | Used Quantity | VAT Price (€) | Subtotal (€)  | Note |
|----|--------------|------------|-----|---|---|---|---|
| #1 | ESP32 38 pin | [ESP32](https://www.aliexpress.com/item/1005001636295529.html) | [AliExpress](https://www.aliexpress.com) | 1 | 3.67 | 3.67 | - | 
| #2 | ESP32 38 pin terminal adapter | [ESP32](https://www.aliexpress.com/item/1005001636295529.html) | [AliExpress](https://www.aliexpress.com) | 1 | 2.69 | 2.69 | - | 
| #3 | 100 X 80 X 8 mm ply-wood | [plywood](https://www.skroutz.gr/mp/162035068/Kontra-Plake-THalassis-Okoume-100CH80-cm-Pachos-8mm.html) | [Skroutz](https://www.skroutz.gr) | 1 | 16.02 | 16.02 | - |
| #4 | Gravity: Joystick Module V2 (DFR0061) | [Joystick](https://www.hellasdigital.gr/electronics/sensors/keypad-and-joystick/gravity-joystick-module-v2-dfr0061/) | [Hellas Digital](https://www.hellasdigital.gr) | 1 | 6.20 | 6.20 | - |
| #5 | 10K Ohm Linear Potentiometer B10K 15 mm | [Potentiometer](https://www.hellasdigital.gr/electronics/components/potentiometer/10k-ohm-linear-potentiometer-b10k-15mm/) | [Hellas Digital](https://www.hellasdigital.gr) | 2 | 0.50 | 1 | - |
| #6 | 5v step down converter | [step down converter](https://grobotronics.com/dc-dc-step-down-1.3-35v-3a.html) | [Grobotronics](https://grobotronics.com) | 1 | 2.90 | 2.90 | - |
| #7 | Micro limit switch | [limit switch](https://grobotronics.com/microswitch-micro-spdt-on-on-roller-lever.html) | [Grobotronics](https://grobotronics.com) | 2 | 0.20 | 0.40 | - | 
| #8 | 5 wire, 4-wire and 2-wire ribbon cable  | [Ribbon cable 28AWG](https://grobotronics.com/ribbon-cable-28awg-0.081mm2-20-wire.html)   | [GRobotronics](https://grobotronics.com/) | 1  | 1 | 1 | - |
| #9 | NEM Li-PO 7.4v/ 1500mAh/ 20C | [battery](http://nemhobby.com/nem-li-po-7-4v-1500mah-20c-500-charges-p31130.html) | [NEM hobby](http://nemhobby.com) | 1 | 15.00 | 15.00 | - |
| #10 | Connector T-Plug Gold Plated -Male | [T-plug](http://nemhobby.com/connector-t-plug-gold-plated-male-p34785.html) | [NEM hobby](http://nemhobby.com) | 1 | 0.62  | 0.62 | - |
| #11 | Black and red wire| [Black-red wire](https://grobotronics.com/wire-2x0.5mm-stranded-black-red-10m.html)   | [GRobotronics](https://grobotronics.com/)  | 1  | 8.00 | 0.00 | shared Component |
 | **Total** |      |    |     |      |     |  **65.52**  | - | 

</div>

The total cost to manufacture the Agrofelis remote controller prototype controller, excluding shipping and labor cost, amounts to approximately **65.52** euros.

# Summary

The rationale of the module, its sub components and their elements were elaborated. Photos outlining details of the different phases of the manufacturing process were provided. Source code files, schematics, instructions and printouts to reconstruct the Agrofelis basic remote controller, have been documented. The document closes with a photo of the remote controller being held by the Robot's operator. 

![Remote control being held](_figures/remote-control-13-held.jpg)
