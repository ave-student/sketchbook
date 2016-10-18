/*
LN5644.h - библиотека для работы с семисигментным
4-х символьным дисплем.
*/

#include "Arduino.h"
#include "LN5644.h"

LN5644::LN5644(void) {

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
		for (int m = 0; m < 8; m++) {
			this->_leds[n][m] = state;
		}
	}
	this->_activeAnod = 0;
}

// задает массив выходов подключенных к анодам
void LN5644::setAnods(int pins[]) {
	for (int i = 0; i < 4; i++) {
		pinMode(pins[i], OUTPUT);
		this->_anods[i] = pins[i];
	}
}

// задает массив выходов подкюченных к катодам
void LN5644::setCatods(int pins[]) {
	for (int i = 0; i < 8; i++) {
		pinMode(pins[i], OUTPUT);
		this->_catods[i] = pins[i];
	}
}

// используется в цикле loop() программы для отображения содержимого дисплея
void LN5644::next(void) {
	if (this->_delay(this->_delayTime)) {

	}
	else {
		this->_write(this->_anods[this->_activeAnod], LOW);

		this->_activeAnod = (this->_activeAnod + 5) % 4;

		for (int i = 0; i < 8; i++) {
			this->_write(this->_catods[i], this->_leds[this->_activeAnod][i]);
		}
		this->_write(this->_anods[this->_activeAnod], HIGH);
	}
}

void LN5644::_write(int pin, int value) {
	digitalWrite(pin, value);
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
	for (int i = 0; i < 8; i++) {
		this->_leds[position][i] = !this->_readBit(i, data);
	}
}

int LN5644::_readBit(int position, int number) {
	int c = 0x80;
	c = c >> position;
	if (number & c) {
		return 1;
	}
	else {
		return 0;
	}
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
		for (int j = 0; j < 8; j++) {
			if (d == 1) {
				if (j == 0) {
					this->_leds[i][j] = 0;
				}
				else {
					this->_leds[i][j] = 1;
				}
			}
			else {
				if (j == 3) {
					this->_leds[i][j] = 0;
				}
				else {
					this->_leds[i][j] = 1;
				}
			}
		}
	}
}
