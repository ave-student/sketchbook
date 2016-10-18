#ifndef cl_h
#define cl_h

#include "Arduino.h"

class cl {
	public:
		cl();
		void setArray(int array[]);
		void printArray();
		void func();
	private:
		int _array[8];
};

#endif
