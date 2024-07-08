#include <stdio.h> 
#include <stdlib.h> 

int main(void) 
{
    puts("start"); 

    #ifdef X 
    puts("Symbol X is defined from command line"); 
    #endif 

    #ifdef Y 
    puts("Symbol Y is defined from command line"); 
    #endif 

    #ifdef Z 
    puts("Symbol Z is defined from command line"); 
    #endif

    puts("end"); 

    return (0);  
}
