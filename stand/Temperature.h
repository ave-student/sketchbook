#ifndef Temperature_h
#define Temperature_h

#define ONE_WIRE_BUS 2

#include "Arduino.h"
#include "OneWire.h"
#include "DallasTemperature.h"
#include "Time.h"

class Temperature {
	public:
		float getOutTemp();
		float getInTemp();
		void setRespTime(long time);    // установить время опроса

	private:
		long _respTime;    // значение времени опроса
		OneWire _oneWire(ONE_WIRE_BUS);
		Time _time;
		DallasTemperature _outSensor(&_oneWire);

};

#endif
