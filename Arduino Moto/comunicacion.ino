#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>
#include <ESPmDNS.h> 

const char* ssid = "";
const char* password = "";

WebServer server(80);

void responderDatos() {
  JsonDocument doc;
  
  doc["sensor"] = analogRead(34); 
  doc["estado"] = "activo";

  String json;
  serializeJson(doc, json);

  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", json);
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConectado!");

  MDNS.begin("moto")

  server.on("/datos", responderDatos);
  server.begin();
}

void loop() {
  server.handleClient();
}
