#include <stdio.h> 
#include <stdlib.h> 

void mult_arr_using_dds(void); 
void mult_arr_using_dyn_mem_functions(void); 

int main(void)
{
    mult_arr_using_dds(); 
    mult_arr_using_dyn_mem_functions(); 
    exit(EXIT_SUCCESS); 
}

void mult_arr_using_dds(void)
{
    int a[5][3]; // While using DDS, total number of dimensions 
                 // and total magnitude of each dimensions must be 
                 // known at the time of writing the source code 
    int i, j; 
    
    puts("Multi Dimensional array using DDS - START"); 
    // a[i][j] = i + j for all elements of array 
    for(i = 0; i < 5; ++i)
        for(j = 0; j < 3; ++j)
            a[i][j] = i + j; 

    // Show all elements in array 
    for(i = 0; i < 5; ++i)
        for(j = 0; j < 3; ++j)
            printf("a[%d][%d]:%d\n", i, j, a[i][j]); 

    puts("Multi Dimensional array using DDS - END");
}

void mult_arr_using_dyn_mem_functions(void)
{
    int* p = NULL; 
    int i, j; 

    p = (int*)malloc(5 * 3 * sizeof(int)); 
    if(p == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    // set all elements to sum of their indices 
    for(i = 0; i < 5; ++i)
        for(j = 0; j < 3; ++j)
            *(p + i * 3 + j) = i + j; 

    // show all elements of array 
    for(i = 0; i < 5; ++i)
        for(j = 0; j < 3; ++j)
            printf("*(p + %d * 3 + %d) == %d\n", i, j, *(p + i * 3 + j)); 

    free(p); 
    p = NULL; 
}