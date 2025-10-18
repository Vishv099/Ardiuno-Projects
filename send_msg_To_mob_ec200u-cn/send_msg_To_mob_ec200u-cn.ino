#include <SoftwareSerial.h>

SoftwareSerial ec200u(8, 7); // RX = 8, TX = 7

void setup() {
  Serial.begin(115200);
  ec200u.begin(115200);
  delay(3000);

  Serial.println("=== EC200U SMS Example ===");

  sendCommand("AT");                // Check module
  sendCommand("ATE0");              // Echo off
  sendCommand("AT+CPIN?");          // SIM check
  sendCommand("AT+CSQ");            // Signal quality
  sendCommand("AT+CREG?");          // Network registration
  sendCommand("AT+CMGF=1");         // SMS text mode

  // Send SMS
  ec200u.println("AT+CMGS=\"+917387451535\""); // Replace with real number
  delay(1000);
  ec200u.print("Hello from EC200U + Arduino!");
  ec200u.write(0x1A);  // Ctrl+Z to send
  delay(3000);
}

void loop() {
  // Print module responses
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
