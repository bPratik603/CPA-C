#include <stdio.h> 
#include <stdlib.h> 

int main(void){
	int* p = 0; 

	p = (int*)malloc(sizeof(int)); 
	if(p == 0){
		puts("Error in allocating memory"); 
		exit(-1); 
	}

	*p = 500; 
	printf("*p = %d\n", *p); 
	
	free(p); 
	p = 0; 

	exit(0); 
}
