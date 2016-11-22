//********************************************************************//
// ### Демонстрация роботы регистра 74CH165 ###
//********************************************************************//

// Пин 9 Q
#define pinData 11

// Пин 7 Q/
#define pinDataInv 12

// Пин 2_CP
#define pinClock 8 

// Пин 1 PL/
#define pinLatch 7

// Количество регистров
#define REGISTR_COUNT 2

#include "LN5644.h"

long bits;
int bytes[4] = {0};
LN5644 disp;

void setup() {
	disp.init();
	disp.setPins(2, 3, 4);
	// Настройка вывода платы в режим "Выход"
	pinMode(pinClock, OUTPUT);  
	pinMode(pinLatch, OUTPUT);

	// Настройка вывода платы в режим "Вход"  
	pinMode(pinData, INPUT);
	pinMode(pinDataInv, INPUT);

	// Устанавливаем состояние защелки: OFF
	digitalWrite(pinLatch, LOW);    

	// Инициализация SerialPort
	Serial.begin(9600);    
}
	 
void loop() {
	/* Serial.println("fedcba9876543210"); */
	bits = shiftInReg(pinData, pinClock, pinLatch);
	displayBits(bits);
	/* Serial.println(bits, BIN); */
	/* Serial.println(bits); */
	/* delay(1000);  */
}

long shiftInReg(int dataPin, int clockPin, int latchPin) {
	long data = 0;
	int temp;

	// Устанавливаем состояние защелки: ON
	digitalWrite(latchPin, HIGH);

	/* Serial.println(); */

	// Прием данных с регистра
	for(int i = 0; i < 8 * REGISTR_COUNT; i++) {
		temp = digitalRead(dataPin);
		if (temp) {
			data = (data << 1) | 1;
		}
		else {
			data = data << 1;
		}

		// Посылаем такт синхронизации
		digitalWrite(clockPin, HIGH);
		digitalWrite(clockPin, LOW);  
	}

	// Устанавливаем состояние защелки: OFF
	digitalWrite(latchPin, LOW);

	return data;
}

void displayBits(long data) {
	for (int i = 0; i < 4; i++) {
		bytes[i] = data & 0xf;
		/* Serial.println(int(data & 0xf), BIN); */
		/* disp.display(i+1, int(data & 0xf)); */
		disp.display(1111);
		data = data >> 4;
	}
	/* Serial.println(); */
	/* for (int i = 0; i < 4; i++) { */
		/* Serial.print(i); */
		/* Serial.print(" = "); */
		/* Serial.println(bytes[i], BIN); */
	/* } */
}
