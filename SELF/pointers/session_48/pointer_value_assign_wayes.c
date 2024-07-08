#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int A[5] = {1000, 2000, 3000, 4000, 5000}; 
    int i; 
    int n;
    int (*p_arr)[5]; 
    int* p_int; 

    puts("way 1: Using name"); 
    for(i=0; i<5; ++i)
        printf("A[%d]=%d\n", i, A[i]); 

    puts("Way 2: Using pointer to array"); 
    p_arr = &A; 
    for(i=0; i<5; ++i)
        printf("(*p_arr)[%d]=%d\n", i, (*p_arr)[i]); 

    puts("Way 3: Pointr to array element type"); 
    p_int = &A[0]; 
    for(i=0; i<5; ++i)
        printf("*(p_int+%d)=%d\n", i, *(p_int+i)); 

    puts("Way 34 Pointr to array element type but using array name"); 
    p_int = A; 
    for(i=0; i<5; ++i)
        printf("*(p_int+%d)=%d\n", i, *(p_int+i)); 

    return (0); 
}

/* 
    Pointer to array. 

    int A[5]; 
    int (*p)[5]; 
    p = &A; 

    pointer to element type     
    int* p = &A[0]; 

    RHS 
    = A; 

Array Name VALUE_WISE TYPE_WISE 
&Arra_Name[0]

type(A) = type(&A[0]) .. by def. of C type system 

type(&A[0]) = Element Type* 

Element Type* p = A; 

int A[5]; 

int* p = A; /* because A == &A[0] 

    = A; 

    int n; 
    int A[5]; 

int* p1 = &n; 
int* p2 = A; 

VALUE(&A)==VALUE(A)=VALUE(&A[0])

TYPE(A) == TYPE(&A[0]) = ELEMENT TYPE*

TYPE(&A) = T(*)[N]

T* p1= &A[0]; 
T* p2= A; 

T(*p3)[N] = &A; ... // NOBODY USES THIS 
                    // BECAUSE NOBODY KNOWS THIS! 
*/                     



