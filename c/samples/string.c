#include <stdio.h>
#include <string.h>

int main(){
	
	char nome[] = "Isca";
	char snome[]= "Zero";

	if (strncmp(nome,  "Isca", 4) == 0) {

	printf("Meu nome é: %s %s\n", nome, snome);
	}
	else {
	printf("Nao e o Isca");
	}
	return 0;

}
