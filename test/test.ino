int an[] = {10, 11, A4, A5};

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 8; i++) {
    pinMode(i + 2, OUTPUT);
    digitalWrite(i + 2, LOW);
  }

  for (int i = 0; i < 4; i++) {
    pinMode(an[i], OUTPUT);
    digitalWrite(an[i], HIGH);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
