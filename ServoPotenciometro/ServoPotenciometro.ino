#include <Servo.h>

Servo servo1;
int pinServo = 2;
int angulo;
int valorPot;
int pot = 0;

void setup() {
  servo1.attach(pinServo);
}

void loop() {
  valorPot = analogRead(pot);
  angulo = map(valorPot, 0, 1023, 0, 180);    // la funcion map toma un valor de un intervalo y lo transforma en otro valor de otro intervalo de forma proporcional
  servo1.write(angulo);
  delay(20);
}