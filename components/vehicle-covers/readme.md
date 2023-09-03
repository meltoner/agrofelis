# Agrofelis frame protective covers

# Abstract 

The document builds on the Agrofelis frame design and fabrication documentation by enumerating and indexing the vehicle's metal cover parts, their schematics and their source code files driving a CNC Plasma cutter. Photographic material during the fabrication, detail further the manufactured parts. A list of components and indicative suppliers that comprise the bill and material information for isolating the robot from its external environment, is provided. 

# Introduction

To protect the robot from the harsh environment found in the agriculture, where dust, dirt, rocks and rain are expected, covers were designed and fabricated from black iron of 2 mm and 3 mm. The rigid detachable cover parts, conveniently provide access to the compartments of the robotic vehicle. The covers, attach to the vehicle using 8 mm bolts to its front, back, top, bottom, left and right sides. While the side covers are quantised by smaller parts, the top and bottom parts where designed with fewer and larger parts to provide additional protection by minimizing the number of intersections. The larger parts, were fabricated using a grinder and the rest using our small DIY plasma cutter. 

In the following sections the details for fabricating the Agrofelis Robot protective covers are documented.


# Protective covers

The vehicles detectable covers are compromised of 25 items. Most items of the left and right sides are symmetric except two having additional cavities to accommodate the vehicle's main power switch and its charging socket. The following diagram visualizes the vehicle's protective covers. 

![Covers overview](_figures/01_cover_overview.png)

More specifically, the following schematic enumerates all plasma cut covers. The symmetric left side items were omitted, for simplicity.

![Covers enumeration](_figures/02_covers_enumerate.png)


The consequent table, following the depicted enumeration, lists the item part the Scalable Vector Graphic (SVG) design file and its derivative Numerical Control (NC) file driving the CNC plasma cutter.
| part | SVG | NC |
|+++|++++++++++|++++++++|
| 1 | [cover_r1_normalised.svg](assets/frame-covers/SVG/cover_r1_normalised.svg) | [cover_r1_normalised.nc](assets/frame-covers/NC/cover_r1_normalised.nc) |
| 2 | [cover_r2_normalised.svg](assets/frame-covers/SVG/cover_r2_normalised.svg) | [cover_r2_normalised.nc](assets/frame-covers/NC/cover_r2_normalised.nc) |
| 2 | [cover_r2_side_door_normalised.svg](assets/frame-covers/SVG/side_door_normalised.svg) | [cover_r2_side_door_normalised.nc](assets/frame-covers/NC/side_door_normalised.nc) |
| 3 | [cover_r3_normalised.svg](assets/frame-covers/SVG/cover_r3_normalised.svg) | [cover_r3_normalised.nc](assets/frame-covers/NC/cover_r3_normalised.nc) |
| 4 | [cover_r4_normalised.svg](assets/frame-covers/SVG/cover_r4_normalised.svg) | [cover_r4_normalised.nc](assets/frame-covers/NC/cover_r4_normalised.nc) |
| 5,6 | [cover_r56_normalised.svg](assets/frame-covers/SVG/cover_r56_normalised.svg) | [cover_r56_normalised.nc](assets/frame-covers/NC/cover_r56_normalised.nc) |
| 7,8 | [cover_r78_normalised.svg](assets/frame-covers/SVG/cover_r78_normalised.svg) | [cover_r78_normalised.nc](assets/frame-covers/NC/cover_r78_normalised.nc) |
| 9 | [cover_r9_normalised.svg](assets/frame-covers/SVG/cover_r9_normalised.svg) | [cover_r9_normalised.nc](assets/frame-covers/NC/cover_r9_normalised.nc) |
| 1 (Left) | [cover_l1_normalised.svg](assets/frame-covers/SVG/cover_l1_normalised.svg) | [cover_l1_normalised.nc](assets/frame-covers/NC/cover_l1_normalised.nc) |
| 2 (Left) | [cover_l2_normalised.svg](assets/frame-covers/SVG/cover_l2_normalised.svg) | [cover_l2_normalised.nc](assets/frame-covers/NC/cover_l2_normalised.nc) |
| 10 | [bottom_front_normalised.svg](assets/frame-covers/SVG/bottom_front_normalised.svg) | [bottom_front_normalised.nc](assets/frame-covers/NC/bottom_front_normalised.nc) |
| 11 | [top_front_normalised.svg](assets/frame-covers/SVG/top_front_normalised.svg) | [top_front_normalised.nc](assets/frame-covers/NC/top_front_normalised.nc) |
| 12 | [cover_front_normalised.svg](assets/frame-covers/SVG/cover_front_normalised.svg) | [cover_front_normalised.nc](assets/frame-covers/NC/cover_front_normalised.nc) |
| 13 | [cover_back_normalised.svg](assets/frame-covers/SVG/cover_back_normalised.svg) | [cover_back_normalised.nc](assets/frame-covers/NC/cover_back_normalised.nc) |

The non symmetric parts 1 and 2 are provided for both left and the right side. The symmetric parts 3-9 are provided just for the right side since these are the same with thei left side. 


Part 2 of the right side contains also the design plan to fabricate a side door with its sealing cover as seen in the following diagram. The side door is used to provide access to the charging socket of the vehicle.

![Cover side door](_figures/06.charching-door.png)

The fabricated side door as seen from within the vehicle can be viewed, via the following photo.

![Door photo internal](_figures/07-door_in.jpg)

Likewise, the next photo snapshots the door from its outer side.

![Door photo external](_figures/08-door_outside.jpg)

The following diagram layouts all covers made out of a 2 mm iron sheet, indicating also the approximate area occupying within a standard metal sheet profile.

![Metal sheet 2 mm covers](_figures/03_2mm_covers.png)


The following photo, showcases the plasma cutter fabricating part 2 of the left side.

![Plasma cut photo a](_figures/03_plasma_cut_a.jpg)

To provide additional protection, a 3 mm black iron sheet was employed overlaying completely the battery compartment. The following schematic encodes the dimensions of the silhouette of the cover fabricated manually because it was too big for our DIY plasma cutter. 

![Battery cover 3 mm schematic](_figures/04-battery-cover-3mm.png)

Also too big to fabricate in our DIY plasma cutter, the back top and back bottom covers silhouette dimensions are annotated in the following schematic.

![Top bottom back cover](_figures/05.top-bottom_back_covers.png)


The fabricated details of the battery cover and the top back cover as these are mounted consequently in the vehicle, are showcased by the consequent photo.

![Battery cover actual](_figures/05-battery-cover-actual.jpg)

The fabricated left side part 1,2 covers, mounted in the vehicle are showcased by the following photo.

![Covers photo a](_figures/09-covers-placed-a.jpg)

The next photograph depicts the detail of the back left side covers as these change into the battery compartment, parts 1-6.

![Cover photo b](_figures/10_covers-placed-b.jpg)

The following photo snapshots the covers drying after painted with a primer and orange oil paint.

![Covers painted](_figures/12_covers_painted.jpg)


# Summary

All covers of the vehicle were illustrated and enumerated. The cover parts design plans and plasma cut source files were organized and indexed. The raw material needed to fabricated the vehicles protected covers where documented and linked to indicative suppliers provided. The vehicle mounted in a vertical position in a transferring platform with most of its covers mounted is presented in the closing image below.

![Covers established](_figures/13_covers-placed_overview.jpg)


