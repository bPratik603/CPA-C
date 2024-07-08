#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int (*p)[8] = 0; 
    int i; 

    for(i = 0; i < 8; ++i)
        printf("(*p + %d = %p)\n", i, (*p + i)); 

    return (0); 
}

