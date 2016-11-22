/*
LN5644.h - библиотека для работы с семисигментным
4-х символьным дисплем.
*/

#ifndef LN5644_h    // если библиотека не подключена
#define LN5644_h    // подключаем ее

#include "Arduino.h"

#define N0 0xfc    // 0b11111100
#define N1 0x60    // 0b01100000
#define N2 0xda    // 0b11011010
#define N3 0xf2    // 0b11110010
#define N4 0x66    // 0b01100110
#define N5 0xb6    // 0b10110110
#define N6 0xbe    // 0b10111110
#define N7 0xe0    // 0b11100000
#define N8 0xfe    // 0b11111110
#define N9 0xf6    // 0b11110110
#define Na 0xee    // 0b11101110
#define Nb 0x3e    // 0b00111110
#define Nc 0x9c    // 0b10011100
#define Nd 0x7a    // 0b01111010
#define Ne 0x9e    // 0b10011110
#define Nf 0x8e    // 0b10001110
#define OVER_MIN 0
#define OVER_MAX 1
#define MINUS 0x02

// Класс для работы с дисплеем.
class LN5644 {
	public:
		int numbers[16] = {N0, N1, N2, N3, N4, N5, N6, N7,
			N8, N9, Na, Nb, Nc, Nd, Ne, Nf};    // массив символов цифр 0-9 и шестнадцатиричные символы a-f

		LN5644();    //
		void init();    // инициализация
		void next();    // отобразить следующий символ на дисплее
		void display(int number);    // вывод на дисплей целого числа
		void display(double number);
		void display(double number, int digit);    // вывод на дисплей числа с плавающей точкой
		void display(int position, int data);    // отобразить в указанной позиции символ, заданный байтом данных
		void clear();    // очистить дисплей
		void test();    // включить все сегменты дисплея
		void setPins(byte dP, byte cP, byte lP);    // Задать пины управляющей шины
		void setDelayTime(long time);    // установить время задержки, влияет на частоту смены сегментов
		void setDot(byte position);    // поставить точку в заданной позиции
		void setLeds(int bt, int digit);

	private:
		int _activeAnod;    // Активный сегмент
		byte _latchPin;    // пин защелки регистра
		byte _dataPin;    // пин данных
		byte _clockPin;    // пин синхронизации
		int _leds[4];    // массив состояний сегментов дисплея (содержит двоичные данные)
		boolean _onDelay;    // флаг активности функции задержки
		long _initTime;    // время начала задержки
		long _delayTime;    // время задержки

		void _initLeds(int state);    // инициализация состояния сегментов
		boolean _delay(long ms);    // задержка
		int _readBit(int position, int digit);    // читает указанный бит числа
		int _extractDigit(int position, int number);    // извлечь из числа цифру в указанной позиции
		int _pow(int number, int n);    // возведение в степень
		void _overflow(int d);    // слишком много символов
};

#endif
