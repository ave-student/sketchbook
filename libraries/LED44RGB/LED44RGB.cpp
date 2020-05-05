/*********************************************************************
* LED44RGB - библиотека для работы со светодиодной RGB матрицей 4х4. *
*                                                                    *
*********************************************************************/

#include "LED44RGB.h"

LED44RGB::LED44RGB(void) {
	this->_delayTime = 2;
	this->_onDelay = false;
	this->_initTime = 0;
}

// назначить пины
void LED44RGB::setPins(int dPin, int cPin, int lPin) {
	this->_dataPin = dPin;
	this->_clockPin = cPin;
	this->_latchPin = lPin;
}

void LED44RGB::run(void) {
	if (this->_delay(this->_delayTime)) {

	}
}

// функция задержки
boolean LED44RGB::_delay(long ms) {
	if (!this->_onDelay) {
		this->_onDelay = true;
		this->_initTime = millis();
		return false;
	}
	if (millis() - this->_initTime < ms) {
		this->_onDelay = false;
		return true;
	}
	return false;
}
