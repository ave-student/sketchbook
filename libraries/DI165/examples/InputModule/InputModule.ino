//********************************************************************//
// ### Демонстрация роботы регистра 74CH165 ###
//********************************************************************//

// Пин 9 Q
#define pinData 11

// Пин 7 Q/
#define pinDataInv 12

// Пин 2_CP
#define pinClock 10 

// Пин 1 PL
#define pinLatch 9

// Количество регистров
#define REGISTR_COUNT 2

#include "Wire.h"
#include "LiquidCrystal_I2C.h"
#include "DI165.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
DI165 dim(pinDataInv, pinClock, pinLatch, REGISTR_COUNT);

long bits;

void setup() {
	lcd.init();
	lcd.backlight();
	lcd.print("74HC165 input");
}
	 
void loop() {
	bits = dim.shiftIn(0);
	bits = bits << 8;
	bits = bits | dim.shiftIn(1);

	lcd.setCursor(0, 1);
	lcd.print(bits, BIN);
}
