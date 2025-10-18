int potPin = A0;
int leds[5][2] = {
  {2, 3},
  {4, 5},
  {6, 7},
  {8, 9},
  {10, 11}
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

  // Turn all LEDs off first
  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i][0], LOW);
    digitalWrite(leds[i][1], LOW);
  }

  // Decide how many LED pairs to light
  int level = 0;
  if (potValue > 0)   level = 1;
  if (potValue > 205) level = 2;
  if (potValue > 410) level = 3;
  if (potValue > 615) level = 4;
  if (potValue > 820) level = 5;

  // Turn ON LED pairs up to "level"
  for (int i = 0; i < level; i++) {
    digitalWrite(leds[i][0], HIGH);
    digitalWrite(leds[i][1], HIGH);
  }
}
