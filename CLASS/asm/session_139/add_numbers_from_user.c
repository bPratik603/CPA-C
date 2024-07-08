#include <stdio.h> 
#include <stdlib.h> 

int num1; 
int num2; 
int summation;

int main(void){
	printf("Enter num1:"); 
	scanf("%d", &num1); 

	printf("Enter num2:"); 
	scanf("%d", &num2); 

	summation = num1 + num2; 
	printf("Summation = %d\n", summation); 

	exit(0); 
}
