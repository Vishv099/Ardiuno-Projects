#define pot A0
#define led 9

int potvalue, bright;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potvalue = analogRead(A0);
  bright = map(potvalue, 0, 1023, 0, 255);
  analogWrite(led, bright);

  Serial.println("Potvalue");
  Serial.print(potvalue);
  Serial.println("Brightness");
  Serial.print(bright);
  delay(30);

}
