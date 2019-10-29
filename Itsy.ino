#include"sensor.h"

Sensor s1 = Sensor(13, 12);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int distance = s1.getDistance();
  Serial.println(distance);
  delay(500);
}
