/* 
    Write a program to concat two given input strings! 
*/

#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    char* msg1 = "Hello"; 
    char* msg2 = "CPA World!"; 
    char* dest = NULL; 
    int i; 
    int N1; 
    int N2; 
    int N; 

    i = 0; 
    N1 = 0; 
    while(msg1[i] != '\0')
    {
        ++N1; 
        ++i; 
    }

    i = 0; 
    N2 = 0; 
    while(msg2[i] != '\0')
    {
        ++N2; 
        ++i; 
    }

    dest = (char*)malloc(N1 + N2 + 1); 
    if(dest == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    dest[N1+N2] = '\0'; 

    for(i = 0; i < N1; ++i)
        dest[i] = msg1[i]; 

    for(i = 0; i < N2; ++i)
        dest[N1+i] = msg2[i]; 

    printf("Destination String = %s\n", dest); 

    free(dest); 
    dest = NULL; 

    return (EXIT_SUCCESS); 
}

/* 
    Plan: 
    1)  Calculate the length of string 1, say N1. 
    2)  Calculate the length of string 2, say N2. 
    3)  Allocate storage for holding N1 + N2 + 1 chars. 
    4)  Copy string 1 [0...N1-1] into appropriate indices 
        of destination string. 
    5)  Copy string 2[0...N2-1] into appropriate indices of 
        destination string. 

*/