/* OFFSET_OF macro */

#include <stdio.h> 
#include <stdlib.h> 

#define OFFSET_OF(type, mem)   ( (unsigned long long int)(&(((type*)0) -> mem)) )

struct A 
{
    int a;  // offset of a = 0 
    char b; // offset of b = 4 
    int c;  // offset of c = 8 
    char d; // offset of d = 12 
}; 

struct B 
{
    char a, b;  // offset of a = 0, offset of b = 1 
    int c, d;   // offset of c = 4, offset of d = 8 
};

int main(void)
{
    struct A inA; 
    struct A* ptrA = 0; 

    unsigned long long int off_c; 

    off_c = (unsigned long long int)&inA.c - (unsigned long long int)&inA; 
    printf("off_c = %llu\n", off_c); 

    printf("offset of c = %llu\n", (unsigned long long int)(&ptrA->c)); 
    /* assuming ptrA == 0, &ptrA->c evaluates to offset of c relative to struct A*/

    struct A* ptrA = 0; 

    off_c = (unsigned long long int)(&((struct A*)0)->c); 
    printf("off_c = %llu\n", off_c); 
  
    return (0); 
}

void test()
{
    int b;      /* Let x be a base address of b*/

    b;          /* eax <- M[x:x+3] */
    (short)b;   /* ax <- M[x:x+1]*/
    (char)b;    /* al <- M[x] */
    (unsigned long long int)b; 
}

/* 
    ptrA->c 

    Address in ptrA  + offset of c relative to type(ptrA)

    x + offset of c relative to struct A 

    If ptrA->c is on LHS then write on 

    x + offset of c relative to struct A 

    If ptrA->c is on RHS then read from 

    x + offset of c relative to struct A 

    &ptrA->c 

    &(ptrA->c); 

    arr[i]; 

    type(arr) == int []
    type(arr[i]) == int 
*/

//n : M[1000:1003]

//unsigned long long int x = (unsigned long long int)&n; 

//int* p = &n; // 1000

           
