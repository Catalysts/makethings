# Drones

In this workshop you will learn how to build a transmitter station to control your drone.

# Requirements

- 1x Arduino Pro Micro
- 1x A7105 RF chip
- 1x Breadboard
- 10x Cables
- 1x 10kΩ Resistor
- 2x LEDs (optional)

Optional (reset button):
- 1x Pushbutton
- 2x Cables

Optional (LEDs):
- 2x LED
- 2x Resistor
- 4x Cables

# Basic flow

## Build the transmitter station

![](fritzing/wiring.png)

1. Attach the A7105 to the middle of the breadboard (see image).
2. Wire the 3.3v of the arduino board to the live rail on the breadboard.
3. Wire the ground pin of the arduino to the ground rail on the breadboard.
4. Connect the VDD pin of the A7105 to the live rail of the breadboard.
5. Connect the two GND pins of the A7105 chip to the ground rail of the breadboard.
6. Wire the MOSI pin of the Arduino board to one end of the 10kΩ resistor
7. Wire the other end of the resistor to the SDIO pin of the A7105
8. Wire gio1 of the A7105 to the MISO port of the Arduino board
9. Wire 'SCK' of the arduino to 'SCK' on the A7105
10. Wire pin 10 of the arduino to 'SCS' on the A7105

Optional: Add a push button for resetting the arduino:
1. Attach the push button to the breadboard
2. Wire one side of the push button to the RST pin of the arduino
3. Wire the other side of the push button (as seen in the image) to the ground rail of the breadboard

Optional: Add LEDs to indicate the binding status:
1. Add the LEDs, resistors and cables as seen in the image.

## Upload software



# Advance flow

## Control drone through camera




# Links
* [Original Tutorial (for Arduino Due)](www.instructables.com/id/Easy-Android-controllable-PC-Interfaceable-Relati/)
* [Pro Micro & Fio v3 Hookup Guide](https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide)

# Appendices
