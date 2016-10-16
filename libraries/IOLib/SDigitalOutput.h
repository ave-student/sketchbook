/*
SDigitalOutput.h - библиотека-обертка для работы с цифровыми выходами.
*/

#ifndef SDigitalOutput_h
#define SDigitalOutput_h

#include "Arduino.h"
#include "DigitalOutput.h"

class SDigitalOutput : public DigitalOutput {
	public:
		SDigitalOutput();
		SDigitalOutput(int pin);    // конструктор
		SDigitalOutput(int pin, byte initState);    //
		void high();    // установить логическую единицу на выходе
		void low();    // установить логический ноль на выходе
		void inverse();    // инвертировать состояние выхода
		int read();    // возвращает текущее состояние выходa
		void write(byte state);    // установить заданное состояние выхода
	private:
		byte _pin;    // пин выхода
		void _initPin(int pin);    // инициализация выхода
};

#endif
