char degree = 176;  // ASCII value of degree

void setup() {
  // put your setup code here, to run oncet+
  pinMode(A0, INPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);  // Start communication
}

void loop()

{
  // put your main code here, to run repeatedly:=
  int temp = analogRead(A0);  // 1023 Reading data from sensorm
  // This voltage is stored as a 10-bit nummer

  float voltage = (temp * 5.0) / 1024;  // (5 temp) / 1024 is to convert the 10-hit
  // number to voltage readings

  float milivolt = voltage * 1000;  // This multiplyied by 1000 to convert it to millivolt



  float tempcel = (milivolt - 500) / 10;  // For TMP36 Sensor. Range (-40C to +125c)

  float tempfar(((tempcel * 9) / 5) + 32);  // Used to convert Fahrenheit

  digitalWrite(3, LOW);  // LED OFF

  Serial.print("10-bit number 0-1023)");
  Serial.println(temp);  // To print 18-bit values

  Serial.print("Voltage:");
  Serial.print(voltage);  // to print voltage values
  Serial.println("v");

  Serial.print("Milivolt: ");
  Serial.print(milivolt);
  Serial.println("mv");

  Serial.print("Celsius: ");
  Serial.print(tempcel);
  Serial.println(degree);

  Serial.print("Fahrenheit: ");
  Serial.print(tempfar);
  Serial.println("");

  if (tempcel >= 100)  // If Temp is higher that 100 the LED ON
  {
    digitalWrite(3, HIGH);
  } else  // if not LED OFF
  {
    digitalWrite(3, LOW);
  }
  delay(1000);
}

// temp 75 Yellow LED ON
// temp 100 RED LED ON
// temp 75 GREEN ON
