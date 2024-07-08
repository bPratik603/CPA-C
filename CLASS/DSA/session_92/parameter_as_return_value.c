#include <stdio.h> 
#include <stdlib.h> 
/////////////////////////////////////////
int f1()
{

    return (0); 
}
/////////////////////////////////////////
void caller_of_f1()
{
    int n; 

    n = f1(); 
}
//////////////////////////////////////
void f2(int* p_int)
{
    *p_int = 0; 
}

void caller_of_f2()
{
    int n; 

    f2(&n); 
}
/////////////////////////////////////////
int *f3(void)
{
    int* p = 0; 

    p = (int*)malloc(sizeof(int)); 
    if(p == 0)
    {
        puts("error"); 
        exit(-1); 
    }

    return (p); 
}
/////////////////////////////////////////
void caller_of_f3(void)
{
    int* p_ret = NULL; 

    p_ret = f3(); 
    *p_ret = 100; 
    printf("*p_ret = %d\n", *p_ret); 

    free(p_ret); 
    p_ret = NULL; 
}
/////////////////////////////////////////
void f4(int** pp_int)
{
    int* ptr = NULL; 
    ptr = (int*)malloc(sizeof(int)); 
    if(ptr == NULL)
    {
        puts("error"); 
        exit(-1); 
    }

    /* 
        type(pp_int) == int** ... given by programmer 
        type(*pp_int) == int*
        type(ptr) == int* 

        *pp_int = ptr; 
    */

   *pp_int = ptr; 
}
/////////////////////////////////////////
void caller_of_f4(void)
{
    int* p_ret = NULL; 

    f4(&p_ret); 
    *p_ret = 100; 
    printf("*p_ret = %d\n", *p_ret); 

    free(p_ret); 
    p_ret = NULL; 
}
//////////////////////////////////////////////////////
int** f5(int* pN)
{
    // int* a[5]; 
    int** pp_int = NULL; 
    int i; 
    /* 
        int *a[5]; 

        type(a) == type(&a[0]) 
        type(a[0]) == int* 
        type(&a[0]) == int**

    */

    pp_int = (int**)malloc(5 * sizeof(int*)); 
    if(pp_int == NULL)
    {
        puts("Error"); 
        exit(-1); 
    }

    for(i = 0; i < 5; ++i)
    {
        pp_int[i] = (int*)malloc(sizeof(int)); 
        if(pp_int[i] == NULL)
        {
            puts("error"); 
            exit(-1); 
        }
    }

    /* 
        type(pp_int) == int** 
        type(pp_int[i]) == int* 
    */
   *pN = 5; 
    return (pp_int); 
}
/////////////////////////////////////////
/* 
int** f()
{
    int n1, n2, n3, n4, n5; 
    int* a[5]; 

    a[0] = &n1; 
    a[1] = &n2;
    a[2] = &n3;
    a[3] = &n4;
    a[4] = &n5;

    return (a)
}
*/
/////////////////////////////////////////
void caller_of_f5(void)
{
    int** p_array_of_pointer_to_int = NULL; 
    int N = -1;     
    int i; 

    p_array_of_pointer_to_int = f5(&N); 
    for(i = 0; i < N; ++i)
        *p_array_of_pointer_to_int[i] = (i+1) * 100; 

    for(i = 0; i < N; ++i)
        printf("A[%d]:%d\n", i, *p_array_of_pointer_to_int[i]); 

    for(i = 0; i < N; ++i)
        free(p_array_of_pointer_to_int[i]); 

    free(p_array_of_pointer_to_int); 
    p_array_of_pointer_to_int = NULL; 
}
/////////////////////////////////////////
void f6(int*** ppp_int, int* pN)
{
    int** pp_int = NULL; 
    int i; 

    pp_int = (int**)malloc(5 * sizeof(int*)); 
    if(pp_int == NULL)
    {
        puts("Error"); 
        exit(-1); 
    }

    for(i = 0; i < 5; ++i)
    {
        pp_int[i] = (int*)malloc(sizeof(int)); 
        if(pp_int[i] == NULL)
        {
            puts("error"); 
            exit(-1); 
        }
    }

   *pN = 5; 
   *ppp_int = pp_int; 
}
/////////////////////////////////////////
void caller_of_f6(void)
{
    int** pp_int_of_caller = NULL; 
    int N = -1; 
    int i; 

    f6(&pp_int_of_caller, &N); 

    for(i = 0; i < N; ++i)
        *pp_int_of_caller[i] = (i+1) * 100; 

    for(i = 0; i < N; ++i)
        printf("*pp_int_of_caller[%d]:%d\n", i, 
                *pp_int_of_caller[i]); 

    for(i = 0; i < N; ++i)
        free(pp_int_of_caller[i]); 

    free(pp_int_of_caller); 
    pp_int_of_caller = NULL; 
}
/////////////////////////////////////////////////////////
int main(void)
{
    caller_of_f1(); 
    caller_of_f2(); 
    caller_of_f3(); 
    caller_of_f4(); 
    caller_of_f5(); 
    caller_of_f6(); 

    return (0); 
}
//////////////////////////////////////////////////////////