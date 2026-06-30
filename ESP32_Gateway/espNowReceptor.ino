void aoReceber(const esp_now_recv_info_t *info, const uint8_t *incomingData, int len){
  memcpy(&dadosRecebidos, incomingData, sizeof(dadosRecebidos));
  novosDadosRecebidos = true;

  Serial.print("Recebido da vaga ");
  Serial.print("A1");
  Serial.println(dadosRecebidos.estadoVaga1 ? ": OCUPADA" : ": LIVRE");

  //enviarDados(dadosRecebidos.estadoVaga1);
}

void setupEspNow(){
  WiFi.mode(WIFI_STA);

  if(esp_now_init() != ESP_OK){
    Serial.println("Erro ao iniciar esp-now");
    delay(2000);
    ESP.restart();
  }
  Serial.println("Esp-now iniciado com sucesso");

  esp_now_register_recv_cb(aoReceber);
}