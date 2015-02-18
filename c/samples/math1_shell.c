#include <stdio.h>
#include <stdlib.h> /*Chama a Lib do sistema pra usar shell-script*/

int main(){
	/* Soma Simples */
	int a =0, b=1,c = 2,d=3;
	a = b + c + d;
	printf("%d\n", a);

	int e = 3;
	float f = 4.5;
	double g = 5.24;
	double sum;

	sum = e + f + g;
	printf("Resultado da soma é:%f\n", sum);

	/*Exemplo da stdlib usando shell*/	
	system ("echo FIM!");
	return 0;
}
