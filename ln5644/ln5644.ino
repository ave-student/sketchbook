/*

*/

#include "IOLib.h"
#include "LN5644.h"

/* int d1 = 10; */
/* int d2 = 11; */
/* int dig[] = {d1, d2}; */

SDigitalOutput doa5(A5);
SDigitalOutput doa6(A6);
SDigitalOutput do10(10);
SDigitalOutput do11(11);

SDigitalOutput an[] = {do10, do11, doa5, doa6};

SDigitalOutput seg[8];

void _init(void) {
	for (int i = 0; i < 8; i++) {
		seg[i] = newDO(i);
	}
}

/* int an[] = {13, 10, 11, 13}; */
/* int seg[] = {2, 3, 4, 5, 6, 7, 8, 9};  */

/* int n6[] = {LOW, HIGH, LOW, LOW, LOW, LOW, LOW, HIGH}; */
/* int n9[] = {LOW, LOW, LOW, LOW, HIGH, LOW, LOW, HIGH}; */
/*  */
/* int nums[2][8] = {{LOW, HIGH, LOW, LOW, LOW, LOW, LOW, HIGH}, */
/* 	{LOW, LOW, LOW, LOW, HIGH, LOW, LOW, HIGH}}; */

/* int d = 1; */
/* int n = 0; */

LN5644 disp(an, seg);

void setup() {
	/* for(int i = 2; i <= 11; i++) { */
	/* 	pinMode(i, OUTPUT); */
	/* 	if (i > 9) { */
	/* 		digitalWrite(i, HIGH); */
	/* 	} */
	/* 	else { */
	/* 		digitalWrite(i, LOW); */
	/* 	} */
	/* } */
	/* delay(2000); */
	/* digitalWrite(d1, LOW); */
	/* digitalWrite(d2, LOW); */
	_init();
	/* disp.display(1, N6); */
	/* disp.display(2, N9); */
}

void loop() {
	disp.next();
	int num = analogRead(A0);
	disp.display(num);
	/* digitalWrite(dig[d], LOW); */
    /*  */
	/* d = !d; */
	/* n = !n; */
    /*  */
	/* for (int i = 0; i < 8; i++) { */
	/* 	digitalWrite(seg[i], nums[n][i]);  */
	/* } */
    /*  */
	/* digitalWrite(dig[d], HIGH); */
    /*  */
	/* delay(analogRead(A0)); */
}
