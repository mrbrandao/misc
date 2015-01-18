#include <stdio.h>
#include <stdlib.h>

int array[10] = {1,2,3,4,5,6,7,8,9,10};
int i;
int sum = 0;

int main(){

	for (i =1; i <= 10; i++){
	
	sum += array[i];
	printf("%d\n", sum);
	system ("sleep 1");
	 
}
	return 0;
}
