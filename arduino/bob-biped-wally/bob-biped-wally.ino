/* First Step for a Biped
 *  
 *  This first version must be a 4 servos 9g responding to an pot
 *  The pot values must be printed on serial 
 */

#include <Servo.h>

Servo rfoot; //right foot
Servo lfoot; //left foot
Servo rbut; //right but
Servo lbut; //left but


int potpin = 0; //analog ping A0 connect to the first pot
int potA; //prints of my pot

int stepa;
int pevai = 1;

void setup() {
  
  Serial.begin(9600);
  rfoot.attach(3);
  //lfoot.attach(5);
  //rbut.attach(6);
  //lbut.attach(9);
  //lfoot.write(30);
  
}

void dance() {

  if (stepa == 0) {delay(1000); pevai = 1 ;}
  if ( stepa == 87) {delay(1000); pevai = -1;}
  
  stepa += pevai;
  Serial.println(stepa);
  rfoot.write(stepa);
  lfoot.write(stepa);
  delay(10);
}

void potcontrol(){
  
  //poting controling two servos... rfoot and lfoot
  potA = analogRead(potpin); //reading pot on potA
  Serial.println(potA);
  potA = map(potA, 0, 1023, 0, 180);
  rfoot.write(potA);
  //lfoot.write(potA);
  //rbut.write(potA);
  //lbut.write(potA);
  delay(15);
}

void walk(){
  
  
}

void loop() {

  //dance();
  potcontrol();  
  //walk();

}
