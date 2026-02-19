#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Replace with your Blynk Auth Token
char auth[] = "YOUR_BLYNK_AUTH_TOKEN";

// Replace with your WiFi credentials
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// LED connected to D1 pin (GPIO5)
#define LED_PIN D1

// This function runs when button widget on Blynk changes state
BLYNK_WRITE(V1) {
  int ledState = param.asInt();  // 1 = ON, 0 = OFF
  digitalWrite(LED_PIN, ledState ? HIGH : LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);   // LED OFF at start

  // Connect to Blynk Cloud
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}
