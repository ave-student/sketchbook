/*
Пример использования библиотеки PushButton.h

Схема:
	pin 2 - кнопка
	pin 12 - зумер
	pin 13 - светодиод (встроенный)

Работа:
	При нажатии на кнопку происходит инвертирование состояния
	светодиода и включение зумера. Зумер отключается сразу
	после отпускания кнопки.
*/

#include "Arduino.h"
#include "PushButton.h"

// Объявляем пины
#define btn_pin 2
#define led 13
#define zoomer 12

// Время демпфирования
// Фиксация значения входного сигнала происходит в случае,
// если его уровень был стабилен дольше заданной величины
// времени демпфирования.
// В противном случае колебания уровня сигнала игнорируются.

int debounceDelay = 50;
boolean state = LOW;

// Объявляем переменную дискретного входа
PushButton button(btn_pin, debounceDelay);

void setup() {
	// объявляем пины как выходы
	pinMode(led, OUTPUT);
	pinMode(zoomer, OUTPUT);

	// инициализируем com-порт
	Serial.begin(9600);
}

void loop() {
	// запускает обработчик кнопки
	button.run();
	
	// если произошло событие нажатия кнопки
	if (button.clicked()) {
		// выводим в com-порт сообщение
		Serial.println("Button clicked...");
		// инвертируем состояние выхода светодиода
		if (state == LOW) {
			digitalWrite(led, !digitalRead(led));
		}
		// включаем зумер с заданной частотой
		tone(zoomer, 5000);
		state = HIGH;
	}

	// если произошло событие отпускания кнопки
	if (button.released()) {
		// выводим в com-порт сообщение
		Serial.println("Button released...");
		// выключаем зумер
		noTone(zoomer);
		state = LOW;
	}
}
