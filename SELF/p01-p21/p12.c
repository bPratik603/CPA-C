#include <stdio.h> 
#include <stdlib.h> 

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

    for(i = 0; i < 5; ++i)
    {
        *a[i] = (i+1) * 100; 
    }

    for(i = 0; i < 5; ++i)
    {
        printf("*a[%d]=%d\n", i, *a[i]); 
    }

    for(i = 0; i < 5; ++i)
    {
        free(a[i]); 
        a[i] = 0; 
    }
    
    return (0); 
}

