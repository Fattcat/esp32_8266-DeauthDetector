#include <WiFi.h>

// ! ESP32 Code for detect DEAUTH ATTACKs on YOUR ROUTER with BUZZER !
// BUZZER     -->   ESP32
// BuzzerPin  -->   13

const int BUZZER_PIN = 13; // Pin, na ktorom je pripojený bzučiak
const char* SSID = "YourSSID-OfROuter";
const char* PASS = "YourPassss";


void setup() {
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);

  // Pripoj sa ku wifi
  WiFi.begin(SSID, PASS);

  // Počka kým sa pripojí
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi pripojené");
}

void loop() {
  // Ak eni pripojený na WiFi siet
  if (!WiFi.isConnected()) {
    Serial.print("ESP32 JE Odpojene asi deauth utokom !");
    WiFi.begin(SSID, PASS);
    delay(300);
    
    digitalWrite(BUZZER_PIN, HIGH);
    delay(500);
    digitalWrite(BUZZER_PIN, LOW);
    delay(500);
  }
}
