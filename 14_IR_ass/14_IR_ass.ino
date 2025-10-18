int sensor_pin = 2;
int sensor_value = 0;
int red_Led = 10;
int green_Led = 11;
void setup() {
  // put your setup code here, to run once:
  pinMode(sensor_pin, INPUT);
  pinMode(red_Led, OUTPUT);
  pinMode(green_Led, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  sensor_value = digitalRead(sensor_pin);
  if (sensor_value == LOW) {

    Serial.println("object Detected");
    digitalWrite(red_Led, HIGH);
    digitalWrite(green_Led, LOW);
  } else {
    Serial.println("No object Detected");
    digitalWrite(green_Led, HIGH);
    digitalWrite(red_Led, LOW);
  }
  delay(500);
}
