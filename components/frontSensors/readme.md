 # 3D Lidar front sensors design and fabrication

 # Abstract

 The document presents the front sensors module, used primarily for implementing a 3d Lidar mount on the Agrofelis robot enabling it to become aware of its surroundings. The fabrication process evaluated the benefits and downsides of minimizing the supportive equipment needed to build the module, by relying on a cheep and readily available PCB shield for the ESP32. To our surprise, the approach lead to a working prototype, that among other provides the flexibility to mount additional sensors such as a GPS an MPU, or other sensor without having to perform any foundational changes to the module. Although some extra physical space had to be reserved, that was well within the footprint specifications set for the module. The module was fabricated during the summer holidays were access to tools and machines were very confined, testing among others the difficulty of the fabrication. The module is composed of an ESP32, a ESP32 shield exposing the GPIO pins, a servo and a Lidar. The ESP32's main role is to digest the Lidar serial data, keep the desired information and publish the data via the USB bus. The module tilts the 2D Lidar capturing multiple 360 degree distance planes, accumulating a spherical 3d view of its surroundings. The rational of the module, its schematics, manufacturing steps, the software controlling the module and reflecting its information, as well as a Lidar data analysis tool developed, are presented. The document closes with the list of concluded components and indicative suppliers, assisting the repeatability of the module. 


 # Introduction

 Being able to sense the surroundings of a robot enables a profound range of functionalities that can be established. Apart of being able to generate detailed 3d maps of the world, your trajectory and position in them, can serve as a copilot preventing movements that would lead to a collision or adapt them such that there is none. Being able moreover to construct 3d maps of the world the trajectory of the vehicle, enables to perform precise movements as well as opens the possibility of recording and replaying a particular work performed on the field. The 3d maps generated can be indexed by GPS coordinates or compared against known maps. A gyroscope can moreover be used to derive absolute reference of the slope of the ground and the tilt of the Lidar. The implementation focused on establishing the design and structure of the module and the  the most unknown factor, how to utilize the Lidar information from an ESP32 that could also facilitate to multiple other sensors. Although we didn't have time to establish both a GPS and an MPU in the module, we present photographic material and their intended locations in the design as well as provide references on other owned open source repository where an MPU and a GPS were implemented for a small scale remote control car, performed as a feasibility trial in early stages of the project. In the following sections the Agrofelis front sensors 3D Lidar module fabrication is documented.


## Front Sensors module

The purpose of this sub project was to design a reusable module that could be installed in the front or / and the back of the robot. The module should be able to perform 3D scans of its front sight using a servo and a 2D Ldar, be able provide some protection to a camera, be able to track the absolute rotational position of the vehicle as well as allow to establish a GPS sensor with open view to the sky. Although the module is not mandatory to operate the Agrofelis robot, the module opens up a wide range of functionalities that can be developed. 






 