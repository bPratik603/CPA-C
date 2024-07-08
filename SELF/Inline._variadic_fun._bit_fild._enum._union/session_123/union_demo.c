#include <stdio.h> 
#include <stdlib.h> 

struct A {  
    int a; 
    char b;
    float c; 
}; 

struct B{
    double d1; 
    short s[4]; 
    int n1, n2; 
}; 

struct C {
    float f_arr[2]; 

}; 

union X{
    struct A inA; // 12  
    struct B inB; // 24 
    struct C inC; // 8 
    char c; // 1 
    int n; // 4 
    double d; // 8 
}; 

/* When an instance of union X will created then a memory 
    = max(sizeof(inA), sizeof(inB), sizeof(inC))
    will be allocated

    And at any given time, memory of instance of X can be used 
    as inA, inB, or inC. 
*/

int main(void){
    printf("sizeof(inC)=%llu, sizeof(union X)=%llu\n", sizeof(struct C), sizeof(union X)); 
    union X inX; 

    inX.c; 
    inX.n; 
    inX.d; 

    inX.inA.a; 
    inX.inA.b; 
    inX.inA.c; 

    inX.inB.d1; 
    inX.inB.n1; 
    inX.inB.n2; 
    inX.inB.s; 

    inX.inC.f_arr[0]; 
    inX.inC.f_arr[1]; 

    return (0); 
}

void f(void)
{
    void* p = malloc(24); 

    ((struct A*)p)->a; // inX.inA.a 
    ((struct A*)p)->b; // inX.inA.b
    ((struct A*)p)->c;  // inX.inA.c

    ((struct B*)p)->d1; // inX.inB.d1 
    ((struct B*)p)->n1; // inX.inB.n1
    ((struct B*)p)->n2; // inX.inB.n2
    ((struct B*)p)->s; // inX.inB.s

    ((struct C*)p)->f_arr[0]; // inX.inC.f_arr[2]; 
    ((struct C*)p)->f_arr[1]; // inX.inC.f_arr[1]

    *(char*)p;  // inX.c
    *(int*)p;   // inX.n
    *(double*)p; // inX.d 

    free(p); 
    p = NULL; 

}