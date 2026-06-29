void calibrarSensor(){
  float soma = 0;
  for(int i = 0; i<10; i++){
    float d = sensorVagaA1.lerDistancia();
    soma += d;
    delay(500);
  }
  alturaSensorChao = soma / 10;
}