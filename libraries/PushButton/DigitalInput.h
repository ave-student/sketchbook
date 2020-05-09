/* DigitalInput.h - интерфейс цифрового входа
для калсса PushButton */

#ifndef DigitalInput_h
#define DigitalInput_h

class DigitalInput {
	public:
		DigitalInput() {};
		~DigitalInput() {};
		int read();
};

#endif
