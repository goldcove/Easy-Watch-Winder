# watchwinder
*Yet another Arduino based watch winder*

## Requirements

### Software
Sellita Movement SW200:
- TPD: 650-800
- Turn direction: Both

### Hardware
Step motor:
Welleman vma401 with ULN2003 driver board (https://www.velleman.eu/downloads/29/vma401_a4v01.pdf)

## Operation

## Development milestones
### Version 1.0
- Basic software and hardware to safely wind a watch.
### Version 2.0
- Advanced operation
  - TPD selector
  - Operation Selector
  - Power switches.

## Background info
### Watch-specific factors (variables) affecting the programming:
- Turns per day (TPD)
- Rest (time)
- Direction of turning
- Smooth motor operation

### Factors (Watch-specific) affecting the hardware/construction:
- Three-way switch for selecting rotation
- Two-way on-off switch
- Rheostat for adjusting TPD
- Noise (operation)
- Angle of watch housing (?)
- De-Magnetization

### Watch winder operation
- https://www.orbita.com/winder-support
- https://blog.crownandcaliber.com/how-to-use-a-watch-winder/
- https://www.buywatchwinders.com/blog/how-to-properly-use-and-set-your-watch-winder/
- https://www.barringtonwatchwinders.com/how-it-works
- https://www.timetutelary.co.uk/pages/what-is-a-watch-winder

### Other DIY watch winder projects
- https://www.youtube.com/watch?v=9rfCjYOQ4L8

### Programming examples and tidbits
- https://www.instructables.com/id/How-to-use-Potentiometer-Arduino-Tutorial/
- https://www.arduino.cc/en/tutorial/potentiometer
-

## License
This project is licensed under GPLv3 (or later)
