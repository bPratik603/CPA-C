#include <stdio.h> 
#include <stdlib.h> 

/* 
    goal: 
        allocate_array_of_pointers_to_integers() 
            This function will be called by main() function 
            and as a part of its execution it will 
                i)  Take size of array as input from end user 
                ii) Make sure that the size is positive integer 
                iii) Dynamically allocate array of pointers to integers 
                     whose length is 'size' 
                iv) Dynamically allocate as many integers as the length of 
                    the array and store the result of each integer in 
                    pointer in array 
                v)  Return address of array of pointer to integer   
                    and the length of array to caller. 

        Planning: 
            Return value 1) Address of array of pointer to integer 
                            will be returned by return value of function 
            Return Value 2) Size/length of array: Parameter as return value. 

            Derivation of return type of function: 

            if A is array of pointer to integer then base address of array 
            must be stored in pointer to array element type. 

            typeof(array element) = int* 
            typeof(pointer to array element) = int** 

            Return type of function = int** 

            Derivation of type of formal parameter: 
                length of array = int 
                so caller must allocate an integer and 
                share the address of integer with callee 
                Therefore type of formal parameter is int* 
*/

int** allocate_array_of_pointer_to_integer(int* pN); 
void initialise_array(int** pp_arr, int N); 
void show_array(int** pp_arr, int N); 
void release_array(int** pp_arr, int N); 
void release_array_2(int*** ppp_arr, int N); 

int main(void)
{
    int** pp_arr = 0; 
    int N = -1; 

    pp_arr = allocate_array_of_pointer_to_integer(&N); 
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

int** allocate_array_of_pointer_to_integer(int* pN)
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

    *pN = N; 
    return (pp_arr); 
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

