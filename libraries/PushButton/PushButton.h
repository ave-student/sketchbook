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
		~PushButton() {};
		boolean clicked();    // передний фронт сигнала
		boolean pressed();    // длительное удержание активного состояния
		boolean longPress();	// долгое нажатие на кнопку
		boolean released();    // задний фронт сигнала
		byte getPin();    // получить номер пина
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
		byte _pin;    // номер пина
		long _debounceTime;    // время демпфирования
		long _lastTime;    // время последнего изменения состояния входа
		long _longPressTime;	// время долгого нажатия
		boolean _state;    // текущее установившееся состояние сигнала
		boolean _prevState;    // предыдущее установившееся состояние сигнала
		boolean _lastState;    // последнее мгновенное состояние сигнала

		void _setPin(byte pin);    // инициализирует пин как дискретный вход
		void _initVar();    // инициализация переменных
		void _doAction();    // обработка событий
};

#endif
