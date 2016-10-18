#include "Arduino.h"
#include "cl.h"

cl::cl(void) {
	Serial.begin(9600);
}

void cl::setArray(int array[]) {
	for (int i = 0; i < 8; i++) {
		this->_array[i] = array[i];
	}
	this->printArray();
}

void cl::printArray(void) {
	Serial.print("\n\tArray:\n");
	for (int i = 0; i < 8; i++) {
		Serial.println(this->_array[i]);
	}
}

void cl::func(void) {
	this->printArray();
}
