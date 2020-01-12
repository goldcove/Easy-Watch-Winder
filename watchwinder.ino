/* Yet another arduino based watch winder
 * Copyright goldcove@gmail.com
 * License: GPLv3 or later
 */

#include <Stepper.h>

//watchwinder
const float stepsPerRevolution = 2048; 
Stepper steppmotor(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // put your setup code here, to run once:
  //watchwinder
  // set the speed at 60 rpm:
  steppmotor.setSpeed(8);
  // initialize the serial port:
  Serial.begin(9600);
  Serial.println("watchwinder dev");
}

void loop() {
  // put your main code here, to run repeatedly:
  // step one revolution  in one direction:
  Serial.println("clockwise");
  steppmotor.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  steppmotor.step(-stepsPerRevolution);
  delay(500);
}
