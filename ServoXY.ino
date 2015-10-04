/*
* ----------------------------------------------------------------------------
* "THE BEER-WARE LICENSE" (Revision 42):
* <phk@FreeBSD.ORG> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think
* this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
* ----------------------------------------------------------------------------
*/

#include <Servo.h>

#define pinAxisX A0
#define pinAxisY A1
#define pinServo1 5
#define pinServo2 6

Servo servo1;
Servo servo2;

int x, y;
unsigned int pos[] = { 10, 90, 170, 90 };    

void setup() {
  Serial.begin(9600);
  Serial.println("\nStarting arduino...");
  
  servo1.attach(pinServo1);
  servo2.attach(pinServo2);
  
  servo1.write(90);
  servo2.write(90);
}

void loop() {  
  getAxis();  
  moveServos();  
}

void getAxis() {
  x = analogRead(pinAxisX);
  y = analogRead(pinAxisY);
  
  x = map(x, 0, 1023, 0, 180);
  y = map(y, 0, 1023, 0, 180);
  
  Serial.print("x: "); Serial.print(x);
  Serial.print(" y: "); Serial.println(y);
}

void moveServos() {
  servo1.write(x);
  servo2.write(y);
}
