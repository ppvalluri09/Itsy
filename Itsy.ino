#include"sensor.h"
#include"wheels.h"

//Sensor s1 = Sensor(13, 12);
Wheel l_wheel = Wheel(32, 2, 4, 3, 5);
Wheel r_wheel = Wheel(32, 6, 8, 7, 9);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  l_wheel.setSpeed(800);
  r_wheel.setSpeed(800);
}

void loop() {
  // put your main code here, to run repeatedly:
//  int distance = s1.getDistance();
//  Serial.println(distance);
//  delay(500);
  rotateWheels(&l_wheel, &r_wheel);
}
