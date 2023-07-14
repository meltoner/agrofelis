The folder contains the SVG files defining the wholes and paths of the pcb.
Moreover, the folder contains the actionable NC derivatives, produced via 
the respective JavaScript applications

SVG 
- 1.DRILL.svg
- 2.CURVE.svg

NC

- 1.DRILL.ENHANCED.nc
- 2.CURVE.ENHANCED.NC

JavaScript
- LineRoutesToHoles.html
- LineRoutesToWire.html

The transformation procedure follows :

A. FROM SVG EXPORT IN RHINO A4 1:1
OPEN IN ILLUSTRATOR AND SCALE X * 1.887640
MOVE OBJECT TO LEFT DOWN CORNER
SAVE

B. OPEN IN LASERGRBL AND SAVE AS CNC BOTH FILES

C. EDIT THE CNC CODE AND PROCESS IT VIA THE 

LineRoutesToHoles.html THE DRILLING AND THE
LineRoutesToWire.html THE WIRING CNC CODE

USE A DRILL BIT IN THE FOR THE DRILLING
USE A PCB NOSE BIT FOR THE WIRING

DRIL.svg IS THE DRILLING PART
CURVE.svg IS THE WIRING PART

---------------------
189.26611224