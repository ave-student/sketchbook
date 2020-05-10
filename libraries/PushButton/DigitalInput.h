/* DigitalInput.h - интерфейс цифрового входа
для калсса PushButton */

#ifndef DigitalInput_h
#define DigitalInput_h

class DigitalInput {
	public:
		DigitalInput() {};
		~DigitalInput() {};
		virtual int read() = 0;
};

#endif
