/*********************************************************************
 * DI165 - библиотека для работы со сдвиговыми регистрами 74hc165.
*********************************************************************/

#ifndef DI165_h
#define DI165_h

// максимальное число регистров подключенны каскадно
#define REGISTER_COUNT_DI165 8

#include "Arduino.h"

// Класс для работы с модулем дискретного ввода
class DI165 {
	public:

		DI165();    // конструктор
		DI165(int dataP, int clockP, int latchP);
		DI165(int dataP, int clockP, int latchP, int regCount);
		void setPins(int dataP, int clockP, int latchP);    // установить управляющие пины
		void setRegCount(int count);    // установить количество регистров подключенных каскадно
		byte shiftIn(int reg);    // считать состояние входов заданного регистра
		byte read(int pin);    // считать значение заданного входа
		void setRespTime(long time);    // установить время опроса в миллисекундах
		void clear();    // очистка массива данных
		
	private:
		int _regCount;    // количество подключенных регистров
		byte _data[REGISTER_COUNT_DI165];    // данные считанные с регистров
		int _respTime;    // период опроса
		int _dataPin;
		int _clockPin;
		int _latchPin;
		long _initTime;
		boolean _onDelay;

		void _shiftIn();    // считать состояние входов
		void _init();
		boolean _delay(long time);
};

#endif
