#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

const char* ssid = "JFrancisQ";
const char* password = "12345678";
const char* apiKey = "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";

ESP8266WebServer server(80);

String inputText = "Hello Chat gpt";  // Default prompt

void handleRoot() {
  String url = "https://api.openai.com/v1/completions";
  String payload = "{\"model\": \"gpt-3.5-turbo\",\"messages\": [{\"role\": \"user\", \"content\": \"" + inputText + "\"}]}";
  // String payload = "{\"prompt\":\"" + inputText + "\",\"max_tokens\":100, \"model\": \"gpt-3.5-turbo\"}";

  WiFiClientSecure client;
  client.setInsecure();

  if (!client.connect("api.openai.com", 443)) {
    Serial.println("connection failed");
    return;
  }

  client.println("POST " + String(url) + " HTTP/1.1");
  client.println("Host: api.openai.com");
  client.println("Content-Type: application/json");
  client.println("Content-Length: " + String(payload.length()));
  client.println("Authorization: Bearer " + String(apiKey));
  client.println("Connection: close");
  client.println();
  client.println(payload);

  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  String response = "";
  while (client.available()) {
    char c = client.read();
    response += c;
  }

  client.stop();

  DynamicJsonDocument jsonDoc(1024);
  deserializeJson(jsonDoc, response);
  Serial.println("Request Payload: " + payload);
  Serial.println("Response: " + response);

  String outputText = jsonDoc["choices"][0]["text"];
  
  Serial.println("outputText: " + outputText);
  String page = "<html><body><h1>" + outputText + "</h1></body></html>";
  server.send(200, "text/html", page);
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
    Serial.flush();
  }

  Serial.println("Connected to WiFi");
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());
  Serial.flush();

  server.on("/", HTTP_GET, handleRoot);

  server.begin();
}

void loop() {
  server.handleClient();

  // Check if there is any input from the serial monitor
  if (Serial.available() > 0) {
    inputText = Serial.readStringUntil('\n');
    Serial.println("New input: " + inputText);
  }
}
