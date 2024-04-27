#include <Arduino.h>
#include <RoboUltrassonico.h>

// Defina os pinos do sensor ultrassônico e do drive de motores que deve ser PWM
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
  
  // Verifica se a distância é menor que um valor de obstáculo
  if (distancia < 20) {
    // Se houver um obstáculo próximo, faça o robô dar ré e girar para a direita
    robo.re(150);
    delay(1000); // Dá ré por 1 segundo
    robo.vireDireita(200);
    delay(1000); // Gira para a direita por 1 segundo
  } else {
    // Se não houver obstáculo, siga em frente
    robo.frente(200);
  }

  // Imprime a distância medida para monitoramento
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Aguarda um curto período de tempo antes da próxima leitura
  delay(100);
}
