#include<Stepper.h>

using namespace std;

class Wheel {
	private:
		unsigned int pin1;
		unsigned int pin2;
		unsigned int pin3;
		unsigned int pin4;
		unsigned int steps_per_rev;
		Stepper *stepper;
		int rpm;

	public:
		Wheel() {
			this->pin1 = 8;
			this->pin2 = 9;
			this->pin3 = 10;
			this->pin4 = 11;
			this->steps_per_rev = 32;
			stepper = new Stepper(this->steps_per_rev, this->pin1, this->pin2, this->pin3, this->pin4);
			this->rpm = 500;
			(*stepper).setSpeed(this->rpm);
		}
		
		Wheel(unsigned int steps_per_rev, unsigned int pin1, unsigned int pin2, unsigned int pin3, unsigned int pin4) {
			this->pin1 = pin1;
			this->pin2 = pin2;
			this->pin3 = pin3;
			this->pin4 = pin4;
			this->steps_per_rev = steps_per_rev;
			stepper = new Stepper(this->steps_per_rev, this->pin1, this->pin2, this->pin3, this->pin4);
			this->rpm = 500;
			(*stepper).setSpeed(this->rpm);
		}

		void setSpeed(int);
		void incrementSpeed(int);
		void updateRPM(int);
		void step(int);
};

void Wheel::setSpeed(int rpm) {
	this->rpm = rpm;
	(*stepper).setSpeed(this->rpm);
}

void Wheel::step(int steps) {
	(*stepper).step(steps);
}

void Wheel::incrementSpeed(int delta) {
	(*stepper).setSpeed(this->rpm + delta);
}

void rotateWheels(Wheel *w1, Wheel *w2, Sensor *s_left, Sensor *s_right) {
	for (int i = 0; i < 400; i++) {
		int dist_left = s_left->getDistance();
		int dist_right = s_right->getDistance();
		Serial.println(dist_right);
		Serial.println(dist_left);

		if (dist_left >= 50 && dist_right >= 50) {
			for (int i = 0; i < 100; i++) {
				w1->step(1);
				w2->step(1);
			}
		} else if (dist_left < 50) {
			for (int i = 0; i < 100; i++) {
				w1->step(1);
				w2->step(0);
			}
		} else if (dist_right < 50) {
			for (int i = 0; i < 100; i++) {
				w1->step(0);
				w2->step(1);
			}
		}
	}
}