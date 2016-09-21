// Пины светодиодов
#define led1 5
#define led2 6
#define led3 7
#define led4 8
#define led5 9

// Пин зумера
#define zoomer 12

// Направление движения
#define UP 1
#define DOWN 0

// Матрица светодиодов
int steps[5] = {led1, led2, led3, led4, led5};

// Структура датчиков
struct sensor {
  byte pin;
  byte prev_state;
  byte state;
  byte last_state;
  long last_time;
};

// Переменные сенсоров
sensor sensor_down = {
  2,
  HIGH,
  HIGH,
  HIGH,
  0
};

sensor sensor_up = {
  3,
  HIGH,
  HIGH,
  HIGH,
  0
};

// Переменные для функции устранения дребезга контактов
int debounce_delay = 50;

// Параметры
int step_time = 3000;

void setup() {
  for (int i = 0; i <= 4; i += 1) {
    pinMode(steps[i], OUTPUT);
    digitalWrite(steps[i], HIGH);
  }
  pinMode(sensor_up.pin, INPUT);
  pinMode(sensor_down.pin, INPUT);
  digitalWrite(sensor_up.pin, HIGH);
  digitalWrite(sensor_down.pin, HIGH);
}
  
void loop() {
  debounce_read(sensor_down);
  if (sensor_down.prev_state == HIGH) {
    if (sensor_down.state == LOW) {
      switch_led(led1);
      tone(zoomer, 5000);
    }
  }
  if (sensor_down.state == HIGH) {
    noTone(zoomer);
  }
  sensor_down.prev_state = sensor_down.state;
}

void switch_led(int led) {
  digitalWrite(led, !digitalRead(led));
}

// Функция устранения дребезга контактов
void debounce_read(sensor sens) {
  int reading = digitalRead(sens.pin);
  
  if (reading != sens.last_state) {
    sens.last_time = millis();
  }
  
  if ((millis() - sens.last_time) > debounce_delay) {
    if (reading != sens.state) {
      sens.state = reading;
    }
  }
  sens.last_state = reading;
}

void on_led_up(int direction) {
  if (direction == UP) {
    for (int step = 0; step <=4; step++) {
      digitalWrite(steps[step], LOW);
	  delay(step_time);
    }
  }
}
