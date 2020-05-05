/*
**********************************************************************
* Пример выводит числовое значение аналогового сигнала на дисплей.   *
*                                                                    *
* Схема подключения:                                                 *
*     11 - dataPin                                                   *
*     12 - clockPin                                                  *
*     8 - latchPin                                                   *
*     A0 - аналоговый вход                                           *
**********************************************************************
*/

#include "LN5644.h"

#define dataPin 11
#define clockPin 12
#define latchPin 8

LN5644 disp;

void setup() {
	// выполняем функцию инициализации дисплея
	disp.init();
	// задаем пины шины управления
	disp.setPins(dataPin, clockPin, latchPin);
}

void loop() {
	disp.next();
	disp.display(analogRead(A0) * 12 - 1400);
}
