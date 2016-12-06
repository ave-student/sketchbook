#ifndef Temperature_h
#define Temperature_h

#include "Arduino.h"
#include "OneWire.h"
#include "DallasTemperature.h"
#include "Time.h"

class Temperature {
	public:
		float getOutTemp();
		float getInTemp();
		void setOutPin(int pin);
		void setInPin(int pin);

	private:
		OneWire _oneWire;
		Time _time;
		int _outPin;
		int _inPin;

};

#endif
