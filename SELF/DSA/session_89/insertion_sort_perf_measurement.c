/* 
    Declare unsinged int N; 
    Take N input from end user. 
    VALIDATE: N>=2 
    Allocate array of N elements. 
    Populate the array with random data. (rand_s() function)
    Sort array using insersion sort 
    and show array before and after sort. 
*/ 

#define _CRT_RAND_S 

#include <stdio.h> 
#include <stdlib.h> 

void get_array(unsigned int** pp_arr, unsigned int* puN); 
void insert_at_sorting_position(unsigned int* p_arr, unsigned int N); 
void insertion_sort(unsigned int* p_arr, unsigned int N); 
void show_array(unsigned int* p_arr, unsigned int N, const char* msg);

int main(void)
{
    unsigned int* p_arr = NULL; 
    unsigned int N = 0; 
    unsigned int i; 
    unsigned int t_start, t_end, t_delta; 

    get_array(&p_arr, &N); 
    t_start = time(0); 
    insertion_sort(p_arr, N); 
    t_end = time(0); 
    t_delta = t_end - t_start; 
    printf("seconds:%u\n", t_delta); 

    for(i = 0; i < N-1; ++i)
        if(p_arr[i] > p_arr[i+1])
            puts("Sorting failure"); 
    if(i == N-1)
        puts("Sort success"); 

    free(p_arr); 
    p_arr = NULL; 

    return (0); 
}

void get_array(unsigned int** pp_arr, unsigned int* puN)
{
    unsigned int* p_arr = NULL; 
    unsigned int N; 
    unsigned int i; 

    printf("Enter size of array:"); 
    scanf("%d", &N); 

    if(N < 2)
    {
        puts("Enter valid array size"); 
        exit(EXIT_FAILURE); 
    }

    p_arr = (unsigned int*)malloc(N * sizeof(unsigned)); 
    if(p_arr == NULL)
    {
        puts("error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    srand(time(0)); 
    for(i = 0; i < N; ++i)
        rand_s(p_arr + i); 

    *pp_arr = p_arr; 
    *puN = N; 
}

void insert_at_sorting_position(unsigned int* p_arr, unsigned int N)
{
    long long i; 
    int key; 

    key = p_arr[N-1]; 

    i = N - 2; 
    while(i > -1 && p_arr[i] > key)
    {
        p_arr[i+1] = p_arr[i]; 
        i = i - 1; 
    }

    p_arr[i+1] = key; 
}

void insertion_sort(unsigned int* p_arr, unsigned int N)
{
    unsigned int size; 

    for(size = 2; size <= N; ++size)
        insert_at_sorting_position(p_arr, size); 
}

void show_array(unsigned int* p_arr, unsigned int N, const char* msg)
{
    unsigned int i; 

    if(msg)
        puts(msg); 

    for(i = 0; i < N; ++i)
        printf("A[%u]:%u\n", i, p_arr[i]); 
}