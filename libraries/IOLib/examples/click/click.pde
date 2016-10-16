/*
Пример использования библиотеки DigitalInput.h

Схема:
	pin 2 - кнопка
	pin 12 - зумер
	pin 13 - светодиод (встроенный)

Работа:
	При нажатии на кнопку происходит инвертирование состояния
	светодиода и включение зумера. Зумер отключается сразу
	после отпускания кнопки.
*/

/* #include "DigitalInput.h" */
#include "IOLib.h"

// Объявляем пины
#define led 13
#define zoomer 12

// Время демпфирования
// Фиксация значения входного сигнала происходит в случае,
// если его уровень был стабилен дольше задонной величины
// времени демпфирования.
// В противном случае колебания уровня сигнала игнорируются.
int debounceDelay = 50;

// Объявляем переменную дискретного входа
DigitalInput button(2, debounceDelay);
/* DigitalInput button = newDI(2, debounceDelay); */
/* button = IOLib.newDI(2, debounceDelay); */

void setup() {
	// объявляем пины как выходы
	pinMode(led, OUTPUT);
	pinMode(zoomer, OUTPUT);

	// инициализируем com-порт
	Serial.begin(9600);
}

void loop() {
	// если произошло событие нажатия кнопки
	if (button.clicked()) {
		// выводим в com-порт сообщение
		Serial.println("Button clicked...");
		// инвертируем состояние выхода светодиода
		digitalWrite(led, !digitalRead(led));
		// включаем зумер с заданной частотой
		tone(zoomer, 5000);
	}

	// если произошло событие отпускания кнопки
	if (button.released()) {
		// выводим в com-порт сообщение
		Serial.println("Button released...");
		// выключаем зумер
		noTone(zoomer);
	}
}
