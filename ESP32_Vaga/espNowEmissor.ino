#include <esp_wifi.h> // necessário para esp_wifi_set_channel

void aoEnviar(const wifi_tx_info_t* info, esp_now_send_status_t status){
  Serial.print("Envio: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "OK" : "FALHOU");
}

void setupEspNow(){
  const uint8_t canal = 3; // ATENÇÃO! Mudar de acordo com o canal do ESP receptor.
  WiFi.mode(WIFI_STA);
  esp_wifi_set_channel(canal, WIFI_SECOND_CHAN_NONE); // precisa coincidir com o canal do roteador

  if(esp_now_init() != ESP_OK){
    Serial.println("Erro ao iniciar esp-now");
    delay(2000);
    ESP.restart();
  }
  Serial.println("Esp-now iniciado com sucesso");

  esp_now_register_send_cb(aoEnviar);

  esp_now_peer_info_t peer = {};
  memcpy(peer.peer_addr, macGateway, 6);
  peer.channel = canal;
  peer.encrypt = false;

  if(esp_now_add_peer(&peer) != ESP_OK){
    Serial.println("Erro ao adicionar peer");
    delay(2000);
    ESP.restart();
  }
  Serial.println("Peer adicionado com sucesso");
}

void enviarDados(){
  esp_err_t resultado = esp_now_send(macGateway, (uint8_t*) &dados, sizeof(dados));
  if(resultado != ESP_OK){
    Serial.println("Erro ao enviar pacotes");
    return;
  }
  Serial.println("Pacotes enviados");
}
