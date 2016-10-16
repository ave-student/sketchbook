/*
DigitalInput.h - библиотека для работы с
цифровыми входами.
*/

#include "Arduino.h"
#include "DigitalInput.h"

DigitalInput::DigitalInput(byte pin) {
	_debounceTime = 50;
	_setPin(pin);
	_initVar();
}

DigitalInput::DigitalInput(byte pin, long debounceTime) {
	_debounceTime = debounceTime;
	_setPin(pin);
	_initVar();
}

// инициализация параметров
void DigitalInput::_initVar() {
	_lastTime = 0;    // время последнего изменения сигнала
	_lastState = HIGH;    // последнее мгновенное состояние входного сигнала
	_state = HIGH;    // текущее установившееся состояние входного сигнала
	_prevState = HIGH;    // предыдущее установившееся состояние сигнала
}

// инициализирует пин как дискретный вход с подтягивающим резистором
void DigitalInput::_setPin(byte pin) {
	_pin = pin;
	pinMode(_pin, INPUT_PULLUP);
}

// получить номер пина
byte DigitalInput::getPin(void) {
	return _pin;
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
boolean DigitalInput::_readPin(void) {
	return digitalRead(_pin);
}

// метод возвращает значение сигнала на входе с учетом дребезга контактов
boolean DigitalInput::read(void) {
	boolean reading = _readPin();

	if (reading != _lastState) {
		_lastTime = millis();
	}

	if (millis() - _lastTime > _debounceTime) {
		if (reading != _state) {
			_prevState = _state;
			_state = reading;
		}
	}

	_lastState = reading;
	return _state;
}

// событие подачи сигнала (клик)
boolean DigitalInput::clicked() {
	read();

	if (_prevState == HIGH && _state == LOW) {
		_prevState = _state;
		return true;
	}

	return false;
}

// низкий уровень сигнала (кнопка нажата)
boolean DigitalInput::pressed() {
	read();

	if (_state == LOW) {
		return true;
	}

	return false;
}

// событие съема сигнала (отпускание кнопки)
boolean DigitalInput::released() {
	read();

	if (_prevState == LOW &&_state == HIGH) {
		_prevState = _state;
		return true;
	}

	return false;
}
