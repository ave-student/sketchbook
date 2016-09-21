// Пины светодиодов
#define led1 5
#define led2 6
#define led3 7
#define led4 8
#define led5 9

// Пин зумера
#define zoomer 12

// Пины сенсоров
#define sensor_up 3
#define sensor_down 2

// Направление движения
#define UP 1
#define DOWN 0

// Матрица светодиодов
int steps[] = {led1, led2, led3, led4, led5};

// Переменные сенсоров
int prev_state = digitalRead(sensor_down);

// Переменные для функции устранения дребезга контактов
int state;
int last_state = HIGH;
long last_time = 0;
int debounce_delay = 50;

void setup() {
  for (int i = 0; i <= 4; i += 1) {
    pinMode(steps[i], OUTPUT);
    digitalWrite(steps[i], HIGH);
  }
  pinMode(sensor_up, INPUT);
  pinMode(sensor_down, INPUT);
  digitalWrite(sensor_up, HIGH);
  digitalWrite(sensor_down, HIGH);
}
  
void loop() {
  int cur_state = debounce_read(sensor_down);
  if (prev_state == HIGH) {
    if (cur_state == LOW) {
      switch_led(led1);
      tone(zoomer, 5000);
    }
  }
  if (cur_state == HIGH) {
    noTone(zoomer);
  }
  prev_state = cur_state;
}

void switch_led(int led) {
  digitalWrite(led, !digitalRead(led));
}

// Функция устранения дребезга контактов
int debounce_read(int pin) {
  int reading = digitalRead(pin);
  
  if (reading != last_state) {
    last_time = millis();
  }
  
  if ((millis() - last_time) > debounce_delay) {
    if (reading != state) {
      state = reading;
    }
  }
  last_state = reading;
  
  return state;
}

void on_led_up(int direction) {
  if (direction == UP) {
    for (int step = 0; step <=4; step += 1) {
      digitalWrite(steps[step], HIGH);
    }
  }
}
