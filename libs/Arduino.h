#ifndef Arduino_h
#define Arduino_h

#define INPUT 1
#define INPUT_PULLUP 1
#define OUTPUT 0

#define HIGH 1
#define LOW 0

#define A0 14
#define A1 15
#define A2 16
#define A3 17
#define A4 18
#define A5 19
#define A6 20

int pins[20] = {0};

void pinMode(int pin, int type);    // иммитация установки режимa заданного пина
void digitalWrite(int pin, int value);    // иммитация записи бита в указанный канал
int digitalRead(int pin);    // иммитация чтения бита из канала
long millis();    //

class TimePC {
	public:
		long time = 0;
};

class SerialPC {
	public:
		void print(char* str);    // иммитация вывода в последовательный порт
		void print(int dig);    // иммитация вывода в последовательный порт
		void print(float dig);    // иммитация вывода в последовательный порт
		void println(char* str);    // иммитация вывода в последовательный порт
		void println(int dig);    // иммитация вывода в последовательный порт
		void println(float dig);    // иммитация вывода в последовательный порт
};

#endif
