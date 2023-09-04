# Agrofelis Robot Wheel Fabrication

# Abstract

This document presents a comprehensive overview of the manufacturing process behind the four-wheel drive (4WD) system of the Agrofelis robotic vehicle. It begins by detailing the specific requirements and then progresses to the completed fabricated solution. The design plans, compilation procedures, assistance assets and images taken throughout development are presented in a step-by-step manner. The sub-components composing four Agrofelis wheels are indexed with their unit prices and overall cost, along with references to indicative suppliers.

# Introduction

Finding an elegant solution for the mobility requirements of a low speed robotic vehicle such as the Agrofelis robot proved to be a time-consuming procedure requiring extensive research and consideration.

After researching various solutions and vendors, for the uncommon case of low rpm, high torque, small footprint and low cost, we concluded that a solution composed of geared in-wheel motor hubs, equipped with hall sensors, providing at least 120 total Newton meter (NM), operable at 24v with less than 1000 watt total power consumption and ability to withstand 350 kilos of weight, as well as fit within a 16 inch wheel, would be the appropriate characteristics of the designed solution. In order to maximise traction, steering, and load distribution, a 4WD active system rather than a 2WD drive was deemed necessary. In the following sections the details of the active wheels, their components and the indicative sub-component suppliers are documented.

## Agrofelis Wheels

The requirements study resulted in an optimal solution employing four geared in-wheel hub motors of 250 Watt (0.33 HP) and 38 NM of torque each, summing up to 152 NM of torque and 1 KW (1.32 HP) of power, meeting all field requirements set for the Agrofelis robot. The wheel is assembled from individual parts allowing to variate according to the problem focused on. In the following sections the particular composition evaluated and employed is presented.

The wheel with its motor, spokes, spoke lacing pattern and 16-inch rim are all photographed below.

![Wheel knit overview](_figures/vehicle-wheels-01_wheel.jpg)

The wheel decomposed to its sub-components, is illustrated by the following figure.

![Wheel decomposition](_figures/vehicle-wheels-02-decomposition.png)

Key dimensions of the individual components forming the prototyped wheel, are depicted in the following diagram.

![Wheel dimensions](_figures/vehicle-wheels-03-dimensions.png)

The four wheels supporting the vehicle, are arranged in a nearly square layout, as shown in the diagram below.

![Wheels dimensions](_figures/vehicle-wheels-04-arrangement-dimensions.png)

### Wheel Compilation

To optimize costs, and despite the fact that knitting the wheels by hand was quite laborious, the motor hubs were purchased without their rims so that they could reserve less volume, around 1/4, resulting in significantly lower shipping costs. Along with the motors, their respective motor drivers, the wheel spokes, the disc brakes and the fork brakes, were purchased from a foreign supplier. The 16-inch aluminium rims, the inner tubes and tires, were purchased from local suppliers.  

The approach of purchasing the wheels unassembled provides the option of reducing or increasing the wheel size as long as the spokes length are adapted accordingly. The wheels spokes, which connect the motors to the rim, were knitted and aligned manually. 

Four wheel modules were developed with disc brakes, inflatable tubes and fat tires to maximize the traction, for this kind of wheel size. The sub-components utilised are showcased in further detail in subsequent sections.

The following picture showcases the 250W, 24V in-wheel brush-less motor hub.

![wheels motor](_figures/vehicle-wheels-05-motor.jpg)

After communicating with various suppliers and evaluating the applicability of their products, the SR250D 250W brush-less hub motor from Suringmax was chosen due to its geared feature (1:4.4), waterproof IP54 IP grade, max torque power at 38 Nm, compatibility with a wide range of rim sizes including a 16 inch rim, and compatibility with a 24v system. The provider was also able to manufacture and provide custom spokes, according to the requested length such that they fit a 16-inch rim, something that played an important role for selecting them. Depending on the problem that the Agrofelis robot is intended to address, larger motors and/or rims/tires can be selected by following the equivalent procedure presented in this document.

The in-wheel motor hubs, were equipped with disc brakes, as shown in the image below.

![wheels brake](_figures/vehicle-wheels-06-disc-brake.jpg)

Each of the motors supports 36 spokes, totaling 144 spokes for all four wheels, as shown below.

![wheels spokes](_figures/vehicle-wheels-07-spokes.jpg)

A close-up view of the spokes along with their securing nuts (nipples), can be seen in the following photo.

![wheels spokes](_figures/vehicle-wheels-08-spokes.jpg)

In order to match the number of spokes supported by the motors (36) and the customary number of spokes provided by low cost rims of this size (16), additional holes had to be annotated and drilled. A repeating pattern printable in regular size printer paper was designed. The PDF asset file encoding the associated pattern is referenced below.

- [36 holes drilling pattern for 16 inch rims](assets/36holes-16-inch-pattern.pdf)

The pattern is printed four times and connected using transparent tape on the annotated remark line. Consequently, the pattern is cut and glued within the inner top surface of the rim. On the annotated positions, the rims are drilled to make up the appropriate connection points for the spokes.

The following figure showcases the printed pattern, depicting the spots where the related rim should be drilled.

![wheels pattern](_figures/vehicle-wheels-09-26-drill-pattern.jpg)

A photo, showcasing the rim adaptation is provided.

![wheels drilling](_figures/vehicle-wheels-10-drilling.jpg)

The following photo compares the difference between the standard rim holes (16) and the new ones drilled (36).

![wheels drill holes difference](_figures/vehicle-wheels-11-holes-difference.jpg)

The printed pattern moreover, hides the previous invalid holes, assisting the assembling procedure.

![wheels selection](_figures/vehicle-wheels-12-holes-selection.jpg)

It should be noted that 16-inch wheels with 36 holes exist in the market at approximately twice the cost.

The image below displays the four assembled wheels without their tubes and tires.

![wheels completed](_figures/vehicle-wheels-13-completed.jpg)

The four fully completed wheels are captured in the following photograph.

![wheels completed with tires](_figures/vehicle-wheels-14-completed.jpg)

The motor hubs are connected to their motor drivers via a cable supplied with the motors. Consequently, the active wheels of the vehicle interface with the [Agrofelis Motors hub driver](https://github.com/meltoner/agrofelis/tree/main/components/mobility/motors_hub_driver) modules, which enhances their functionality by enabling to digitally monitor and control the motors to perform precise and adaptive coordinated movements at near constant low RPM, regardless of ground slope.

## Wheel Components and Indicative Suppliers

The following table lists the individual components used for manufacturing four Agrofelis wheels. The index table also includes the product URL, the indicative supplier, as well as the unit price total amount.
<div align="center">

| No.|  Product | Product URL | Supplier | Used Quantity | VAT Price (€) | Subtotal (€)  |
|----|--------------|------------|-----|---|---|---|
| #1 | SR250D Suringmax Motor | [Motor Hub](http://www.suringmax.com/index.php?m=home&c=View&a=index&aid=97) | [Suringmax](http://www.suringmax.com/) | 4 | 70.00 | 280.00 |
| #2 | 36 spokes to fit the inner dimensions of the rims with inner diameter of 28 cm | - | [Suringmax](http://www.suringmax.com/) | 4 | 3.00 | 12.00 |
| #3 | Disk brakes | - | [Suringmax](http://www.suringmax.com/) |4 | 5.00 | 20.00 |
| #4 | Motor drivers at 24v with forward and reverse driving and no display connection | [Motor driver](http://www.suringmax.com/index.php?m=home&c=View&a=index&aid=139) | [Suringmax](http://www.suringmax.com/) | 4 | 15.00 |  60.00 |
| #5 | Viper tires 16 X 3.00 |  [Fat tire](https://podilatada.gr/product/viper-elastiko-16x3-00-gia-e-bike-e-scooter/) | [Podilatada](https://podilatada.gr) | 4 | 25.90 | 103.60 | 
| #6 | SHINKO Tube 16X2.50/3.0 | [Tire tube](https://podilatada.gr/product/shinko-16x2-50-3-0-aerothalamos-ilektrikou-podilatou-valvida-tr87-stravi/) | [Podilatada](https://podilatada.gr) | 4 | 9.90 | 39.60 | 
| #7 | 16 inch aluminum rims | [Rim](https://www.podilatis.gr/troxos-podilatou-asimi-alouminiou-0-016-175.html) | [Podilatis](https://www.podilatis.gr) | 4 | 15.00 | 60.00 |
| **Total** |      |    |     |      |     |  **575.20**  | 

</div>

Consequently, we observe that the total cost to manufacture four wheels, excluding shipping and assembly charges, is approximately **575** euros.

# Summary

This document elucidated the design details for the Agrofelis active wheels. The manufacturing processes utilized for reproducing the particular prototype wheels, as well as implementing derivative variations, have been comprehensively documented. Approaches used to minimize shipping costs while also providing flexibility were highlighted. Images that chronicle the step-by-step procedures involved in reproducing the Agrofelis wheels, alongside detailed information for procuring the relevant sub-components, were documented.
