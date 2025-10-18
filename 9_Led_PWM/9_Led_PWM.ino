#define led 9   // Use a PWM pin like 3, 5, 6, 9, 10, or 11

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  // Fade in
  for (int i = 0; i <= 255; i++) {
    analogWrite(led, i);
    delay(5);
  }

  // Fade out
  for (int j = 255; j >= 0; j--) {
    analogWrite(led, j);
    delay(5);
  }
}
