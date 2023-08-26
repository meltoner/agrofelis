# Agrofelis robot

Energy dense, multipurpose agile agricultural robot design plans and system source code repository. www.agrofelis.com

![Robotic Vehicle](introduction/figures/figureA.jpg)

## The Problem 

The declining demographics in the West, economic disparity, energy cost inflation, supply chain disruptions and climate change have created a dangerous mix of factors for the world and particular for Agriculture and Public Safety.  

Farmers are having increasing difficulties finding seasonal farm workers while also having to deal with considerable increases on the cultivation cost, which results in marginal profits, unpicked produce even to abandoned farms. The need of increasing a farm worker's productivity with an affordable platform that is between a Tractor and Handheld tools is essential for small farmers in order to maintain existing plant capital. 

Climate change though has also increased the probability of fires and floods. Fire Services face more frequent fires, the need of an affordable vehicle that can serve in an integrated role with firefighting units in non-urban environments that reduces the work load and offers standoff safety from heat exposure is also essential. 

Existing vehicles in the market that could serve as a platform for various tools are too expensive or just not available. The ability to manufacture a low cost Base Vehicle at a local machine shop in single units or small volumes that has a small footprint is energy dense and agile can address local problems in agriculture and public safety. The robotic vehicle system that is proposed, prototyped and open sourced, aims to offer an answer to those needs for the variety of applications in those fields and could be utilized by individual farmers, farmers Coops, fire departments, municipalities etc.

## The Technology Considerations

The majority of technical solutions proposed for agricultural robotic systems aim at high level of autonomy through the use of satellite positioning systems like RTK GNSS, Cameras and LIDAR sensors for achieving Simultaneous Localisation And Mapping (SLAM), and supplementary systems like Radars Odometers and Inertial Systems.  

In the case of RTK GNSS signal interruption due to foliage, weather or lack of ground stations makes it of limited use. However LIDAR that can be combined with Odometers Cameras and IMUs has a considerably lower cost and potential robustness. On top of that repairing a vehicle of high technological complexity can be a challenge for the average user across the world. The choice of LiFePO4 batteries offers endurance in high temperatures, incombustibility, nontoxic
materials, they can work unevenly charged and have a slow rate of self dishcharge.

The purpose here is to offer a technology accessible to non highly technical users like a farmer or a volunteer fire fighter. A remote control system with the ability of automating certain functions through recording and replaying can offer a cheaper alternative suitable for smaller platforms, while having a wider applicability and offering a considerably cheaper increase in productivity.

## The Potential

The technologies that could be incorporated on an Agricultural Vehicle could include implements such as:
- Grass Cutter/lawn mower a frequent and necessary application in Orchards
- Turbine Sprayers useful both in orchards and vegetable cultivation for either pesticide or water soluble fertilizer
- Fog Sprayers for greater reach in dense foliage and also antifreeze protection with glycerin oil
- Fertilizer Casting, a copious job that must be done in both orchards and vegetables
- Sensor Suite for Plant Data collection , e.g. Plant disease diagnosis
- Mechanical , Laser or Microwave weed killing platform 
- Robotic Picking Arm Base & Power Hub, for low plant cultivation and also Green houses
- Power Hub, fruit picking for trees (see Tevel)
 
The technologies that could be incorporated on a Public Safety Vehicle could include applications like:
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

In the following sections, the detailed documentation of all developed modules constituting the Agrofelis robot, are referenced along with their abstracts and figures highlights, are being overviewed. The documents present the rational of each module, how they are decomposed into sub parts and sub-components, how to reproduce them by following step wise procedures using schematics and photos taken during their fabrication. The documents moreover provide indicative supliers and total cost estimations.

## Agrofelis chassis frame design and fabrication

The [chassis frame design and fabrication document](components/vehicle-frame) focuses on the manufacturing details of the vehicle's frame. The frame houses and protects the 8kw power module with its LiFePO4 batteries, the electronics, the sensors and actuators of the unmanned vehicle. The frame was implemented using a total of 7.35 meters of 20X20 mm regular square iron bars, it establishes key placeholders for mounting the detachable wheels, the protective covers and via its grid-like attachment points enables mounting anticipated tools, as well as future ones. The primary design considerations were footprint minimization, battery compartment protection, chassis rigidity, and ease of manufacture utilizing low-budget tools and readily available materials. 

The complete documentation of the Agrofelis chassis frame is provided bellow.

- [Chassis frame design and fabrication](components/mobility/motors_hub_driver)

An indicative selection of figures from the Agrofelis chassis frame design and fabrication document, is summarised by the following  figure. 


![Agrofelis chassis frame design and fabrication figures highlights](components/vehicle-frame/_figures/highlights_vehicle-frame.jpg)



## Agrofelis robot wheels fabrication

This [Agrofelis robot wheels fabrication document] describes the details of manufacturing the active 4 wheel drive system equipping the Agrofelis robotic vehicle. The  requirements specifications set are being documented followed with the end fabricated solution. The design plans, compilation procedures, assistive assets and photographs taken during the development, are being presented following a stepwise progression. The sub components composing four Agrofelis wheels are being indexed along with their unit price, their total cost along with references to indicative suppliers.

The complete documentation of the Agrofelis robot wheels fabrication, is refernced bellow.

- [Chassis frame design and fabrication](components/mobility/motors_hub_driver)

A figure listing the four most representative figures from the document is summarised below.

![Agrofelis Robot wheels fabrication figures highlights](components/vehicle-wheels/_figures/highlights_vehicle-wheels.jpg)


## Agrofelis Motors hub driver

This [Motors hub driver document](components/mobility/motors_hub_driver) delves into the manufacturing and functional intricacies of a composite module tailored for controlling and sensing a pair of in-wheel motor hubs digitally, over the air. The documentation decomposes the different elements involved into sub-modules, into their sub elements in an organized and progressive manner. A detailed exposition of each component's rationale and its seamless integration with counterparts is provided, bolstered by design plans and photographic evidence of the actual implementation. The document offers a roadmap through the Agrofelis repository, elucidating the source file locations and the production processes underpinning the manufacturing of the Agrofelis Motors Hub Driver. The document presents the structural elements of the unit, the three type of PCB sub-components, the software running on the micro-controller, key tools employed in the manufacturing process and ends with a compendium of indicative suppliers to purchase the different parts.

The complete documentation for the motors hub driver module is provided below.

- [Motors hub driver document](components/mobility/motors_hub_driver)

In a nutshell, the *Motors Hub Driver module* goes over the electronic sub-modules, which include the motors hub controller, power, and ADAC modules. The motors hub controller module processes signals, wirelessly controls actuators, and manages motor hubs through ESP32. It reads analog driver hall sensors via an ADAC module, senses motor conditions, and regulates power, speed, and direction.
The motors hub power module handle motor hub drivers, incorporating relays, current sensors, and logic level converters, while the motors hub ADAC module facilitates sensor interfacing and uses external ADC for analog channel expansion.

A representative depiction of the progression in crafting the motor hub driver is showcased by the following highlights figure.

![Agrofelis motors hub driver figures highlights](components/mobility/motors_hub_driver/_figures/hghlights_motors_hub_driver.jpg)
