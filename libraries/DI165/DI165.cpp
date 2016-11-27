/*********************************************************************
 * DI165 - библиотека для работы со сдвиговыми регистрами 74hc165.
*********************************************************************/

#include "DI165.h"

DI165::DI165(void) {
    this->_init();
}

DI165::DI165(int dataP, int clockP, int latchP) {
	this->_init();
	this->setPins(dataP, clockP, latchP);
}

DI165::DI165(int dataP, int clockP, int latchP, int regCount) {
	this->_init();
	this->setPins(dataP, clockP, latchP);
	this->setRegCount(regCount);
}

void DI165::_init(void) {
    this->_respTime = 0;
	this->setRegCount(1);
	this->_initTime = 0;
	this->_onDelay = false;
	this->clear();
}

void DI165::clear(void) {
	for (int i = 0; i < this->_regCount; i++) {
		this->_data[i] = 0;
	}
}

void DI165::setPins(int dataP, int clockP, int latchP) {
	this->_dataPin = dataP;
	this->_clockPin = clockP;
	this->_latchPin = latchP;

	// Настройка вывода платы в режим "Выход"
	pinMode(this->_clockPin, OUTPUT);  
	pinMode(this->_latchPin, OUTPUT);

	// Настройка вывода платы в режим "Вход"  
	pinMode(this->_dataPin, INPUT);

	// Устанавливаем состояние защелки: OFF
	digitalWrite(this->_latchPin, LOW);    
}

void DI165::setRegCount(int count) {
	if (count > REGISTER_COUNT_DI165) {
		this->_regCount = REGISTER_COUNT_DI165;
	}
	this->_regCount = count;
}

void DI165::_shiftIn(void) {
	if (this->_delay(this->_respTime)) {
		digitalWrite(this->_latchPin, HIGH);

		for (int i = 0; i < this->_regCount; i++) {
			byte temp = 0;

			for (int j = 0; j < 8; j++) {
				if (digitalRead(this->_dataPin)) {
					temp = (temp << 1) | 1;
				}
				else {
					temp = temp << 1;
				}
				digitalWrite(this->_clockPin, HIGH);
				digitalWrite(this->_clockPin, LOW);
			}
			this->_data[i] = temp;
		}

		digitalWrite(this->_latchPin, LOW);
	}
}

byte DI165::shiftIn(int reg) {
	this->_shiftIn();
	if (reg > this->_regCount - 1) {
		return 0;
	}
	else if (reg > REGISTER_COUNT_DI165 - 1) {
		return 0;
	}
	else {
		return this->_data[reg];
	}
}

byte DI165::read(int pin) {
	this->_shiftIn();
	int reg = 0;
	int bit = 0;

	if (pin > 8 * this->_regCount) {
		return 0;
	}

	reg = pin / 8;    // определяем номер сдвигового регистра
	bit = pin % 8;    // определяем номер входа регистра

	return this->_data[reg] & (1 << (pin - 1));
}

boolean DI165::_delay(long time) {
	if (!this->_onDelay) {
		this->_initTime = millis();
		this->_onDelay = true;
		return false;
	}
	if (millis() - this->_initTime > time) {
		this->_onDelay = false;
		return true;
	}
	return false;
}
