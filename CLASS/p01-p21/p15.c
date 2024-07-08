#include <stdio.h> 
#include <stdlib.h> 

void initialise_array(int** pp_arr, int N); 
void show_array(int** pp_arr, int N); 

int main(void)
{
    int** pp_arr = 0; 
    int N = 5; 
    int i; 

    pp_arr = (int**)malloc(N * sizeof(int*)); 
    if(pp_arr == 0)
    {
        puts("Error in allocating memory"); 
        exit(-1); 
    }

    for(i = 0; i < N; ++i)
    {
        pp_arr[i] = (int*)malloc(sizeof(int)); 
        if(pp_arr[i] == 0)
        {
            puts("Error in allocating memory"); 
            exit(-1); 
        }
    }

    initialise_array(pp_arr, N); 
    show_array(pp_arr, N); 

    for(i = 0; i < N; ++i)
    {
        free(pp_arr[i]); 
        pp_arr[i] = 0; 
    }

    free(pp_arr); 
    pp_arr = 0; 

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

struct teacher
{
    char name[16]; 
    int experience; 
} ; 

#include <string.h> 

int main(void)
{
    struct teacher t; 

    memset(t.name, 0, 16); 
    strncpy(t.name, "yogeshwar", strlen("yogeshwar")); 
    printf("name = %s\n", t.name); 
}