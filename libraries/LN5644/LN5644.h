/*
LN5644.h - библиотека для работы с семисигментным
4-х символьным LCD-дисплем.
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

// Класс для работы с дисплеем.
class LN5644 {
	public:
		LN5644();    //
		LN5644(int anods[], int catods[]);    // конструктор
		void display(int digit);    // вывод на дисплей целого числа
		void display(float digit);    // вывод на дисплей числа с плавающей точкой
		void display(int position, int data);    // отобразить в указанной позиции символ, заданный байтом данных
		void clear();    // очистить дисплей
		void test();    // включить все сегменты дисплея
		void setAnods(int pins[]);    // установить пины анодов
		void setCatods(int pins[]);    // установить пины катодов
	private:
		int _leds[4][8];    // массив состояний сегментов дисплея
		int _anods[];    // пины анодов
		int _catods[];    // пины катодов
		int* _readBits(int data);    // 
		void _initLeds();    // инициализация состояния сегментов
};

#endif
