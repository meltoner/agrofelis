# 3D Lidar Front Sensors Design and Fabrication

# Abstract

This document details the creation of the front sensors module, which is used to install a 3D Lidar mount on the Agrofelis robot, enabling it to have spatial awareness of its surroundings. The module comprises an ESP32, an ESP32 Terminal Adapter, a Servo, a Lidar, an MPU and a GPS sensor. The ESP32's primary role is to process Lidar serial data, gather motion sensor and GPS data and pass their information over the USB bus. The module facilitates the tilting of the 2D Lidar to capture multiple planes of 360-degree coverage , effectively creating a spherical 3D view of its surroundings. The rationale behind the module, its schematics, the manufacturing process, the software controlling the module and reflecting its information, as well as a Lidar data analysis tool developed, are all discussed. The document concludes with a list of the components used and indicative suppliers, aiding in the replication of the module.

# Introduction

Equipping a robot with the ability to sense its surroundings enables a profound range of functionalities. Apart from being able to generate detailed 3D maps of the world, perform localization and determine the trajectory of the vehicle, it can also serve as a copilot, preventing movements that would lead to a collision or adjusting robot movements to avoid them. Furthermore, the ability to create 3D maps of the world, record all controlled data and the trajectory of the vehicle, establishes the capability for automation via recording and replaying sequences of moves performed in the field.

The generated 3D maps can be indexed and recalled based on GPS truncated coordinates, compared to known maps, or set by the user. The motion processing unit (MPU) is attached directly beneath the Lidar and tilts with it. Its data can be used to derive the absolute orientation of the vehicle and the true point cloud when navigating on an uneven terrain.

The following figure depicts how different tilting azimouths and the internal polar rotation of the Lidar translate to x, y, and z coordinates.

![planes](_figures/vehicle-lidar-00-planes.jpg)

In the subsequent sections, the Agrofelis front sensors 3D Lidar module design and fabrication is documented.


## Front Sensors Module

The purpose of this module is to create a reusable module that can be installed on the front and/or back of the robot to provide complete coverage of its surroundings. Although the module is not neccessary for the operation of the Agrofelis robot, it renders it capable to navigate through the world and perform autonomous functions, as well as adapt its motor's dynamic ranges efficiently due to the additional data modalities that can be utilised. The module's prototype utilizes a terminal shield, making it easy to extend its functionality with other sensors like CO2 or humidity sensors without altering its core structure. Although the selected Lidar's internals are already enclosed in a dust and waterproof casing, further work could focus on extending the prototype to provide additional structural protection.

The following figure depicts an overview of the vehicle with the relevant module installed on the front side. 
 
![lidar overview](_figures/vehicle-lidar-01-lidar-overview.png)

To construct this module, a plate is attached to the frame cover's sockets using long bolts with nuts adjusting its height and securing the frame covers. Within the enclosure formed by the two iron plates, the electronics and power/data connection socket are established. On the top side of the plate, a GPS antenna is installed, along with a servo actuator positioned in the middle. A 70mm x 70mm piece of plywood is affixed to the top bracket of the servo. On top side of the plywood plate, the MPU (gyroscope and magnetometer) is installed. Finally, the Lidar is attached on top of the MPU using PCB standoffs and the plate is secured to the servo bracket. 

## Schematics and Fabrication

In this section, the schematics of the module along with photographs taken during the fabrication process are provided.

The following figure encodes the key dimensions of the module.

![lidar dimensions](_figures/vehicle-lidar-02-lidar-dimensions.png)

The consequent diagram enumerates the module's components using an exploded view. 

![lidar exploded view](_figures/vehicle-lidar-03-lidar-exploded-view.png)

The numbered components correspond to the following items:

1. LD19 Lidar Scanner 360° TOF 12m
2. MPU 9250
3. Plywood Plate
4. Servo RDS3218 20KG 270 Degree
5. GY-NEO6MV2 GPS Module Antenna
6. Iron Sheet (2mm)
7. Data Socket
8. 5V Power Socket
9. ESP32 with 38PIN Terminal Adapter Shield
10. GY-NEO6MV2 GPS PCB

The following photo showcases a piece of iron plate, near the designed dimensions with four drilled holes matching the sockets layout of the related cover of the Agrofelis robot. 

![plate](_figures/vehicle-lidar-04-plate.jpg)

In the middle of the plate, four holes following the servo's bracket layout are drilled and the servo's longer bracket is assembled using four bolts and nuts, as illustrated in the following image.

![servo-mount](_figures/vehicle-lidar-05-servo-mount.jpg)

The servo is then mounted on the installed bracket, as shown by the next photograph.

![servo](_figures/vehicle-lidar-06-servo.jpg)

The top bracket of the servo is installed on a 70 mm X 70 mm 4 mm plywood plate, as seen in the image below.

![top-plate](_figures/vehicle-lidar-07-top-plate.jpg)

Three thin PCB standoffs are installed on the other side of the plywood plate in its middle, following the Lidar's profile holes.

![plate-standoff-pins](_figures/vehicle-lidar-08-plate-standoff-pins.jpg)

Within the PCB standoff in the middle of the plate, the MPU 9250 sensor is installed.

![mpu](_figures/vehicle-lidar-09-mpu.jpg)

The module, complete with the plate, servo, plywood plate, MPU, Lidar and connecting cable, is shown in the following photograph.

![compiled](_figures/vehicle-lidar-10-compiled.jpg)

The tilting mechanism of the Lidar via the servo and the installment of the GPS antenna can be seen in the following two images.

![tilted-front](_figures/vehicle-lidar-11-tilted-front.jpg)
![tilted-back](_figures/vehicle-lidar-12-tilted-back.jpg)

Two types of cables are fabricated in order to connect the module to the Agrofelis robot.
The first type provides 5V to power the micro-controller and the servo motor.
The second type enables data connectivity using a 3-pin ribbon cable.
This second type taps into the USB connection of the ESP32. By cutting a regular USB cable in half and omitting the 5V cable, as the module is already powered, then interfacing the ground, data A and data B cables, a high-throughput wired connection is established all the way to the back of the vehicle's USB hub, which connects to the Jetson Nano. This USB channel was found to be the most robust solution for transferring the high-frequency Lidar data without errors. The two types of cables, along with their sockets installed and grouped using a cable insulation tube, are shown in the following photo

![cables](_figures/vehicle-lidar-13-cables.jpg)

The consequent photo snapshots the fabricated underside of the prototype, illustrating the installed electronics, sensor cable, USB cable hack, sockets and the two types of cables connected to them.

![electronics](_figures/vehicle-lidar-14-electronics.jpg)

The next photo shows the fabricated top side of the prototype, presenting the tilting mechanism and the Lidar.

![front-view](_figures/vehicle-lidar-15-front-view.jpg)

The following schematic illustrates the designed module attached to the vehicle, alongside the 2 degrees of freedom rotating implement mount.
![with-rotating-implement](_figures/vehicle-lidar-16-with-rotating-implement.png)

The next photograph shows the energized fabricated module mounted on the Agrofelis Robot.

![actual-front-view](_figures/vehicle-lidar-17-actual-front-view.jpg)

A close-up view of the module attached to the vehicle is provided below.

![front-view-closeup](_figures/vehicle-lidar-18-front-view-closeup.jpg)


## Lidar Data 

In order to retrieve data from the ESP32 micro-controller, we harnessed the capabilities of the following open-source repository.

- [Lidar_LD06_for_Arduino Repository](https://github.com/henjin0/Lidar_LD06_for_Arduino)

Although this repository was initially designed to support the LD06 model, its functionality was verified for the LD19 model as well. 
The Lidar's cable was cut and connected to the Serial2 interface of ESP32 and a pulse-width modulation (PWM) capable GPIO, using the following correspondence.

![Lidar pin cable correspondence](_figures/vehicle-lidar-cable-pins.png)

The data provided by the UART interface are decoded by the library and are converted to angular degrees, distances and confidence levels. The Agrofelis software of the module transmits the first two variables in real-time batches of arcs, and less frequently the applied tilt, the three orientations, the magnetic orientation, the GPS coordinates (longitude and latitude) and the number of satellites locked on to.

The following screenshot captures a glimpse of the data being transmitted and recorded by the Unficator server, encompassing data from both the Lidar and mobility modules.

![data peek](_figures/vehicle-lidar-20-data.jpg)


## Agrofelis Front Sensors Software

The software of the module is contained within the [src folder](https://github.com/meltoner/agrofelis/tree/main/components/vehicle-lidar/src/FrontSenseA). The software is composed of a C++ application developed to reflect and control the internal state of the micro-controller via the USB serial interface.
 
This *Agrofelis Front Sensors Software* adheres to a common baseline pattern that has been established in nearly all Agrofelis modules. This baseline pattern introduces a "context" class, which is passed to practically all classes as a common ground, enabling instances to exchange information when necessary. The second baseline pattern established refers to the frequency of execution, providing the facilities to trigger specific functionalities at desired intervals. This design consideration accommodates components like the Lidar or gyroscope, which require much more frequent updates compared to components such as GPS or potentiometer sensors. As a bootstrap template, the software provides six different execution frequencies, ranging from 50 milliseconds to 5-second intervals. Using this approach, delays blocking the execution are avoided and the different calls can be organized based on their responsiveness requirements.

Furthermore, the software incorporates straightforward, concrete implementations for elements such as the servo, GPS and Lidar, resulting in a one-to-one mapping between physical hardware elements and their respective software counterparts.

The following table indexes and summarizes the implemented classes of the *Agrofelis Front Sensors Driver Software*.

| Class | Description | 
|----|------------------|
|FrontSenseA.ino | Boots the application, initialises top-level classes and encodes the triggering frequencies of various functional elements. |
|Context | Provides a common ground for sharing information and encodes the triggering frequencies, helpful functions and a unique identifier of the model.|
|Invoker | Tracks the execution frequencies so these are called at the right time. |
|SerialCommandParser | Base class for monitoring and parsing the serial interface data. The class defines the function parsing compact commands of the form &lt;1&#124;1&gt;, where the first parameter corresponds to the applicable action number and the second is an integer value used by the related action. |
| Servo | Object representing the tilt mechanism actuating a servo motor. The object can be initialised with a limited target range, as much as scan the field without exceeding the physical limits of the mechanism. The class was used with a *TIANKONGRC RDS-8120 20KG ROBOT DIGITAL SERVO*. The class can be instantiated by providing the connected GPIO, the desired range to actuate from the applicable (0-180), which is then mapped to a range of 0 to 100. |
|CommandParser | Base class for monitoring and parsing the Serial interface. The class defines the function parsing compact commands of the form &lt;1&#124;1&gt;, where the first parameter corresponds to the applicable action number and the second is an integer value used by the related action. |
| LD06forArduino.ino | See [Lidar_LD06_for_Arduino]( https://github.com/henjin0/Lidar_LD06_for_Arduino) external dependency available on GitHub. |
|FrontSensorsController| The class extends the “CommandParser”, allowing to externally control the tilt servo and the rotational speed of the Lidar. |


## Lidar Data Analysis and Visualization Software

An exploratory data analysis application was rapid prototype as a Shiny R application, facilitating the uploading and analysis of log data captured and packaged by the Unificator server. The application software parses the packages, maintains the Lidar information, extracts the tilt degree and parses the polar coordinate arcs into a data table. The parsed Lidar data are being visualised in two scalable vector graphics (SVG) graphs. The first graph reflects the data as if they were Cartesian coordinates and subsequently projects them using a polar-to-Cartesian coordinate transformation. The application offers the functionality to filter data using a sliding window of 500ms intervals (chunks) and to maintain the 80th percentile of the data, ensuring a focus on nearby surroundings. A screenshot showcasing the Shiny R application for Lidar data analysis, is provided below.

![rshiny-app](_figures/vehicle-lidar-19-rshiny-app.jpg)

The source code for the Shiny application can be accessed at the following path:

- [Shiny Lidar Analysis](src/shiny_lidar_analysis)

The application's source code comprises four files:

| File | Description | 
| ----- | --------- |
| global.R | This file loads the R packages used by the program as well as loads the “helpers.R” file. |
| helpers.R | This file implements file manipulation, Lidar data parsing and data visualisation functions. |
| ui.R | In this file, the source code defines the layout of the web interface and its input elements. |
| server.R| Responsible for initializing the server and defining the reactivity of the application. |
 

## 3D Lidar Front Sensors Components

The following table lists the individual components employed for manufacturing the Agrofelis front sensors Lidar controller. The index table includes moreover the product URLs, the indicative suppliers, as well as unit prices and total cost estimates.


<div align="center">

| No. |  Product | Product URL | Supplier | Used Quantity | VAT Price (€) | Subtotal (€)  | Note |
|----|--------------|------------|-----|---|---|---|---|
| #1 | LD06 12m Range | [Lidar](https://www.aliexpress.com/item/1005003788925347.html) | [AliExpress](https://www.aliexpress.com) | 1 | 119.45 | 119.45  | - |
| #2 | RDS3218 20KG 270 Degree | [Servo](https://nem.gr/RDS3518-Servo-Robot-DIY-Digital-Metal-Gear-Brushed-Arduino) | [NEM](https://nem.gr) |1 | 19.84 |  19.84 | - |
| #3 | MPU-9250 9DOF 9-axis | [MPU](https://www.hellasdigital.gr/electronics/sensors/gyro-acceleration-magnetic/mpu-9250-9dof-9-axis-altitudegyroacceleratormagnetometer-spi-iic/) | [Hellas Digital](https://www.hellasdigital.gr) | 1 | 10.48 | 10.48 | - | 
| #4 | NEO-6M GPS Module | [GPS](https://www.aliexpress.com/item/1005001635722164.html) | [AliExpress](https://www.aliexpress.com)  | 1 | 2.69 | 2.69 | - | 
| #5 | ESP32 38 pin | [ESP32](https://www.aliexpress.com/item/1005001636295529.html) | [AliExpress](https://www.aliexpress.com) | 1 | 3.67 | 3.67 | - | 
| #6 | ESP32 38 pin terminal adapter | [ESP32](https://www.aliexpress.com/item/1005001636295529.html) | [AliExpress](https://www.aliexpress.com) | 1 | 2.69 | 2.69 | - | 
 | **Total** |      |    |     |      |     |  **158.82**  | | 

</div>

The total cost to manufacture the Agrofelis front sensors Lidar controller, exclusive of shipping and labor cost, amounts to approximately **159** euros.


# Conclusion

The document has extensively covered the front sensors module, designed for the implementation of a 3D Lidar mount on the Agrofelis robot. The rationale of the module, its design plans and fabrication steps were documented in a progressive manner.
The Lidar data were explained and the software developed for managing the microcontroller and for analyzing the polar data were summarized. The list of the most crucial components, complete with product links, pricing information, along with indicative suppliers for acquiring them, to facilitate the reproduction of this module, were documented. A closing view of the fabricated attachment is presented below.

![actual-side-view-cables](_figures/vehicle-lidar-21-actual-side-view-cables.jpg)
