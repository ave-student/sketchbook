#include "Timer.h"

Timer::Timer(void) {
	this->_onDelay = false;
	this->_initTime = 0;
}

bool Timer::delay(long time) {
	if (!this->_onDelay) {
		this->_initTime = millis();
		this->_onDelay = true;
		return true;
	}
	if ((millis() - this->_initTime) > time) {
		this->_onDelay = false;
		return false;
	}
	return true;
}
