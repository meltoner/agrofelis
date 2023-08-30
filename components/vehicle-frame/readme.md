# Agrofelis chassis frame design and fabrication

# Abstract 

The current document focuses on the manufacturing details of the vehicle's frame. The frame houses and protects the 8kw power module with its LiFePO4 batteries, the electronics, the sensors and actuators of the unmanned vehicle. 
The frame was implemented using a total of 7.35 meters of 20X20 mm regular square iron bars , it establishes key placeholders for mounting the detachable wheels, the protective covers and via its grid-like attachment points enables mounting anticipated tools, as well as future ones. The primary design considerations were footprint minimization, battery compartment protection, chassis rigidity, and ease of manufacture utilizing low-budget tools and readily available materials.

The documentation presents the frame fabrication by decomposing it into its individual elements and fabrication steps.

# Introduction

The cross like symmetric chassis frame of the vehicle can be decomposed into identical bottom and top parts, a middle part contributing to the chassis height, front and back wheel mounting points, a fixed protective cover for the batteries, and a grid-like array of mounting sockets. 

The following figure illustrates the schematics of the chassis from multiple view points.

![Views of the frame](_figures/vehicle-frame-01-3dview.png)

Crucial dimensions of the frame and its components are annotated in the following diagram.

![Key dimensions of the frame](_figures/vehicle-frame-02-top_view_measure.png)

The frame with its components arranged in an exploded view, is presented below.

![Exploded components of the frame](_figures/vehicle-frame-03-exploded.png)

In the preceding diagram, numerical annotations are used to indicate various subpars of the frame, each labeled as follows:

1. The bottom part
2. The bottom batteries cover part
3. The middle bars
4. The top part
5. The back wheel mounting points part
6. The front wheel mounting points part

## Stepwise frame fabrication

This section delves into the systematic fabrication of the chassis, which unfolds across seven distinct steps. In addition, for each step, we provide accompanying images to aid comprehension and ease of reference.

### Step 01

The first part of the chassis fabrication is the bottom part, which is clearly illustrated by the following projection diagram.

![Manufacturing the frame step 1](_figures/vehicle-frame-04-step-01.png)

### Step 02

In the second step, in the bottom part of the frame, a 3 mm thick iron sheet following the battery compartment silhouette is welded, securing the 8kw LiFePO4 batteries from external forces, as illustrated by the following diagram.

![Manufacturing the frame step 2, battery bottom protection cover](_figures/vehicle-frame-04-step-02.png)


### Step 03

In the third step of the fabrication, the top part is being implemented. This part, in conjunction with the already constructed bottom part, is showcased in the diagram below.

![Manufacturing the frame step 3, bottom and top parts](_figures/vehicle-frame-04-step-03-01.png)

The bottom and top part of the frame as fabricated are snapshot-ed, by the following images.

![Manufacturing the frame step 3, fabricated bottom and top parts aligned](_figures/vehicle-frame-04-step-03-02-actual.jpg)

![Manufacturing the frame step 3, fabricated bottom and top parts](_figures/vehicle-frame-04-step-03-03-actual.jpg)

### Step 04

In the fourth step of the fabrication, the middle bars are MIG welded, connecting the top and bottom parts implemented in the previous steps, as shown in the image below.

![Manufacturing the frame step 4, middle bars](_figures/vehicle-frame-04-step-04-01.png)

The following images showcase the fabricated top, bottom and middle parts of the chassis.

![Manufacturing the frame step 4, fabricating the middle bars in progress](_figures/vehicle-frame-04-step-04-02-actual.jpg)

![Manufacturing the frame step 4, fabricating the middle bars, completed](_figures/vehicle-frame-04-step-04-03-actual.jpg)


### Step 05

Proceeding to the fifth step of the fabrication, the back wheel attachment points are being fabricated, as depicted in the succeeding illustration. The back wheel attachment points, enable to dismantle the related modules or to interchange the steering wheels according the the scope of the problem.

![Manufacturing the frame step 5, back wheels attachment](_figures/vehicle-frame-04-step-05-01.png)

Further insight into the manufactured part can be seen in the following image.

![Manufacturing the frame step 5, back wheels attachment fabricated](_figures/vehicle-frame-04-step-05-02-acual.jpg)

> Although not crucial, these vertical bars can be offset-ed by 30 mm, something that is performed by the prototype frame using some additional drilled bars and washers, meticulously documented in the  dedicated document presenting the steering wheels module.

### Step 06

In the sixth step of the chassis fabrication, the front wheel attachments, using regular T-shaped iron bars of 25 mm width by 25 mm height, are welded onto the corner bars, allowing to interchange easily the front wheels of the robot and to support future wheel design variations based on the problem targeting.

![Manufacturing the frame step 6, Front wheels attachment](_figures/vehicle-frame-04-step-06.png)

### Step 07

Concluding with the seventh step of the chassis fabrication, 76 nuts are welded into every corner formed by the iron bars. These nuts serve dual purposes, allowing to mount the protecting covers of the frame and establishing multiple mounting points for tools and extensions of the Agrofelis Robot. The arrangement of grid-like mounting socket locations in the fabricated chassis is depicted in the following image.

![Manufacturing the frame step 7, Nuts forming multiple attach points](_figures/vehicle-frame-04-step-07-01.png)

The subsequent figure showcases two perspectives of the painted fabricated frame .

![Views of the fabricated frame](_figures/vehicle-frame-04-step-07-02-actual.jpg)

## Finalization steps

As with all metallic parts of the Agrofelis robot, the frame is being coated with a two-layer primer application, followed by a double coating of oil paint.
Additionally, a 5 mm compressible adhesive foam is glued to the external surfaces of the frame. This measure ensures almost air-tight protection when the covers are attached, effectively safeguarding internal components against dust and water.


## Chassis components and indicative suppliers
 
The following table lists the individual components employed for manufacturing the Agrofelis chassis frame. The index table includes moreover the product URL, the indicative supplier, as well as the unit price total Amount.

<div align="center">

| No. |  Product | Product URL | Supplier | Used Quantity | VAT Price (€) | Subtotal (€)  | Note |
|----|--------------|------------|-----|---|---|---|---|
| #1 | 6 meters black iron square bar 20mm X 20mm X 2mm | [Square bar](https://e-iron.gr/product/6-11/) | [QOOP Metalworks](https://www.qoop.gr) | 2 | 7.00 | 14.00 | Few meters remain from the batch that can utilised for others parts |
| #2 | Black iron metal sheet 1000x2000x3mm  | [3mm metal sheet](https://www.e-metalshop.gr/sidera/lamarynes/lamarina-sidhroy-mayrh-1000x2000x3mm) | [QOOP Metalworks](https://www.qoop.gr)  | 1 | 73.85 | 73.85 | A significant area of the product can be reused to fabricate other components |
| #3 | 1 meter black iron T bar 25 x 3 | [T bar](https://sitsianis.gr/%CF%80%CF%81%CE%BF%CE%B9%CE%BF%CE%BD%CF%84%CE%B1-%CF%83%CE%B9%CE%B4%CE%B7%CF%81%CE%BF%CF%85-%CE%BC%CE%B5%CF%84%CE%B1%CE%BB%CE%BB%CE%BF%CF%85/%CF%84%CE%B1%CF%86/) | [QOOP Metalworks](https://www.qoop.gr) | 1 | 6.00 | 6.00 | - |
| #4 | 100 pack nut connector M08X24mm | [Nut M08X24mm](https://droutsas.gr/shop/%ce%b5%ce%af%ce%b4%ce%b7-%ce%ba%ce%b9%ce%b3%ce%ba%ce%b1%ce%bb%ce%b5%cf%81%ce%af%ce%b1%cf%82/sidirika/%ce%b2%ce%af%ce%b4%ce%b5%cf%82/%ce%bc%ce%bf%cf%85%cf%86%ce%b5%cf%83-%ce%bd%cf%84%ce%b9%ce%b6%cf%89%ce%bd-%ce%b5%ce%be%ce%b1%ce%b3%cf%89%ce%bd%ce%b5%cf%83-%ce%b3%ce%b1%ce%bb%ce%b2%ce%b1%ce%bd%ce%b9%ce%b6%ce%b5-din-6334-m08x24-ff/) | [Droutsas](https://droutsas.gr)| 1 | 13.00 | 13.00 | - |
| #5 | Self-adhesive foam | [Adhesive sealing foam](https://egarbis.gr/doorado-autokolito-afrodes-prostteutiko-megalou-mikous-gia-toixous-gkaraz-maurou-xromatos-se-rolo-park-flwp20020b) | [Egarbis](https://egarbis.gr) | 2 | 4.70 | 9.40 | - | 
| #6 | 750ml Vitex Metal Primer | [Primer](https://www.stereotiki.gr/store4/vitex-metal-primer-astari-metallon.html) | [Stereotiki](https://www.stereotiki.gr) | 1 | 6.50 | 6.50 | - |
| #7 | Gray oil paint 0,375 kg | [Metal paint](https://vrontinos.gr/el/Product/0001A515.aspx) | [Vrontinos](https://vrontinos.gr) | 1 | 5.60 | 5.60 | - |
| #8 | Brushes| [Brush](https://nova-ceramica.gr/products/morris-39253) | [Nova Ceramica](https://nova-ceramica.gr/) | 3 | 1.00 | 3.00 | - |
| | White spirit| [White spirit](https://www.rigatos-shop.gr/dialytika-diavrwtika-spray/2381-white-spirit-%CE%B4%CE%B9%CE%B1%CE%BB%CF%85%CF%84%CE%B9%CE%BA%CF%8C-500ml.html)  | [Rigatos Shop](https://www.rigatos-shop.gr/) | 1 | 1.50 | 1.50 | - |
| | Paper sheet | [Paint paper](https://xromagora.gr/%CF%83%CF%85%CE%BD%CE%B1%CF%86%CE%AE-%CF%87%CF%81%CF%89%CE%BC%CE%AC%CF%84%CF%89%CE%BD/%CF%87%CE%B1%CF%81%CF%84%CE%AF-%CE%B3%CE%BA%CE%BF%CF%86%CF%81%CE%AD-%CE%BD%CE%AC%CF%85%CE%BB%CE%BF%CE%BD/%CF%87%CE%B1%CF%81%CF%84%CE%AF-%CE%B3%CE%BA%CE%BF%CF%86%CF%81%CE%B5-%CE%BF%CE%BD%CF%84%CE%BF%CF%85%CE%BB%CE%B5.) | [Xromagora](https://xromagora.gr/) | 5 | 0.80 | 4.00 | - |
| #9 | 100 pack Allen screws DIN 912 8.8 M 8 x 25 | [Screws M8X25](http://www.sinter-hellas.gr/index.php/products/eidh-vidopoiias/vides-me-speirwma-gia-perikoxlio/93-allen/din912-88-mavr)  |[Sinter Hellas](http://www.sinter-hellas.gr/) | 1 | 18.62 | 18.62 | - |
| **Total** |      |    |     |      |     |  **155.47**  | | 
</div>

The total cost to manufacture the Agrofelis frame excluding shipping, cutting, welding and painting costs, sums to approximately **155** euros.

## Summary

The development process, component details and essential dimensions for reproducing the Agrofelis chassis has been documented in a progressive manner. A photograph of the vehicle with some covers removed, exposing details of the end frame, is presented in the closing image below.

![Close up view of the frame](_figures/vehicle-frame-05_actual.jpg)
