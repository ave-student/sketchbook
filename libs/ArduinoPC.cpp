#include "ArduinoPC.h"
#include <stdio.h>
// #include <string.h>

SerialClass Serial;

void pinMode(int pin, int type) {
	if (type) {
		printf("Pin %d set to INPUT\n", pin);
	}
	else {
		printf("Pin %d set to OUTPUT\n", pin);
	}
}

void digitalWrite(int pin, int value) {
	pins[pin] = value;
	printf("In pin %d wrote %d\n", pin, value);
}

int digitalRead(int pin) {
	printf("Read %d from pin %d\n", pins[pin], pin);
}

long millis(void) {
	_time++;
	return _time;
}

// void SerialClass::print(string str) {
// 	printf("%s", str);
// }

void SerialClass::print(int dig) {
	printf("%d", dig);
}

void SerialClass::print(float dig) {
	printf("%d", dig);
}

// void SerialClass::println(string str) {
// 	printf("%s\n", str);
// }

void SerialClass::println(int dig) {
	printf("%d\n", dig);
}

void SerialClass::println(float dig) {
	printf("%d\n", dig);
}
