/* UltraSonic Trash

This is a Trash controled by a UltraSonic Sensor HC-SR04
It' very simple, when something is next of the sensor the trash cover open.

The cover of trash is controled by a servo motor.

by: isca0 - igorsca at gmail dot com

enjoy
 
*/ 

#include <Servo.h> 

Servo motor;

 
#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin

int maximumRange = 200; //Maximum range needed
int minimumRange = 0; //Minimun range needed
long duration, distance; // Duration used to calculate distance


 
void setup() 
{ 
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  motor.attach(9);  // attaches the servo on pin 9 to the servo object 
} 

void open_trash()
  {
  
    motor.write(125);
    delay(1000);
    
  }

void close_trash()
{
  motor.write(5);
  delay(1000);
}

void loop() 
{
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 

 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 Serial.println(distance); 
 
 if (distance > 50) {
 
  motor.write(20);
  delay(1000);
  //close_trash();
  //Serial.println("10CM VEio!!!");
 }
 else {
  motor.write(170);
  delay(1000);
  //open_trash();
 }
 

 delay(50);



}


 

