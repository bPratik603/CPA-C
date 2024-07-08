#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    const char* src = "This is a moderately long string!"; 
    char* dest = NULL; 
    int i; 
    int N; 
    
    /* 
        @goal: Duplicate src into dest. 
    */

    N = 0; 
    i = 0; 
    while(src[i] != '\0')
    {
        ++N; 
        ++i; 
    }

    dest = (char*)malloc(N+1); 
    if(dest == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    i = 0; 
    while(i < N)
    {
        dest[i] = src[i]; 
        ++i; 
    }

    dest[i] = '\0'; 

    printf("src = %s, dest = %s\n", src, dest); 

    free(dest); 
    dest = NULL; 

    return (EXIT_SUCCESS); 
}


/* 
    Plan: 
        1) Calculate the length of source string, say N. 
        2) Allocate memory dynamically to hold N+1 chars. 
        3) Copy src[0...N-1] to dest[0...N-1]
        4) Make dest[N] to be equal to '\0'
*/