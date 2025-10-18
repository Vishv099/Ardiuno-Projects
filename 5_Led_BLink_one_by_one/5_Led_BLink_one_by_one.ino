void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
int x, y;
  for ( x = 11; x >= 2; x--) 
  {
    // Turn off all pins
    for (int y = 2; y <= 11; y++) {
      digitalWrite(y, LOW);
    }
    
    // Turn on one pin
    digitalWrite(x, HIGH);
    // Wait
    delay(700);
  }

}
