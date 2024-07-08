#define _CRT_RAND_S 
#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    unsigned int num; 
    unsigned int N;
    unsigned int i; 

    printf("Enter how many random numbers must be generated:"); 
    scanf("%u", &N); 

    for(i = 0; i < N; ++i)
    {
        rand_s(&num); 
        printf("num = %u\n", num); 
    }

    return (0); 
}