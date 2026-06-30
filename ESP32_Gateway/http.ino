void enviarDados(bool ocupada) {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Sem WiFi, dado não enviado.");
    return;
  }

  HTTPClient http;
  http.begin(serverURL);
  http.addHeader("Content-Type", "application/json");

  String payload = "{\"estado\":" + String(ocupada ? "true" : "false") + "}";

  int httpCode = http.POST(payload);

  if (httpCode > 0) {
    Serial.printf("POST OK: %d\n", httpCode);
  } else {
    Serial.printf("Erro HTTP: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
}