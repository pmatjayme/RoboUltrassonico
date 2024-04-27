#include "RoboUltrassonico.h"

RoboUltrassonico::RoboUltrassonico(int trigPin, int echoPin, int in1Pin, int in2Pin, int in3Pin, int in4Pin) {
  _trigPin = trigPin;
  _echoPin = echoPin;
  _in1Pin = in1Pin;
  _in2Pin = in2Pin;
  _in3Pin = in3Pin;
  _in4Pin = in4Pin;

  pinMode(_trigPin, OUTPUT);
  pinMode(_echoPin, INPUT);
  pinMode(_in1Pin, OUTPUT);
  pinMode(_in2Pin, OUTPUT);
  pinMode(_in3Pin, OUTPUT);
  pinMode(_in4Pin, OUTPUT);
}

void RoboUltrassonico::frente(int velocidade) {
  digitalWrite(_in1Pin, HIGH);
  digitalWrite(_in2Pin, LOW);
  digitalWrite(_in3Pin, HIGH);
  digitalWrite(_in4Pin, LOW);
  analogWrite(_in1Pin, velocidade);
  analogWrite(_in3Pin, velocidade);
}

void RoboUltrassonico::re(int velocidade) {
  digitalWrite(_in1Pin, LOW);
  digitalWrite(_in2Pin, HIGH);
  digitalWrite(_in3Pin, LOW);
  digitalWrite(_in4Pin, HIGH);
  analogWrite(_in2Pin, velocidade);
  analogWrite(_in4Pin, velocidade);
}

void RoboUltrassonico::vireDireita(int velocidade) {
  digitalWrite(_in1Pin, HIGH);
  digitalWrite(_in2Pin, LOW);
  digitalWrite(_in3Pin, LOW);
  digitalWrite(_in4Pin, HIGH);
  analogWrite(_in1Pin, velocidade);
  analogWrite(_in4Pin, velocidade);
}

void RoboUltrassonico::vireEsquerda(int velocidade) {
  digitalWrite(_in1Pin, LOW);
  digitalWrite(_in2Pin, HIGH);
  digitalWrite(_in3Pin, HIGH);
  digitalWrite(_in4Pin, LOW);
  analogWrite(_in2Pin, velocidade);
  analogWrite(_in3Pin, velocidade);
}

float RoboUltrassonico::lerSensor() {
  long duration;
  digitalWrite(_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);
  duration = pulseIn(_echoPin, HIGH);
  distancia = (duration * 0.0343)/2;
  return distancia;
}


