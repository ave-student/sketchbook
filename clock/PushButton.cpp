/*
PushButton.h - библиотека для работы с
цифровыми входами.
*/

#include "Arduino.h"
#include "PushButton.h"

PushButton::PushButton(byte pin) {
	_debounceTime = 50;
	_longPressTime = 3000;
	_setPin(pin);
	_initVar();
}

PushButton::PushButton(byte pin, long debounceTime) {
	_debounceTime = debounceTime;
	_setPin(pin);
	_initVar();
}

// инициализация параметров
void PushButton::_initVar() {
	_lastTime = 0;    // время последнего изменения сигнала
	_lastState = HIGH;    // последнее мгновенное состояние входного сигнала
	_state = HIGH;    // текущее установившееся состояние входного сигнала
	_prevState = HIGH;    // предыдущее установившееся состояние сигнала
}

// инициализирует пин как дискретный вход с подтягивающим резистором
void PushButton::_setPin(byte pin) {
	_pin = pin;
	pinMode(_pin, INPUT_PULLUP);
}

// получить номер пина
byte PushButton::getPin(void) {
	return _pin;
}

// метод возращает значение времени демпфирования
long PushButton::getDebounceTime(void) {
	return _debounceTime;
}

// метод задает время демпфирования
void PushButton::setDebounceTime(long time) {
	_debounceTime = time;
}

long PushButton::getLongPressTime(void) {
	return _longPressTime;
}

void PushButton::setLongPressTime(long time) {
	_longPressTime = time;
}

// метод возвращает значение сигнала на данном входе
boolean PushButton::_readPin(void) {
	return digitalRead(_pin);
}

// метод возвращает значение сигнала на входе с учетом дребезга контактов
boolean PushButton::read(void) {
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
boolean PushButton::clicked() {
	read();

	if (_prevState == HIGH && _state == LOW) {
		_prevState = _state;
		return true;
	}

	return false;
}

// низкий уровень сигнала (кнопка нажата)
boolean PushButton::pressed() {
	read();

	if (_state == LOW) {
		return true;
	}

	return false;
}

boolean PushButton::longPress() {
	read();

	if ((_state == LOW) && (millis() - _lastTime > _longPressTime)) {
		return true;
	}

	return false;
}

// событие съема сигнала (отпускание кнопки)
boolean PushButton::released() {
	read();

	if (_prevState == LOW && _state == HIGH) {
		_prevState = _state;
		return true;
	}

	return false;
}
