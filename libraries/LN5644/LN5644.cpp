/*
LN5644.h - библиотека для работы с семисигментным
4-х символьным LCD-дисплем.
*/

#include "Arduino.h"
#include "LN5644.h"

LN5644::LN5644(void) {
	this->_initLeds(LOW);
	this->setDelayTime(100);
}

LN5644::LN5644(int anods[], int catods[]) {
	Serial.begin(9600);
	this->setAnods(anods);
	this->setCatods(catods);

	this->_initLeds(LOW);
	this->setDelayTime(100);
}

// инициирует состояния светодиодов дисплея
void LN5644::_initLeds(int state) {
	for (int n = 0; n < 4; n++) {
		for (int m = 0; m < 8; m++) {
			this->_leds[n][m] = state;
		}
	}

	this->_activeAnod = 0;
	this->_initTime = 0;
}

// задает массив выходов подключенных к анодам
void LN5644::setAnods(int pins[]) {
	for (int i = 0; i < 4; i++) {
		this->_anods[i] = pins[i];
		Serial.print("Anod: ");
		Serial.print(i);
		Serial.print(" - Pin: ");
		Serial.println(this->_anods[i]);
	}
}

// задает массив выходов подкюченных к катодам
void LN5644::setCatods(int pins[]) {
	for (int i = 0; i < 8; i++) {
		this->_catods[i] = pins[i];
		Serial.print("Catod: "); 
		Serial.print(i);
		Serial.print(" - Pin: ");
		Serial.println(this->_catods[i]);
	}
}

// используется в цикле loop() программы для отображения содержимого дисплея
void LN5644::next(void) {
	// if (this->_delay(this->_delayTime)) {
	// 	Serial.println("delay");
	// }
	// else {
		delay(500);
		Serial.print("next() {\n");
		for (int i = 0; i < 4; i++){
			Serial.print("\tAnod: ");
			Serial.print(i);
			Serial.print(" - Pin: ");
			Serial.println(this->_anods[i]);
		}
		for (int i = 0; i < 8; i++){
			Serial.print("\tCatod: ");
			Serial.print(i);
			Serial.print(" - Pin: ");
			Serial.println(this->_catods[i]);
		}
		Serial.print("\n\tActive anode: ");
		Serial.println(this->_activeAnod);
		// this->_anods[this->_activeAnod].write(LOW);
		digitalWrite(this->_anods[this->_activeAnod], LOW);
		this->_activeAnod = (this->_activeAnod + 5) % 4;
		Serial.print("\n\tActive anode: ");
		Serial.println(this->_activeAnod);

		for (int i = 0; i < 8; i++) {
			// this->_catods[i].write(!this->_leds[this->_activeAnod][i]);
			digitalWrite(this->_catods[i], this->_leds[this->_activeAnod][i]);
			Serial.print("\n\tLed ");
			Serial.print(i);
			Serial.print(" : ");
			Serial.println(this->_leds[this->_activeAnod][i]);
		}
		// this->_anods[this->_activeAnod].write(HIGH);
		delay(500);
		digitalWrite(this->_anods[this->_activeAnod], HIGH);
		Serial.println("next() }");
	// }
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
	this->_readBits(data);
	for (int i = 0; i < 8; i++) {
		this->_leds[position][i] = this->_bits[i];
		Serial.print("Bit ");
		Serial.print(i);
		Serial.print(" : ");
		Serial.println(this->_bits[i]);
	}
}

void LN5644::display(int number) {
	Serial.print("display(int number) {\n");
	this->_extractDigits(number);
	for (int i = 0; i < 4; i++) {
		this->display(i, this->numbers[this->_numbers[i]]);
	}
	Serial.print("}\n");
}

int LN5644::_countNums(int number) {
	int n = 0;
	if (number < 0)
		number = -number;
	if (number < 10000)
		n = 4;
	if (number < 1000)
		n = 3;
	if (number < 100)
		n = 2;
	if (number < 10)
		n = 1;
	return n;
}

void LN5644::_extractDigits(int number) {
	int divider = 10;
	int quotient = 0;
	for (int i = 0; i < (this->_countNums(number)); i++) {
		this->_numbers[i] = number % divider;
		number = (number - this->_numbers[i]) / divider;
		divider = divider * 10;
	}
}

// создает массив бит двоичного представления переданного числа
void LN5644::_readBits(int data) {
	int c = 1;
	for (int i = 0; i < 8; i++) {
		if (data & c) {
			this->_bits[i] = 1;
		}
		else {
			this->_bits[i] = 0;
		}
		c = c << 1;
	}
	for (int i = 0; i < 8; i++) {
		Serial.print("BitSource ");
		Serial.print(i);
		Serial.print(" : ");
		Serial.println(this->_bits[i]);
	}
}
