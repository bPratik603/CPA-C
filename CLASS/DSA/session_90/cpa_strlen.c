#include <stdio.h> 
#include <stdlib.h> 

int cpa_strlen(const char* str)
{
    int i; 
    int len; 

    len = 0; 
    i = 0; 
    while(str[i] != '\0')
    {
        len += 1; 
        i += 1; 
    }

    return (len); 
}