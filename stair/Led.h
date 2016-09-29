/*
Класс сегмента подсветки.
*/

#include "Arduino.h"

class Led {
	public:
		Led(byte pin);
		Led(byte pin, boolean state);    // Конструктор
		void onLed();    // Включить сегмент
		void offLed();    // Выключить сегмент
		boolean isOn();    // Проверить включен ли сегмент
	private:
		byte _pin;    // Номер пина
		boolean _initState;    // Начальное состояние
};
