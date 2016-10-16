/*
IOLib.h - библиотека-обертка операций ввода/вывода для Arduino...
*/

#include "IOLib.h"

DigitalInput newDI(byte pin) {
	DigitalInput din(pin);
	return din;
}

DigitalInput newDI(byte pin, long debounceTime) {
	DigitalInput din(pin, debounceTime);
	return din;
}

SDigitalOutput newDO(byte pin) {
	SDigitalOutput dout(pin);
	return dout;
}

SDigitalOutput newDO(byte pin, byte initState) {
	SDigitalOutput dout(pin);
	return dout;
}
