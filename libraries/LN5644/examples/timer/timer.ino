#include "LN5644.h"
#include "Timer.h"

#define bStart 10
#define bPause 11
#define bStop 12
#define zoomer A4

int an[4] = {A0, A1, A2, A3};
int cat[8] = {7, 9, 5, 3, 2, 8, 6, 4}; 

LN5644 disp;
Timer timer;

void setup() {
	pinMode(bStart, INPUT_PULLUP);
	pinMode(bStop, INPUT_PULLUP);
	pinMode(bPause, INPUT_PULLUP);
	pinMode(zoomer, OUTPUT);
	digitalWrite(zoomer, LOW);
	
	disp.init();

	disp.setAnods(an);
	disp.setCatods(cat);
}

void loop() {
	disp.next();
	if (!digitalRead(bStart)) {
		timer.start();
	}
	if (!digitalRead(bPause)) {
		timer.pause();
	}
	if (!digitalRead(bStop)) {
		timer.stop();
	}
	disp.display(timer.next());
	if ((timer.next() > 0) && (timer.next() % 60) == 0) {
		tone(zoomer, 5000);
	}
	else {
		noTone(zoomer);
	}	
}

