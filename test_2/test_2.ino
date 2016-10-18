#include "cl.h"

int a[] = {2, 3, 4, 5, 6, 7, 8, 9};
cl trouble;

void setup() {
	Serial.begin(9600);
	Serial.print("Begin\n");
	trouble.setArray(a);
	Serial.print("After set\n");
	trouble.printArray();
	Serial.print("End setup\n");
}

void loop() {
	Serial.print("loop()\n");
	trouble.func();
}
