#include <stdio.h> 
#include <stdlib.h> 

struct A 
{
    int a; 
    char b; 
    float f; 
}; 

int main(void)
{
    struct A* pA;   /* Note that pA does not contain any valid address 
                        right now, therefore, 
                        (*pA).a will be a segmentation fault 
                        pA->a will also be a segmentation fault 
                    */
    struct A inA; 

    pA = &inA;  
    /* After this assignment statement, pA is ready for dereference */

    /* While writing, dereference + dot operator */


    (*pA).a = 500;  /* pA->a = 500;     */
    (*pA).b = 'A';  /* pA->b = 'A';     */
    (*pA).f = 3.14; /* pA->f = 3.14;    */

    printf("pA->a=%d, pA->b=%c, pA->f=%.2f\n", pA->a, pA->b, pA->f); 

    return (0); 
}