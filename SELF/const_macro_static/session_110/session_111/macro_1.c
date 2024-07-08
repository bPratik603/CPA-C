#include <stdio.h> 
#include <stdlib.h> 

#define ADD(a, b)   ((a) + (b)) /* ADD is a macro */

#define ARR_SIZE    5   /* ARR_SIZE is a symbolic constant */

int main(void)
{
    int rs; 
    int m  = 10, n = 25; 

    rs = ADD(5, 7); 
    printf("rs = %d\n", rs); 
    rs = ADD(4 + 5, 7 - 9); 
    printf("rs = %d\n", rs); 
    rs = ADD(m + 1, n * 2); 
    printf("rs = %d\n", rs); 

    return (0); 
}

/* 
    ADD(5, 7)

EXPANDING ADD TO ITS DEFINITION 

    ((a) + (b))

REPLACING PARAMTERS OF MACRO BY THEIR ARGUMENT 
a will be textually replaced by 5 
b will be textually replaced by 7 

rs = ((5) + (7)); 
rs == 12 

rs = ADD(4 + 5, 7 - 9)

STEP 1 : Replacement of macro by its definition 

rs = ((a) + (b))

STEP 2: Replacement of parameters of macro by their argument 

rs = ((4 + 5) + (7 - 9))
rs == 7 

rs = ADD(m + 1, n * 2); 

STEP 1: ((a) + (b))
STEP 2: ((m+1) + (n*2))

*/