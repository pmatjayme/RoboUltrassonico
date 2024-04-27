#include <Arduino.h>
#include <RoboUltrassonico.h>

// Defina os pinos do sensor ultrassônico e do drive de motores, que devem ser PWM
const int trigPin = 2;
const int echoPin = 3;
const int in1Pin = 5;
const int in2Pin = 6;
const int in3Pin = 9;
const int in4Pin = 10;

// Crie uma instância da classe RoboUltrassonico
RoboUltrassonico robo(trigPin, echoPin, in1Pin, in2Pin, in3Pin, in4Pin);

void setup() {
  // Inicializa a comunicação serial para monitoramento
  Serial.begin(9600);
}

void loop() {
  // Lê a distância medida pelo sensor ultrassônico
  float distancia = robo.lerSensor();
  
  // Tomada de decisão com base na distância medida
  if (distancia < 10) {
    Serial.println("Objeto detectado muito próximo. Recuando...");
    robo.re(200);
    delay(1000);
  } else if (distancia >= 10 && distancia < 20) {
    Serial.println("Objeto detectado à frente. Virando à direita...");
    robo.vireDireita(150);
    delay(1000);
  } else if (distancia >= 20 && distancia < 30) {
    Serial.println("Objeto detectado à frente. Virando à esquerda...");
    robo.vireEsquerda(150);
    delay(1000);
  } else {
    Serial.println("Nenhum objeto detectado à frente. Avançando...");
    robo.frente(200);
    delay(1000);
  }

  // Imprime a distância medida para monitoramento
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Aguarda um curto período de tempo antes da próxima leitura
  delay(500);
}
