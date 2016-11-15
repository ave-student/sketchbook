#ifndef Timer_h
#define Timer_h

#include "Arduino.h"

class Timer {
	public:
		Timer();
		int next();
		void start();
		void pause();
		void stop();
		void setInitTime(int value);
		bool delay(long time);

	private:
		int _curTime;
		bool _onStart;
		bool _onDelay;
		long _initTime;
};

#endif
