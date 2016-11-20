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

// Принятые данные
int INDATA[7*REGISTR_COUNT+1];

// Принятые данные инверсные
int INDATAINVERT[7*REGISTR_COUNT+1];

void setup() {
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
	Serial.println("fedcba9876543210");
	Serial.println(shiftInReg(pinData, pinClock, pinLatch), BIN);
	Serial.println();
	delay(1000); 
}

int shiftInReg(int dataPin, int clockPin, int latchPin) {
	int data = 0;
	int temp;

	// Устанавливаем состояние защелки: ON
	digitalWrite(latchPin, HIGH);

	// Прием данных с регистра
	for(int i = 0; i < 7 * REGISTR_COUNT + 1; i++) {
		temp = digitalRead(dataPin);
		if (temp) {
			data = (data << 1) | 1;
		}
		else {
			data = data << 1;
		}

		/* INDATA[i] = digitalRead(pinData); */
		
		// Получаем данные инверсные
		/* INDATAINVERT[i] = digitalRead(pinDataInv); */

		// Посылаем такт синхронизации
		digitalWrite(clockPin, HIGH);
		digitalWrite(clockPin, LOW);  
	}

	// Устанавливаем состояние защелки: OFF
	digitalWrite(latchPin, LOW);

	return data;

	// Выводим данные в терминал
	/* for(int i = 0; i <7*REGISTR_COUNT+1; i++) { */
	/* 	// Получаем данные */
	/* 	Serial.print(INDATA[i]); */
	/* }     */
	/* Serial.print(": INDATA"); */

	// Выводим данные инверсные в терминал
	/* for(int i = 0; i <7*REGISTR_COUNT+1; i++) { */
	/* 	// Получаем данные */
	/* 	Serial.print(INDATAINVERT[i]); */
	/* }     */
	/* Serial.print(": INDATAINVERT"); */
}
