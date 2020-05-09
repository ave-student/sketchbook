/*
clock.h - скетч часов с будильником и
измерением температуры, влажности в помещении.
*/

#ifndef clock_h
#define clock_h

#include "PushButton.h"

class Clock {
	public:
		void begin(void);
		void update(void);
		char* getDate(void);
		char* getTime(void);
		int* getDateTime(void);
		int getMin(void);
		int getHour(void);
		int getDay(void);
		int getMonth(void);
		int getYear(void);
		void setDateTime(int min, int hour, int day, int month, int year);
		void setAlarm(int min, int hour);
		void alarmOn(void);
		void alarmOff(void);
		void switchAlarm(void);
		float getTemperature(void);
		float getHummidity(void);
	private:
		boolean _alarmActivity;
		int dateTime[6];
};

#endif clock_h
