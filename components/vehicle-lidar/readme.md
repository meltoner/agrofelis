 # 3D Lidar front sensors design and fabrication

 # Abstract

 The document presents the front sensors module, used for implementing a 3d Lidar mount on the Agrofelis robot, enabling it to become aware of its surroundings. The module is composed of an ESP32, an ESP32 terminal adapter, a servo a Lidar, an MPU and a GPS sensor. The ESP32's main role is to process the Lidar serial data, read the motion sensor data, the GPS data and reflect their information over the USB bus. The module tilts the 2D Lidar capturing multiple 360 degree distance planes, accumulating a spherical 3D view of its surroundings. The rational of the module, its schematics, manufacturing steps, the software controlling the module and reflecting its information, as well as a Lidar data analysis tool developed, are presented. The document closes with the list of concluded components and indicative suppliers, assisting the repeatability of the module. 


 # Introduction

 Being able to sense the surroundings of a robot enables a profound range of functionalities that can be established. Apart of being able to generate detailed 3D maps of the world, perform localization and determine the trajectory of the vehicle, it can serve as a copilot preventing movements that would lead to a collision or adapt them such that there isn't. Being able moreover to construct 3D maps of the world, record all the controlled data and the trajectory of the vehicle, enables to perform precise movements as well as opens the possibility of recording and replaying a particular work performed in the field towards automating them. 

 The 3D maps generated can be either indexed and recalled based on the GPS truncated coordinates, get compared against known maps or set by the user. The motion processing unit (MPU) data, attached just right under the Lidar, tilting with it, can be used to derive the absolute orientation of the vehicle and consequently the true cloud point when moving on an uneven terrain.

The following figure visualises how different tilting (azimouth) changes and the internal rotation of the lidar (polar), translate to x, y, z coordinates. 

![planes](_figures/vehicle-lidar-00-planes.jpg)

In the consequent sections, the Agrofelis front sensors 3D Lidar module design and fabrication is documented.


## Front Sensors module

The purpose of this module is to design a reusable module that can be installed in the front or / and in the back of the robot to provide total coverage of the robot's surroundings. Even though the module is not necessary to operate the Agrofelis robot, the module renders it capable to navigate through the world and perform autonomous functions, adapt its motors dynamic ranges better due the additional data modalities that can be utilised. Because the prototype module employs a terminal shield, extending the module to use also a CO2, or humidity or other sensors for example, requires no change to its foundations. Although the selected Lidar's internals are enclosed within a dust and water proof enclosure, further work should extend the prototype to provide additional structural protection to its elements.

The following figure depicts an overview of the vehicle with the relevant module installed on its front side. 
 
![lidar overview](_figures/vehicle-lidar-01-lidar-overview.png)

A plate, attaches to the frame cover's sockets using lengthy bolts with nuts adjusting its height and securing the frame covers. On the enclosure being created by the two iron plates, the electronics and power/data connection socket are being established. on the top side of the plate, the GPS antenna is installed along with a servo actuator in its middle. A 70 mm X 70 mm piece of plywood is attached on the top bracket of the servo. On top side of the plywood plate the MPU (gyroscope, magnetometer) is installed. Finally, the Lidar is attached on top of the MPU using PCB stand offs and the plate is secured on the servo bracket. 

## Schematics and fabrication 

In this section the schematics of the module along with photographs taken during the fabrication process are provided.

The following figure encodes the key dimensions of the module.

![lidar dimensions](_figures/vehicle-lidar-02-lidar-dimensions.png)

The consequent diagram enumerates the module's components using an exploded view. 

![lidar exploded view](_figures/vehicle-lidar-03-lidar-exploded-view.png)

The numbered components, correspond to the following items :

1. LD19 Lidar Scanner 360°TOF 12m
2. MPU 9250
3. Plywood plate
4. Servo RDS3218 20KG 270 Degree
5. GY-NEO6MV2 GPS Module Antenna
6. Iron sheet 2mm
7. Data socket 
8. 5v Power socket 
9. ESP32 with 38PIN terminal adapter shield
10. GY-NEO6MV2 GPS PCB

The following photo showcases a piece of iron plate, near the designed dimensions with four drilled holes matching the sockets layout of the related cover of the Agrofelis robot. 

![plate](_figures/vehicle-lidar-04-plate.jpg)

In the middle of the plate, four holes following the servo's bracket lay out are drilled and the servo's lengthier bracket is assembled using 4 bolts and nuts as illustrated by the consequent image.

![servo-mount](_figures/vehicle-lidar-05-servo-mount.jpg)

The servo is mounted on the installed bracket as shown by the next photograph.

![servo](_figures/vehicle-lidar-06-servo.jpg)

The top bracket of the servo is installed on a 70 mm X 70 mm 4 mm plywood plate as seen by the following image.

![top-plate](_figures/vehicle-lidar-07-top-plate.jpg)

Three thin PCB stand offs are installed on the other side of the ply-wood plate in its middle, following the Lidar's profile holes. 

![plate-standoff-pins](_figures/vehicle-lidar-08-plate-standoff-pins.jpg)

Within the PCB stand off in the middle of the plate the MPU 9250 sensor is installed.

![mpu](_figures/vehicle-lidar-09-mpu.jpg)

The module with the plate, servo, plywood plate, MPU, Lidar and connecting cable are snapshot-ed by the consequent photograph.

![compiled](_figures/vehicle-lidar-10-compiled.jpg)

The tilting of the lidar via the servo, and the installment of the GPS antenna can be seen be following two images.

![tilted-front](_figures/vehicle-lidar-11-tilted-front.jpg)
![tilted-back](_figures/vehicle-lidar-12-tilted-back.jpg)

Two type of cables are fabricated in order to connect the module on the Agrofelis robot . 
The first type provides 5v energizing the micro-controller and the servo motor. 
The second type provides data connectivity using 3 pin ribbon cable. 
The second type taps into the USB connection of the esp32. By cutting in half a regular USB cable and omitting the 5v cable, as the module is already energized, and interfacing the ground, data a and data b cables, establishes a high throughput wired connection all the way to the back side of the vehicle's USB hub being connected with the Jetson Nano. The USB channel was found to be the most robust solution for transferring the high frequency Lidar data without errors. The two type of cable with their sockets installed are grouped using an cable insulation tube are showing by the following photo.

![cables](_figures/vehicle-lidar-13-cables.jpg)

The consequent photo snapshots the fabricated underside of the prototype, illustrating the installed electronics, sensor cable, USB cable hack, sockets the two type of cables connected to them.

![electronics](_figures/vehicle-lidar-14-electronics.jpg)

The next photo snapshots the fabricated top side of the prototype presenting the tilting mechanism and the Lidar.

![front-view](_figures/vehicle-lidar-15-front-view.jpg)

The following schematic illustrates the designed module attached on the vehicle along side the 2 degrees of freedom rotating implement mount.

![with-rotating-implement](_figures/vehicle-lidar-16-with-rotating-implement.png)

The next photograph shows the energized fabricated module mounted on the Agrofelis Robot.

![actual-front-view](_figures/vehicle-lidar-17-actual-front-view.jpg)

A close up view of the module attached on the vehicle is provided below.

![front-view-closeup](_figures/vehicle-lidar-18-front-view-closeup.jpg)


## Lidar data 

In order to read the data from the ESP32 micro-controller the following open source repository was utilised.

- Lidar_LD06_for_Arduino - https://github.com/henjin0/Lidar_LD06_for_Arduino

Although its reported to support the LD06 model, its functionality was verified for the LD19 as well. 
The Lidar's cable was cut and connected to the Serial2 interface of ESP32 and a pwm capable GPUIO using the following correspondence.

![Lidar pin cable correspondence](_figures/vehicle-lidar-cable-pins.png)

The data provided by the UART interface are decoded by the library and are converted to degrees, distances and confidence. The Afrofelis software of the module transmits the first two variables in real-time batches of arcs, and less frequently the applied tilt, the three orientations, the magnetic orientation, the GPS longitude, latitude and number of satellites locked on to.

The following screenshot provide a peek at the data being transmitted and recorded by the Unficator server, for the Lidar and the mobility modules.

![data peek](_figures/vehicle-lidar-20-data.jpg)

 

## Agrofelis Front sensors software 

The software of the module is contained within [src folder](https://github.com/meltoner/agrofelis/tree/main/components/vehicle-lidar/src/FrontSenseA). The software is composed of a C++ application developed to reflect and control the internal state of the micro controller over the USB serial interface. 
 
This Agrofelis Front sensors software adheres to a common baseline pattern that has been established in nearly all Agrofelis modules. This baseline establishes a context class that is passed to practically all classes as a common ground, enabling instances to exchange information when necessary. The second baseline pattern established refers to the frequency of execution, providing the facilities to trigger functionalities at the desired intervals. A idar, or a gyroscope for example, need to be triggered far more frequently than a GPS or a potentiometer sensor. As a bootstrap template, the software provides 6 different frequencies ranging from 50 milliseconds to 5 second intervals. Using this approach, delays blocking the execution are avoided and the different calls can be organized based on their responsiveness requirements.

The software encodes easy to follow concrete implementations such as Servo, GPS or Lidar, resulting in a one-to-one mapping between the physical element and its respective software counterpart.

The following table indexes and summarizes the implemented classes of the Agrofelis Front sensors driver software.

| Class | Description | 
|----|------------------|
|FrontSenseA.ino | Boots the application, initialises the top classes and encodes the triggering frequencies of various functional elements. |
|Context | Provides a common ground for sharing information and encodes the triggering frequencies, helpful functions and a unique identifier of the model.|
|Invoker | Tracks the execution frequencies so these are called at the right time. |
|SerialCommandParser | Base class for monitoring and parsing the serial interface data. The class defines the function parsing compact commands of the form &lt;1&#124;1&gt;, where the first parameter corresponds to the applicable action number and the second is an integer value used by the related action. |
| Servo | Object representing a the tilt mechanism  actuating a servo motor. The object can be initialised with a limited target range, as much as scan the field without exceeding the physical limits of the mechanism. The class was used with a *TIANKONGRC RDS-8120 20KG ROBOT DIGITAL SERVO*. The class can be instantiated by providing the connected GPIO, the desired range to actuate from the applicable (0-180), which is then mapped to a the range of 0 to 100. |
|CommandParser | Base class for monitoring and parsing the web socket interface. The class defines the function parsing compact commands of the form &lt;1&#124;1&gt;, where the first parameter corresponds to the applicable action number and the second is an integer value used by the related action. |
| LD06forArduino.ino | see Lidar_LD06_for_Arduino external dependency on github |
|FrontSensorsController| The class extends the CommandParser allowing to externally control the tilt servo and the rotational speed of the Lidar |


## Lidar data analysis and visualisation software

An exploratory data analysis application was rapid prototype as a Shinny R application allowing to upload the log data captured and packaged by Unificator server. The application software parses the packages maintains the lidar information extract the tilt degree and parses the polar coordinate arcs into a data table. The parsed lidar data are being visualised in two scalable vector graphics graphs. The first graph reflects the data as if these were cartesian coordinates and consequent projects them using the related polar to cartesian coordinates transformation. The application can filter the data as using a sliding window of 500ms intervals (chunks) as well as maintain the maintain the 80th percentile of the data to keep focusing on the closer surroundings. Find below a snapshot of analysis application.

![rshiny-app](_figures/vehicle-lidar-19-rshiny-app.jpg)

The shiny application source code can be found at the following path :

[Shiny Lidar Analysis](src/shiny_lidar_analysis)

The application source code, consists of four files :

| File | Description | 
| ----- | --------- |
| global.R | The file loads the R packages used by the program as well as loads the helpers.R file |
| helpers.R | The helper file implements file manipulation, lidar data parsing and data visualisation functions |
| ui.R | The source code define the layout of the web interface and its inputs |
| server.R| The files boots up the server and define the reactivity of the application. |
 


## Front sensor components

The following table lists the individual components employed for manufacturing the Agrofelis Front sensors Lidar controller. The index table includes moreover the product URLs, the indicative suppliers, as well as unit prices and sum totals.


<div align="center">

| No. |  Product | Product URL | Supplier | Used Quantity | VAT Price (€) | Subtotal (€)  | Note |
|----|--------------|------------|-----|---|---|---|---|
| #1 | LD06 12m Range | [Lidar](https://www.aliexpress.com/item/1005003788925347.html) | [aliexpress](https://www.aliexpress.com) | 1 | 119.45 | 119.45  | - |
| #2 | RDS3218 20KG 270 Degree | [servo](https://nem.gr/RDS3518-Servo-Robot-DIY-Digital-Metal-Gear-Brushed-Arduino) | 1 | 19.84 |  19.84 | - |
| #3 | MPU-9250 9DOF 9-axis | [MPU](https://www.hellasdigital.gr/electronics/sensors/gyro-acceleration-magnetic/mpu-9250-9dof-9-axis-altitudegyroacceleratormagnetometer-spi-iic/) | [Hellas Digital](https://www.hellasdigital.gr) | 1 | 10.48 | 10.48 | - | 
| #4 | NEO-6M GPS Module | [gps](https://www.aliexpress.com/item/1005001635722164.html) | [aliexpress](https://www.aliexpress.com)  | 1 | 2.69 | 2.69 | - | 
| #5 | ESP32 38 pin | [ESP32](https://www.aliexpress.com/item/1005001636295529.html) | [aliexpress](https://www.aliexpress.com) | 1 | 3.67 | 3.67 | - | 
| #6 | ESP32 38 pin terminal adapter | [ESP32](https://www.aliexpress.com/item/1005001636295529.html) | [aliexpress](https://www.aliexpress.com) | 1 | 2.69 | 2.69 | - | 
 | **Total** |      |    |     |      |     |  **158.82**  | | 

</div>

The total cost to manufacture the Agrofelis Front sensors Lidar controller, exclusive of shipping and labor cost, totals approximately **159** euros.


# Conclusion

The document presented the front sensors module, used for implementing a 3d Lidar mount on the Agrofelis robot. The rational of the module its design plans and fabrication steps were documented in a progressive manner.
The Lidar data were explained, the software developed for the microcontroller and for Analysing the polar data were summarized. The list of most crucial components, their product links, the price  along with indicative suppliers for acquiring them to reproduce the module were documented. A closing view of the fabricated attachment is presented below.

![actual-side-view-cables](_figures/vehicle-lidar-21-actual-side-view-cables.jpg)
