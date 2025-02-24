#include <stdio.h> 
#include <stdlib.h> 

long long sum_r(int* a, long long k); 

int main(void)
{
    int a[10] = {   
                    10, 20, 30, 40, 50, 
                    60, 70, 80, 90, 100
                }; 

    int N = 10; 
    long long S = sum_r(a, N-1); 

    printf("S = %lld\n", S); 

    return (EXIT_SUCCESS); 
}

long long sum_r(int* a, long long k)
{
    if(k < 0)
        return (0); 
    else
        return a[k] + sum_r(a, k-1); 
}