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

The purpose of this module is to design a reusable module that can be installed in the front or / and in the back of the robot to provide total coverage of the robot's surroundings. Even though the module is not necessary to operate the Agrofelis robot, the module renders it capable to to navigate through the world and perform autonomous functions, adapt its motors dynamic ranges better due to the slope information as well get access additional localization. Because the prototype module employs a terminal shield, extending the module to use also a CO2, or humidity or other sensors for example, requires no change to its foundations. Although the selected Lidar's internals are enclosed within a dust and water proof enclosure, further work should extend the prototype to provide additional structural protection to its elements.

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

![electronics](_figures/vehicle-lidar-14-electronics.jpg)
![front-view](_figures/vehicle-lidar-15-front-view.jpg)
![with-rotating-implement](_figures/vehicle-lidar-16-with-rotating-implement.png)
![actual-front-view](_figures/vehicle-lidar-17-actual-front-view.jpg)
![front-view-closeup](_figures/vehicle-lidar-18-front-view-closeup.jpg)
![rshiny-app](_figures/vehicle-lidar-19-rshiny-app.jpg)
![data](_figures/vehicle-lidar-20-data.jpg)
![actual-side-view-cables](_figures/vehicle-lidar-21-actual-side-view-cables.jpg)


https://www.hellasdigital.gr/electronics/sensors/gyro-acceleration-magnetic/mpu-9250-9dof-9-axis-altitudegyroacceleratormagnetometer-spi-iic/
https://www.aliexpress.com/item/1005003788925347.html?spm=a2g0o.order_list.order_list_main.73.706c1802bV0ipB
https://www.aliexpress.com/item/1005001635722164.html?spm=a2g0o.order_list.order_list_main.103.706c1802bV0ipB
https://www.aliexpress.com/item/1005001636295529.html?spm=a2g0o.order_list.order_list_main.107.39cc1802TzNeML
https://nem.gr/RDS3518-Servo-Robot-DIY-Digital-Metal-Gear-Brushed-Arduino
