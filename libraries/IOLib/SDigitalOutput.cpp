/*
SDigitalOutput.h - библиотека-обертка для работы с цифровыми выходами.
*/

#include "Arduino.h"
#include "SDigitalOutput.h"

SDigitalOutput::SDigitalOutput() {

}

SDigitalOutput::SDigitalOutput(int pin) {
	_initPin(pin);
}

SDigitalOutput::SDigitalOutput(int pin, byte initState) {
	_initPin(pin);
	digitalWrite(_pin, initState);
}

void SDigitalOutput::_initPin(int pin) {
	_pin = pin;
	pinMode(_pin, OUTPUT);
}

int SDigitalOutput::read(void) {
	return digitalRead(_pin);
}

void SDigitalOutput::write(byte state) {
	digitalWrite(_pin, state);
}

void SDigitalOutput::high() {
	digitalWrite(_pin, HIGH);
}

void SDigitalOutput::low() {
	digitalWrite(_pin, LOW);
}

void SDigitalOutput::inverse() {
	digitalWrite(_pin, !digitalRead(_pin));
}
