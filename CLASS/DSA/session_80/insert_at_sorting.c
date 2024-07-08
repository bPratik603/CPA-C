#include <stdio.h> 
#include <stdlib.h> 

void get_array(int** pp_arr, int* pN); 
void insert_at_sorting_position(int* p_arr, int N); 
void show_array(int* p_arr, int N, const char* msg); 

int main(void)
{
    int* p_arr = NULL; 
    int N; 

    get_array(&p_arr, &N); 
    show_array(p_arr, N, "Before insert_at_sorting_position():"); 
    insert_at_sorting_position(p_arr, N); 
    show_array(p_arr, N, "After:Insert at sorting position"); 

    free(p_arr); 
    p_arr = NULL; 

    return (0); 
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

    puts("Enter array elements such that all but last element are sorted"); 
    for(i = 0; i < N; ++i)
    {
        printf("Enter data at index %d:", i); 
        scanf("%d", p_arr + i); 
    }    

    *pp_arr = p_arr; 
    *pN = N; 
}

void  show_array(int* p_arr, int N, const char* msg)
{
    int i; 

    if(msg)
        puts(msg); 

    for(i = 0; i < N; ++i)
        printf("p_arr[%d]:%d\n", i, p_arr[i]); 
}

/* 
    Deeper analysis: 

    When the control flow comes out of the while loop: 

    (k >= 0 && p_arr[k] > tmp) == False 

    not (k >= 0 and p_arr[k] > tmp ) == True

    [De Morgans law: not (p and q) == not p OR not q] 

    [not (k >= 0) or not (p_arr[k] > tmp)] == True 

    not (p_arr[k] > tmp) == p_arr[k] <= tmp

    not (k >= 0) == k < 0 

    k == -1

*/