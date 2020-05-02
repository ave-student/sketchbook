/*
clock.h - скетч часов с будильником и
измерением температуры, влажности в помещении.
*/

#ifndef clock_h
#define clock_h

class Clock {
	public:
		int mode;
		int getTemperature();
		int getHummidity();
	private:
};

#endif clock_h
