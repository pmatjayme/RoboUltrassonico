#ifndef RoboUltrassonico_h
#define RoboUltrassonico_h

#include <Arduino.h>

class RoboUltrassonico {
  public:
    RoboUltrassonico(int trigPin, int echoPin, int in1Pin, int in2Pin, int in3Pin, int in4Pin);

    void frente(int velocidade);
    void re(int velocidade);
    void vireDireita(int velocidade);
    void vireEsquerda(int velocidade);
    float lerSensor();

  private:
    int _trigPin;
    int _echoPin;
    int _in1Pin;
    int _in2Pin;
    int _in3Pin;
    int _in4Pin;
};

#endif
