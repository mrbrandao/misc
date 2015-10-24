#include <stdio.h>
#include <string.h>

int main()
{
	char str[13] = "Igor Brandao";
	char * teste;
	
	teste = strtok(str, " ");
	//printf("%s\n", teste);
	while( teste != NULL)
	{
		printf("%s\n", teste);
		teste = strtok(NULL," ");
	}
	return(0);
}
