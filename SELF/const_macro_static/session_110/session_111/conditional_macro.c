#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int n; 

    printf("Enter n:"); 
    scanf("%d", &n); 

    /*  
        is if statement is used to draw analogy to explain
        conditional macro using #ifdef whose general syntax 
        is explained under main 
    */

    if(n > 0)
    {
        // do something 
    }

    // do something else 

    exit(0); 
}

/* 
    Preprocessor directive 1 for conditional macro 

    General Syntax: 

    #ifdef SYMBOL 
        PART OF C SOURCE CODE 

    #endif // Delimiter  

    #ifndef SYMBOL 


    #endif 

*/

/* 
1.c 
#include <stdio.h> 

2.c 
#include <stdio.h> 

3.c 
#include <stdio.h> 


stdio.h

#ifndef _STDIO_H 
#define _STDIO_H 

COMPLETE HEADER FILE 

#endif 

my_header.h 

name.h 
#ifndef _NAME_H 
#define _NAME_H 

#endif 

*/