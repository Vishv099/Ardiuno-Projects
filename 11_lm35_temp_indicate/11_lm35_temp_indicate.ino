char degree = 176;  // ASCII value for degree symbol

void setup() {
  pinMode(A0, INPUT);
  pinMode(3, OUTPUT);  // red
  pinMode(4, OUTPUT);  // yellow
  pinMode(5, OUTPUT);  // green

  Serial.begin(9600);  // Start serial communication
}

void loop() {
  int temp = analogRead(A0);  // Read from TMP36 sensor
  float voltage = (temp * 5.0) / 1024;
  float milivolt = voltage * 1000;
  float tempcel = (milivolt - 500) / 10;  // TMP36 conversion
  float tempfar = ((tempcel * 9) / 5) + 32;

  // Turn off all LEDs
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

  // Print data to Serial Monitor
  Serial.print("10-bit value (0-1023): ");
  Serial.println(temp);

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  Serial.print("Millivolt: ");
  Serial.print(milivolt);
  Serial.println(" mV");

  Serial.print("Celsius: ");
  Serial.print(tempcel);
  Serial.print(degree);
  Serial.println("C");

  Serial.print("Fahrenheit: ");
  Serial.println(tempfar);

  // LED logic based on temperature
  if (tempcel >= 100) {
    digitalWrite(3, HIGH);  // red
  }
  else if (tempcel >= 75 && tempcel < 100) {
    digitalWrite(4, HIGH);  // yellow
  }
  else {
    digitalWrite(5, HIGH);  // green
  }

  delay(1000);  // Wait 1 second before next reading
}
