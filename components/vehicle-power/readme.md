# Agrofelis power system

# Abstract

The document presents the power related elements classifying the Agrofelis robot an energy dense solution. The choice of the batteries technology employed, their magnitude, their management, monitoring and charging systems are elaborated. The batteries arrangement, designed to minimize the vehicle footprint, their protective enclosure and their cable connectivity schematics are documented. The power distribution, the different voltages energizing the various electronics along with the protective mechanisms established are documented. The document moreover describes WIFI relays employed and adaptation applied to make them more robust. The documentation moreover list all the utilised components, their price along with indicative suppliers easening the reproducibility of the system. 

# Introduction

The power module and its sub-elements is the most expensive module of the Agrofelis robot. A staggering 8 KW battery system was chosen in view of being able to perform an 8 hour shift while on a relatively moderate energy demanding work peaking between 500 watt and 1000 watt. The latest most widely used type of batteries employed in off the grid solar panels systems were chosen, called LifePo4. The type of technology was furthermore chosen for their unusual lifespan, high discharge rate, environmental friendliness high safety, low toxicity, their stable performance at fluctuating environmental temperatures, [^LiFePOA] their thermal and chemical stability characteristics. 

A wide range of sensors were established in the Agrofelis robot enabling to monitor the total discharge rate of the system as well as power consumption of the individual components and actuators. Employing various energy feedback sensors, enables of being able to discover and intelligently drive the different elements to their most efficient range prolonging their lifetime and the runtime of the robot. 

Passive systems usually employed in the car industry as well as active systems were installed in energy demanding routes of the system, protecting the rest of the electronics and modules in case a component fails unexpectedly. 

In the following sections the overall energy system is being decomposed to its layers, its elements and their details.

An overview of the vehicle its batteries and their compartment can ..

![00-overview](_figures/vehicle-power-00-overview.png)


## Batteries

The battery technology chosen for the Agrofelis robot is called lithium iron phosphate battery (LiFePO 4 battery). Because of their, high safety, low toxicity, long cycle life, LFP batteries are finding a number of roles in vehicle use, utility-scale stationary applications, and backup power systems [^LiFePO]. Eight CATL 302Ah LiFePO 4 battery cells (LEP71H3L7-01) connected in series, make up the battery module of the vehicle. Each cell approximately weights 5.5 kg, can have a voltage range between 2.0V and 3.65V with a nominal voltage of 3.2v, while is able operate between -35 and 65 ℃. Their life cycle exceeds 4000 charge discharge cycles corresponding to nearly 11 years, if the robot is operated on a daily basis. The battery lifespan can also be expanded if the depth of charge and discharge rates are bounded to lower levels than their maximum. The batteries nominal discharge rate is at 0.5C and the maximum continues rate is 1.0 C. This means that the system can effectively deliver constantly 150 amps and peak safely up to 300 amps of power. 

[CATL_302A](assets/CATL_302Ah.pdf)


[^LiFePO]: https://en.wikipedia.org/wiki/Lithium_iron_phosphate_battery "Wikipedia - LiFePO4" 

The typical dimension of a 302Ah battery cell are visualised by the following image.

![battery cell](_figures/vehicle-power-01.png)


The following perhaps peculiar battery arrangment, enables to minimise the overall footprint of the vehicle by aproximately 20 cm.

![02-batteries-arrangment](_figures/vehicle-power-02-batteries-arrangment.png)

The batteries photo ...

![02-batteries-arrangment-actual](_figures/vehicle-power-02-batteries-arrangment-actual.jpg)

In order to isolate the batteries from external temperature differnces pieaces as well as compensate for minor acumuliative dimensions differences either in the batteries or in the frame, as well facilitate as shock abosorbers, pieces of plywood wood are cut and inserted in between the frame and the bateries.
The pieces of wood allow to gently impose compressing forces into the batteries preventing them from expanding during their charchring and discharcging cycles prolonging ther lifetime. 

The foll fig  ill 

![03-bateries-wood-covers](_figures/vehicle-power-03-bateries-wood-covers.png)

the in an exploded view and enumrated 

![04-covers-exploded](_figures/vehicle-power-04-covers-exploded.png)

Their dimensions and thickness

![04-covers-dimensions](_figures/vehicle-power-04-covers-dimensions.png)

The figure actual

![02-batteries-enclosed-actual](_figures/vehicle-power-02-batteries-enclosed-actual.jpg)

Batter management system BMS 250 ah

![05-bms-close](_figures/vehicle-power-05-bms-close.jpg)

as packed with the voltage cable, temperature sensors and ..

![05-bms-peripherals](_figures/vehicle-power-05-bms-peripherals.jpg)

Note the B- and P- outlets of the bms are re-mantled and repositioned so these face the sensors outlets as seen by fig


![06-components](_figures/vehicle-power-06-components.png)
1 high current swicth
2 250 amp mechanical relay fuse
3 positive voltage
4 negative voltage
5 bms 

B0 - outlets
B8 + outlet


![07-step-down-converters](_figures/vehicle-power-07-step-down-converters.png)



5v step down power module 
12v step down power module
5v step down power module dedicated to the brake servos

The figure depicts the related power modules, electronics and actuators 

![-07-electrical-components](_figures/vehicle-power--07-electrical-components.jpg)


Making the power distributor for the mobility drivers and the steering

two of these are fabricated one for the back wheels and another for the front wheels

![15-relay-fuse-1](_figures/vehicle-power-15-relay-fuse-1.jpg)
![15-relay-fuse-2](_figures/vehicle-power-15-relay-fuse-2.jpg)
![15-relay-fuse-3](_figures/vehicle-power-15-relay-fuse-3.jpg)
![15-relay-fuse-4](_figures/vehicle-power-15-relay-fuse-4.jpg)
![15-relay-fuse-5](_figures/vehicle-power-15-relay-fuse-5.jpg)


### Arrangement

## BMS
## Charging

add changer photo 

add wifi relay fix applied


https://www.alibaba.com/product-detail/4PCS-US-STOCK-CATL-3-2V_1600209660693.html