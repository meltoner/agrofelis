# Agrofelis

Open source low cost multipurpuse agricultural robot design plans and open source code repository. www.agrofelis.com

![Robotic Vehicle](introduction/figures/figureA.jpg)

## The Problem 

The declining demographics in the West, climate change, economic disparity, energy cost inflation, and supply chain disruptions have created a dangerous mix of factors for the world’s agriculture. 

Farmers are having increasing difficulties finding seasonal farm workers while also having to deal with considerable increases on the cultivation cost, which results in marginal profits, unpicked produce even to abandoned farms. In the case of Orchards the realized loss of an abandoned orchard is multifold compared to seasonal plants since an orchard needs 10+ years to reach full production capability with a break even period of 4-5 years. 

The problem is even more intense for small orchard farms of less than 5 Hectares. The need of increasing a farm worker’s productivity with a platform that is affordable and can be amortized relatively fast is essential for small farmers in order to maintain existing plant capital. The 3 basic jobs in an orchard are Grass Cutting, Spraying, Fertiliser Casting comprise 35% of the cultivation cost , the remaining 65% being fruit picking and pruning . 

A low budget, energy dense agile robotic vehicle system | is designed, fabricated, documented and open sourced, as a robust step towards addressing the identified problem.
  
## The Technology 

The majority of technical solutions proposed for agricultural robotic systems aim at high level of autonomy through the use of satellite positioning systems like RTK GNSS , Cameras and LIDAR sensors for achieving Simultaneous Localisation And Mapping (SLAM), and supplementary systems like Radars Odometers and Inertial Systems.   

In the case of RTK GNSS signal interruption due to foliage, weather or lack of ground stations makes it of limited use and in the case of LIDAR that can be combined with Odometers Cameras and IMUs add a considerable cost to the system that makes sense only for bigger heavier vehicles. On top of that repairing a vehicle of high technological complexity can be a challenge for the average farmer across the world.

A remote control system with the ability to automate certain functions can offer a cheaper alternative suitable for smaller platforms positioning such systems between handheld tools and modern tractors , offering a considerably cheaper increase in productivity  


## The Project 

The purpose of the project is to create an open source programmable remote control system that can migrate in various mechanical platforms either for motion control or for implement control while having programmable capability for automation and retaining the possibility for precision farming applications

The robotic vehicle prototype is an iron bar welded chassis with detachable components, which is capable of carrying 250 kilos of payload, has energy autonomy of 8.8 Kwh and fits within a 1 sqm. A four wheel drive system is employed with energy efficient in-hub motors that are dynamically controlled using feadback sensors in real time. The steering system is composed of two independent linear actuators driven with mechanical and energy monitoring sensors. The power system is composed of 8 element LiFePO4 batteries of 320 amps, paired with an intelligent Battery Management System at 300 Amp max discharge rate capacity and a data link enabling the utilization of energy related indicators. 

The processing elements of the system are modularised systems composed of Arduino or ESP32 modules connected with their relevant sensors and actuators acting on real time adaptations while being orchestrated via a Jetson Nano GPU running on Linux and using the ROS2 protocols and implementation for interconnecting existing and future components. A high speed camera connected to the Jetso Nano enables the vision modality that is supported by a Coral AI accelerator, enabling machine vision tasks on edge. A high throughput disk (250 MB/s read/write) equips the system with 128GB of storage, enabling the robot to record and recall a sufficient amount of offline and online data. 

The system, in addition to its wire-full infrastructure, supports bluetooth connectivity for closeby wireless attachments, WiFi for nearby controllers, mobile phones and / or modules, as well as a 2km digital wireless transceiver. A long range digital remote control / transceiver is also developed powered by an esp32, a TFT monitor, joysticks and a lipo rechargeable battery. 

Additional sensors employed by the system include GPS, accelerometer, compass, temperature, distance, current, voltage, sensors as well as servos, stepper drivers and power modules. An underlying IOT service allows the deployment of new firmware for the system’s individual components and its behavioral functions, access to its real time and recorded data.
