/*
DigitalInput.h - библиотека для работы с
цифровыми входами.
*/

#include "Arduino.h"
#include "DigitalInput.h"

DigitalInput::DigitalInput(byte pin) {
	_pin = pin;
	_debounceTime = 50;
	_initVar();
}

DigitalInput::DigitalInput(byte pin, long debounceTime) {
	_pin = pin;
	_debounceTime = debounceTime;
	_initVar();
}

// инициализация параметров
void _initVar(void) {
	_lastTime = 0;
	_lastState = HIGH;
	_state = HIGH;
}

// метод возращает значение времени демпфирования
long DigitalInput::getDebounceTime(void) {
	return _debounceTime;
}

// метод задает время демпфирования
void DigitalInput::setDebounceTime(long time) {
	_debounceTime = time;
}

// метод возвращает значение сигнала на данном входе
boolean DigitalInput::read(void) {
	return digitalRead(_pin);
}

// метод возвращает значение сигнала на входе с учетом дребезга контактов
boolean DigitalInput::debounceRead(void) {
	boolean reading = read();

	if (reading != _lastState) {
		_lastTime = millis();
	}

	if (millis() - _lastTime > _debounceTime) {
		if (reading != _state) {
			_state = reading;
		}
	}

	_lastState = reading;

	return _state;
}
