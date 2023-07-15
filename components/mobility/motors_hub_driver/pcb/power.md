### Motor hub power module

This sub-module of the Motors Hub Driver decomposes the functionality of powering, sensing the current and reversing the direction of a motor hub driver. 

The Motors Hub Power Driver is composed of the following components :

1. A PCB board, with its schematics located within PCB.CNC.power\ folder.
2. The PCB top side printed cover located within PCB.PRINT.Stickers.
3. Two relays trigger/able with 3v [HK4100F-DC 3V SHG Relay 6Pin]
4. One car relay, trigger/able with 12v with 20 amp capacity [6770718 - 12v 20A].
5. An [ACS712] 20 amp current Sensor.
6. One 5 pin male header.
7. A JST-SM 2pin connector, connecting with the motor driver reverse function.
8. One small wire for connecting the PCB with the 20 amp relay.
9. 3 pin headers for connecting the PCB with the 20 amp relay.
10. 4 cm high current wire.
11. Female high current connector.
12. Glue gun to secure the copper side of the pcb from extrernal factors applied after its function has been verified.

This sub-module is used twice, within the Motors hub driver module.

Remarks :

- Two pins of the 3v relays are trimmed as illustrated in the schematics, thus interfacing with the PCB with only the utilised pins.
- The ACS712 20 amp current sensor pins/connectors are de-soldered and pins are solder from the bottom side of the sensor's PCB interfacing with the PCB of the module.
- It was noticed that not all HK4100F-DC 3V were operational with esp32. About 45% of these relays are manufactured more efficiently and are triggerable by the low amp of the esp32.  During test the diferentiating factor wast that these operated, were triggerable with less voltage like 1.8v, while others required at least 2v.
    
Document location :  /agrofelis/components/mobility/motors_hub_driver/pcb/power.md
 