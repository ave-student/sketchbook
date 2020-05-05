#ifndef Timer_h
#define Timer_h

class Timer {
	public:
		Timer();
		int next();
		void start();
		void pause();
		void stop();
		bool delay(long time);
		void setInitTime(long time);
	private:
		int _curTime;
		bool _onStart;
		bool _onDelay;
		long _initTime;
};

#endif
