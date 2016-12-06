#include "Temperature.h"

Temperature::Temperature(void) {
	this->_outSensor.begin();
}

void Temperature::setRespTime(long time) {
	this->_respTime = time;
}

float Temperature::getOutTemp(void) {
	this->_outSensor.requestTemperatures();
	return this->_outSensor.getTempCByIndex(0);
}
