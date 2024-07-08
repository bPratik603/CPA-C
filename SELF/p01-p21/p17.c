#include <stdio.h> 
#include <stdlib.h> 

void allocate_array_of_pointers_to_integer(int*** ppp_arr, int* pN); 
void initialise_array(int** pp_arr, int N); 
void show_array(int** pp_arr, int N); 
void release_array(int** pp_arr, int N); 
void release_array_2(int*** ppp_arr, int N); 

int main(void)
{
    int** pp_arr = 0; 
    int N = -1; 

    allocate_array_of_pointers_to_integer(&pp_arr, &N); 
    initialise_array(pp_arr, N); 
    show_array(pp_arr, N); 
    /* 
        release_array(pp_arr, N); 
        pp_arr = 0; 
    */ 
    printf("main():BEFORE call to release_array_2():pp_arr=%llu\n", 
            (unsigned long long int)pp_arr); 

    release_array_2(&pp_arr, N); 
    
    printf("main():AFTER call to release_array_2():pp_arr=%llu\n", 
             (unsigned long long int)pp_arr); 

    return (0); 
}

void allocate_array_of_pointers_to_integer(int*** ppp_arr, int* pN)
{
    int N = -1; 
    int** pp_arr = 0; 
    int i; 

    printf("Enter length of array:"); 
    scanf("%d", &N); 

    if(N <= 0)
    {
        puts("Bad value for array length"); 
        exit(EXIT_FAILURE); 
    }

    pp_arr = (int**)malloc(N * sizeof(int*)); 
    if(pp_arr == 0)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < N; ++i)
    {
        pp_arr[i] = (int*)malloc(sizeof(int)); 
        if(pp_arr[i] == 0)
        {
            puts("Error in allocating memory"); 
            exit(EXIT_FAILURE); 
        }
    }

    *ppp_arr = pp_arr; 
    *pN = N; 
}

void initialise_array(int** pp_arr, int N)
{
    int i; 

    for(i = 0; i < N; ++i)
        *pp_arr[i] = (i+1) * 100; 
}

void show_array(int** pp_arr, int N)
{
    int i; 

    for(i = 0; i < N; ++i)
        printf("*pp_arr[%d]:%d\n", i, *pp_arr[i]); 
}

void release_array(int** pp_arr, int N)
{
    int i; 

    for(i = 0; i < N; ++i)
    {
        free(pp_arr[i]); 
        pp_arr[i] = 0; 
    }

    free(pp_arr); 
    pp_arr = 0; 
}

void release_array_2(int*** ppp_arr, int N)
{
    int** pp_arr = 0; 
    int i; 

    pp_arr = *ppp_arr; 

    for(i = 0; i < N; ++i)
    {
        free(pp_arr[i]); 
        pp_arr[i] = 0; 
    }

    free(pp_arr); 
    pp_arr = 0; 

    *ppp_arr = 0; 
}
