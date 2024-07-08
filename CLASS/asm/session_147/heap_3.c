#include <stdio.h> 
#include <stdlib.h> 

struct A{
	int m; 
	char c; 
	int n; 
}; 


int main(void){
	struct A* pA = NULL; 
	
	pA = (struct A*)malloc(sizeof(struct A)); 
	if(pA == NULL){
		puts("Error in allocating memory"); 
		exit(-1); 
	}

	pA->m = 100; 
	pA->c = 'A'; 
	pA->n = 200; 

	printf("pA->m=%d, pA->c=%c, pA->n=%d\n", 
			pA->m, pA->c, pA->n); 

	free(pA); 
	pA = NULL; 

	exit(0); 
}
