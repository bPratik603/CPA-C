/* 
    Consider array A of N integers. N > 0 
    Create two dynamic arrays A1 and A2
    such that A1 contains all even numbers in A 
    and A2 contains all odd numbers in A 
*/

#include <stdio.h> 
#include <stdlib.h> 

void get_cloned_sub_arrays(int* a, int N, int** pp_a1, int *pN1, 
                            int** pp_a2, int* pN2); 

void show_array(int* a, int N, const char* msg); 

int main(void)
{
    int* a1 = NULL, *a2 = NULL; 
    int N1=0, N2=0;

    int a[15] = {   
                    -1, 8, 99, 87, 10, 
                    20, 30, 5, 15, 17, 
                    25, 35, -11, 2, 520         
                }; 

    get_cloned_sub_arrays(a, 15, &a1, &N1, &a2, &N2); 
    show_array(a1, N1, "Array of even numbers"); 
    show_array(a2, N2, "Array of odd numbers:"); 

    free(a1); 
    a1 = NULL; 

    free(a2); 
    a2 = NULL; 

    return (EXIT_SUCCESS); 
}

void get_cloned_sub_arrays(int* a, int N, int** pp_a1, int *pN1, 
                            int** pp_a2, int* pN2)
{
    int* a1 = NULL, *a2 = NULL; 
    int N1 = 0, N2 = 0; 
    int k, k1, k2; 

    for(k = 0; k < N; ++k)
    {
        if(a[k] % 2 == 0)
            ++N1; 
        else 
            ++N2; 
    }

    a1 = (int*)malloc(N1 * sizeof(int)); 
    if(a1 == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    a2 = (int*)malloc(N2 * sizeof(int)); 
    if(a2 == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    k1 = 0; 
    k2 = 0; 
    for(k = 0; k < N; ++k)
    {
        if(a[k] % 2 == 0)
        {
            a1[k1] = a[k]; 
            k1++; 
        }
        else 
        {
            a2[k2] = a[k]; 
            k2++; 
        }
    }

    *pp_a1 = a1; 
    *pN1 = N1; 

    *pp_a2 = a2; 
    *pN2 = N2; 
}

void show_array(int* a, int N, const char* msg)
{
    int k; 

    if(msg)
        puts(msg); 

    for(k = 0; k < N; ++k)
        printf("a[%d]:%d\n", k, a[k]); 
}


