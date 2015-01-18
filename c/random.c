/* Alguns exemplos usando random em C
estou usando o time para semear o random
e mostro aqui tres exemplos.
No primeiro como gerar numeros aleatorios
no segundo um jogo de dados
e no terceiro um cara e coroa.

By: zz0
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //estou usando o time como seed

int num;


/*Primeiro exemplo
Numeros Aleatorios*/

int numero(){
srand(time(NULL));//seed do random
int num = random() %5;//varia entre 0 e 4
printf("Numero aleatorio da vez: %d\n", num);
}

//Um jogo de dados

int dado(){
int num = random() %6 + 1;//intervalo entre 1 e 6
printf ("Dado resultou em: %d\n", num);
}


//Cara e coroa

int moeda(){
int num = random() %2 +1; //intervalo entre 1 e 2
if (num == 1) {printf("Deu cara\n");}
else if (num == 2) {printf("Deu coroa\n");}
}

int main(){
numero();
dado();
moeda();
}
