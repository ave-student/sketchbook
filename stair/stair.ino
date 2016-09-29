#include "DigitalInput.h"

// Пины светодиодов
#define led1 5
#define led2 6
#define led3 7
#define led4 8
#define led5 9

// Пины сенсоров
#define sens1 2
#define sens2 3

// Направление движения
#define UP 1
#define DOWN 0

// Переменные для функции устранения дребезга контактов
int debounceDelay = 50;

// Параметры
int stepTime = 3000;

void setup() {
	Serial.begin(9600);
}

void loop() {

}
