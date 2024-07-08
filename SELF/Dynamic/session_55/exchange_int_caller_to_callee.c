#include <stdio.h> 
#include <stdlib.h> 

void test_1(int n);   /* In parameter */
void test_2(int* p);  /* Out parameter */
void test_3(int* p);  /* In - Out parameter */

int main(void)
{
    int m; 
    int n; 
    int k = 2000; 

    test_1(100); 
    m=200; 
    test_1(m); 

    printf("Before call to test_2():n=%d\n", n); 
    test_2(&n); 
    printf("After call to test_2():n=%d\n", n); 
    puts("------------------------------------"); 
    
    printf("Before call to test_3(), k has value 2000, k = %d\n", k); 
    test_3(&k); 
    printf("After call to test_3(), k has following value %d\n", k); 
    puts("------------------------------------"); 

    return (0); 
}

void test_1(int n)
{
    printf("Received input from caller:n=%d\n", n); 
    puts("------------------------------------"); 
}

void test_2(int* p)
{
    *p = 500; 
}

void test_3(int* p)
{
    printf("Just entered in test 3:*p=%d\n", *p); 
    *p = *p * *p;
}