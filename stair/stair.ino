#include "DigitalInput.h"

// Пины светодиодов
#define led1 5
#define led2 6
#define led3 7
#define led4 8
#define led5 9

// Пин зумера
#define zoomer 12

// Направление движения
#define UP 1
#define DOWN 0

// Переменные для функции устранения дребезга контактов
int debounceDelay = 50;

// Параметры
int stepTime = 3000;

// Матрица светодиодов
int steps[5] = {led1, led2, led3, led4, led5};

// Сенсоры
DigitalInput sensorDown(2, debounceDelay);
DigitalInput sensorMiddle(3, debounceDelay);
DigitalInput sensorUp(4, debounceDelay);

void setup() {
	for (int i = 0; i <= 4; i += 1) {
		pinMode(steps[i], OUTPUT);
		digitalWrite(steps[i], HIGH);
	}

	Serial.begin(9600);
}

void loop() {
	if (sensorDown.clicked()) {
		Serial.println("Sensor clicked...");
		switchLed(led1);
		tone(zoomer, 5000);
	}

	if (sensorDown.released()) {
		Serial.println("Sensor released...");
		noTone(zoomer);
	}
}

void switchLed(int led) {
	digitalWrite(led, !digitalRead(led));
}

void onLedUp(int direction) {
	if (direction == UP) {
		for (int step = 0; step <=4; step++) {
			digitalWrite(steps[step], LOW);
			delay(stepTime);
		}
	}
}
