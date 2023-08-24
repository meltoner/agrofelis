# Agrofelis Robot wheels

# Abstract

This document describes the details of manufacturing the active 4 wheel Drive system equipping the Agrofelis robotic vehicle. 

# Introduction

Finding the right motors for the vehicle such that sufficient torque power is generated at the desired low rpm context, the low energy consumption ratio and the low cost, was a time consuming research process. 

After researching various solutions for the uncommon case of low rpm, high torque, small footprint and low cost, we concluded that a solution composed of geared in-wheel motor hubs, equipped with hall sensors, providing at least 120 total NM, operable at 24v with less than 1000 watt total power consumption and tolerance to withstand 350 kilos of weight, as well as fit within a 16 inch wheel, compile the necessary characteristics of the needed solution. A four wheel drive active system instead for example a 2wd drive was considered necessary to maximize the traction, and distribute the load of the vehicle. In the following sections the details of the active wheels, their components and the indicative suppliers, are presented.

## The Agrofelis wheels

The market research concluded that the most optimal solution was to employ four geared in-wheel hub motors of 250 watt each providing at most 38NM each, summing to 152 NM of total torque power matching all requirements set for the Agrofelis robot. The in-wheel motor hub is connected via 36 spokes with a 16 inch aluminum rim. 

Bellow, the wheel with its motor, the spokes, the spokes lacing pattern and the 16 inch rim, are photographed.

![Wheel knit showcase](_figures/vehicle-wheels-01_wheel.jpg)

The wheel decomposed to its sub-components, is illustrated by the following figure.

![Wheel decomposition](_figures/vehicle-wheels-02-decomposition.png)

Key dimensions of the individual components forming the prototyped wheel, are documented by the following diagram.

![Wheel dimensions](_figures/vehicle-wheels-03-dimensions.png)

The four wheels supporting the vehicle, are arranged into a near square arrangement, as show by the following diagram.

![wheels dimensions](_figures/vehicle-wheels-04-arrangement-dimensions.png)


### Wheels compilation

To minimize costs and although it was quite laborious, the motor hubs were purchased without their rims so these could reserve less volume, approximately 1/4, leading to significantly lower shipping costs. Along with the motors, their respective motor drivers the wheel spokes, the disc brakes and the brakes were purchased from a foreign supplier, while the 16 inch aluminum rims, the inner tubes and tires, from local suppliers. 

The approach of purchasing the wheels un-assembled provides the option to decrease or increase the wheel size subject that the spokes length are adapted accordingly. The wheels spokes, connecting the motors with the rim, were knitted and aligned manually. 

Four wheel modules were developed with disc brakes, inflatable tubes and fat tires to maximize the traction for this kind of wheel size, and by employing off the self available components. The components are showcased in the following sections.

The following picture showcases the 250w, 24v in-wheel brush-less motor hub.

![wheels motor](_figures/vehicle-wheels-05-motor.jpg)


After communicating with various suppliers and evaluating the applicability of their products, the SR250D 250W brush-less hub motor  from Suringmax were chosen because of their geared feature (1:4.4), their waterproof IP54 IP grade, their max torque power at 38 Nm, their compatibility with a wide range of rim sizes including a 16 inch rim and their compatibility with a 24v system. The provider was also able to manufacture and provide custom spokes, according to the requested length such that they fit a 16 inch rim, something that played an important role for selecting them. Depending on the problem the Agrofelis is set to address larger motors and / or wheel can be selected following the equivalent procedure presented in this document.

The motors, were equipped with disc brakes as these shown by the following photo.

![wheels brake](_figures/vehicle-wheels-06-disc-brake.jpg)

Each of the motors supports 36 spokes summing to 144 spokes for four wheels, as shown below.

![wheels spokes](_figures/vehicle-wheels-07-spokes.jpg)

A close up view of the spokes along with their securing nuts (nipples) can be seen by the following photo.

![wheels spokes](_figures/vehicle-wheels-08-spokes.jpg)


In order to match number of spokes supported by the motors (36) and the usual number of spokes provided by rims of this size (16), additional holes had to be annotated and drilled. A repeating pattern, printable in regular size printer paper was designed. The PDF asset file encoding the related pattern, is referenced below.

- [36 drilling pattern for 16 inch rims](assets/36holes-16-inch-pattern.pdf)


The pattern is printed 4 times and connected using transparent tape on the annotated remark line. Consequently the pattern is cut and glued within the inner top surface of the rim. On the annotated positions, the rims are drilled to make up the appropriate connection points for the spokes.

The following figure showcases the printed pattern depicting the locations where the related rim, should be drilled.

![wheels pattern](_figures/vehicle-wheels-09-26-drill-pattern.jpg)

A photo, capturing the rim adaptation to the motors by drilling the related 36 holes, is provided.

![wheels drilling](_figures/vehicle-wheels-10-drilling.jpg)

The following photo showcases the difference between the standard rim holes (16) and the new ones drilled (36).

![wheels drill holes difference](_figures/vehicle-wheels-11-holes-difference.jpg)


![wheels selection](_figures/vehicle-wheels-12-holes-selection.jpg)

The following photo shows the four assembled wheels, without their tube and tires.

![wheels completed](_figures/vehicle-wheels-13-completed.jpg)

The four fully completed wheels are snapshoted by the following photo.

![wheels completed with tires](_figures/vehicle-wheels-14-completed.jpg)

The active wheels of the vehicle interface with the [Agrofelis Motors hub driver](https://github.com/meltoner/agrofelis/tree/main/components/mobility/motors_hub_driver) modules, enabling to digitally monitor and perform precise and adaptive coordinated movements, at near constant low RPM, independent of the ground slope.


## The wheels components
 
The following table lists the individual components employed for the Agrofelis wheel, along with their unit price, and an indicative supplier link.

| Units | Product | Unit price | Link | Total Cost |
|---|-----------------------|-----|----|-----|
| 4 | SR250D Suringmax Motors | 70 | http://www.suringmax.com/index.php?m=home&c=View&a=index&aid=97 | 280 |
| 4 | 36 spokes to fit the inner dimensions of the rims of 28cm length | 3 | http://www.suringmax.com | 12 |
| 4 | Disk brakes | 5 | http://www.suringmax.com | 20 |
| 4 | Motor drivers at 24v with forward and reverse driving and no display connection | 15 | http://www.suringmax.com/index.php?m=home&c=View&a=index&aid=139 | 60 |
| 4 | Viper tires 16 X 3.00 | 26 | https://podilatada.gr/product/viper-elastiko-16x3-00-gia-e-bike-e-scooter/ | 104 |
| 4 | SHINKO Tube 16X2.50/3.0 | 10 | https://podilatada.gr/product/shinko-16x2-50-3-0-aerothalamos-ilektrikou-podilatou-valvida-tr87-stravi/ | 40 | 
| 4 | 16 inch aluminum rims | 15 | https://www.podilatis.gr/troxos-podilatou-asimi-alouminiou-0-016-175.html | 60 |

The total cost to manufacture four wheels excluding shipping and work cost sums to approximately 576 euros.

# Summary

The Agrofelis active wheels design details were presented. The manufacturing procedures employed, allowing to reproduce the particular wheels prototyped as well implement derivative variations, were documented. Approaches employed to minimize the shipping costs as well as provide flexibility, were showcased. Images illustrating the individual steps to compile the wheel and indicative links to purchase the components were documented.