#include "LN5644.h"

#define buttons A4

int value;

LN5644 disp;

void setup() {
	pinMode(A4, INPUT);
	disp.init();
	disp.setPins(11, 12, 8);
}

void loop() {
	disp.next();
	value = analogRead(buttons);
	disp.display(value);

	/* if (!digitalRead(bStart())) { */
	/* 	timer.start(); */
	/* } */
	/* if (!digitalRead(bPause())) { */
	/* 	timer.pause(); */
	/* } */
	/* if (!digitalRead(bStop())) { */
	/* 	timer.stop(); */
	/* } */
	/* disp.display(timer.next()); */
	/* if ((timer.next() > 0) && (timer.next() % 60) == 0) { */
	/* 	tone(zoomer, 5000); */
	/* } */
	/* else { */
	/* 	noTone(zoomer); */
	/* }	 */
	
}
