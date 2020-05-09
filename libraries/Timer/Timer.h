#ifndef Timer_h
#define Timer_h

#include "Arduino.h"

class Timer {
	public:
		Timer();
		bool delay(long time);

	private:
		bool _onDelay;
		long _initTime;
};

#endif
