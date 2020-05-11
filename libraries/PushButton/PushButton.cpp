/*
PushButton.h - библиотека для работы с
цифровыми входами.
*/

#include "PushButton.h"

PushButton::PushButton(byte pin) {
	_debounceTime = 50;
	_longPressTime = 3000;
	_setInput(pin);
	_initVar();
}

PushButton::PushButton(byte pin, long debounceTime) {
	_debounceTime = debounceTime;
	_longPressTime = 3000;
	_setInput(pin);
	_initVar();
}

PushButton::PushButton(DigitalInput* in) {
	_in = in;
	_debounceTime = 50;
	_longPressTime = 3000;
	_initVar();
}

PushButton::PushButton(DigitalInput* in, long debounceTime) {
	_in = in;
	_debounceTime = debounceTime;
	_longPressTime = 3000;
	_initVar();
}

void PushButton::_setInput(byte pin) {
	_in = new RealDigitalInput(pin);
}

// инициализация параметров
void PushButton::_initVar() {
	_lastTime = 0;    // время последнего изменения сигнала
	_lastState = HIGH;    // последнее мгновенное состояние входного сигнала
	_state = HIGH;    // текущее установившееся состояние входного сигнала
	_prevState = HIGH;    // предыдущее установившееся состояние сигнала
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

// метод запускается в основном цикле программы loop()
void PushButton::run(void) {
	boolean reading = _in->read();

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
	_doAction();
}

// событие подачи сигнала (клик)
boolean PushButton::clicked() {
	if (_prevState == HIGH && _state == LOW) {
		return true;
	}
	return false;
}

// низкий уровень сигнала (кнопка нажата)
boolean PushButton::pressed() {
	if (_state == LOW) {
		return true;
	}
	return false;
}

boolean PushButton::longPress() {
	if ((_state == LOW) && (millis() - _lastTime > _longPressTime)) {
		return true;
	}
	return false;
}

// событие съема сигнала (отпускание кнопки)
boolean PushButton::released() {
	if (_prevState == LOW && _state == HIGH) {
		return true;
	}
	return false;
}

void PushButton::_doAction() {
	if (clicked()) {
		onClick();
	}
	if (pressed()) {
		onPress();
	}
	if (longPress()) {
		onLongPress();
	}
	if (released()) {
		onRelease();
	}
}
