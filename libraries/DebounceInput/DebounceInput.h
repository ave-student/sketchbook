/*
DebounceInput.h - библиотека для работы с
цифровыми входами.
*/

#ifndef DebounceInput_h    // если библиотека не подключена
#define DebounceInput_h    // подключаем ее

#include "Arduino.h"

// класс обработки дискретных сигналов
class DebounceInput {
	public:
		DebounceInput(byte pin, long debounceTime);    // конструктор
		boolean onClicked();    // кратковременная подача сигнала
		boolean onPressed();    // длительное удержание активного состояния
		long debounceTime;    // время демпфирования

	private:
		long _lastTime;    // время последнего изменения состояния входа
		boolean _state;    // состояние входа
		boolean _lastState;    // последнее состояние входа
}

#endif
