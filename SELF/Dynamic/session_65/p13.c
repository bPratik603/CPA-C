#include <stdio.h> 
#include <stdlib.h> 

void initialise_array(int** pp_arr, int N); 
void show_array(int** pp_arr, int N); 

int main(void)
{
    int* a[5] = {0, 0, 0, 0, 0}; 
    int i; 
     
    for(i = 0; i < 5; ++i)
    {
        a[i] = (int*)malloc(sizeof(int)); 
        if(a[i] == 0)
        {
            puts("malloc():error in allocating memory"); 
            exit(-1); 
        }
    }
    
    initialise_array(a, 5); 
    show_array(a, 5); 

    for(i = 0; i < 5; ++i)
    {
        free(a[i]); 
        a[i] = 0; 
    }
    
    return (0); 
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