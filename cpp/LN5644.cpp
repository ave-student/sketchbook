/*
LN5644.h - библиотека для работы с семисигментным
4-х символьным дисплем.
*/

#include "Arduino.h"
#include "LN5644.h"

LN5644::LN5644(void) {
	this->_activeAnod = 0xff;
}

void LN5644::init(void) {
	this->_initLeds(LOW);
	this->setDelayTime(2);
	this->_initTime = 0;
	this->clear();
}

// инициирует состояния светодиодов дисплея
void LN5644::_initLeds(int state) {
	for (int n = 0; n < 4; n++) {
		if (state) {
			this->_leds[n] = 0x00;
		}
		else {
			this->_leds[n] = 0xff;
		}
	}
}

// задать пины управляющей шины
void LN5644::setPins(byte dP, byte cP, byte lP) {
	this->_dataPin = dP;
	this->_clockPin = cP;
	this->_latchPin = lP;
	pinMode(this->_dataPin, OUTPUT);
	pinMode(this->_clockPin, OUTPUT);
	pinMode(this->_latchPin, OUTPUT);
}

// используется в цикле loop() программы для отображения содержимого дисплея
void LN5644::next(void) {
	if (this->_delay(this->_delayTime)) {

	}
	else {
		digitalWrite(this->_latchPin, LOW);

		this->_activeAnod = (this->_activeAnod + 5) % 4;
		shiftOut(this->_dataPin, this->_clockPin, LSBFIRST, this->_pow(2 , this->_activeAnod) << 4);

		shiftOut(this->_dataPin, this->_clockPin, LSBFIRST, this->_leds[this->_activeAnod]);

		// "защелкиваем" регистр, чтобы биты появились на его выходе
		digitalWrite(this->_latchPin, HIGH);
	}
}

// задает время задержки, определяющее частоту мерцания сегментов дисплея
void LN5644::setDelayTime(long time) {
	this->_delayTime = time;
}

// тестирование дисплея (включаются все светодиоды)
void LN5644::test(void) {
	this->_initLeds(HIGH);
}

// очистка дисплея
void LN5644::clear(void) {
	this->_initLeds(LOW);
}

// функция задержки по времени
boolean LN5644::_delay(long ms) {
	if (!this->_onDelay){
		this->_initTime = millis();
		this->_onDelay = true;
		return true;
	}
	if ((millis() - this->_initTime) > ms) {
		this->_onDelay = false;
		return false;
	}
	return true;
}

void LN5644::display(int position, int data) {
	// ~data & 0xff - выполняет инверсию бит входных данных
	this->_leds[position] = ~data & 0xff;
}

void LN5644::display(int number) {
	if (number > 9999) {
		this->_overflow(OVER_MAX);
	}
	else if (number < -999) {
		this->_overflow(OVER_MIN);
	}
	else {
		for (int i = 0; i < 4; i++) {
			if ((number < 0) && (i == 3)) {
				this->display(i, MINUS);
			}
			else {
				this->display(i, this->numbers[this->_extractDigit(i, number)]);
			}
		}
	}
}

void LN5644::display(double number, int digit) {
	if (number > this->_pow(10, 4 - digit)) {
		this->_overflow(OVER_MAX);
	}
	else if (number < - this->_pow(10, 3 - digit)) {
		this->_overflow(OVER_MIN);
	}
	else {
		this->display(int(number * this->_pow(10, digit)));
		if (digit != 0) {
			this->setDot(digit);
		}
	}
}

void LN5644::display(double number) {
	this->display(number, 1);
}

void LN5644::setDot(byte position) {
	this->_leds[position] = this->_leds[position] >> 1 << 1;
}

int LN5644::_extractDigit(int position, int number) {
	int res;
	int divider = 10;
	
	if (number < 0) {
		number = -number;
	}
	
	res = (number - number % this->_pow(divider, position)) % this->_pow(divider, position + 1);
	res /= this->_pow(divider, position);
	return res;
}

int LN5644::_pow(int number, int n) {
	int res = 1;
	if (n == 0)
		return res;
	for (int i = 0; i < (n); i++) {
		res *= number;	
	}
	return res;
}

void LN5644::_overflow(int d) {
	for (int i = 0; i < 4; i++) {
		if (d == 1) {
			this->_leds[i] = 0x7f;
		}
		else {
			this->_leds[i] = 0xef;

		}
	}
}

void LN5644::setLeds(int bt, int digit) {

}
