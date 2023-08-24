# Agrofelis Robot wheels

# Abstract

This document describes the details of the 4 Wheel Drive system equipping the Agrofelis robotic vehicle.

# Introduction

Finding the right motors for the vehicle such that sufficient torque power is generated at the desired low rpm context, the low energy consumption ratio and the low cost, was a time consuming research process. After researching various solutions for the unusual case of low rpm, high torque, small footprint and low cost we concluded that a solution composed of geared in-wheel motor hubs, equipped with hall sensors, providing at least 120 total NM, operable at 24v with less than 1000 watt total power consumption and the tolerance to withstand 350 kilos of weight, as well as fit within an 16 inch wheel, would be needed. A four wheel drive active system was more over decided necessary to maximize the traction and vector thrust of the vehicle. In the following sections the details of the active wheels, their components and indicative suppliers are being presented.

## The Agrofelis wheels

The market research concluded that the most optimal solution was to employ four geared in-wheel hub motors of 250 watt each providing at most 38NM each, summing to 152 NM of total torque power matching all requirements set for the Agrofelis robot. The in-wheel motor hub is connected via the 36 spokes with a 16 inch aluminum rim. 

Bellow, the wheel with its motor, the spokes, the spokes knitting / lacing pattern and the 16 inch rim, are photographed.

![Wheel knit showcase](_figures/vehicle-wheels-01_wheel.jpg)

The wheel decomposed to its components, is illustrated by the following figure.

![Wheel decomposition](_figures/vehicle-wheels-02-decomposition.png)

The dimensions of the individual components composing the wheel are documented by the following diagram.

![Wheel dimensions](_figures/vehicle-wheels-03-dimensions.png)

After contacting various suppliers and evaluating the applicability of their products, the SR250D 250W brush-less hub motor  from Suringmax were chosen because of their geared feature (1:4.4), their waterproof IP54 IP grade, their max torque power at 38 Nm, their compatibility with a wide range of rim sizes including a 16 inch rim and their compatibility with a 24v system. The provider was also able to manufacture and provide custom spokes, according to the requested length such that they fit a 16 inch rim. 

### Wheels compilation

To minimize costs and although it was more laborious, the motor hubs were purchased without their rims so these could reserve less volume, leading to significantly lower shipping costs. Along with the motors, their respective motor drivers the wheel spokes, the disc brakes and the brakes were purchased from a foreign supplier, while the 16 inch aluminum rims, the inner tubes and tires, from local suppliers. 

In order to match number of spokes supported by the motors (36) and the usual number of spokes provided by rims of this size, additional holes where annotated and drilled. A repeating pattern, printable in regular size printer papers was designed. The PDF asset file is referenced below.

- [36 drilling pattern for 16 inch rims](assets/36holes-16-inch-pattern.pdf)


The pattern is printed 4 times and connected using transparent tape on the annotated remark line. Consequently the pattern is glued within the inner top surface of the rim. On the annotated circles the rims are drilled to make up the appropriate connection points.

The following figure showcases the printed pattern depicting the locations where the related rim, should be drilled.

![wheels pattern](_figures/vehicle-wheels-09-26-drill-pattern.jpg)

The approach of purchasing the wheels un-assembled provides the option to allows to decrease or increase the wheel size subject that the spokes length are adapted accordingly. The wheels spokes, connecting the motors with the rim, were knitted and aligned manually. 


Four wheel modules were developed with disc brakes, inflatable tubes and fat tires to maximize the traction for this kind of wheel size, and by employing off the self available components. 

The following picture showcases the 250w, 24v in wheel brush-less motor hub.

![wheels motor](_figures/vehicle-wheels-05-motor.jpg)

Below, the disc brake mountable to the motor hub photographed.

![wheels brake](_figures/vehicle-wheels-06-disc-brake.jpg)

The 144 custom spokes provided by the vendor are shown below.

![wheels spokes](_figures/vehicle-wheels-07-spokes.jpg)

A close up view of the spokes along with their securing nuts (nipples) can be seen by the following photo.

![wheels spokes](_figures/vehicle-wheels-08-spokes.jpg)





![wheels drilling](_figures/vehicle-wheels-10-drilling.jpg)
![wheels drill holes difference](_figures/vehicle-wheels-11-holes-difference.jpg)
![wheels selection](_figures/vehicle-wheels-12-holes-selection.jpg)
![wheels completed](_figures/vehicle-wheels-13-completed.jpg)
![wheels completed with tires](_figures/vehicle-wheels-14-completed.jpg)


The active wheels of the vehicle interface with the Agrofelis Motors hub driver modules, enabling to digitally monitor and perform precise adaptive coordinated movements, at very low RPM. 



## The wheels components

### The Motor hubs




### The Rims






![wheels dimensions](_figures/vehicle-wheels-04-arrangement-dimensions.png)


| Units | Product | Unit price | Link |
| 4 | SR250D Suringmax Motors $70  http://www.suringmax.com/index.php?m=home&c=View&a=index&aid=97
| 4 | 36 spokes to fit the inner dimensions of the rims of 28cm length | $3 | http://www.suringmax.com |
| 4 | Disk brakes | $5 | http://www.suringmax.com |
| 4 | Motor drivers at 24v with forward and reverse driving and no display connection | $15 | http://www.suringmax.com/index.php?m=home&c=View&a=index&aid=139 |
| 4 | Viper tires 16 X 3.00 | 26 | https://podilatada.gr/product/viper-elastiko-16x3-00-gia-e-bike-e-scooter/ |
| 4 | SHINKO Tube 16X2.50/3.0 | 10 | https://podilatada.gr/product/shinko-16x2-50-3-0-aerothalamos-ilektrikou-podilatou-valvida-tr87-stravi/ |
| 4 | 16 inch aluminum rims | 15 | https://www.podilatis.gr/troxos-podilatou-asimi-alouminiou-0-016-175.html |


