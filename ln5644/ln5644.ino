#include "LN5644.h"
#include "Timer.h"
#include "IOLib.h"

#define buttons A4

#define lim 4

SDigitalOutput zoomer(12, LOW);

SDigitalOutput a0(A0);
SDigitalOutput a1(A1);
SDigitalOutput a2(A2);
SDigitalOutput a3(A3);
SDigitalOutput an[4] = {a0, a1, a2, a3};

SDigitalOutput d7(7);
SDigitalOutput d9(9);
SDigitalOutput d5(5);
SDigitalOutput d3(3);
SDigitalOutput d2(2);
SDigitalOutput d8(8);
SDigitalOutput d6(6);
SDigitalOutput d4(4);
SDigitalOutput cat[8] = {d7, d9, d5, d3, d2, d8, d6, d4};

int value;

LN5644 disp;
/* Timer timer; */

void setup() {
	disp.init();

	disp.setAnods(an);
	disp.setCatods(cat);
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
