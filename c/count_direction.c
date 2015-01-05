//Apenas um teste em C para verificar o += como reducao e adicao em loop
#include <stdio.h>

int num[10]; //inicia o array com 10 inteiros

int direction = 1; //seta o contador direction como 1
int change = 0; //seta o contador change como 0
int x; 
int a = 1; //apenas para criar um while true

void loop(){ //funcao loop infinito que conta de 0 a 9 e 9 a 0
while (a == 1){
	for (x=0; x<10; x++){
		printf("num [%d]\n", x);
		change += direction; //muda a direcao do loop no array
		if (change == 9) {direction = -1;}
		if (change == 0) {direction = 1;}
		printf("Mudanca: %d\n", change);
		}
	}
}

int main()
{
loop();
}
