#include <stdio.h> 
#include <stdlib.h> 

int i; 

int main(void){
	printf("Enter i:"); 
	scanf("%d", &i); 

	do{
		printf("i = %d\n", i); 
		i = i + 1; 
	}while(i < 5); 
	puts("End of program"); 
	exit(0); 
}
