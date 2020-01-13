/* Yet another arduino based watch winder
 * Copyright goldcove@gmail.com
 * License: GPLv3 or later
 */
<<<<<<< HEAD
#include <Stepper.h>
const float stepsPerRevolution = 2048; //Steps required for one shat revolution. based on your motor speed and gear ratio.
int rpm = 15; /* set the speed in rotation per minute (rpm).
              Test and see what rpm your motor can handle...
              rpm less than 0.5 risks that your program runs continuously*/
Stepper steppmotor(stepsPerRevolution, 8, 10, 9, 11); //initialize the stepper. In accordance with your motor. See https://www.arduino.cc/en/reference/stepper
int direction; //Motor turnning direction. 0=both, 1=clockwise, 2=counterclockwise. In accordance with your watch requirements.
int tpd; //Number of turns per day, in accordance with your watch requirements.
int turns; //number of turns to turn for each run cycle
unsigned long rest; //seconds to rest between each run cycle
int cw; //clockwise
int ccw; //counterclockwise
int debug=1; //enable debuging

void setup() {
  steppmotor.setSpeed(rpm);
  // initialize the serial port:
  Serial.begin(9600);
  tpd=725;
  direction=0;
  Serial.println("watchwinder dev");
  if (debug) {
    Serial.print("tpd: ");
    Serial.println(tpd);
    Serial.print("direction: ");
    Serial.println(direction);
  }
}

void loop() {
  //Read tpd from potentiometer (v2)
  //Read direction (v2)

  /*Calculate turns for each run cycle and rest in seconds between cycle.
  The winder will run every hour of the day.*/
  turns=tpd/24; //turns per hour
  rest=3600-(turns*60/rpm); //Remainig seconds in hour is rest.
  if (debug) {
    Serial.print("turns: ");
    Serial.println(turns);
    Serial.print("rest: ");
    Serial.println(rest);
  }

  //run
  switch (direction) {
    case 0: //both directions
      cw=turns/2;
      ccw=turns-ccw; //in case odd number
      Serial.println("running cw");
      steppmotor.step(stepsPerRevolution*cw);
      Serial.println("running ccw");
      steppmotor.step(-stepsPerRevolution*ccw);
      break;
    case 1: //clockwise
      Serial.println("running cw");
      steppmotor.step(stepsPerRevolution*turns);
      break;
    case 2: //counterclockwise
      Serial.println("running ccw");
      steppmotor.step(-stepsPerRevolution*turns);
      break;
  }
  //rest between run cycles
  Serial.println("resting");
  delay(rest*1000); //delay n seconds
=======

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
>>>>>>> stepper_motor
}
