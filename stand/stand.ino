//********************************************************************//
// ### Демонстрация роботы регистра 74CH165 ###
//********************************************************************//

#include "LN5644.h"

#define dP 2
#define cP 3
#define lP 4

#define Pin_REGDATA 11
#define Pin_REGDATAINVERT 12
#define Pin_REGCLOCK 8 
#define Pin_REGCHECK 7
// Номер пина на плате к которому будет подключено: Вывод включения микросхемы
// Пин 15  СE/
#define Pin_REGACTIV 5
// Количество регистров
#define REGISTR_COUNT 1

// Состояние шини синхронизации
#define REGCLOCK_HIGH HIGH // высокий уровень на шине
#define REGCLOCK_LOW  LOW  // низкий уровень на шине

// Состояние защелки
#define REGCHECK_ON  HIGH // Защелка включена
#define REGCHECK_OFF LOW  // Защелка выключена

// Состояние роботи регистра
#define REGACTIV_ON  LOW   // триггер сброшен
#define REGACTIV_OFF HIGH  // тригер не сброшен

// Принятые данные
int INDATA[7*REGISTR_COUNT+1];

// Принятые данные инверсные
int INDATAINVERT[7*REGISTR_COUNT+1];

LN5644 disp;

void setup()
{
	// Настройка вывода платы в режим "Выход"
	pinMode(Pin_REGCLOCK, OUTPUT);  
	pinMode(Pin_REGCHECK, OUTPUT);
	pinMode(Pin_REGACTIV, OUTPUT);

	// Настройка вывода платы в режим "Вход"  
	pinMode(Pin_REGDATA, INPUT);
	pinMode(Pin_REGDATAINVERT, INPUT);

	// Устанавливаем состояние регистра: NoActiv 
	digitalWrite(Pin_REGACTIV, REGACTIV_OFF); 

	// Устанавливаем состояние защелки: OFF
	digitalWrite(Pin_REGCHECK, REGCHECK_OFF);    
	// Инициализация SerialPort
	Serial.begin(9600);    
	disp.init();
	disp.setPins(dP, cP, lP);
}

void loop()
	{
	disp.next();
	// Устанавливаем состояние защелки: ON
	digitalWrite(Pin_REGCHECK, REGCHECK_ON);
	// Устанавливаем состояние регистра: Activ 
	digitalWrite(Pin_REGACTIV, REGACTIV_ON); 

	// Прием данных с регистра
	for(int i = 0; i <7*REGISTR_COUNT+1; i++)
	{
		// Получаем данные
		INDATA[i] = digitalRead(Pin_REGDATA);
		// Получаем данные инверсные
		INDATAINVERT[i] = digitalRead(Pin_REGDATAINVERT);

		// Посилаем такт синхронизации
		digitalWrite(Pin_REGCLOCK, REGCLOCK_HIGH);
		digitalWrite(Pin_REGCLOCK, REGCLOCK_LOW);  
	}

	// Устанавливаем состояние регистра: NoActiv 
	digitalWrite(Pin_REGACTIV, REGACTIV_OFF); 

	// Устанавливаем состояние защелки: OFF
	digitalWrite(Pin_REGCHECK, REGCHECK_OFF);

	// Выводим данные в терминал
	for(int i = 0; i <7*REGISTR_COUNT+1; i++)
	{
		// Получаем данные
		Serial.print(INDATA[i]);
	}    

	Serial.println(": INDATA");
	
	// Выводим данные инверсные в терминал
	for(int i = 0; i <7*REGISTR_COUNT+1; i++)
	{
		// Получаем данные
		Serial.print(INDATAINVERT[i]);
	}    

	Serial.println(": INDATAINVERT");

	// Задержка времени
	delay(1000); 
	disp.display(1111);
}
