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
			this->rpm = 10;
			(*stepper).setSpeed(this->rpm);
		}
		
		Wheel(unsigned int steps_per_rev, unsigned int pin1, unsigned int pin2, unsigned int pin3, unsigned int pin4) {
			this->pin1 = pin1;
			this->pin2 = pin2;
			this->pin3 = pin3;
			this->pin4 = pin4;
			this->steps_per_rev = steps_per_rev;
			stepper = new Stepper(this->steps_per_rev, this->pin1, this->pin2, this->pin3, this->pin4);
			this->rpm = 10;
			(*stepper).setSpeed(this->rpm);
		}

		void setSpeed(int);
		void incrementSpeed(int);
		void updateRPM(int);
		void step();
};

void Wheel::setSpeed(int rpm) {
	this->rpm = rpm;
	(*stepper).setSpeed(this->rpm);
	this->step();
}

void Wheel::step() {
	(*stepper).step(this->steps_per_rev);
}

void Wheel::incrementSpeed(int delta) {
	this->rpm = this->rpm + delta;
	(*stepper).setSpeed(this->rpm);
	this->step();
}
