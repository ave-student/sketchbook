#include "LN5644.h"

int an[4] = {10, 11, A4, A5};
int cat[8] = {2, 3, 4, 5, 6, 7, 8, 9}; 

LN5644 disp;

void setup() {
	disp.init();

	disp.setAnods(an);
	disp.setCatods(cat);
}

void loop() {
	disp.next();
	disp.display(analogRead(A0) * 12 - 1400);
}
