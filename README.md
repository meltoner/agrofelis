# Agrofelis

Energy dense, multipurpose agile agricultural robot design plans and system source code repository. www.agrofelis.com

![Robotic Vehicle](introduction/figures/figureA.jpg)

## The Problem 

The declining demographics in the West, economic disparity, energy cost inflation, supply chain disruptions and climate change have created a dangerous mix of factors for the world and particular for Agriculture and Public Safety.  

Farmers are having increasing difficulties finding seasonal farm workers while also having to deal with considerable increases on the cultivation cost, which results in marginal profits, unpicked produce even to abandoned farms. The need of increasing a farm worker's productivity with an affordable platform that is between a Tractor and Handheld tools is essential for small farmers in order to maintain existing plant capital. 

The probability of fires and floods has increased considerably. Fire Services face more frequent fires, the need of an affordable vehicle that can serve in an integrated role with firefighting units in non-urban environments that reduces the work load and offers standoff safety from heat exposure is also essential. 

Existing vehicles in the market that could serve as a platform for various tools are too expensive or just not available. The ability to manufacture a low cost Base Vehicle at a local machine shop in single units or small volumes that has a small footprint is energy dense and agile can address local problems in agriculture and public safety. The robotic vehicle system that is proposed, prototyped and open sourced, aims to offer an answer to those needs for the variety of applications in those fields and could be utilized by individual farmers, farmers Coops, fire departments, municipalities etc.

## The Technology Considerations

The majority of technical solutions proposed for agricultural robotic systems aim at high level of autonomy through the use of satellite positioning systems like RTK GNSS , Cameras and LIDAR sensors for achieving Simultaneous Localisation And Mapping (SLAM), and supplementary systems like Radars Odometers and Inertial Systems.  

In the case of RTK GNSS signal interruption due to foliage, weather or lack of ground stations makes it of limited use. However LIDAR that can be combined with Odometers Cameras and IMUs has a considerably lower cost and potential robustness. On top of that repairing a vehicle of high technological complexity can be a challenge for the average user across the world. The choise of LiFePO4 batteries offers endurance in high temperatures , incombustibility , nontoxic
materials , they can work unevenly charged and have a slow rate of self dishcharge.

The purpose here is to offer a technology accessible to non highly technical users like a farmer or a volunteer fire fighter. A remote control system with the ability of automating certain functions through recording and replaying can offer a cheaper alternative suitable for smaller platforms , while having a wider applicability and offering a considerably cheaper increase in productivity.

## The Potential

The technologies that could be incorporated on an Agricultural Vehicle could include implements such as :
- Grass Cutter/lawn mower a frequent and necessary application in Orchards
- Turbine Sprayers useful both in orchards and vegetable cultivation for either pesticide or water soluble fertilizer
- Fog Sprayers for greater reach in dense foliage and also antifreeze protection with glycerin oil
- Fertilizer Casting, a copious job that must be done in both orchards and vegetables
- Sensor Suite for Plant disease diagnosis
- Robotic Picking Arm Base & Power Hub, for low cultivation and also Green houses
- Power Hub, fruit picking for trees (see Tevel)
 
The technologies that could be incorporated on an Public Safety Vehicle could include applications like :
- Fire fighting Gear Carrier
- Standoff Water Cannon Base
- Tethered Drone Base for situational awareness (see Elistair)
- Sensor Suite for patrolling and surveillance

The potential of having the ability to produce an open sourced Base Robotic Vehicle for a variety of applications and tools offers significant versatility.

## The Project 

The Chassis of the vehicle should be designed according to the specifications of the job at hand, carrying capacity, choice of suspension and wheels, and 
of course size is expected to vary, so the project proposes the particular chassis as a baseline since it is assumed that there will be different designs. The Project core is the open source programmable system that can migrate in various mechanical platforms either for motion control or for implement control while having programmable capability for automation and retaining the capability for precision applications and AI readiness. 

The chassis implemented for the project is an iron bar welded chassis with detachable components, with a maximum carrying capacity of 250 kilos of payload with no suspension for cost reduction. A four wheel drive system is employed with energy efficient in-hub motors that are dynamically controlled using feedback sensors in real time. The steering system is composed of two independent linear actuators driven with mechanical and energy monitoring sensors.

The power system has energy autonomy of 8.8 Kwh and fits within an 1 sqm.  It is composed of 8 element LiFePO4 batteries of 320 amps, paired with an intelligent Battery Management System at 300 Amp max discharge rate capacity and a data link enabling the utilization of energy related indicators. 

The processing elements of the system are modularised systems composed of Arduino or ESP32 modules connected with their relevant sensors and actuators acting on real time adaptations while being orchestrated via a Jetson Nano GPU running on Linux and using the ROS2 protocols and Web Sockets allowing implementation for interconnecting existing and future components. A high speed camera connected to the Jetso Nano enables the vision modality that is supported by a Coral AI accelerator, enabling machine vision tasks on edge. A high throughput disk (250 MB/s read/write) equips the system with 128GB of storage, enabling the robot to record and recall a sufficient amount of offline and online data. 

The Project implements moreover a two degrees of freedom actuator rotating base, for attaching a thermal pulse jet fogger, attached on top of the robotic vehicle.

The system, in addition to its wire-full infrastructure, supports Bluetooth connectivity for closeby wireless attachments, WiFi for nearby controllers, mobile phones and / or modules, as well as a 2km digital wireless transceiver. A long range digital remote control / transceiver is also developed powered by an ESP32, a TFT monitor, joysticks and a lipo rechargeable battery. 

Additional sensors employed by the system include GPS, accelerator, compass, temperature, distance, current, voltage, sensors as well as servos, stepper drivers and power modules. An underlying IOT service allows the deployment of new firmware for the system's individual components and its behavioral functions, access to its real time and recorded data.

# Documentation

## Motors hub driver

This [Motors hub driver document](components/mobility/motors_hub_driver), presents the details of manufacturing a composite module for controlling and sensing a pair of in-wheel motor hubs digitally, over the air. The documentation decomposes the different elements involved into sub-modules, into their sub elements in an organized and progressive manner. The rational of each component and its integration with its counterparts is elaborated. Details of the design plans followed by photos of the actual implementation are provided. The locations of the source files in the Agrofelis repository, as well as how these were produced to manufacture the Agrofelis Motors hub driver, are presented. The document presents the structural elements of the unit, the three type of PCB sub-components, the software running on the micro-controller, key tools employed in the manufacturing process and ends with indicative suppliers to purchase the different parts. 

- [Motors hub driver document](components/mobility/motors_hub_driver)
