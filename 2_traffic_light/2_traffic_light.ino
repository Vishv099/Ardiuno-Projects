// Pin definitions
#define RED 2     // Red LED connected to pin 2
#define YELLOW 3  // Yellow LED connected to pin 3
#define GREEN 4   // Green LED connected to pin 4

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  // Green light ON for 5 sec
  digitalWrite(RED, HIGH);
  delay(5000);
  digitalWrite(RED, LOW);

  digitalWrite(GREEN, HIGH);
  delay(5000);
  digitalWrite(YELLOW, HIGH);
  delay(1000);
  digitalWrite(GREEN, LOW);

  delay(100);
  digitalWrite(YELLOW, LOW);
  delay(100);




  
}