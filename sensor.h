using namespace std;

class Sensor {
	private:
		unsigned int TRIG_PIN;
		unsigned int ECHO_PIN;

	public:
		Sensor() {
			this->TRIG_PIN = 13;
			this->ECHO_PIN = 12;
			pinMode(this->TRIG_PIN, OUTPUT);
			pinMode(this->ECHO_PIN, INPUT);
		}

		Sensor(unsigned int TRIG_PIN, unsigned int ECHO_PIN) {
			this->TRIG_PIN = TRIG_PIN;
			this->ECHO_PIN = ECHO_PIN;
			pinMode(this->TRIG_PIN, OUTPUT);
			pinMode(this->ECHO_PIN, INPUT);
		}

		int getDistance();
		unsigned int getDuration();
};


unsigned int Sensor::getDuration() {
	digitalWrite(this->TRIG_PIN, LOW);
	delayMicroseconds(2);
	digitalWrite(this->TRIG_PIN, HIGH);
	delayMicroseconds(2);
	digitalWrite(this->TRIG_PIN, LOW);
	delayMicroseconds(2);

	unsigned int duration = pulseIn(this->ECHO_PIN, HIGH);
	return duration;
}

int Sensor::getDistance() {
	unsigned int duration = this->getDuration();
	int distance = duration / 29 / 2;
	return distance;
}
