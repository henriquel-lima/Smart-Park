#pragma once

class HCSR04 {
  uint8_t _echoPin;
  uint8_t _trigPin;
  static constexpr float velocidadeSom = 0.017f;

  public:

  HCSR04(uint8_t echoPin, uint8_t trigPin) : _echoPin(echoPin), _trigPin(trigPin) {
    pinMode(_echoPin, INPUT);
    pinMode(_trigPin, OUTPUT);
  }

  float lerDistancia() {
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);

    unsigned long tempo = pulseIn(_echoPin, HIGH, 10000);

    if (tempo == 0){ 
      return -1.0f;
    }
    return tempo * velocidadeSom;
  }
};