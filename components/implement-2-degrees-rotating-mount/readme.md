# Two degrees of freedom rotating implement mount

# Abstract

This document describes the construction of the Rotating Implement Mount (RIM) positioned on the top part of the Agrofelis robot. The RIM's primary role is to allow the use of directional implements such as the thermal fogger depicted in the video. The rotation is acheived through the use of a stepper motor turning a gear that runs on a turntable, and elevation/depression is achieved with the use of a linear actuator leveraging the mount, thus facilitating a 2 Degrees of freedom capability for any implement mounted on it. The rationale behind the module, its schematics and the manufacturing process is covered. The document concludes with a list of the components used and assorted with indicative suppliers, aiding in the replication of the module.

# Introduction

The module comprises of the bottom part which is a 360-degree turntable with an inner circle of cut in rectangular holes in which the gear teeth run, the mid part that moves vertically with a depression angle of -5 degrees and elevation angle of +40 degrees leveraged by the linear actuator and the top part which is the actual mount surface.

![overal-view](_figures/implement-2-degrees-rotating-mount-01-overal-view.png)

## Implement mount module 

add

![module](_figures/implement-2-degrees-rotating-mount-02-module.png)
![components](_figures/implement-2-degrees-rotating-mount-03-components.jpg)

![exploded](_figures/implement-2-degrees-rotating-mount-04-exploded.png)
![decomposed](_figures/implement-2-degrees-rotating-mount-05-decomposed.png)
![enumerated](_figures/implement-2-degrees-rotating-mount-06-enumerated.png)

1.
2.
3.
4.
5.
6.
7.
8.
9.
10.


## Fabrication parts

### Base

![part 1](_figures/implement-2-degrees-rotating-mount-07-part-1.png)
![part 1 actual](_figures/implement-2-degrees-rotating-mount-08-part-1-actual.jpg)
![part 1 actual-painted](_figures/implement-2-degrees-rotating-mount-09-part-1-actual-painted.jpg)

### Vertical gear

2mm laser cut outsource 

![part 3](_figures/implement-2-degrees-rotating-mount-10-part-3.png)
![part 1 2 3](_figures/implement-2-degrees-rotating-mount-11-part-1-2-3.jpg)

to add cnc code

### Servo Motor

![part 5](_figures/implement-2-degrees-rotating-mount-12-part-5.png)
![part 5 actual](_figures/implement-2-degrees-rotating-mount-13-part-5-actal.jpg)

### Supporting walls

![part 4](_figures/implement-2-degrees-rotating-mount-14-part-4.png)
![assempled](_figures/implement-2-degrees-rotating-mount-15-assempled.jpg)

to add 3d print gcode

### Gear 

3 layers, grinded 

![gear view](_figures/implement-2-degrees-rotating-mount-16-gear-view.jpg)
![gear](_figures/implement-2-degrees-rotating-mount-17-gear.jpg)
![gear-edge](_figures/implement-2-degrees-rotating-mount-18-gear-edge.jpg)

### Mid base

![part 7](_figures/implement-2-degrees-rotating-mount-19-part-7.png)
![part 7-plasma-cut](_figures/implement-2-degrees-rotating-mount-20-part-7-plasma-cut.jpg)
![part 7-actual](_figures/implement-2-degrees-rotating-mount-21-part-7-actual.jpg)

### Top mount base

![part 10](_figures/implement-2-degrees-rotating-mount-22-part-10.png)
![part 10-actual](_figures/implement-2-degrees-rotating-mount-23-part-10-actual.jpg)

### End module 

unpainted


![fabricated a](_figures/implement-2-degrees-rotating-mount-24-fabricated-a.jpg)
![fabricated b](_figures/implement-2-degrees-rotating-mount-25-fabricated-b.jpg)
![fabricated c](_figures/implement-2-degrees-rotating-mount-26-fabricated-c.jpg)

 
## Implement mount components and indicative suppliers
 
The following table lists the individual components employed for manufacturing the Agrofelis two degrees of freedom rotating implement mount. The index table includes moreover the product URL, the indicative supplier, as well as the unit price total Amount.

<div align="center">

| No. |  Product | Product URL | Supplier | Used Quantity | VAT Price (€) | Subtotal (€)  | Note |
|----|--------------|------------|-----|---|---|---|---|
| #1 | Black iron metal sheet 1000x2000x3mm  | [3mm metal sheet](https://www.e-metalshop.gr/sidera/lamarynes/lamarina-sidhroy-mayrh-1000x2000x3mm) | [E-Metalshop](https://www.e-metalshop.gr/)  | 0.2 | 73.85 | 14.77 | - |
| #2 | Black iron metal sheet 1000x2000x2mm  | [2mm metal sheet](https://www.e-metalshop.gr/sidera/lamarynes/lamarina-sidhroy-mayrh-1000x2000x2mm) | [E-Metalshop](https://www.e-metalshop.gr/)  | 0.3 | 49.23 | 14.76 | - |
 #3 | 100 pack Allen screws DIN 912 8.8 M 8 x 25 | [Screws M8X25](http://www.sinter-hellas.gr/index.php/products/eidh-vidopoiias/vides-me-speirwma-gia-perikoxlio/93-allen/din912-88-mavr)  |[Sinter Hellas](http://www.sinter-hellas.gr/) | 0 | 18.62 | 0 | 4 scews reused from frame material |
| #4 | 300mm Aluminium Rotating Bearing Turntable | [Turntable](https://www.aliexpress.com/item/1005002246256122.html) | [AliExpress](https://www.aliexpress.com/) | 1 | 29.53 | 29.53 | - |
| #5 | Linear Actuator 50 mm 24V 200N 45 mm/s| [Linear Actuator](https://www.aliexpress.com/item/32687100164.html) |  [AliExpress](https://www.aliexpress.com/) | 1 | 21.93 | 21.93 | - |
| #6 2 | H-Bridge Brushed DC Motor Driver | [Motor Driver](https://www.cableworks.gr/ilektronika/arduino-and-microcontrollers/motors/drivers/drv8871-h-bridge-brushed-dc-motor-driver-breakout-board-for-arduino/) | [Cableworks](https://www.cableworks.gr) | 2 | 6.00 | 12.00 | - |
| #7 | NEMA23 single shaft 8mm, 4.2A | [NEMA23](https://www.aliexpress.com/item/32868067877.html) | 1 | 18.44 | 18.44 | - |
| #8 | Closed loop Nema 23 driver | [closed loop stepper driver](https://www.aliexpress.com/item/1005005446035245.html) | [AliExpress](https://www.aliexpress.com/) | 1 | 21.82 | 21.82  | - |
| #9 | Nema 23 L bracket | [Stepper Bracket](https://isac.gr/product/goniaki-vasi-nema-23-motor/) | [Isac](https://isac.gr) | 1 | 6 | 6 | - |
| #10 | Linear motion shaft OD 12mm 500mm length | [Linear shaft](https://isac.gr/product/axonas-grammikis-kinisis-od-12mm/?attribute_pa_size=500mm) | [Isac](https://isac.gr) | 1 | 8.3 | 8.3 | - |
| #11 | Linear shaft support bracket SHF 12mm | [Linear shaft bracket](https://isac.gr/product/vasi-thesis-axona-shf-12mm/) | [Isac](https://isac.gr) | 2 | 4.84 | 9.67 | - |
| #12 | Omega shaft bracket 12 mm| [Omega shaft](https://isac.gr/product/koyzineto-kp-omega12mm/) | [Isac](https://isac.gr) | 2 | 5.58 | 11.16 | - |
| #13 | 750ml Vitex Metal Primer | [Primer](https://www.stereotiki.gr/store4/vitex-metal-primer-astari-metallon.html) | [Stereotiki](https://www.stereotiki.gr) | 0 | 6.50 | 0.00 | Reused from frame material|
| #14 | Orange oil paint 0,75kg | [Metal paint](https://www.bousounis.gr/%CF%87%CF%81%CF%89%CE%BC%CE%B1%CF%84%CE%B1-amp-%CE%B2%CE%B5%CF%81%CE%BD%CE%B9%CE%BA%CE%B9%CE%B1/%CE%BD%CF%84%CE%BF%CF%85%CE%BA%CE%BF%CF%87%CF%81%CF%89%CE%BC%CE%B1%CF%84%CE%B1/vechro-gumilak-metal-duco-%CF%85%CF%88%CE%B7%CE%BB%CE%B7%CF%83-%CE%B1%CE%BD%CF%84%CE%BF%CF%87%CE%B7%CF%83-%CE%BD%CF%84%CE%BF%CF%85%CE%BA%CE%BF%CF%87%CF%81%CF%89%CE%BC%CE%B1-603-%CE%B7%CE%BB%CE%B5%CE%BA%CF%84%CF%81%CE%BF-750ml.htm) | [Bousounis](https://www.bousounis.gr/) | 1 | 9.70 | 9.70 | - |
| #15 | Brushes| [Brush](https://nova-ceramica.gr/products/morris-39253) | [Nova Ceramica](https://nova-ceramica.gr/) | 3 | 1.00 | 3.00 | - |
| #16 | White spirit| [White spirit](https://www.rigatos-shop.gr/dialytika-diavrwtika-spray/2381-white-spirit-%CE%B4%CE%B9%CE%B1%CE%BB%CF%85%CF%84%CE%B9%CE%BA%CF%8C-500ml.html)  | [Rigatos Shop](https://www.rigatos-shop.gr/) | 1 | 1.50 | 1.50 | - |
| #17 | Paper sheet | [Paint paper](https://xromagora.gr/%CF%83%CF%85%CE%BD%CE%B1%CF%86%CE%AE-%CF%87%CF%81%CF%89%CE%BC%CE%AC%CF%84%CF%89%CE%BD/%CF%87%CE%B1%CF%81%CF%84%CE%AF-%CE%B3%CE%BA%CE%BF%CF%86%CF%81%CE%AD-%CE%BD%CE%AC%CF%85%CE%BB%CE%BF%CE%BD/%CF%87%CE%B1%CF%81%CF%84%CE%AF-%CE%B3%CE%BA%CE%BF%CF%86%CF%81%CE%B5-%CE%BF%CE%BD%CF%84%CE%BF%CF%85%CE%BB%CE%B5.) | [Xromagora](https://xromagora.gr/) | 0 | 0.80 | 0.00 | Reused from frame material|
| #18 | Laser cut gears out of stainless steel sheet 2 mm as of design | [See dwg design file](assets/stainless-steel-laser-cut/laser-cut_stainless_gear_disk_motor_gear_order.dwg) | [QOOP Metalworks](https://www.qoop.gr) | 1 | 85 | 85 | - |
| #19 | 3d Printed side walls as of gcode  [See gcode design file](assets/3d-print/RotationTableWalls/walls.stl) | [3d printing services](https://www.3dhub.gr/upload-3d-file/) | [3dhub](https://www.3dhub.gr/) | 1 | 55 | 55 | - |
| **Total** |      |    |     |      |     |  **155.47**  | | 
</div>

The total cost to manufacture the Agrofelis frame excluding shipping, cutting, welding and painting costs, sums to approximately **155** euros.

## Summary

# Conclusion

add
