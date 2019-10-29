#include"sensor.h"
#include"wheels.h"

//Sensor s1 = Sensor(13, 12);
Wheel l_wheel = Wheel(32, 2, 4, 3, 5);
Wheel r_wheel = Wheel(32, 6, 8, 7, 9);

Sensor s_left = Sensor(13, 12);
Sensor s_right = Sensor(10, 11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  l_wheel.setSpeed(800);
  r_wheel.setSpeed(800);
}

void loop() {
  // put your main code here, to run repeatedly:
  int distance_left = s_left.getDistance();
  int distance_right = s_right.getDistance();
  rotateWheels(&l_wheel, &r_wheel, &s_left, &s_right);
}
