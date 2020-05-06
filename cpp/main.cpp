#include "Arduino.h"
#include "LN5644.h"
#include "Timer.h"

#define buttons A0

int value;
int anods[3] = {2, 3, 4};
Timer timer;
LN5644 disp;

void setup() {
	pinMode(A4, INPUT);
	pinMode(buttons, INPUT);
	disp.init();
	disp.setAnods(anods);
	timer.setInitTime(1000);
}

bool bStart(int value) {
	if ((100 < value) && (value <= 250)) {
		return true;
	}
	return false;
}

bool bPause(int value) {
	if ((250 < value) && (value <= 400))
		return true;
	return false;
}

bool bStop(int value) {
	if ((400 < value) && (value <= 550))
		return true;
	return false;
}

void loop() {
	disp.next();

	value = analogRead(buttons);

	if (bStart(value)) {
		timer.start();
	}
	if (bPause(value)) {
		timer.pause();
	}
	if (bStop(value)) {
		timer.stop();
	}

	disp.display(timer.next());

	/* if ((timer.next() > 0) && (timer.next() % 60) == 0) { */
	/* 	tone(zoomer, 5000); */
	/* } */
	/* else { */
	/* 	noTone(zoomer); */
	/* }	 */
}

int main() {
	setup();
	while (true) {
		loop();
	}
}
