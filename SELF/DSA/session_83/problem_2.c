/* 
    Consider array A of N integers. N > 0 
    Create two dynamic arrays A1, A2 and A3
    such that A1 contains all even numbers in A 
    and A2 contains all odd numbers in A 
    and A3 contains all prime numbers in A. 
*/
/* 
    Consider array A of N integers. N > 0 
    Create three dynamic arrays A1, A2 and A3
    such that A1 contains all even numbers in A 
    and A2 contains all odd numbers in A 
    and A3 contains all prime numbers in A. 
*/

#include <stdio.h> 
#include <stdlib.h> 

#define TRUE    1 
#define FALSE   0 
#define N_INPUT 15 

void show_array(int* a, int N, const char* msg); 
void get_subarrays(int* a_input, int N_input, 
                    int** ppa_even, int* pN_even, 
                    int** ppa_odd, int* pN_odd, 
                    int** ppa_prime, int* pN_prime); 

int main(void)
{
    int* a_even = NULL, *a_odd = NULL, *a_prime = NULL; 
    int N_even = 0, N_odd = 0, N_prime = 0; 
    int a_input[15] = {   
                    -1, 8, 99, 87, 10, 
                    20, 30, 5, 15, 17, 
                    25, 35, -11, 2, 520         
                }; 

    get_subarrays(a_input, N_INPUT, 
                    &a_even, &N_even, 
                    &a_odd, &N_odd, 
                    &a_prime, &N_prime); 
    
    show_array(a_input, N_INPUT, "Input array"); 
    show_array(a_even, N_even, "Even numbers array"); 
    show_array(a_odd, N_odd, "Odd number array"); 
    show_array(a_prime, N_prime, "Prime number array"); 

    free(a_even); 
    a_even = NULL; 

    free(a_odd); 
    a_odd = NULL; 

    free(a_prime); 
    a_prime = NULL; 

    return (EXIT_SUCCESS); 
}   

void get_subarrays(int* a_input, int N_input, 
                    int** ppa_even, int* pN_even, 
                    int** ppa_odd, int* pN_odd, 
                    int** ppa_prime, int* pN_prime)
{
    int* a_even = NULL; 
    int* a_odd = NULL; 
    int* a_prime = NULL; 
    int N_even = 0; 
    int N_odd = 0; 
    int N_prime = 0; 
    int k, k_even, k_odd, k_prime; 

    for(k = 0; k < N_input; ++k)
    {
        if(a_input[k] % 2 ==  0)
            ++N_even; 
        else if(a_input[k] % 2 == 1)
            ++N_odd; 
        
        if(is_prime(a_input[k]) == TRUE)
            ++N_prime; 
    }
    
    a_even = (int*)malloc(N_even * sizeof(int)); 
    if(a_even == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    a_odd = (int*)malloc(N_odd * sizeof(int)); 
    if(a_odd == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    a_prime = (int*)malloc(N_prime * sizeof(int)); 
    if(a_prime == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    k_even = 0; 
    k_odd = 0; 
    k_prime = 0; 

    for(k = 0; k < N_input; ++k)
    {
        if(a_input[k] % 2 == 0)
        {
            a_even[k_even] = a_input[k]; 
            ++k_even; 
        }
        else if(a_input[k] % 2 == 1)
        {
            a_odd[k_odd] = a_input[k]; 
            ++k_odd; 
        }
        
        if(is_prime(a_input[k]) == TRUE)
        {
            a_prime[k_prime] = a_input[k]; 
            ++k_prime; 
        }
    } 
    
    *ppa_even = a_even; 
    *pN_even = N_even; 

    *ppa_odd = a_odd; 
    *pN_odd = N_odd; 

    *ppa_prime = a_prime; 
    *pN_prime = N_prime; 
}

void show_array(int* a, int N, const char* msg)
{
    int k; 

    if(msg)
        puts(msg); 

    for(k = 0; k < N; ++k)
        printf("a[%d]:%d\n", k, a[k]); 
}

int is_prime(int N)
{
    int k; 

    if(N <= 1)
        return (FALSE); 

    if(N == 2)
        return (TRUE); 

    for(k = 2; k < N/2; ++k)
        if(N % k == 0)
            return (FALSE); 
        
    return (TRUE);         
}