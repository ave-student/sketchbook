/*
DigitalOutput.h - библиотека-обертка для работы с цифровыми выходами.
*/

#ifndef DigitalOutput_h
#define DigitalOutput_h

#include "Arduino.h"

class DigitalOutput {
	public:
		DigitalOutput(byte pin);    // конструктор
		DigitalOutput(byte pin, byte initState);    //
		void high();    // установить логическую единицу на выходе
		void low();    // установить логический ноль на выходе
		void inverse();    // инвертировать состояние выхода
		int read();    // возвращает текущее состояние выходa
		void write(byte state);    // установить заданное состояние выхода
	private:
		byte _pin;    // пин выхода
		void _initPin(byte pin);    // инициализация выхода
};

#endif
