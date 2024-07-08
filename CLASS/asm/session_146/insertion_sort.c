#include <stdio.h> 
#include <stdlib.h> 

int arr[8] = {100, 50, 3, 10, 200, 150, 75, 1}; 

int main(void){
	int i, j; 
	int key; 

	puts("Before sort:"); 
	for(i = 0; i < 8; ++i)
		printf("arr[%d]=%d\n", i, arr[i]); 
	
	for(j = 1; j < 8; ++j){
		key = arr[j]; 
		i = j - 1; 
		while(i > -1 && arr[i] > key){
			arr[i+1] = arr[i]; 
			i = i - 1; 
		}
		arr[i+1] = key; 
	}

	puts("After sort:"); 
	for(i = 0; i < 8; ++i) 
		printf("arr[%d]=%d\n", i, arr[i]); 

	exit(0); 
}
