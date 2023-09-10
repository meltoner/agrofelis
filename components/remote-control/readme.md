# Agrofelis Remote Controller Design and Fabrication

# Abstract

The document presents the details of fabricating a baseline remote controller for actuating the wheels, steering, brakes and power functions of the Agrofelis robot. Emphasizing ergonomics, cost-effectiveness and the use of readily available components, a simple extendable design is presented, rapidly prototyping the minimum number of sensors and components needed for booting and controlling the mobility functions of the vehicle. The module is de-compiled using annotated design plans with crucial metrics and is re-compiled using photos captured during the fabrication process. The software source code running on the micro-controller is also presented, following approaches similar to those implemented in other Agrofelis modules. The document concludes with a list of components used and provides information on indicative suppliers, aiding in the replication of the module.

# Introduction

The objective of this module is to implement a minimum viable remote controller for the Agrofelis robot. Serving its purpose in conducting the first round of on-field tests, this module acts as a baseline remote controller that can be expanded with additional modules, such as a TFT monitor, supplementary sensors and/or range extenders. The following photograph depicts the remote controller and the Agrofelis robot in operation within a vineyard.

![Remote control and vehicle](_figures/remote-control-00-view-using.jpg)

In the following sections, the Agrofelis robot remote controller prototype is documented.

## Agrofelis Remote Controller

While the Agrofelis unificator software, which integrates all Agrofelis module data streams with its corresponding web application, allows the system to be controlled through regular mobile phones and computers, there is a need for a dedicated physical interface that can be operated with one's hands, thus offering a more natural and robust interface. In addition, a dedicated physical controller bypasses issues associated with mobile phones, which are prone to interruptions from incoming calls, the necessity for clean and bare hands, distraction from the vehicle due to the necessity of looking at the RC module instead of the vehicle and usability issues influenced by ambient luminosity levels of the environment.

The designed and implemented remote controller for Agrofelis is constructed as a reversed drawer-like structure, roughly the size of an average person's chest span, thus offering a more comfortable user experience. Furthermore, the holding sides of the structure fit conveniently within the palm of the user, providing a firm grip of the module. The controller's input sensors are strategically located within thumb's reach, making it easy to access and engage with the input controls. The controller incorporates several key components, including an ESP32, a battery, a 5V step-down converter, a joystick with an embedded switch, two potentiometers and two switches, attached to the sides of the wooden structure.

Although controllers found in game engines are frequently used in such projects, this choice eventually limits the flexibility one can have. Furthermore, prototyping from the ground up builds know-how, which consequently allows the ability to extend the baseline modules based on the acquired experience. The implementation leverages established patterns and practices employed in the *Agrofelis Motors Hub Driver* and *Front Sensors Lidar* modules, further testing the decisions made, which leads to more robust software. The primary distinction between other Agrofelis modules and the basic remote controller is that the latter is simply composed of input sensors.

The controller can detect momentary button presses, prolonged presses and combinations of presses. Additionally, it quantizes the sensor signal ranges to suppress noise or accidental movements. The software actively monitors changes in the joystick's internal potentiometers, mapping forward and backward movements with its y-axis input sensor and steering with its x-axis. 

The controller uses an indirect way to control the speed by varying the duration of sensor activation or inactivity. The controller fades-in the y-axis input values slower when actuated (acceleration) and fades-out of them faster when un-engaged (deceleration). The first potentiometer located on the left side limits the speed signal sent to the robot via the joystick, while the second potentiometer controls the maximum rotation degree sent to the disk brake servos, controlling how hard or soft they are actuated. The first switch powers the Agrofelis robot mobility system on or off when pressed for an extended period of time. The second switch actuates the brakes based on the signal from the second potentiometer. When the joystick's button is pressed for a prolonged time, it switches on or off the maximum or regular steering radius of the vehicle.

The software implements smooth acceleration and rapid deceleration controls for the vehicle, ensuring safe maneuverability of the module. The speed of the vehicle can be set to four speed states, ranging from zero to the maximum programmed speed. Consequently, whether on a slope or flat ground, the brakes can be adjusted to consume less energy when actuated. The remote controller was programmed and fine-tuned in the field in order to optimize its responsiveness, ensuring that the vehicle's movements were smooth, safe and forgiving by allowing users sufficient time to observe the outcomes of their movements.

The following diagram depicts the remote controller module, with distances encoded from the component to the outer rim of the controller's body.

![Module schematics](_figures/remote-control-01-module-schematics.png)

The module's components are enumerated by the consequent exploded view schematic.

![Module exploded view](_figures/remote-control-02-module-exploded.png)

The list below enumerates the components comprising the remote controller:

1. ESP32 38 pin on an ESP32 terminal adapter
2. 5V step-down converter
3. Wooden structure
4. Two limit switches
5. Two 10k metallic potentiometers
6. Cartesian joystick with a press-down switch
7. Battery

### Structure

To prototype the body of the remote controller, the module utilised pieces of wood due to their light weight and ability to be easily drilled and machined. The structure is composed of four wooden pieces glued together to form a sturdy structure, to which the rest of the components are attached.
Although the current appearance and finishing of the body are not the desired end appearance and feel of the remote controller, this rapid prototyping phase confirmed the module's approximate dimensions, the arrangement of its components, connectivity and established a functional remote controller.

The following diagram depicts the dimensions of the wooden pieces used to assemble the module's structure. Notably, it showcases two holes on the top-left side of the structure, designed for routing the cables of the potentiometers and three smaller holes matching with the pins of the limit switches layout. Two more holes can be seen in the center of the upper side of the structure for securing the battery of the remote controller, using either a strap or tape.


![Structure schematics](_figures/remote-control-03-structure-schematics.png)

The following photo illustrates the underside of the fabricated structure, which accommodates the ESP32 terminal adapter, attached using two screws.

![Structure actual](_figures/remote-control-04-frame.jpg)

The subsequent photo depicts the top side of the structure facilitating the joystick, the battery positioned in the top middle side, above the ESP32 terminal adapter which is located on the underside of the module's body.

![Structure battery and joystick](_figures/remote-control-05-frame-battery-joystic.jpg)

The following photo provides a side view of the controller, captured during the same fabrication stage shown in the previous figure.

![Module side](_figures/remote-control-06-side.jpg)

The following photograph focuses on the left side of the remote controller, where the two limit switches and two potentiometers have been securely attached using hot glue. The cables of the input sensors pass through the structure towards the electronics, using related holes following the layout of the components. The four input sensors are connected to the ESP32 GPIO ports using a combination of four-pin and two-pin ribbon cables, for linking their signals and supply them with power.

![Switches and potentiometers](_figures/remote-control-07-switch-potetiometer.jpg)

The fabricated remote controller is shown via the following photograph.

![Top side view of module](_figures/remote-control-08-top-side-sensors.jpg)

The side view of the fabricated module, is attached next.

![Side view of module](_figures/remote-control-09-side.jpg)


### Electronics

The following photo snapshots the underside of the module, revealing its electronic components and their interconnections.

![Underside view of electronics](_figures/remote-control-10-under-electronics.jpg)

The consequent photograph focuses on the left underside of the controller, where the limit switches and the potentiometer are linked with the ESP32. 
All sensors input pins are connected with the 3.3V output of the controller. Their output pins are connected to the digital or analogue ESP32 GPIO ports and the potentiometers are additionally linked with the ground.

![Under left side view of electronics](_figures/remote-control-11-imder-left-side.jpg)

The following image depicts the right underside of the structure, where the 5V step-down converter and the right side of the ESP32 terminal pin connections are visible.

![Under right side view of electronics](_figures/remote-control-12-uner-right-side.jpg)

The joystick's X and Y axis sensors are connected to the 34th and 39th GPIO ports, respectively, with its tactile switch interfacing with port 36. The potentiometers on the left side are connected to ports 35 and 32. Finally, the two limit switches are linked to ports 16 and 33.
 
 
## Software

This *Agrofelis base remote controller software* adheres to a common baseline pattern that has been established in nearly all Agrofelis modules. This baseline pattern introduces a "context" class, which is passed to practically all classes as a common ground, enabling instances to exchange information when necessary. The second baseline pattern established refers to the frequency of execution, providing the facilities to trigger specific functionalities at desired intervals. This design consideration accommodates for components such as an MPU or a magnetometer sensors, which require much more frequent updates compared to components such as potentiometer sensors. As a bootstrap template, the software provides six different execution frequencies, ranging from 50 milliseconds to 5-second intervals. Using this approach, delays blocking the execution are avoided and the different calls can be organized based on their responsiveness requirements.

The software encodes easy-to-follow and straightforward implementations, such as current sensors or motor(s), resulting in a one-to-one mapping between the physical element and its respective software counterpart. In this software prototype, where the module only comprised input sensors, a *Sensors module* was defined, which implemented all sensor reading and processing in a single class. The software leverages a web socket interface to communicate with the Unificator software over Wi-Fi.

The following table indexes and summarizes the classes implemented in the Agrofelis remote controller software.

| Class | Description | 
|----|------------------|
|esp32RemoteController.ino | Boots the application, initialises the top-level classes and encodes the triggering frequencies of the functional elements. |
|Context | Provides a common ground for sharing information and encodes the triggering frequencies, helpful functions and a unique identifier of the model. |
|Invoker | Tracks the execution frequencies so these are called at the right time. |
|Sensors | The class defines the pin ports of all input sensors. The software reads all input sensors based on their type in one step and in a second step evaluates their combinatorial state and amount of time being actuated, triggering accordingly a respective command action to be sent to the Agrofelis robot. |
 
## Remote Controller Components

The following table lists the individual components employed for prototyping the Agrofelis remote controller. The index table includes moreover the product URLs, the indicative suppliers, as well as unit prices and total cost estimates.

<div align="center">

| No. |  Product | Product URL | Supplier | Used Quantity | VAT Price (€) | Subtotal (€)  | Note |
|----|--------------|------------|-----|---|---|---|---|
| #1 | ESP32 38-pin | [ESP32](https://www.aliexpress.com/item/1005001636295529.html) | [AliExpress](https://www.aliexpress.com) | 1 | 3.67 | 3.67 | - | 
| #2 | ESP32 38-pin terminal adapter | [ESP32](https://www.aliexpress.com/item/1005001636295529.html) | [AliExpress](https://www.aliexpress.com) | 1 | 2.69 | 2.69 | - | 
| #3 | 100 X 80 X 8 mm ply-wood | [Plywood](https://www.skroutz.gr/mp/162035068/Kontra-Plake-THalassis-Okoume-100CH80-cm-Pachos-8mm.html) | [Skroutz](https://www.skroutz.gr) | 1 | 16.02 | 16.02 | - |
| #4 | Gravity: Joystick Module V2 (DFR0061) | [Joystick](https://www.hellasdigital.gr/electronics/sensors/keypad-and-joystick/gravity-joystick-module-v2-dfr0061/) | [Hellas Digital](https://www.hellasdigital.gr) | 1 | 6.20 | 6.20 | - |
| #5 | 10K Ohm Linear Potentiometer B10K 15 mm | [Potentiometer](https://www.hellasdigital.gr/electronics/components/potentiometer/10k-ohm-linear-potentiometer-b10k-15mm/) | [Hellas Digital](https://www.hellasdigital.gr) | 2 | 0.50 | 1 | - |
| #6 | 5V step down converter | [Step-down converter](https://grobotronics.com/dc-dc-step-down-1.3-35v-3a.html) | [GRobotronics](https://grobotronics.com) | 1 | 2.90 | 2.90 | - |
| #7 | Micro limit switch | [Limit switch](https://grobotronics.com/microswitch-micro-spdt-on-on-roller-lever.html) | [GRobotronics](https://grobotronics.com) | 2 | 0.20 | 0.40 | - | 
| #8 | 5 wire, 4-wire and 2-wire ribbon cable  | [Ribbon cable 28AWG](https://grobotronics.com/ribbon-cable-28awg-0.081mm2-20-wire.html)   | [GRobotronics](https://grobotronics.com/) | 1  | 1 | 1 | - |
| #9 | NEM Li-PO 7.4v/ 1500mAh/ 20C | [Battery](http://nemhobby.com/nem-li-po-7-4v-1500mah-20c-500-charges-p31130.html) | [NEM hobby](http://nemhobby.com) | 1 | 15.00 | 15.00 | - |
| #10 | Connector T-Plug Gold Plated -Male | [T-plug](http://nemhobby.com/connector-t-plug-gold-plated-male-p34785.html) | [NEM hobby](http://nemhobby.com) | 1 | 0.62  | 0.62 | - |
| #11 | Black and red wire| [Black-red wire](https://grobotronics.com/wire-2x0.5mm-stranded-black-red-10m.html)   | [GRobotronics](https://grobotronics.com/)  | 0 | 8.00 | 0.00 | Shared Component |
 | **Total** |      |    |     |      |     |  **65.52**  | - | 

</div>

The total cost for manufacturing the Agrofelis remote controller prototype, excluding shipping and labor costs, amounts to approximately **65** euros.

# Summary

The rationale of the module, its sub-components and their elements were elaborated. Photos outlining details of the different phases of the manufacturing process were provided. Source code files, schematics, instructions and printouts to reconstruct the Agrofelis basic remote controller have all been documented. The document concludes with a photo of the remote controller being held by the robot's operator. 

![Remote control being held](_figures/remote-control-13-held.jpg)
