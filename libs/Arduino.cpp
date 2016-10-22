#include "Arduino.h"
#include <stdio.h>

TimePC time;
SerialPC Serial;

void pinMode(int pin, int type) {
	char* stype;
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

long millis(void) {
	time.time++;
	return time.time;
}

void SerialPC::print(char* str) {
	printf("%s", str);
}

void SerialPC::print(int dig) {
	printf("%d", dig);
}

void SerialPC::print(float dig) {
	printf("%d", dig);
}

void SerialPC::println(char* str) {
	printf("%s\n", str);
}

void SerialPC::println(int dig) {
	printf("%d\n", dig);
}

void SerialPC::println(float dig) {
	printf("%d\n", dig);
}
