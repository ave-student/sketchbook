#include "Time.h"

Time::Time(void) {
	this->_initTime = 0;
	this->_onDelay = false;
}

boolean Time::delay(long ms) {
	if (!this->_onDelay) {
		this->_initTime = millis();
		this->_onDelay = true;
		return false;
	}
	if (millis() - this->_initTime > ms) {
		this->_onDelay = false;
		return true;
	}
	return false;
}
