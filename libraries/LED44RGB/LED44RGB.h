/*********************************************************************
* LED44RGB - библиотека для работы со светодиодной RGB матрицей 4х4. *
*                                                                    *
*********************************************************************/

#ifndef LED44RGB_h
#define LED44RGB_h

#define NONE 0
#define RED 1
#define GREEN 2
#define BLUE 4

#include "Ardiuno.h"

class LED44RGB {
	public:

		LED44RGB(void);
		void setPins(int dPin, int cPin, int lPin);    // назначить пины
		void setLed(int row, int col, int color);    // установить состояние заданного диода
		void run();    //
	
	private:
		int _leds[4][4] = {0};    // массив состояний светодиодов
		byte _activeRow;    // активная строка диодов
		int _dataPin;
		int _clockPin;
		int _latchPin;
		long _delayTime;    // время смены активного ряда диодов
		long _initTime;    // начальное время для ф-ции задержки
		boolean _onDelay;    // флаг активности задержки

		boolean _delay(long ms);    // метод реализующий задержку
};

#endif
