#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define CAP 50 

struct sum_of_array{
	int* p_arr; 
	int N; 
	int sum; 
}; 

int main(void){
	struct sum_of_array* psa = NULL; 
	int i; 

	psa = (struct sum_of_array*)malloc(sizeof(struct sum_of_array)); 
	if(psa == NULL){
		puts("Error in allocating memory"); 
		exit(-1); 
	}

	printf("Enter sizeof array:"); 
	scanf("%d", &psa->N); 

	if(psa->N <= 0){
		puts("Bad size for array"); 
		exit(-1); 
	}

	psa->p_arr = (int*)calloc(psa->N, sizeof(int)); 
	if(psa->p_arr == NULL){
		puts("Error in allocating memory for array"); 
		exit(-1); 
	}

	srand(time(0));
	for(i = 0; i < psa->N; ++i) 
		psa->p_arr[i] = rand() % CAP; 

	psa->sum = 0; 
	for(i = 0; i < psa->N; ++i) 
		psa->sum = psa->sum + psa->p_arr[i]; 

	for(i = 0; i < psa->N; ++i) 
		printf("psa->p_arr[%d]:%d\n", i, psa->p_arr[i]); 

	printf("Sum = %d\n", psa->sum); 
	
	free(psa->p_arr); 
	free(psa); 
	psa = NULL; 

	exit(0); 
}
