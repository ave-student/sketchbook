/*
Класс StairLigth...
*/

#include "Arduino.h"
#include "DigitalInput.h"
#include "Led.h"

class StairLight {
	public:
		StairLight();    // Конструктор
		void onLight(boolean direct);    // Включить подсветку
		void setLeds(byte leds[]);    // Задать пины сегментов подсветки
		void setDelay(long time);    // Установить интервал между включением секций
		void run();    // Основной цикл
	private:
		DigitalInput _sensorDown;    // Нижний датчик
		DigitalInput _sensorUp;    // Верхний датчик
		long _delayTime;    // Интервал между включением секций
		byte _leds[];    // Массив пинов сегмена подсветки
};
