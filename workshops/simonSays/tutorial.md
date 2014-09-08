# Play Simon with Arduino

In this workshop we are going to build the Simon game (<http://en.wikipedia.org/wiki/Simon_(game)>) with Arduino. To make the assembly routine faster, I reduced the size of the available colors to three, but the code will permit very easily to add extra colors.
A round in the game consists of the device lighting up one or more LEDs, and playing a corresponding note, in a random order, after which the player must reproduce that order by pressing the buttons. 

![](imgs/simon_s.jpg)

>This is what you will build in this workshop.


## Requirements

- 1 x Arduino
- 3 x LED's of different colours
- 3 x Buttons
- 1 x Breadboard
- 1 x Piezo speaker
- 3 x 220Ω resistors for the LEDs
- 3 x 10kΩ resistors for the buttons
- 1 x 100Ω resistor for the speaker
- N x jumpers

### Tools / Equipment

- Laptops with Arduino IDE installed
- USB cables to load sketches onto Arduino

## Flow 1

In this simple flow we'll just check that Arduino and the IDE in your machine are fully functional. We are goin to upload a simple sketch (that's how arduino programs are called) that will blink a led.
Most Arduino boards already have an internal LED attached to pin 13 on the board itself, so there's no need yet to use any additional hardware.

1. Download the IDE at <http://arduino.cc/en/Main/Software>
2. Follow the simple instructions, based on your platform at <http://arduino.cc/en/Guide/Windows>, <http://arduino.cc/en/Guide/MacOSX>, <http://www.arduino.cc/playground/Learning/Linux>

Congratulations! We are now ready to so more interesting things!

## Flow 2

In this simple flow we'll start to plug the components on the breadboard. Please insert the components as shown in the following picture. You can notice that the connected dots in the breadboards are green. 

![](imgs/flow2.png)

Open the sketch flow2 (sketches/flow2.ino) and upload it to the board. It's very simple: when you push the button, the led is lighted up. The purpose of this sketch is to let you familiarize in creating small circuits on the breadboard and in understanding the basic API of Arduino.

## Flow 3

In this last flow, we'll complete the game and we'll finally have some fun playing with it.
To start, repeat what we do in flow2 for three times, so to have not one, but three combinations of led + button. Then, we need to add the Piezo speaker (sometimes also called Buzzer) to provide some fancy sounds.

The final result should look similar to the picture (you could connect the lower leg of the LEDs directly to the ground horizontal line of the breadboard. In this way you don't have to connect the three little black wires):

![](imgs/flow3.png)

Open the sketch flow3 (sketches/flow3.ino) and upload it to the board.

"The code uses an extra file, pitches.h. This file contains all the pitch values for typical notes. For example, NOTE_C4 is middle C. NOTE_FS4 is F sharp, and so forth. This note table was originally written by Brett Hagman, on whose work the tone() command was based. You may find it useful for whenever you want to make musical notes." 

Have fun!





## Aditional resources

1. Arduino <http://arduino.cc>
2. Fritzing <http://fritzing.org>
3. Arduino Tone functions <http://arduino.cc/en/Reference/Tone>
