/*
IOLib.h - библиотека-обертка операций ввода/вывода для Arduino...
*/

#include "IOLib.h"
#include "DigitalInput.h"
#include "DigitalOutput.h"

DigitalInput newDI(byte pin) {
	DigitalInput din(pin);
	return din;
}

DigitalInput newDI(byte pin, long debounceTime) {
	DigitalInput din(pin, debounceTime);
	return din;
}

DigitalOutput newDO(byte pin) {
	DigitalOutput dout(pin);
	return dout;
}

DigitalOutput newDO(byte pin, byte initState) {
	DigitalOutput dout(pin);
	return dout;
}
