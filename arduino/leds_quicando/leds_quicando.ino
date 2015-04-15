/* Leds que quicam
Neste exercicio vou criar um efeito que 10 leds pisquem como
um bola que estivesse quicando e fosse diminuindo a velocidade
conforme chega ao final da linha*/

int leds[]={3,4,5,6,7,8,9,10,11,12,13};

int changeled=0;

void setup(){
  for (int x=0; x<10; x++){
    pinMode(leds[x], OUTPUT);
  }
}


void loop(){
  for (int x=0; x<10; x++){
    digitalWrite(leds[x], LOW);
  }
  led_quicando();
}


void led_quicando(){
  for (int x=changeled; x<10; x++){
    digitalWrite(leds[x], HIGH);
    delay(60);
  }
  changeled+= 1;
  if (changeled == 9){changeled = 0;}
}

