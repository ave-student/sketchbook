#include "Temperature.h"

Temperature::Temperature(void) {

}

Temperature::setOutPin(int pin) {
	this->_outPin = pin;
	
}

Temperature::setInPin(int pin) {
	this->_inPin = pin;
}
