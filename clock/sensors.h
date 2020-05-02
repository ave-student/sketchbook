/*
sensors.h - интерфейс датчиков.
*/

#ifndef sensors_h
#define sensors_h

class Sensor {
	public:
		virtual float getValue();
};

class TemperatureSensor : public Sensor {
	public:
		float getValue();
		void setCorrection(float value);
	private:
		float correctionValue = 0;
};

#endif sensors_h
