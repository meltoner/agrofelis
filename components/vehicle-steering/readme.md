# Agrofelis steering system design and fabrication

# Abstract

This document delves into the details making up the steering system of the Agrofelis vehicle. The logic behind the design, the structural elements composing it, the feedback mechanisms, the custom PCB board are presented and documented. The source code files, key design metrics, schematics, 3D printed assets, laser cut NC files, and photographs present the fabricated components and manufacturing steps in a progressive manner. The steering module of Agrofelis enables it to make a tight turn within 1 meter and its design minimizes the overall foot print of the vehicle. The document provides the list of components and indicative suppliers forming the bill and material information of the steering module. Last, the documentation presents an overview of the implemented driver software its classes and their relations.


# Introduction

The key design factors of the steering system of the Agrofelis vehicle, were space minimization, sufficient torque to steer the wheels on uneven terrains, sufficient turning speed, feedback motion sensors enabling to precisely move the wheels, and monitoring capacities to observe the current drawn by each wheel while turning. Although a passive system is usually employed implementing the [Ackerman steering geometry](https://en.wikipedia.org/wiki/Ackermann_steering_geometry), the Agrofelis steering system implements the ratios dynamically via software and two independent linear actuators. This decision although perhaps harder to implement, leads to a more compact footprint, promotes the modular mentality and potentially allows for a wider range of wheel alignments worth researching. 

In the following sections, the various sub-modules employed for the steering system of the Agrofelis robot, are being documented. More specifically the overall schematic is being presented and is decomposed into the steering plates, the linear actuators and their protective covers, the feedback mechanism, the custom gears developed using a laser cutter, 3D printed protection covers of the feedback mechanism, the Agrofelis Linear actuators steering driver PCB and its software. 


## Steering module

The following schematic diagram provides an overall view of the steering system.

![Steering system view](_figures/vehicle-steering-01-steering1.png)

The next view diagram, depicts the key sub-elements of the steering system.

![Steering system sub elements](_figures/vehicle-steering-02-steering2.png)

More specifically, the diagram illustrates the following elements.

1. The feedback mechanism, enabling to monitor the actual position of the wheel.
2. The linear actuators mounting into the steering plate and the forks lever.
3. The steering plate providing fixed points to the linear actuators to turn the wheels.
4. The custom PCB shield hosting the actuators drivers, current sensors and sensor inputs.
5. The Arduino mega micro-controller processing the related signals and controlling the steering actuators.

## Steering plates

The steering plates are two detachable 2 mm horizontal plates with welded nuts mounted into the vehicle frame via relevant holes made in the frame. The steering plates provide sufficient headroom to enclose the two linear actuators and provide fixed push points via two 6 mm rods piercing vertically the plates. The steering plates moreover, create three compartments within the vehicle's frame. The bottom compartment hosting the [Agrofelis Motors hub driver](https://github.com/meltoner/agrofelis/tree/main/components/mobility/motors_hub_driver), the middle one hosting the steering linear actuators and the top compartment hosting the steering micro-controller and the Jetson Nano embedded computer. 

The following diagram illustrates the described steering plates, annotated with key dimension metrics. 

![Steering mounting plates diagram](_figures/vehicle-steering-03-mounting-plates-1.png)

The consequent photo, snapshots the two plates just after these were cut with a grinder.

![Cut steering plates](_figures/vehicle-steering-04-mounting-plates-2.jpg)

The following photograph illustrates early stages of the fabrication and how the linear actuators are mounted and positioned in order to rotate the wheels during their actuation.

![Mounting plates fabrication ](_figures/vehicle-steering-05-mounting-plates-3.jpg)

A close up view of the steering plates and how the linear actuators are being mounted using two vertical rods is provided next.
The vertical rods are extended further than necessary, as they are conveniently used to secure further the Motors hub driver module when the vehicle rests at a vertical position during maintenance.

![Mounting plates linear actuators attachment](_figures/vehicle-steering-06-mounting-plates-4.jpg)

## Fork mounting points

The linear actuators attach into the back forks lever, using a nut a bold a washer and a ball bearing to minimize friction, as shown by the following photograph.

![Ball bearings rollers-1](_figures/vehicle-steering-07-rollers-1.jpg)

The assembled mounting point is moreover snapshot-ed by the following photo. 

![Ball bearings rollers-2](_figures/vehicle-steering-08-rollers2.jpg)

## Linear actuators protection

Because the linear actuators extend from within the frame, pass through the vehicle covers to the external environment, they and the frame internals are subject to dust and other unwanted elements. Using an outdoor stretchable waterproof cloth, cut and rolled into a cylinder using the following pattern, protective covers were fabricated isolating linear actuators and the frame internals from the environment, while effortlessly following the movements of the actuators.

![cloth-cover-actuators](_figures/vehicle-steering-09-cloth-cover-actuators.png)

The waterproof cloth cut using a scissor to the presented pattern is snapshot-ed by the following photo. 

![cloth-cover-linear-actuators-1](_figures/vehicle-steering-10-cloth-cover-linear-actuators-1.jpg)

Sufficient offset has been built into the pattern, which is forgiving to imprecise manual cutting.
The cloth piece rolled into a cylinder with its waterproof side in its outer side, is glued using common electrical black tape with the vehicle's cover plates, as seen by the following photograph.

![cloth-cover-linear-actuators-2](_figures/vehicle-steering-11-cloth-cover-linear-actuators-2.jpg)

## Feedback mechanism

Without verifying an actuation in robotics acting in external environments its very common to find deviation of what has actually happened from what the system expects to have happened. The steering system employs various indicator sensors to be able to verify the movement and be able to observe out of the ordinary metrics and detect that something unexpected has happened. 

For the motion aspect, two custom gears were designed, one attached permanently to fork's hinge element and the second to a potentiometer attached to the fork's vehicle mounting mechanism. The feedback sensor was decided to be installed exactly at the rotation point of the fork, compared to the internal rotation point of the linear actuator, to minimize the translation distance between the measurement and the actual rotation of the wheel. 

The feedback mechanism schematic view is illustrated by following figure depicting the two gears, the potentiometer secured on a small corner plate that is attached using two screws into the vehicle's fork mounting mechanism. 

![gears](_figures/vehicle-steering-12-gears.png)

The gears feedback mechanism dimension metrics are encoded by the following schematic.

![gears-2](_figures/vehicle-steering-13.gears-2.png)

Multiple gears are being fabricated from a piece of black 2 mm acrylic, chosen for added strength, using a laser cutter. These are snapshot-ed by the following photo.

![Gears actual](_figures/vehicle-steering-15-Gears-DSC08042.jpg)

A close up view of the potentiometer gear, formed by stacking and gluing together three 2 mm pieces, is provided by the following photograph.

![Gears](_figures/vehicle-steering-16gears3.jpg)

The following folder contains the gear design scalable vector graphics (SVG) as well as the Numerical Control (NC) files driving a [low cost laser cutter CNC](https://eur.vevor.com/wood-engraving-machine-c_11142/3018-pro-cnc-router-3-axis-w-offline-controller-laser-engraver-machine-10000rpm-p_010521182027).

- [assets/laser-cut-feedback-gears](assets/laser-cut-feedback-gears)

The following files contain respectively the two gear SVG design patterns offset-ed by the size of the laser beam.

- [feedback-gear-A-Offset.svg](assets/laser-cut-feedback-gears/feedback-gear-A-Offset.svg)
- [feedback-gear-B-Offset.svg](assets/laser-cut-feedback-gears/feedback-gear-B-Offset.svg)

Moreover, the numerical control NC files driving the CNC follow.

- [feedback-gear-A-Offset.nc](assets/laser-cut-feedback-gears/feedback-gear-A-Offset.nc)
- [feedback-gear-A-Offset.nc](assets/laser-cut-feedback-gears/feedback-gear-A-Offset.nc)

Last, the following NC files, contains both gears in one file for convenience.

- [feedback-gear-A-and-B.nc](assets/laser-cut-feedback-gears/feedback-gear-A-and-B.nc)


## Feedback mechanism covers

In order to provide some protection of the feedback mechanism, from plants or other unwanted elements from obscuring the gears, two symmetric covers where designed and fabricated using a low cost 3d printer. The protective covers attach and detach into the vehicle's fork mounting mechanism using neodymium magnets. The covers schematics, protecting the feedback sensor are illustrated by the following diagram

![Gears protection cover](_figures/vehicle-steering-17-gears-covers.png)

The 3d printed fabricated covers, having the magnets embedded into their structure, can be seen in the following photo.

![gear-covers-1](_figures/vehicle-steering-18-gear-covers-1.jpg)

The protective covers painted using a gray paint are snapshot-ed by the consequent image.

![gear-covers-2](_figures/vehicle-steering-19-gear-covers-2.jpg)


The following folder contains the left and right protective covers symmetric design stereo-lithography (STL) plans and their Geometric Code (GCODE) derivatives, driving a 3D printer.

- [assets/3d-print-feedback-potensiometer-covers](assets/3d-print-feedback-potensiometer-covers)

More specifically the folder contains the following source files. 

- [potensiometerCoversL.stl](assets/3d-print-feedback-potensiometer-covers/potensiometerCoversL.stl)
- [potensiometerCoversR.stl](assets/3d-print-feedback-potensiometer-covers/potensiometerCoversR.stl)
- [potensiometerCoversL.gcode](assets/3d-print-feedback-potensiometer-covers/potensiometerCoversL.gcode)
- [potensiometerCoversR.gcode](assets/3d-print-feedback-potensiometer-covers/potensiometerCoversR.gcode)
 
The end mechanism without the protective covers is pictured by the following photo.

![feedback mechanism actual](_figures/vehicle-steering-20-feedback-1.jpg)

The end mechanism with the protective covers can be compared via the following image.

![feedback mechanism with covers](_figures/vehicle-steering-21-feedback2.jpg)

## Steering PCB driver

In order to drive the linear actuators, sense how much these have been moved in relation to the voltage applied and the friction of the wheel with the ground, as well as sense how much current is being drawn indicating high resistance or no resistance a custom board was designed to organize the various electronic elements as well as tidy the cables per actuator and sensor. The shield was designed so it can be independent of the micro controller and for example instead of an Arduino mega be able to employ an Arduino mega pro or an esp32. The PCB board was designed in such a way that it can be cut in half and drive two individual linear actuators, on another alike part in the system.

The designed PCB indicating the components it hosts, the input and output pins and their function is attached next.

![Steering PCB driver schematic](_figures/vehicle-steering-23_STEERING_DRIVER.png)


The PCB board scalable vector graphic design plan can be found in the following path :

- [driver-board/laser-cut-nc/linear_trails.svg](driver-board/laser-cut-nc/linear_trails.svg)

Its Numerical Control (NC) derivative driving a CNC router is provided bellow :

- [driver-board/laser-cut-nc/linear_trails.nc](driver-board/laser-cut-nc/linear_trails.nc)


The following figure, encodes the PCB board input / output connected into the Arduino Mega board pins.

![STEERING_DRIVER_connections](_figures/vehicle-steering-23_STEERING_DRIVER_connections.png)

The following figure snapshots the underside (copper side) of the manufactured PCB board. 

![PCB Driver copper side](_figures/vehicle-steering-24-pcbdriver-1.jpg)

Although latter in the project we discovered better ways to fabricated PCBs, this board was fabricated by spray painting the copper side of the board, burning the designed pattern using a laser engraver and etching the board in acid. The board's holes were manually made by hand. Other PCB found in the Agrofelis project have improved this process by curving the board and drilling the holes in a completely computerized manner.

The following figure illustrates a supportive file prepared for cable management and more specifically by printing the related labels, cutting them and gluing them using transparent tape, denoting the cables functionality and / or voltage level.

![STEERING_DRIVER_CABLES_LABELS](_figures/vehicle-steering-24-STEERING_DRIVER_CABLES_LABELS.png)

The editable vector file, can be found in the following location :

- [driver-board/STEERING_DRIVER_CABLES_LABELS.pdf](driver-board/STEERING_DRIVER_CABLES_LABELS.pdf)


The following picture highlights the location of the PCB shield next to its micro controller, on the top side of the steering plate, on the back side of the Agrofelis vehicle frame.

![pcb-driver-2](_figures/vehicle-steering-25-pcb-driver-2.jpg)


## Steering PCB components


The following table lists the individual components employed for manufacturing the Agrofelis steering controller. The index table includes moreover the product URL, the indicative supplier, as well as the unit price total Amount.


<div align="center">

| No. |  Product | Product URL | Supplier | Used Quantity | VAT Price (€) | Subtotal (€)  | Note |
|----|--------------|------------|-----|---|---|---|---|
| #1 | Copper board |      [PCB board](https://grobotronics.com/prototyping-copper-board-420x297mm-2-layer.html)   | [GRobotronics](https://grobotronics.com/)    |    0.25  | 9.90 | 2.48 | Shared Resource |
| #2 | H-Bridge Brushed DC Motor Driver | [Motor Driver](https://www.cableworks.gr/ilektronika/arduino-and-microcontrollers/motors/drivers/drv8871-h-bridge-brushed-dc-motor-driver-breakout-board-for-arduino/) | [Cableworks](https://www.cableworks.gr) | 2 | 6 | 12 | - |
| #3 | Linear Potentiometer B10K Ohm | [Metal potentiometer](https://www.hellasdigital.gr/electronics/components/potentiometer/rotary-potentiometer-10k-ohm-linear-com-09939/) | [hellasdigital](https://www.hellasdigital.gr) | 2 | 1.24 | 2.48 | - |
| #4 | ACS712 5A Range Hall Current Sensor Module | [5A Current sensor](https://www.aliexpress.com/item/32348760733.html) | [Ali express](https://www.aliexpress.com) | 2 | 1.10 | 2.20 | - |
| #5 |6-wire ribbon cable 120 mm  | [Ribbon cable 28AWG](https://grobotronics.com/ribbon-cable-28awg-0.081mm2-20-wire.html)   | [GRobotronics](https://grobotronics.com/) | 0.25  | 1.00 | 0.3| Shared Resource |
| #6 | 3 wire cable 350 mm connecting the potentiometer | [3 wire cable](https://www.hellasdigital.gr/computers/cables/sound-cables/roline-3-5mm-audio-cable-m-m-2m-11-09-4502/) | [Hellas Digital](https://www.hellasdigital.gr) | 1 | 2.6 | 2.6 | - |
| #7 | 6-pin header female  | [Female Pin Header Kit](https://www.nettop.gr/index.php?option=com_virtuemart&view=productdetails&virtuemart_product_id=1592)   | [Nettop](https://www.nettop.gr/)  | 1  | 0.00 | 0.00 | Shared Resource |
| #8 | 3-pin header female  | [Female Pin Header Kit](https://www.nettop.gr/index.php?option=com_virtuemart&view=productdetails&virtuemart_product_id=1592)   | [Nettop](https://www.nettop.gr/)  | 1  | 0.00 | 0.00 | Shared Resource |
| #9 | 3-pin header male  | [Male Pin Header Kit](https://www.nettop.gr/index.php?option=com_virtuemart&view=productdetails&virtuemart_product_id=1592)   | [Nettop](https://www.nettop.gr/)  | 1  | 0.00 | 0.00 | Shared Resource |
| #10 | 3-pin header male  | [Male Pin Header Kit](https://www.nettop.gr/index.php?option=com_virtuemart&view=productdetails&virtuemart_product_id=1592)   | [Nettop](https://www.nettop.gr/)  | 1  | 0.00 | 0.00 | Shared Resource |
| #11 | Arduino Mega | [Arduino Mega](https://www.aliexpress.com/item/32823481047.html) | [Ali Express](https://www.aliexpress.com) | 1 | 10 | 10 | - |
| **Total** |      |    |     |      |     |  **32.06**  | | 

</div>

The total cost to manufacture the Agrofelis steering driver shield excluding shipping and assembly charges, sums to approximately **32** euros.

## Steering actuators and structural components

The following table lists the components employed for manufacturing the Agrofelis steering structural elements. The index table includes the product URL, the indicative supplier, as well as the unit price total amount.


| No. |  Product | Product URL | Supplier | Used Quantity | VAT Price (€) | Subtotal (€)  | Note |
|----|--------------|------------|-----|---|---|---|---|
| #1 | Black iron metal sheet 1000x2000x2mm  | [2mm metal sheet](https://www.e-metalshop.gr/sidera/lamarynes/lamarina-sidhroy-mayrh-1000x2000x2mm) | [QOOP Metalworks](https://www.qoop.gr)  | 0.25 | 50 | 15 | - |
| #2 | 8 Nuts 5mm | [Nut 5mm](https://www.kantarzoglou.gr/pegasus/products01/show00.php) |  [QOOP Metalworks](https://www.qoop.gr) | 8 | 0.1 | 0.8 | - |
| #3 | 10 Allen bolts 5mm  | [Bolt 8mm](https://ironhorses.gr/product/m5-x-40mm-allen-bolt-25-pack/) | [QOOP Metalworks](https://www.qoop.gr) | 10 | 0.2 | 2 | - |
| #4 | Mini Plane Axial Thrust Ball Bearing  F7-17M 7 x 17 x 6mm | [ball bearing](https://www.aliexpress.com/item/1005005502256552.html) | [Ali Express](www.aliexpress.com) | 2 | 1.31 | 2.62 | - |
| #5 | Linear actuator 24V 500N 20mm/s, Stroke 100mm | [Linear Actuator](https://www.aliexpress.com/item/1005003897869232.html) | [Ali Express](https://www.aliexpress.com) | 2 | 36.7 | 73.6 | - |
| #6 | Powerful Round Magnets 5x3mm | [Round Magnets](https://www.hellasdigital.gr/electronics/magnets/powerful-round-magnets-5x3mm/) | [Hellas Digital](https://www.hellasdigital.gr) | 4 | 0.1 | 0.4 | - |
| #7 | Powerful Magnets Block 20X5X3mm | [block magnet](https://www.hellasdigital.gr/electronics/magnets/powerful-magnets-block-20x5x3mm/)  | [Hellas Digital](https://www.hellasdigital.gr) | 2 | 0.15 | 0.3 | - |
| #8 | Waterproof fabric 1 sqm | [waterproof fabric](https://www.yfasmatakesidis.gr/adiavroxo-sea-150cm-mayro-p-4905.html) | [Yfasmatakesidis](www.yfasmatakesidis.gr) | 1 | 5 | 5 | - |
| #9 | 6 mm rod | [6 mm rod](https://www.amazon.co.uk/Glarks-Stainless-Straight-Helicopter-Airplane/dp/B07KJ4NWNG/) | [QOOP Metalworks](https://www.qoop.gr)  | 2 | 2 | 4 | - |
| **Total** |      |    |     |      |     |  **103.72**  | | 

The total cost to manufacture the Agrofelis steering structural and actuators elements excluding shipping and assembly charges, sums to approximately **104** euros.
The total cost to fabricate the Agrofelis steering structural, actuators and electronics sums to approximately **136** euros.


## Steering driver software 

The Agrofelis software source code developed, managing the steering system via its actuators and sensors running on an Arduino mega, containing 23 source code files and 3 supportive is referenced bellow :

- [src/linearSteer](src/linearSteer)

The source code contains an ino file initiating the application and series of h and cpp files encoding the declarations and implementations of the classes of the application. 

The project uses an Arduino Mega and few components to sense and control two linear actuators, establishing the steering system.
The module utilises the Serial interface to share the internal state of the components, as well as to control them.

The module consist of custom PCB that hosts two current sensors, two motor drivers and two inlets for two potentiometer used as feedback 
sensor, to readout the steering degree of the wheels. The software enables to control each linear actuator individually as well as in a synchronized 
manner, based on the Ackerman geometry and the physical orientation of the vehicle. The valid ratios of the wheels are measured in fine steps 
and persisted in an association map that is interpolated. 

The module status can be set remotely, so the linear actuators are driven to reach the minimum and maximal points in order to dynamically derive the center and the bounds of
applicable movement. Moreover, the minimum voltage needed to achieve a movement can be derived, as the lowest applicable speed. 

The module provides an interface to make both linear actuators seek and reach the desired position. The application implements the functionality so the linear actuators are operated asynchronously moving the motors in different speeds, to meet the Ackerman geometry based on the observed resistance and the distance have to cover respectively. 

The software moreover, establishes the braking system of the vehicle by driving two servos linked to the disc brakes.


### Application structure


This Agrofelis steering and braking software follows a common baseline pattern established in nearly all Agrofelis modules. This baseline establishes a context class passed to nearly all classes as a common ground enabling instances to share information when necessary. The second baseline pattern establishing relates with the frequencies of execution providing the facilities to trigger functionalities at the desired intervals. For example an gyroscope may need to be triggered far more frequently than a GPS sensor or a potentiometer sensor. As a bootstrap template the software provide 6 different frequencies ranging from 50 milliseconds to 5 second intervals. Using this approach delays, blocking the execution are avoided and the different calls can be organized according to their responsiveness requirement. 

The software encodes easy to follow concrete implementations such as current sensor or brake and brakes making an one to one mapping of the physical element and their respective software counter part

The following table indexes and summarizes the implemented classes of the Agrofelis steering and braking controller.


| Class | Description | 
|----|------------------|
|linearSteer.ino | Boots the application, initialises the top classes, encodes the triggering frequencies of various functional elements |
|Context | Provides a common ground the share information, encodes the triggering frequencies, helpful functions and a unique identifier of the model |
|Invoker | Tracks the execution frequencies such these are called at the right time |
|Brake | Object representing a wheel brake actuating a servo motor. The object can be initialised with a limited target range, as much as to lift the brake. The class was used with a TIANKONGRC RDS-8120 20KG ROBOT DIGITAL SERVO. The class can be instantiated by providing the connected GPIO, the desired range to actuate from the applicable (0-180), which is then mapped to a convenient range of 0 to 100. |
|Brakes | The class can drive two or more brakes objects simultaneously. |
|Sensor | Base class wrapping the functions conveying a sensor. The class reads an analogue port when the apply function is being triggered. The class maintains a gated smoothing read out of the sensor by comparing the previous mean with with current read value. Moreover, maintains a boolean flag, when a movement is being detected based on the absolute difference of the first derivative. Last, it prints out the object internal state, on print() reflecting the sensor's port, its smoothed value, its un-smoothed sensor value and if the sensor is detecting a movement. |
|SensorCurrent | Class extending the Sensor class implementing the specialties of a current sensor. The class translates the raw sensor value to amperage. Moreover, because the current sensor reads rapid current spikes that can be missed, the class maintains a decaying max read value that is renewed based on the maximum value observed within a time window. |
|LinearActuator | The class implements an object to control a linear actuator via a DRV8871 H-Bridge Brushed DC Motor Driver component. The class is instantiated with the board port mappings enabling its re-usability. The first two constructor parameters map the control pins for the direction and the speed of the [DRV8871 H-Bridge Brushed DC Motor Driver] using two pulse width modulation (PWM) ports. Next the GPIO of the analogue [LinearActuator Potentiometer B10K Ohm] and the analogue [ACS712 5A Range Hall Current Sensor Module] sensors are provided. The module operates based on 4 states dictating its function. On states one and two, the min and max potentiometer bounds are identified. On state three, the minimum throttle leading to a movement is derived. On state four, the modules enters when its objective position has been achieved. On state five, the object seeks to reach to the target requested position. States 10 and 11 correspond to erroneous states, such when an actuation is not detected when its expected or when the sensor value reads values close to its physical limits. The applicable bounds can be moreover persisted so these do not have to be re-resolved when booting the Agrofelis vehicle. |
|Interpolate | Class for interpolating a value based on an input/output mapping pair of values. The interpolation object enables to map an input non linearly across an input range and linearly within its sub bounds. The class is employed by initializing it with measurement mappings references such that the Ackerman geometry is followed based on the physical orientation, and the raw potentiometer values recorded by performing incremental movement to both wheel of the vehicle. |
|SteeringDriver | The class holds the linear actuator references, their Ackerman mappings steps and the means to interpolate their ratios from a -100 to 100 positioning range. The object enables to change the state of the system to seek its movement bounds and minimum voltage leading to a movement. The class moreover can dynamically derive and apply more voltage if the expected movement hasn't been observed as well as fade in or fade out the voltage depending on the passed time, the progress of the distance asked to accomplish, and its difference with its counterpart actuator. |
|SerialCommandParser | Base class for monitoring and parsing the serial interface data. The class defines the function parsing compact commands, of the form <1|1> where the first parameter corresponds to the action number to apply and the next an integer value used by the related action. |
|SteeringController | The steeringController extends the SerialCommandParser and defines the applicable commands driving the actuators. The class moreover, reflects the internal state of the brakes, the linear actuators and their sensors so other nodes of the system are aware of their state. |

The repository moreover, contains supportive files used while measuring and adapting the left and right linear actuators such that an end to end Ackerman geometry was met. The process studies and accounts the non-linearity characteristics of the potentiometers, the Digital to analogue convertors (DAC), the linear actuators, as well as the subtle construction accumulative deviations in the following folder :

- [src/linearSteer/data.modeling](src/linearSteer/data.modeling)

The file data.modeling.R was developed in the R language, to study and reflect the end to end differences between the left and right sensors and actuators. 

The following plot, visualizes the raw values sensor differences applying between the left and right sensors in order to meet the Ackerman geometry physically, when steering from hard left to hard right in constant steps.

![End to end Ackerman geometry differences between the Left and Right input sensors](_figures/vehicle-steering-25-R-left-right-ackerman-differences.png)

The steering application runtime information and its modules can be also accessed and controlled via the Agrofelis Unificator software able to unify multiple Agrofelis module connected from different interfaces (Serial, Wifi, Websockets, USB). Lightweight single page web applications can easily map, bind and monitor the internal state of the steering actuators and their sensors, as seen by the following screenshot. 

![Steering - Agrofelis Unificator](_figures/vehicle-steering-26-AgrofelisUnificator-snapshot.jpg)

The [Agrofelis Unificator](https://github.com/meltoner/agrofelis/tree/main/components/connectivity) software is documented in the related chapter of the Agrofelis documentation.

# Summary 

The details of this important mobility module of the Agrofelis robot, have been documented. All source code files, schematics, Numerical control files and patterns involved in the fabrication, have been presented along with photographic material showcasing the progress of the manufacturing progress. The list of components, raw materials, indicative suppliers and cost information aiding to reproducibility of the overall steering system, have been provided in an organized manner. References to the Agrofelis steering system application source code running on the micro-controller, has been referenced with descriptive information per class, offering a quick overview of the the location of the implemented functionality. Approaches followed for bridging the theoretical perfect and the actual, using practical means such as recording, data visualisation and statistics were introduced. The documentation concluded by hinting how the steering module fits in the overall design from a software point of view, how it can be accessed and how all modules can communicate, extended and appended on demand.

