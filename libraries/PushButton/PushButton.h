/*
PushButton.h - библиотека для работы с
цифровыми входами.
*/

#ifndef PushButton_h    // если библиотека не подключена
#define PushButton_h    // подключаем ее

#include "Arduino.h"
#include "DigitalInput.h"

// класс кнопки
class PushButton {
	public:
		PushButton(byte pin);
		PushButton(byte pin, long debounceTime);    // конструктор
		PushButton(DigitalInput* in);    // использование интерфейса цифрового входа
		PushButton(DigitalInput* in, long debounceTime);
		~PushButton() {};
		boolean clicked();    // передний фронт сигнала
		boolean pressed();    // длительное удержание активного состояния
		boolean longPress();	// долгое нажатие на кнопку
		boolean released();    // задний фронт сигнала
		long getDebounceTime();    // получить время демпфирования
		void setDebounceTime(long time);    // установить время демпфирования
		long getLongPressTime();
		void setLongPressTime(long time);
		void run();    // метод запускается в основном цикле программы loop()

		virtual void onClick() {};
		virtual void onPress() {};
		virtual void onRelease() {};
		virtual void onLongPress() {};

	private:
		DigitalInput* _in;    // объект цифрового входа
		long _debounceTime;    // время демпфирования
		long _lastTime;    // время последнего изменения состояния входа
		long _longPressTime;	// время долгого нажатия
		boolean _state;    // текущее установившееся состояние сигнала
		boolean _prevState;    // предыдущее установившееся состояние сигнала
		boolean _lastState;    // последнее мгновенное состояние сигнала

		void _setInput(byte pin);
		void _initVar();    // инициализация переменных
		void _doAction();    // обработка событий
};

class RealDigitalInput: public DigitalInput {
	public:
		RealDigitalInput(byte pin) {
			_pin = pin;
			pinMode(_pin, INPUT_PULLUP);
		};

		int read() {
			return digitalRead(_pin);
		};

	private:
		byte _pin;
};

#endif
