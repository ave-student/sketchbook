#include "DigitalInput.h"
#include "stdio.h"

class DI: public DigitalInput {
	public:
		virtual int read() {
			return 1;
		}
};

class DI2: public DigitalInput {
	public:
		virtual int read() {
			return 2;
		}
};

DI* d1;
DI2* d2;

void pr(DigitalInput* in) {
	printf("This DigitalInput value is: %d", in->read());
}

int main() {
	pr(d1);
	pr(d2);
}
