# Agrofelis steering system design and fabrication

# Abstract

This document delves into the details making up the steering system of the Agrofelis vehicle. The logic behind the design, the structural elements composing it, the feedback mechanisms, the custom PCB board are presented and documented. The source code files, key design metrics, schematics, 3D printed assets, laser cut NC files, and photographs present the fabricated components and manufacturing steps in a progressive manner. The steering module of Agrofelis enables it to make a tight turn within 1 meter and its design minimizes the overall foot print of the vehicle. The document concludes with a list of components and indicative suppliers forming the bill and material information of the steering module.


# Introduction

The key design factors of the steering system of the Agrofelis vehicle, were space minimization, sufficient torque to steer the wheels on uneven terrains, sufficient turning speed, feedback motion sensors enabling to precisely move the wheels, and monitoring capacities to observe the current drawn by each wheel while turning. Although a passive system is usually employed implementing the [Ackerman steering geometry](https://en.wikipedia.org/wiki/Ackermann_steering_geometry), the Agrofelis steering system implements the ratios dynamically via software and two independent linear actuators. This decision although perhaps harder to implement, leads to a more compact footprint, promotes the modular mentality and potentially allows for a wider range of wheel alignments worth researching. 

In the following sections, the various sub-modules employed for the steering system of the Agrofelis robot, are being documented. More specifically the overall schematic is being presented and is decomposed into the steering plates, the linear actuators and their protective covers, the feedback mechanism, the custom gears developed using a laser cutter, 3d printed protection covers of the feedback mechanism, the Agrofelis Linear actuators steering driver PCB and its software. 


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

Because the linear actuators extend from within the frame, pass through the vehicle covers to the external environment, they and the frame internals are subject to dust and other unwanted elements. Using an outdoor stretchable waterproof cloth, cut and rolled into a cilinder using the following pattern, protective covers were fabricated isolating linear actuators and the frame internals from the environment, while effortlessly following the movements of the actuators.

![cloth-cover-actuators](_figures/vehicle-steering-09-cloth-cover-actuators.png)

The waterproof cloth cut using a scissor to the presented pattern is snapshot-ed by the following photo. 

![cloth-cover-linear-actuators-1](_figures/vehicle-steering-10-cloth-cover-linear-actuators-1.jpg)

Sufficient offset has been built into the pattern, which is forgiving to imprecise manual cutting.
The cloth piece rolled into a cylinder with its waterproof side in its outer side, is glued using common electrical black tape and the vehicle's cover plates, as seen by the following photograph.

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


The following folder contains the left and right protective covers symmetric design stereolithography (stl) plans and their Geometric Code (gcode) derivatives, driving a 3d printer.

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

![STEERING_DRIVER](_figures/vehicle-steering-23_STEERING_DRIVER.png)


The PCB board scalable vector graphic design plan can be found in the following path :

- [driver-board/laser-cut-nc/linear_trails.svg](driver-board/laser-cut-nc/linear_trails.svg)

Its Numerical Control (NC) derivative driving a CNC router is provided bellow :

- [driver-board/laser-cut-nc/linear_trails.nc](driver-board/laser-cut-nc/linear_trails.nc)


The following figure, encodes the PCB board input / output connected into the Arduino Mega board pins.

![STEERING_DRIVER_connections](_figures/vehicle-steering-23_STEERING_DRIVER_connections.png)

The following figure snapshots the underside (copper side) of the manufactured PCB board. 

![pcbdriver-1](_figures/vehicle-steering-24-pcbdriver-1.jpg)

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
| #2 | Black iron metal sheet 1000x2000x2mm  | [2mm metal sheet](https://www.e-metalshop.gr/sidera/lamarynes/lamarina-sidhroy-mayrh-1000x2000x2mm) | [QOOP Metalworks](https://www.qoop.gr)  | 0.25 | 50 | 13 | - |


| #4 | 8 Bolt 5mm X 30mm | [Bolt 12mm X 50mm ](https://www.vida.gr/exagones-vides-olopasses-m8-galvanize-metrikes-din-933/) | [Vida](https://www.vida.gr) | 4 | 0.7 | 2.8 | - |

| #5 | 30 Nuts pack 12mm | [Nuts 12mm](https://www.flextools.gr/index.php?route=product/product&path=260&product_id=1077) | [flextools](https://www.flextools.gr) | 1 | 1.5 | 1.5 | - |


| No. |  Product | Product URL | Supplier | Used Quantity | VAT Price (€) | Subtotal (€)  | Note |
|----|--------------|------------|-----|---|---|---|---|
| #1 | Copper board |      [PCB board](https://grobotronics.com/prototyping-copper-board-420x297mm-2-layer.html)   | [GRobotronics](https://grobotronics.com/)    |    0.25  | 9.90 | 2.48 | Shared Resource |
| #2 | H-Bridge Brushed DC Motor Driver | [Motor Driver](https://www.cableworks.gr/ilektronika/arduino-and-microcontrollers/motors/drivers/drv8871-h-bridge-brushed-dc-motor-driver-breakout-board-for-arduino/) | [cableworks](https://www.cableworks.gr) | 2 | 6 | 12 | - |
| #3 | Linear Potentiometer B10K Ohm | [Metal potentiometer](https://www.hellasdigital.gr/electronics/components/potentiometer/rotary-potentiometer-10k-ohm-linear-com-09939/) | [hellasdigital](https://www.hellasdigital.gr) | 2 | 1.24 | 2.48 | - |
| #4 | ACS712 5A Range Hall Current Sensor Module | [5A Current sensor](https://www.aliexpress.com/item/32348760733.html) | [alli express](https://www.aliexpress.com) | 2 | 1.10 | 2.20 | - |
| #5 |6-wire ribbon cable 120mm  | [Ribbon cable 28AWG](https://grobotronics.com/ribbon-cable-28awg-0.081mm2-20-wire.html)   | [GRobotronics](https://grobotronics.com/) | 0.25  | 1.00 | 0.3| Shared Resource |
| #6 | 3 wire cable 350 mm connecting the potentiometers | [3wire cable](https://www.hellasdigital.gr/computers/cables/sound-cables/roline-3-5mm-audio-cable-m-m-2m-11-09-4502/) | [Hellas Digital](https://www.hellasdigital.gr) | 1 | 2.6 | 2.6 | - |
| #7 | 6-pin header female  | [Female Pin Header Kit](https://www.nettop.gr/index.php?option=com_virtuemart&view=productdetails&virtuemart_product_id=1592)   | [Nettop](https://www.nettop.gr/)  | 1  | 0.00 | 0.00 | Shared Resource |
| #8 | 3-pin header female  | [Female Pin Header Kit](https://www.nettop.gr/index.php?option=com_virtuemart&view=productdetails&virtuemart_product_id=1592)   | [Nettop](https://www.nettop.gr/)  | 1  | 0.00 | 0.00 | Shared Resource |
| #9 | 3-pin header male  | [Male Pin Header Kit](https://www.nettop.gr/index.php?option=com_virtuemart&view=productdetails&virtuemart_product_id=1592)   | [Nettop](https://www.nettop.gr/)  | 1  | 0.00 | 0.00 | Shared Resource |
| #10 | 3-pin header male  | [Male Pin Header Kit](https://www.nettop.gr/index.php?option=com_virtuemart&view=productdetails&virtuemart_product_id=1592)   | [Nettop](https://www.nettop.gr/)  | 1  | 0.00 | 0.00 | Shared Resource |


| **Total** |      |    |     |      |     |  **50.5**  | | 

</div>

The total cost to manufacture the Agrofelis steering driver shield excluding shipping, and assembly charges, sums to approximately **50.5** euros.

 
 




## Steering structural components


## Software 



