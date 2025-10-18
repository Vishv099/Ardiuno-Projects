/*
EC200U  ARD 
TX = 8
RX =7
5V= 5V
GND = GND
*/
#include <SoftwareSerial.h>

SoftwareSerial ec200u(8, 7); // RX = 8, TX = 7

// Vodafone India APN
const char apn[] = "internet";                  
const char mqtt_server[] = "test.mosquitto.org"; // Public MQTT broker
const int  mqtt_port = 1883;
const char client_id[] = "arduinoClient";        // MQTT client ID
const char pub_topic[] = "test/arduino/pub";
const char sub_topic[] = "test/arduino/sub";

void setup() {
  Serial.begin(115200);
  ec200u.begin(115200);
  delay(3000);

  Serial.println("=== EC200U MQTT Example (Vodafone) ===");

  sendCommand("AT");                              // Check module
  sendCommand("ATE0");                            // Echo off
  sendCommand("AT+CPIN?");                        // SIM check
  sendCommand("AT+CSQ");                          // Signal quality
  sendCommand("AT+CREG?");                        // Network registration

  // Setup APN for Vodafone
  sendCommand("AT+QICSGP=1,1,\"" + String(apn) + "\",\"\",\"\",1");
  sendCommand("AT+QIACT=1");                      // Activate PDP context
  sendCommand("AT+QIACT?");                       // Check IP

  // MQTT setup
  sendCommand("AT+QMTCFG=\"version\",0,4");       // MQTT 3.1.1
  sendCommand("AT+QMTOPEN=0,\"" + String(mqtt_server) + "\"," + String(mqtt_port));
  delay(3000);
  sendCommand("AT+QMTCONN=0,\"" + String(client_id) + "\"");
  delay(2000);

  // Subscribe to topic
  sendCommand("AT+QMTSUB=0,1,\"" + String(sub_topic) + "\",0");

  // Publish initial message
  mqttPublish("Hello from Arduino");
}

void loop() {
  // Periodically publish
  static unsigned long lastPub = 0;
  if (millis() - lastPub > 10000) { // every 10s
    mqttPublish("Arduino IS HERE");
    lastPub = millis();
  }

  // Print responses (including subscribed messages)
  while (ec200u.available()) {
    Serial.write(ec200u.read());
  }
}

void sendCommand(String cmd) {
  Serial.println(">> " + cmd);
  ec200u.println(cmd);
  delay(1000);
  while (ec200u.available()) {
    Serial.write(ec200u.read());
  }
  Serial.println();
}

void mqttPublish(String msg) {
  String cmd = "AT+QMTPUB=0,0,0,0,\"" + String(pub_topic) + "\"";
  sendCommand(cmd);
  ec200u.print(msg);
  ec200u.write(0x1A); // Ctrl+Z
  delay(1000);
  Serial.println("Published: " + msg);
}
