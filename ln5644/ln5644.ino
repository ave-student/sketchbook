#include "LN5644.h"
#include "Timer.h"

#define zoomer 12
#define buttons A4

#define but1 514
#define but2 599
#define but3 655
#define but12 747
#define but13 791
#define but23 801
#define but123 866

#define lim 4

int an[4] = {A0, A1, A2, A3};
int cat[8] = {7, 9, 5, 3, 2, 8, 6, 4}; 

int value;

LN5644 disp;
/* Timer timer; */

void setup() {
	pinMode(zoomer, OUTPUT);
	digitalWrite(zoomer, LOW);
	
	disp.init();

	disp.setAnods(an);
	disp.setCatods(cat);
}

void loop() {
	disp.next();
	value = analogRead(buttons);
	disp.display(value);

	/* if (value < 100) { */
	/* 	disp.clear(); */
	/* 	disp.display(0, Nb); */
	/* } */
	/* else { */
	/* 	displayButtons(value); */
	/* } */

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

bool inRange(int num, int range, int limit) {
	if ((num > (range - limit)) && (num < (range + limit)))
		return true;
	return false;
}

void displayButtons(int value) {
	if (inRange(value, but1, lim)) {
		disp.display(3, N8);
	}
	if (inRange(value, but2, lim)) {
		disp.display(2, N8);
	}
	if (inRange(value, but3, lim)) {
		disp.display(1, N8);
	}
	if (inRange(value, but12, lim)) {
		disp.display(3, N8);
		disp.display(2, N8);
	}
	if (inRange(value, but13, lim)) {
		disp.display(3, N8);
		disp.display(1, N8);
	}
	if (inRange(value, but23, lim)) {
		disp.display(3, N8);
		disp.display(2, N8);
	}
	if (inRange(value, but123, lim)) {
		disp.display(3, N8);
		disp.display(2, N8);
		disp.display(1, N8);
	}
}
