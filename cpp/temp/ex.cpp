#include "stdio.h"

class DigitalInput {
	public:
		virtual int read() = 0;
};

class A : public DigitalInput {
	public:
		int read() {
			return 10;
		};
};

class B: public DigitalInput {
	public:
		int read() {
			return 20;
		};
};

class C: public B {
	public:
		int read() {
			return 30;
		}
};

void pr(DigitalInput *in) {
	printf("%d\n", in->read());
}

DigitalInput* a = new A;
DigitalInput* b = new B;
DigitalInput* c = new C;

int main() {
//	printf("%d\n", a.read());
	pr(a);
	pr(b);
	pr(c);
	return 0;
}
