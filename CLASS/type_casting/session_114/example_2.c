#include <stdio.h> 
#include <stdlib.h> 

unsigned long long int x; 

/* 
    Step-wise writing in x 
    x has 8 bytes. x[1]....x[8]

    Step 1: 
    x[1] <- 0x1a 

    Step 2: 
    x[2-3] <- 0x2b3c 

    Step 3:  
    x[4-7] <- 0xa0b0c0d0 

    Step 4: 
    x[8] <- 0xdd 

*/

int main(void) 
{
    printf("1. x = %llx\n", x); 

    *(unsigned char*)&x = 0x1a; 

    printf("2. x = %llx\n", x); 

    *(unsigned short*)((char*)&x + 1) = 0x2b3c; 

    printf("3. x = %llx\n", x); 

    *(unsigned int*)((char*)&x + 3) = 0xa0b0c0d0; 

    printf("4. x = %llx\n", x); 

    *(unsigned char*)((char*)&x + 7) = 0xdd; 

    printf("5. x = %llx\n", x); 

    return (0); 

}