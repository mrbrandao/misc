/* LEDs que se Encontram no meio
Exercicios com Leds
Aqui estamos usando 10 leds e fazemos com que os dois ultimos leds
iniciem acessos e sigam avancando um em direcao ao outro ate que se
encontrem no meio e depois retornem a ponta.*/

int leds[] = {3,4,5,6,7,8,9,10,11,12};

byte maior = 9; //define a posicao inicial do ultimo led a esquerda
byte menor = 0; //define a posicao inicial do ultimo led a diretira
byte direction_menor = 1; //seta o ponteiro para contagem de + ou -
byte direction_maior = 1; //seta o ponteiro para contagem de + ou -

void setup(){
  for (byte x=0; x<10; x++){
    pinMode(leds[x], OUTPUT);
  }
}

void loop(){
  pisca();
}

void pisca(){
  
  for (byte x=0; x<10; x++){ //inicia apagando todo mundo
    digitalWrite(leds[x], LOW);
    }
    
    digitalWrite(leds[maior], HIGH); //acende os leds das pontas
    digitalWrite(leds[menor], HIGH);
    delay(200);
   
    //quando o ponteiro estiver no ultimo led maior comeca a diminuir 
    if (maior == 9){ delay(500);direction_maior = -1;}
    
    //quando o ponteiro estiver no ultime led menor comeca a subir
    if (menor == 0){ delay(500);direction_menor = 1;}
    
    if (maior == 5){direction_maior = 1;}
    if (menor == 4){direction_menor = -1;}
    
    maior += direction_maior; //incrementa os ponteiros
    menor += direction_menor;
}
