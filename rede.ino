void setupWiFi(){
  WiFi.begin(ssid, password);
  Serial.print("Conectando");

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConectado");
}

void reconectarWiFi(){
  const unsigned long intervaloReconexao = 10000;
  static unsigned long tempoReconexao = 0;
  if(millis() - tempoReconexao >= intervaloReconexao){
    tempoReconexao = millis();
    if(WiFi.status() != WL_CONNECTED){
      WiFi.reconnect();
      Serial.print("Reconectando...");
    }
  }
}