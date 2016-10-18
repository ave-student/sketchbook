#include "Arduino.h"
#include <stdio.h>


void pinMode(int pin, int type) {
	string stype;
	if (type) {
		stype = "INPUT";
	}
	else {
		stype = "OUTPUT";
	}
	printf("Pin %d set to %s\n", pin, stype);
}

void digitalWrite(int pin, int value) {
	pins[pin] = value;
	printf("In pin %d wrote %d\n", pin, value);
}

int digitalRead(int pin) {
	printf("Read %d from pin %d\n", pins[pin], pin);
}

void Serial::print(string str) {
	printf("%s", str);
}

void Serial::print(int dig) {
	printf("%d", dig);
}

void Serial::print(float dig) {
	printf("%d", dig);
}

void Serial::println(string str) {
	printf("%s\n", str);
}

void Serial::println(int dig) {
	printf("%d\n", dig);
}

void Serial::println(float dig) {
	printf("%d\n", dig);
}
