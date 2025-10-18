#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read");
    return;
  }

  Serial.print("temprature: ");
  Serial.print(t);
  Serial.println("°C \t");

  Serial.print("humidity: ");
  Serial.print(h);
  Serial.println("% \t");

  delay(500);
}
