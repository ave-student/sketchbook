/*
LN5644.h - библиотека для работы с семисигментным
4-х символьным LCD-дисплем.
*/

#include "LN5644.h"

// class Example
// {
// 	public:
// 		template< class T >
// 		void get(T tval);    
// };
//  
// template< class T >
// void Example::get(T tval)
// { std:: cout << tval << std::endl; }


LN5644::LN5644(void) {
	_initLeds();
}

LN5644::LN5644(int anods[], int catods[]) {
	setAnods(anods);
	setCatods(catods);

	for (int i = 0; i < 4; i++) {
		pinMode(_anods[i], OUTPUT);
		digitalWrite(_anods[i], LOW);
	}

	for (int i = 0; i < 8; i++) {
		pinMode(_catods[i], OUTPUT);
		digitalWrite(_catods[i], HIGH);
	}

	_initLeds();
}

void LN5644::_initLeds(void) {
	for (int n = 0; n < 4; n++) {
		for (int m = 0; m < 8; m++) {
			_leds[n][m] = 0;
		}
	}
}

void LN5644::setAnods(int pins[]) {
	for (byte i = 0; i < 4; i++) {
		_anods[i] = pins[i];
	}
}

void LN5644::setCatods(int pins[]) {
	for (byte i = 0; i < 8; i++) {
		_catods[i] = pins[i];
	}
}

void LN5644::display(int position, int data) {
	int* bits;
	bits = _readBits(data);
	for (int i = 0; i < 8; i++) {
		_leds[position][i] = bits[i];
	}
}

int* LN5644::_readBits(int data) {
	int outs[8];
	int c = 1;
	for (int i = 0; i < 8; i++) {
		if (data & c) {
			outs[i] = 1;
		}
		else {
			outs[i] = 0;
		}
		c = c << 1;
	}
	return *outs;
}
