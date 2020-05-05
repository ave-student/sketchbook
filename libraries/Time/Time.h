#ifndef Time_h
#define Time_h

#include "Arduino.h"

class Time {
	public:
		Time();
		boolean delay(long ms);    // метод реализует задержку

	private:
		long _initTime;    // время включение задержки
		boolean _onDelay;    // флаг активности задержки

};

#endif
