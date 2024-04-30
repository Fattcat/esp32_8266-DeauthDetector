#include <ESP8266WiFi.h>

// ! ESP8266 Code for detect DEAUTH ATTACKs on YOUR ROUTER with BUZZER !
// BUZZER     -->   ESP8266
// BuzzerPin  -->   13

const int BUZZER_PIN = 13; // Pin, na ktorom je pripojený bzučiak

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);

  // Pripoj sa k Wi-Fi sieti
  WiFi.begin("Názov_siete", "Heslo_siete");

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
    Serial.print("ESP8266 JE Odpojene asi deauth utokom !");
    WiFi.begin("Názov_siete", "Heslo_siete");
    delay(300);
    // Bzučiak
    digitalWrite(BUZZER_PIN, HIGH); // Zapni bzučiak
    delay(500); // Počkaj 0,5 sekundy
    digitalWrite(BUZZER_PIN, LOW); // Vypni bzučiak
    delay(500); // Počkaj 0,5 sekundy
  }
}
