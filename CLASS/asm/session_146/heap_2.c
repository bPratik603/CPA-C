#include <stdio.h> 
#include <stdlib.h> 

int main(void){
	int* p = NULL; 
	int N; 
	int i; 

	printf("Enter size of array:"); 
	scanf("%d", &N); 

	if(N <= 0){
		puts("Bad size for array"); 
		exit(-1); 
	}

	p = (int*)malloc(N * sizeof(int)); 
	if(p == NULL){
		puts("Error in allocating memory"); 
		exit(-1); 
	}

	for(i = 0; i < N; ++i) 
		*(p + i) = (i + 1) * 100; 

	for(i = 0; i < N; ++i) 
		printf("*(p + %d) = %d\n", i, *(p + i)); 

	free(p); 
	p = NULL; 

	exit(0); 
}
