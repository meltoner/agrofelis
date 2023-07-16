# Agrofelis

Energy dense, multipurpuse agile agricultural robot design plans and system source code repository. www.agrofelis.com

![Robotic Vehicle](introduction/figures/figureA.jpg)

## The Problem 

The declining demographics in the West, economic disparity, energy cost inflation, supply chain disruptions and climate change have created a dangerous mix of factors for the world and particular for Agriculture and Public Safety.  

Farmers are having increasing difficulties finding seasonal farm workers while also having to deal with considerable increases on the cultivation cost, which results in marginal profits, unpicked produce even to abandoned farms. The need of increasing a farm worker’s productivity with an affordable platform that is between a Tractor and Handheld tools is essential for small farmers in order to maintain existing plant capital. 

The probability of fires and floods has increased considerably. Fire Services face more frequent fires, the need of an affordable vehicle that can serve in an intergrated role with firefighting units in non-urban environments that reduces the work load and reduces the risk of exposure to heat due to proximity to the fire front can also become essential. 

The above problems in agriculture and public safety both need a Base Vehicle that is low cost, has a small footprint, is energy dense and agile and can be manufactured at a local machine shop in small volumes or even in single units. The robotic vehicle system that is proposed, prototyped and open sourced, aims to offer an answer to those needs for the variety of applications in those fields.

## The Chosen Technology 

The majority of technical solutions proposed for agricultural robotic systems aim at high level of autonomy through the use of satellite positioning systems like RTK GNSS , Cameras and LIDAR sensors for achieving Simultaneous Localisation And Mapping (SLAM), and supplementary systems like Radars Odometers and Inertial Systems.   

In the case of RTK GNSS signal interruption due to foliage, weather or lack of ground stations makes it of limited use and in the case of LIDAR that can be combined with Odometers Cameras and IMUs add a considerable cost to the system that makes sense only for bigger heavier vehicles. On top of that repairing a vehicle of high technological complexity can be a challenge for the average person across the world.

The purpose here is to offer a technology accesible to a farmer or a volunteer fire fighter. A remote control system with the ability of automating certain functions can offer a cheaper alternative suitable for smaller platforms , offering a considerably cheaper increase in productivity. Also the availability of electrical components like motors and LiFePO4 batteries offer a simpler solution. 

## The Potential

The technologies that could be incorporated on an Agricultural Vehicle could include implements such as 
- Grass Cutter/lawn mower a frequent and necessary application in Orchards 
- Turbine Sprayers usefull both in orchards and veggetable cultivations for either pesticide or water soluble fertilizer
- Fog Sprayers for greater reach in dense folliage and also antifreeze protection with glycerin oil   
- Fertilizer Casting, a copious job that must be done in both orchards and vegetables 
- Sensor Suite for Plant disease diagnosis 
- Robotic Picking Arm Base & Power Hub, for low cultivations and also Green houses  
- Tethered Drone Base & Power Hub, fruit picking for trees (see Tevel as an example)

The technologies that could be incorporated on an Public Safety Vehicle could include applications like 
- Fire fighting Gear Carrier 
- Water Cannon Base
- Tethered Drone Base & Power Hub, for Surveilance and Communications in large area fires
- Sensor Suite for patrolling and surveilance 

The potential of having the ability to produce an open soursed Base Robotic Vehicle for a variety of applications and tools offers significant versatility.

## The Project 

The Chassis of the vehicle should be designed according to the specifications of the job at hand, carrying capacity, choise of suspension and wheels, and 
of course size is expected to vary, so the project doesn't focus on the chassis since it is assumed that there will be different designs rather it is the open source programmable system that can migrate in various mechanical platforms either for motion control or for implement control while having programmable capability for automation and retaining the possibility for precision applications that is the core. 

The chassis implemented for the project is an iron bar welded chassis with detachable components, which is capable of carrying 250 kilos of payload with 
no suspension for cost reduction. A four wheel drive system is employed with energy efficient in-hub motors that are dynamically controlled using feadback sensors in real time. The steering system is composed of two independent linear actuators driven with mechanical and energy monitoring sensors.

The power system has energy autonomy of 8.8 Kwh and fits within an 1 sqm.  It is composed of 8 element LiFePO4 batteries of 320 amps, paired with an intelligent Battery Management System at 300 Amp max discharge rate capacity and a data link enabling the utilization of energy related indicators. 

The processing elements of the system are modularised systems composed of Arduino or ESP32 modules connected with their relevant sensors and actuators acting on real time adaptations while being orchestrated via a Jetson Nano GPU running on Linux and using the ROS2 protocols and implementation for interconnecting existing and future components. A high speed camera connected to the Jetso Nano enables the vision modality that is supported by a Coral AI accelerator, enabling machine vision tasks on edge. A high throughput disk (250 MB/s read/write) equips the system with 128GB of storage, enabling the robot to record and recall a sufficient amount of offline and online data. 

## The Technical Stuff

A) The Motors Hub ADAC

This sub-module of the Motors Hub Driver allows to interface 5v sensors with ESP32, operating at 3.3v. By doing so, it expands the number of channels the ESP32 can handle. Using this submodule the two current sensors and the six hall sensors of the two motors can be interfaced. It consists of the following components:

1) One MCP3008 8-channel 10 bit ADC
2) One 4-channel I2C-safe Bi-directional Logic Level Converter between 5V and 3.3V.
3) One Seven pin ribbon cable for connecting with the ADAC module.
4) One four pin male header
5) One six pin female header
6) One four pin male header for connecting with the Agrofelis controller
7) One 8 pin female header
8) Two 7 cm wire cables connecting the ADAC with the current sensors of the Motor Power driver

The 1st and 2nd channel of the MPC3004 ADAC are connected to the current sensors of the power module.
The remaining 3rd, 4th and 5th channels of the ADAC are connected to the hall sensors of the motor following the yellow, green, blue connection and so on. The ground of the hall sensors is connected to the ground of the Motors hub ADAC module. The one ping from the 8 pin female header was trimmed off.

The module establishes the means of individual and synchronised motion of motors. Moreover, the module meets the needs for micro-controlling mechanisms necessary in precision farming. It also includes safety mechanisms with dynamic protection of various system components based on sensing excessive current or temperature to alert and cut off the power.


B) The Motors Hub controller 

This sub-module of the Motors Hub Driver integrates all components of the overall module. The controller decomposes the functionality of processing the signals, of broadcasting the sensors impulses and for controlling the actuators via wireless means. The module digitally drives the two motor hubs via an ESP32 and reads and intercepts the hall sensors of the analog drivers using the ADAC module. The module senses the current drawn by the motors, reads the individual temperature of the analog drivers and controls the power and spin direction of the motors. It consists of the following components:

1. A PCB board, with its schematics located within PCB.CNC.controller\ folder.
2. The PCB top side printed cover located within PCB.PRINT.Stickers.
3. One ESP32 with 38 pins.
4. Two twenty pin female headers.
5. One two pin female header.
6. One four pin female header.
7. One 2 pin JST male connector for the 5v supply.
8. One 3 pin JST male and female connector used to connect two temperature sensors via the one wire protocol.
9. Two Green 5 mm Screw terminal PCB Connector, one for the speed link of both motors and one for the 12v input.
10. Two five wire ribbon cable 7 cm, used to connect the power modules.
11. Two five ping female headers used to connect the power modules at the end of ribbon cable.
12. One three wire ribbon cable 7 cm, used to connect the temperature sensors.
13. Two temperature sensors DS18B20 connected via one wire.
14. Pieces of wire for the implementing the PCB bridges as indicated by the yellow colour in the PCB.PRINT.Stickers schematic.
15. A case cooler 8 cm LogiLink FAN101 at 12V
16. Two Agrofelis Motor Hub Power Drivers and the Agrofelis Motors hub ADAC module.
17. Non mandatory connectors, two 2 pin terminal, high current red & black wire, male & female connectors to power the analog motor drivers.

C) The Motors Hub Power Driver 

This sub-module is used twice, within the Motors hub driver module. It consists of the following components:

1.	A PCB board, with its schematics located within PCB.CNC.power\ folder.
2.	The PCB top side printed cover located within PCB.PRINT.Stickers.
3.	Two relays trigger/able with 3v [HK4100F-DC 3V SHG Relay 6Pin]
4.	One car relay, trigger/able with 12v with 20 amp capacity [6770718 - 12v 20A].
5.	An [ACS712] 20 amp current Sensor.
6.	One 5 pin male header.
7.	A JST-SM 2pin connector, connecting with the motor driver reverse function.
8.	One small wire for connecting the PCB with the 20 amp relay.
9.	3 pin headers for connecting the PCB with the 20 amp relay.
10.	4 cm high current wire.
11.	Female high current connector.

The system, in addition to its wire-full infrastructure, supports bluetooth connectivity for closeby wireless attachments, WiFi for nearby controllers, mobile phones and / or modules, as well as a 2km digital wireless transceiver. A long range digital remote control / transceiver is also developed powered by an ESP32, a TFT monitor, joysticks and a lipo rechargeable battery. 

Additional sensors employed by the system include GPS, accelerometer, compass, temperature, distance, current, voltage, sensors as well as servos, stepper drivers and power modules. An underlying IOT service allows the deployment of new firmware for the system’s individual components and its behavioral functions, access to its real time and recorded data.

