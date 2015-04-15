//Projeto 25
#include <Servo.h>

Servo servo1; //cria um objeto servo

void setup() {
  servo1.attach(5); //Anexa o servo (fisico), no pino 5 ao objeto (logico)
}

void loop(){
  int angle = analogRead(0); //Le o valor do ptenciometro
  angle=map(angle, 0, 1023, 0 , 180); //mapeia os valores  de 0 a 180 graus
  servo1.write(angle); //Escreve o angulo para o servo
  delay(15); //espera 15ms, para permitir que o servo atinja a posicao
}
