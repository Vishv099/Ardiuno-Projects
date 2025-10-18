int sensor_pin = 2;
int sensor_value = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor_pin, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  sensor_value = digitalRead(sensor_pin);
  if (sensor_value == LOW) {
    Serial.println("object Detected");
    digitalWrite(13, HIGH);
  } else {
    Serial.println("No object Detected");
    digitalWrite(13, LOW);
  }
  delay(500);
}
