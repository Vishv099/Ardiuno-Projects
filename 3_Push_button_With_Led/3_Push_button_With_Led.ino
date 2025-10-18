// Define the pins for the LED and the button
const int buttonPin = 2; // Digital pin connected to the pushbutton
const int ledPin = 3;    // Digital pin connected to the LED

// Variable to store the state of the button
int buttonState = 0;

void setup() {
  // Set the button pin as an input
  pinMode(buttonPin, INPUT);
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the state of the button
  buttonState = digitalRead(buttonPin);

  // Check if the button is pressed (HIGH state)
  if (buttonState == HIGH) {
    // LED on
    digitalWrite(ledPin, HIGH);
  } else {
    // LED off
    digitalWrite(ledPin, LOW);
  }
}