int led[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 12; i++) {
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<12; i++)
  {
    digitalWrite(led[i], HIGH);
    delay(200);
    digitalWrite(led[i], LOW);

  }
    for(int i=11; i>0; i--)
  {
    digitalWrite(led[i], HIGH);
    delay(200);
    digitalWrite(led[i], LOW);

  }
}
