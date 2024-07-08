#include <stdio.h> 
#include <stdlib.h> 

void get_array(int** pp_arr, int* pN); 
void insert_at_sorting_position(int* p_arr, int N); 
void show_array(int* p_arr, int N, const char* msg); 
void insertion_sort(int* pa, int N); 

int main(void)
{
    int* p_arr = NULL; 
    int N; 

    get_array(&p_arr, &N); 
    show_array(p_arr, N, "Before sort():"); 
    insertion_sort(p_arr, N); 
    show_array(p_arr, N, "After sort():"); 

    free(p_arr); 
    p_arr = NULL; 

    return (0); 
}

void insertion_sort(int* pa, int N)
{
    int size; 

    for(size = 2; size <= N; ++size)
        insert_at_sorting_position(pa, size); 
}

void insert_at_sorting_position(int* p_arr, int N)
{
    int tmp;    /* To store p_arr[N-1] */
    int k;      /* Index variable to iterate from 
                    N-1 to 0 */

    tmp = p_arr[N-1]; 
    
    k = N-2; 
    
    while(k >= 0 && p_arr[k] > tmp)
    {
        p_arr[k+1] = p_arr[k]; 
        k = k - 1; 
    }

    p_arr[k+1] = tmp; 
}

void get_array(int** pp_arr, int* pN)
{
    int* p_arr = NULL; 
    int N; 
    int i; 

    printf("Enter size of array:"); 
    scanf("%d", &N);

    if(N <= 0)
    {
        puts("Bad size"); 
        exit(EXIT_FAILURE); 
    } 

    p_arr = (int*)malloc(N * sizeof(int)); 
    if(p_arr == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < N; ++i)
    {
        printf("Enter data at index %d:", i); 
        scanf("%d", p_arr + i); 
    }    

    *pp_arr = p_arr; 
    *pN = N; 
}

void show_array(int* p_arr, int N, const char* msg)
{
    int i; 

    if(msg)
        puts(msg); 

    for(i = 0; i < N; ++i)
        printf("p_arr[%d]:%d\n", i, p_arr[i]); 
}