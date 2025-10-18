const int buttonPin = 1; // Push button pin (changed to avoid conflict)
int buttonState = 0;
int lastButtonState = 0;

// Start from first LED pair (pins 2 & 3)
int currentPair = 0;

// LED pin pairs
int ledPins[][2] = {
  {2, 3},
  {4, 5},
  {6, 7},
  {8, 9},
  {10, 11}
};

void setup() {
  pinMode(buttonPin, INPUT);

  // Set all LED pins as OUTPUT and turn them off
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i][0], OUTPUT);
    pinMode(ledPins[i][1], OUTPUT);
    digitalWrite(ledPins[i][0], LOW);
    digitalWrite(ledPins[i][1], LOW);
  }
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // Detect button press (rising edge)
  if (buttonState == HIGH && lastButtonState == LOW) {
    // Turn off current pair
    for (int i = 0; i < 5; i++) {
      digitalWrite(ledPins[i][0], LOW);
      digitalWrite(ledPins[i][1], LOW);
    }

    // Turn on the next pair
    digitalWrite(ledPins[currentPair][0], HIGH);
    digitalWrite(ledPins[currentPair][1], HIGH);

    // Move to next pair for next press
    currentPair++;
    if (currentPair >= 5) {
      currentPair = 0; // Loop back to first pair
    }

    delay(200); // Debounce
  }

  lastButtonState = buttonState;
}
