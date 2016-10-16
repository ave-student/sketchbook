/*
DigitalOutput.h - библиотека-обертка для работы с цифровыми выходами.
*/

#include "Arduino.h"
#include "DigitalOutput.h"

DigitalOutput::DigitalOutput(byte pin) {
	_initPin(pin);
}

DigitalOutput::DigitalOutput(byte pin, byte initState) {
	_initPin(pin);
	digitalWrite(_pin, initState);
}

void DigitalOutput::_initPin(byte pin) {
	_pin = pin;
	pinMode(_pin, OUTPUT);
}

int DigitalOutput::read(void) {
	return digitalRead(_pin);
}

void DigitalOutput::write(byte state) {
	digitalWrite(_pin, state);
}

void DigitalOutput::high() {
	digitalWrite(_pin, HIGH);
}

void DigitalOutput::low() {
	digitalWrite(_pin, LOW);
}

void DigitalOutput::inverse() {
	digitalWrite(_pin, !digitalRead(_pin));
}
