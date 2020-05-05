/*********************************************************************
* Прошивка для стенда.
*********************************************************************/

#include "Wire.h"
#include "LiquidCrystal_I2C.h"
#include "OneWire.h"
#include "DallasTemperature.h"

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature teSensor(&oneWire);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
	lcd.init();
	lcd.backlight();
	lcd.print("Stand v0.1");
	teSensor.begin();
	lcd.setCursor(0, 1);
	lcd.print("Tout = ");
}
	 
void loop() {
	teSensor.requestTemperatures();
	lcd.setCursor(7, 1);
	lcd.print(teSensor.getTempCByIndex(0));  
}
