/*
DigitalOutput.h - библиотека-обертка для работы с цифровыми выходами.
*/

#ifndef DigitalOutput_h
#define DigitalOutput_h

class DigitalOutput {
	public:
		virtual void inverse();    // инвертировать состояние выхода
		virtual int read();    // возвращает текущее состояние выходa
		virtual void write(byte state);    // установить заданное состояние выхода
};

#endif
