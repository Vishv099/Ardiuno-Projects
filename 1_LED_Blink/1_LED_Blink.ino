void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT); //Select the pin and direction
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(8, HIGH); //To on the LED
  delay(500);
  digitalWrite(8, LOW); //To off The LED
  delay(500);
}
