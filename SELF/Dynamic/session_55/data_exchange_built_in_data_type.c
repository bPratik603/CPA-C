#include <stdio.h> 
#include <stdlib.h> 

void test_1(int n); 
void test_2(int* p); 

int main(void)
{
    int m; 
    int n; 
    test_1(100); 
    m=200; 
    test_1(m); 

    printf("Before call to test_2():n=%d\n", n); 
    test_2(&n); 
    printf("After call to test_2():n=%d\n", n); 
    
    return (0); 
}

// Caller sends integer input to callee 
// Callee receives copy of value sent by caller 
// Callee cannot modify caller's copy of integer 
void test_1(int n)
{
    printf("Received input from caller:n=%d\n", n); 
    puts("------------------------------------"); 
}

// Caller sends an address of its local integer variable 
// to callee.While sending caller does not put any specific 
// value in it. 
// Callee function acceps address of integer in a pointer variable 
// and uses that pointer to write on caller's local variable 
// Therefore, technically p is an input parameter to test_2 but 
// it acts as an output parameter to caller of test_2() 
// This technique is know as parameter as return value or 
// parameterized return value 
void test_2(int* p)
{
*p=500;
}