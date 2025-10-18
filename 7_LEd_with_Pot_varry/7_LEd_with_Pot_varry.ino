int potPin = A0;
int leds[5][2] = {
  { 2, 3 },
  { 4, 5 },
  { 6, 7 },
  { 8, 9 },
  { 10, 11 }
};

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i][0], OUTPUT);
    pinMode(leds[i][1], OUTPUT);
    digitalWrite(leds[i][0], LOW);
    digitalWrite(leds[i][1], LOW);
  }
}

void loop() {
  int potValue = analogRead(potPin); // 0 to 1023

  // Turn all LEDs off
  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i][0], LOW);
    digitalWrite(leds[i][1], LOW);
  }

  // Determine which LED pair to turn on
  int index = map(potValue, 0, 1023, 0, 5); // 0 to 5
  if (index > 0) {
    int ledIndex = index - 1;
    digitalWrite(leds[ledIndex][0], HIGH);
    digitalWrite(leds[ledIndex][1], HIGH);
  }
}
