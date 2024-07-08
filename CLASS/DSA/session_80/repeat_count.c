#include <stdio.h> 
#include <stdlib.h> 

void get_array(int** pp_arr, int* pN); 
void print_unqiue_elements_with_repeat_count(int* p_arr, int N); 

int main(void)
{
    int* p_arr = NULL; 
    int N = -1; 

    get_array(&p_arr, &N); 
    print_unqiue_elements_with_repeat_count(p_arr, N); 
    free(p_arr); 
    p_arr = NULL; 

    return (EXIT_SUCCESS); 
}

void print_unqiue_elements_with_repeat_count(int* p_arr, int N)
{
    int i;  /* Index variable to go through the array */
    int k;  /* Index to scan sub-arrays, 0 to i-1 and i to N-1 */
    int repeat_count; /* To keep number of occurrences encountered 
                        so far of current array element i.e. of p_arr[i]*/

    for(i = 0; i < N; ++i)
    {
        for(k = 0; k < i; ++k)
            if(p_arr[k] == p_arr[i])
                break; 
        
        if(k < i) 
            continue; 
        
        repeat_count = 0; 
        for(k = i; k < N; ++k)
            if(p_arr[k] == p_arr[i])
                ++repeat_count; 

        printf("Unique element:%d occurred %d times\n", p_arr[i], repeat_count);    
    }
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

