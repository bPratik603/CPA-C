#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int* p = NULL; 

    p = (int*)malloc(sizeof(int)); 
    *p = 500; 
    printf("*p = %d\n", *p);  
    free(p); 
    printf("*p = %d\n", *p); 
    puts("END"); 
    return (0); 
}

