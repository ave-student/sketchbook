#include "Arduino.h"
#include "Timer.h"

Timer::Timer(void) {
	this->_curTime = 0;
	this->_onStart = false;
	this->_onDelay = false;
	this->_initTime = 0;
}

int Timer::next(void) {
	if (this->_onStart) {
		if (this->delay(1000)) {
		}
		else {
			this->_curTime++;
			if (this->_curTime > 9999) {
				this->stop();
			}
		}
	}
	return this->_curTime;
}

void Timer::setInitTime(long time) {
	this->_initTime = time;
}

void Timer::start(void) {
	this->_onStart = true;
}

void Timer::pause(void) {
	this->_onStart = false;
}

void Timer::stop(void) {
	this->_onStart = false;
	this->_curTime = 0;
}

bool Timer::delay(long time) {
	if (!this->_onDelay) {
		this->_initTime = time;
		this->_onDelay = true;
		return true;
	}
	if ((millis() - this->_initTime) > time) {
		this->_onDelay = false;
		return false;
	}
	return true;
}
