/*
DigitalInput.h - библиотека для работы с
цифровыми входами.
*/

#ifndef DigitalInput_h    // если библиотека не подключена
#define DigitalInput_h    // подключаем ее

#include "Arduino.h"

// класс обработки дискретных сигналов
class DigitalInput {
	public:
		DigitalInput(byte pin);
		DigitalInput(byte pin, long debounceTime);    // конструктор
		boolean read();    // чтение сигнала на данном входе
		boolean debounceRead();    // чтение сигнала на входе с учетом дребезга контактов
		boolean onClicked();    // кратковременная подача сигнала
		boolean onPressed();    // длительное удержание активного состояния
		long getDebounceTime();    // получить время демпфирования
		void setDebounceTime(long time);    // установить время демпфирования

	private:
		byte _pin;    // номер пина
		long _debounceTime;    // время демпфирования
		long _lastTime;    // время последнего изменения состояния входа
		boolean _state;    // состояние входа
		boolean _lastState;    // последнее состояние входа
		void _initVar();    // инициализация переменных
}

#endif
