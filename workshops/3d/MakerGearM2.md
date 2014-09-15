# Slic3r Settings for Makegear M2

## General
* Bed size: 200mm x 240mm
* Print center: 100mm : 120mm
* Z-offset: 0
* G-code flavor: RepRap
* Extruder 
    * Nozzle diameter: 0.35mm
* Retraction
    * Length: 4.5mm
    * Lift Z: 0

## Start G-code
```
M84 S0 ; don't let go of motors
M108 S155 ; make sure extruder and electronics fans are running
M140 S70
M104 S210
G28 X0 Y0; home X and Y
G1 F10800 ; set high speed
G1 Y20 ; move into the platform along Y
G1 X205 ; move off the platform end along X
G28 Z0 ; home Z now - blobs won't hit the platform
G1 F400
G1 Z10 ; lift Z a little
M190 S70
M109 S210 ; wait for temperature to be reached
G28 Z0 ; home Z
G92 E0 ; reset extruder position to 0
G1 F300 ; set suitable speed
G1 E25 ; extrude 25mm
G92 E0 ; reset extruder position to 0 - needed for cura/SF
G1 F10800 ; set wipe speed
G1 X0 ; wipe nozzle and move to X0
```

## End G-code
```
M104 S0 ; turn off temperature
M140 S0 ; turn off bed temperature
M106 S255 ; Set fan to full power
G1 X0  F10800 ; home X axis
G91 ; Set relative positioning
G1 Z30 F450 ; Lift 3cm
G90 ; Return to absolute positioning
G1 Y80 F10800 ; Set a sensible Y coordinate
G1 F450 ; Set slow speed
; Now move the X axis back and forth for a while to cool
G1 X160 ; Move X to end
G1 X40; Move X to start
G1 X160 ; Move X to end
;G1 X40; Move X to start
;G1 X160 ; Move X to end
;G1 X40; Move X to start
;G1 X160 ; Move X to end
G1 X0; Home X
M106 S0 ; Disable fan
G1 F10800 ; High speed
G1 Y220 ; present parts for removal
M84 ; disable motors
M108 S0 ; turn off extruder and electronics fans
```