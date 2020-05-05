#include "Arduino.h"
#include <stdio.h>
// #include <string.h>

SerialClass Serial;
ArduinoTime ATime;

void pinMode(int pin, int type) {
	if (type) {
		printf("Pin %d set to INPUT\n", pin);
	}
	else {
		printf("Pin %d set to OUTPUT\n", pin);
	}
}

int analogRead(int pin) {
	printf("Read from pin %d\n", pin);
	return 0;
}

void digitalWrite(int pin, int value) {
	// pins[pin] = value;
	printf("In pin %d wrote %d\n", pin, value);
}

int digitalRead(int pin) {
	// printf("Read %d from pin %d\n", pins[pin], pin);
	printf("Read from pin %d\n", pin);
	return 0;
}

long millis(void) {
	return ATime.millis();
	// return 5000;
}

void tone(int pin, int freq) {
	printf("tone(%d, %d)\n;", pin, freq);
}

void noTone(int pin) {
	printf("noTone(%d)\n", pin);
}

// void SerialClass::print(string str) {
// 	printf("%s", str);
// }

void SerialClass::print(int dig) {
	printf("%d", dig);
}

void SerialClass::print(float dig) {
	printf("%f", dig);
}

// void SerialClass::println(string str) {
// 	printf("%s\n", str);
// }

void SerialClass::println(int dig) {
	printf("%d\n", dig);
}

void SerialClass::println(float dig) {
	printf("%f\n", dig);
}
