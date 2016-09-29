/*
Класс сегмента подсветки
*/

#include "Arduino.h"
#include "Led.h"

// Конструктор
Led::Led(byte pin) {
	_pin = pin;
	_initState = digitalRead(_pin);
}

// Конструктор
Led::Led(byte pin, boolean state) {
	_pin = pin;
	_initState = state;
	digitalWrite(_pin, _initState);
}

// Включить сегмент
void Led::onLed() {
	digitalWrite(_pin, !_initState);
}

// Выключить сегмент
void Led::offLed() {
	digitalWrite(_pin, _initState);
}

// Проверить состояние сегмента
boolean Led::isOn() {
	if (digitalRead(_pin) != _initState)
		return true;
}
