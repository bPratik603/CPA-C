#include <stdio.h> 
#include <stdlib.h> 

/* 
    Pre-conditions: 
        1)  String pointed by src is terminated by \0 
        2)  String pointed by dest has minimum length 
            of length(src) + 1
*/

void cpa_strcpy(char* dest, const char* src)
{
    int i; 

    i = 0; 
    while(src[i] != '\0')
    {
        dest[i] = src[i]; 
        i += 1; 
    }

    dest[i] = '\0'; 
}