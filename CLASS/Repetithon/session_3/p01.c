#include <stdio.h> 
#include <stdlib.h> 

void test_1(void); 
void test_2(void); 
void test_3(void); 

int main(void) 
{
    test_1(); 
    test_2(); 
    test_3(); 
    return (0); 
}

void test_1(void)
{
    int n = 10; 
    int* p = NULL; 

    printf("&n = %p\n", &n); 

    printf("p before assignment:p = %p\n", p); // 0 
    p = &n; 
    printf("p after assignment: p = %p\n", p); // &n 

    printf("BEFORE ASSIGNMENT: *p = %d\n", *p); // 10  
    *p = 20; 
    printf("AFTER ASSIGNMENT: *p = %d\n", *p); // 20 
}

void test_2(void)
{
    int m = 100; 
    int n = 500; 
    int* p = 0; 

    printf("&m = %p\n", &m); 
    printf("&n = %p\n", &n); 

    printf("p before p = &m: p = %p\n", p); 
    p = &m; 
    printf("p after p = &m: p = %p\n", p); 

    printf("Before *p = -100: m = %d\n", m); 
    *p = -100; 
    printf("After *p = -100: m = %d\n", m); 

    p = &n; 
    printf("After p = &n: p = %p\n", p); 

    printf("Before *p = -500: n = %d\n", n); 
    *p = -500; 
    printf("After *p = -500: n = %d\n", n);
}

void test_3(void)
{
    int m = 100; 
    int n = 500; 
    int* p = 0; 
    int** pp = 0; 

    puts("test_3():"); 
    printf("&m = %p\n", &m); 
    printf("&n = %p\n", &n); 
    printf("Address of (p) = %p\n", &p); 

    printf("Before pp = &p: pp = %p\n", pp); 
    pp = &p; 
    printf("After pp = &p: pp = %p\n", pp); 

    printf("Before:*pp = &m:p = %p\n", p); 
    *pp = &m; 
    printf("After:*pp = &m:p = %p\n", p);

    printf("Before **pp = -100:m = %d\n", m); 
    **pp = -100; 
    printf("Before **pp = -100:m = %d\n", m); 

    printf("Before *pp = &n:p = %p\n", p); 
    *pp = &n; 
    printf("After *pp = &n: p = %p\n", p); 
    
    printf("Before **pp = -100:n = %d\n", n);
    **pp = -500; 
    printf("After **pp = -100:n = %d\n", n);
}

/* 
    type wise analysis of test_3() 

    type(m) == int  ... given by programmer 
    type(n) == int  ... given by programmer 
    type(p) == int* ... given by programmer 
    type(pp) == int** ... given by programmer 

    type(*pp) = int* ... derived by logic 
    type(**pp) = int ... derived by logic 
    type(*p) = int ... derived by logic 

    int** pp; 

    pp -> int** 
    *pp -> int* 
    **pp -> int 

    int** pp; 

    int* p1; 
    int* p2; 
    int* p3; 

    pp = &p1; 
    pp = &p2; 
    pp = &p3;

    int m, n, k; 

    pp = &p1; 
    *pp = &m; 

    pp = &p2; 
    *pp = &n; 

    pp = &p3; 
    *pp = &k; 

*/