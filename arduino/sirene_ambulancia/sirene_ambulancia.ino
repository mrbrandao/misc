//Sirene de ambulancia com dois leds
//Use um led azul e vermelho para parecer com um ambulancia

int led[] = {9,10};

void setup(){
  for (int x=0; x<2; x++){
    pinMode(led[x], OUTPUT);
  }
}

void loop(){
  for (int x=0; x<2; x++){
    for (int i=0; i<100; i++){
      analogWrite(led[x], i);
      delay(5);
      if (i == 99){analogWrite (led[x], 0);}
    }
  }
}
    
