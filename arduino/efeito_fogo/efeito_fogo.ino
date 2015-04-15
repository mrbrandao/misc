// Projeto 9 - efeito de fogo com Leds
//Foi utilizado um led vermelho e dois amarelos
int led[] = {9,10,11};

void setup(){
  for (int x=1; x<=3; x++){
    pinMode(led[x], OUTPUT);
  }
}

void loop(){
  for (int x=1; x<=3; x++){
   analogWrite(led[x], random(120)+136);
    delay(random(100));
  }
}

