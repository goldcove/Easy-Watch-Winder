  /*
 * Easy Watch Winder
 * Yet another arduino based watch winder
 * Copyright goldcove@gmail.com
 * License: GPLv3 or later
 * Code is optimzed for Teensy 3.2 and some pins may be changed if you are using another Arduino board. Specifically analog pins 8 (A8) and 9 (A9) will need to changed to fit your board.
 */
#define VERSION "2.0"

#include <Stepper.h> //Warning: Risk for motor overheat, see note at end of loop().
const int stepsPerRevolution = 2048; //Steps required for one shat revolution. Based on your motor speed and gear ratio.
int rpm = 8; //set the speed in rotation per minute (rpm)
/*
 *  By observing videos of various commercial watch winders I have observerd that rpm usually is around 8.
 *  Test and see what rpm your motor can handle...
 *  Note: rpm less than 1 risks that your program runs continuously
 */
int motorPin1=8; //digital pin 8
int motorPin2=9;
int motorPin3=10;
int motorPin4=11;
Stepper steppmotor(stepsPerRevolution, motorPin4, motorPin2, motorPin3, motorPin1); //initialize the stepper. In accordance with your motor. See https://www.arduino.cc/en/reference/stepper
/*
 * NOTE: Non-standard pin order for the Welleman 401 stepper motor. See https://forum.vellemanprojects.eu/t/no-reverse-arduino-uno-velleman-vma401-5vdc-stepper-motor/14362/2
 * Motor coils 1 and 4 are switched and different from the example in stepper.h background info: https://www.tigoe.com/pcomp/code/circuits/motors/stepper-motors/
 * The motor will work with 1,2,3,4 pin order but with reduced performance and possbily increased wear.
 */
const int readTpdPin=A9; //Pin used to read tpd value from a rheostat.
const int readTurnPin=A8; //Pin used to read turn direction.

int turndirection; //Motor turnning direction. 0=both, 1=clockwise, 2=counterclockwise. In accordance with your watch requirements.
int tpd; //Number of turns per day, in accordance with your watch requirements.
int turns; //number of turns to turn for each run cycle
unsigned long rest; //seconds to rest between each run cycle
int cw; //clockwise
int ccw; //counterclockwise
int debug=0; //enable debuging

void setup() {
  pinMode(motorPin1, OUTPUT); // Set pins to output mode
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  steppmotor.setSpeed(rpm);
  Serial.begin(9600); // initialize the serial port:
  tpd=720;
  turndirection=0;
  Serial.print("Easy Watch Winder v");
  Serial.println(VERSION);
  if (debug) {
    Serial.print("tpd: ");
    Serial.println(tpd);
    Serial.print("turndirection: ");
    Serial.println(turndirection);
    Serial.print("rpm: ");
    Serial.println(rpm);
  }
  Serial.println("");
}

void loop() {
  /*
   * Read direction from three-way switch
   * Based on code from http://www.lucadentella.it/en/2014/08/01/interruttore-a-tre-posizioni-e-arduino/
   */
  int analogValue = analogRead(readTurnPin);
  //int selectedTurndirection;
  if(analogValue < 100) turndirection = 1; //CW
  else if(analogValue < 900) turndirection = 2; //CW
  else turndirection = 0; //Both
  if (debug) { //print debug info
    Serial.print("Selected turn direction: ");
    Serial.println(String(turndirection));
    Serial.println("NOTE: 0=both\t1=CW\t2=CCW");
  }

   tpd = analogRead(readTpdPin); // read the value from the potentiometer
   /*
    * Read TPD from potentiometer
    * Minimum TPD value 500
    * Maximum TPD value 1500
    * based on max/min values from Orbita database (see readme)
    */
   tpd=map(tpd,0,1023,500,1500); //maps analog read value to tpd range
   if (debug) { //print debug info
     Serial.print("input TPD: ");
     Serial.println(String(tpd));
   }

  /*
   * Calculate turns for each run cycle and rest in seconds between cycle.
   * The winder will run every hour of the day.
   */
  turns=tpd/24; //turns per hour
  rest=3600-(turns*60/rpm); //Remainig seconds in hour is rest.
  if (debug) { //print debug info
    Serial.print("turns: ");
    Serial.println(turns);
    Serial.print("time turns (s): ");
    Serial.println(turns*60/rpm);
    Serial.print("time rest (s): ");
    Serial.println(rest);
  }
  /*
   * run
   */

  cw=0;
  ccw=0;
  switch (turndirection) {
    case 0: //both directions
      cw=turns/2;
      ccw=turns-cw; //in case odd number
      break;
    case 1: //clockwise
      cw=turns;
      break;
    case 2: //counterclockwise
      ccw=turns;
      break;
  }
  /*
  * Check the rotaion direction with your particular hardware.
  * Direction is controlled by positive or negative values give to steppmotor.step()
  */
  if (cw) { //running cw
      Serial.println("running cw");
      if (debug) {Serial.print("cw turns: "); Serial.println(cw);}
      steppmotor.step(-stepsPerRevolution*cw);
      delay(500); //short pause before reversing direction. To (possibly) reduce motor strain.
  }
  if (ccw) { //running ccw
      Serial.println("running ccw");
      if (debug) {Serial.print("ccw turns: "); Serial.println(ccw);}
      steppmotor.step(stepsPerRevolution*ccw);
      delay(500); //short pause before reversing direction. To (possibly) reduce motor strain.
  }
  /*
   * rest between run cycles
   */
  Serial.println("resting");
  /*
   *  The stepper.h library keeps some of the pins HIGH between runs.
   *  In order to reduces power consumption and heat buildup in motor,
   *  set all motor pins LOW.
   */
  digitalWrite(motorPin1, LOW); //turn off power to motor
  digitalWrite(motorPin2, LOW); //turn off power to motor
  digitalWrite(motorPin3, LOW); //turn off power to motor
  digitalWrite(motorPin4, LOW); //turn off power to motor
  delay(rest*1000); //delay n seconds
}
