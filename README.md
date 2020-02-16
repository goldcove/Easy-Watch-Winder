# Easy Watch Winder
*Yet another Arduino based watch winder*

Easy Watch Winder is an user friendly, low cost and watch-safe automatic watch winder.

Simply set the turns per day (TPD) and rotation variable in accordance with your wathc specification (See [Orbita.com](https://www.orbita.com/winder-support)) and run the program :-D

The code is well commented and should be easy to modify for new and experienced programmers alike.

## Software requirements
Stepper.h built-in Arduino library (Note: Risk of motor overheat. See code for comment and fix).

## Hardware requirements
- Ardunio or compatible development board
- Stepper motor – E.g. Welleman vma401 (28BYJ-48)) with ULN2003 driver board (https://www.velleman.eu/downloads/29/vma401_a4v01.pdf)
- 5mm motor shaft coupler with flange coupling
- Arduino board
- Wires
- USB cable and power adapter
- Some sort of housing, e.g. a small box.
- Some small screws to attach motor and shaft coupler
[Photo showing connections on the Arduino](https://github.com/goldcove/Easy-Watch-Winder/raw/master/Easy%20Watch%20Winder%20connections%20v1.0.jpg)

## Development milestones
### Version 1.0
- Basic software and hardware to safely wind a watch.
  - Proof-of-concept watch mount and electronic housing

### Version 2.0
- Advanced operation
  - TPD selector
  - Turn direction selector
  - Power switch (preferably to cut power to both Arduino and stepper motor)
- Permanent watch mount and electronics housing

## Background info
### Watch-specific factors (variables) affecting the programming:
- Turns per day (TPD)
  - Typically between 500-1000, ref. [Orbita.com](https://www.orbita.com/winder-support)
- Rest (time)
  - Function of TPD and RPM.
- RPM.
  - Commercial watch winders typically use approx. 6-8 rpm.
- Direction of turning
  - Clockwise (CW)
  - Counter clockwise (CCW)
  - Both
- Smooth motor operation

Example watch movement specification:

| Movement | TPD | Turn direction |
| ---      | --- | ---            |
| Sellita SW200 | 650-800 | Both |

### Factors (Watch-specific) affecting the hardware/construction:
- Three-way switch for selecting rotation
- Two-way on-off switch
- Rheostat for adjusting TPD
- Angle of watch housing?
    - Commercial watch winders use both vertical, horizontal and slanted mounting. Probably does not affect performance.
- De-Magnetization?
  - One source mentions this, probably safe to disregard.

### Watch winder operation
- https://www.orbita.com/winder-support
- https://blog.crownandcaliber.com/how-to-use-a-watch-winder/
- https://www.buywatchwinders.com/blog/how-to-properly-use-and-set-your-watch-winder/
- https://www.barringtonwatchwinders.com/how-it-works
- https://www.timetutelary.co.uk/pages/what-is-a-watch-winder

### Other DIY watch winder projects
- https://www.youtube.com/watch?v=9rfCjYOQ4L8

### Programming examples and tidbits
- https://www.arduino.cc/reference/en/
- https://www.instructables.com/id/How-to-use-Potentiometer-Arduino-Tutorial/
- https://www.arduino.cc/en/tutorial/potentiometer
- http://www.lucadentella.it/en/2014/08/01/interruttore-a-tre-posizioni-e-arduino/
- https://www.open-electronics.org/the-power-of-arduino-this-unknown/
  - Options for powering the Arduino, see VIN.
## License
This project is licensed under GPLv3 (or later)
