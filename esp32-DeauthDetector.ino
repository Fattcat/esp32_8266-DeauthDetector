#include <WiFi.h>

// ! ESP32 Code for detect DEAUTH ATTACKs on YOUR ROUTER with BUZZER !
// BUZZER     -->   ESP32
// BuzzerPin  -->   13

const int BUZZER_PIN = 13; // Pin, na ktorom je pripojený bzučiak

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);

  // Pripoj sa k Wi-Fi sieti
  WiFi.begin("YourSSID-OfROuter", "YourPassss");

  // Počkaj, kým sa pripojíme
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi pripojené");
}

void loop() {
  // Ak nie sme pripojený na WiFi sieti
  if (!WiFi.isConnected()) {
    Serial.print("ESP32 JE Odpojene asi deauth utokom !");
    WiFi.begin("YourSSID-OfROuter", "YourPassss");
    delay(300);
    // Bzučiak
    digitalWrite(BUZZER_PIN, HIGH); // Zapni bzučiak
    delay(500); // Počkaj 0,5 sekundy
    digitalWrite(BUZZER_PIN, LOW); // Vypni bzučiak
    delay(500); // Počkaj 0,5 sekundy
  }
}
