#include <stdio.h> 
#include <stdlib.h> 

void test_1(void); 
void test_2(void);
void test_3(void); 
void swap_1(int num_1, int num_2); 
void swap_2(int* p_num1, int* p_num2); 

int main(void)
{
    test_1(); 
    test_2(); 
    test_3(); 
    
    return (0); 
}

void test_1(void)
{
    int a = 10; 
    int b = 20; 
    int tmp; 

    printf("a = %d, b = %d\n", a, b); 
    tmp = a; 
    a = b; 
    b = tmp; 
    printf("a = %d, b = %d\n", a, b); 
    puts("----end of test_1()-----"); 
}

void test_2(void)
{
    int x = 100;    /* M[3000:3003]*/
    int y = 200;    /* M[2996:2999]*/

    printf("Before calling: swap_1():x = %d, y = %d\n", x, y); 
    swap_1(x, y); 
    printf("After calling swap_1(): x = %d, y = %d\n", x, y); 
    puts("-----end of test_2()------"); 
}

void test_3(void)
{
    int u = 1000, v = 2000; 

    printf("Before call to swap_2():u = %d, v = %d\n", u, v);
    swap_2(&u, &v); 
    printf("After call to swap_2():u = %d, v = %d\n", u, v); 
    puts("----end of test_3()-------"); 
}

void swap_1(int num_1, int num_2)   /* M[2078:2081], M[2074:2077]*/
{
    int tmp; 

    tmp = num_1; 
    num_1 = num_2; 
    num_2 = tmp; 
}

void swap_2(int* p_num1, int* p_num2)
{
    int tmp; 

    tmp = *p_num1; 
    *p_num1 = *p_num2; 
    *p_num2 = tmp; 
}

/* 
    DSA 
*/ 