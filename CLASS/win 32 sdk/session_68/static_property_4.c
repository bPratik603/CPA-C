#include <stdio.h> 
#include <stdlib.h> 

void test_function(void); 

int main(void)
{
    int i; 

    for(i = 0; i < 5; ++i)
        test_function(); 

    return (0); 
}

void test_function(void)
{
    int m = 1; 
    static int n=1; 
    int i;

    printf("START VALUE:m = %d, n = %d\n", m, n); 

    for(i=1; i<=100; ++i)
    {
        m = m + 1; 
        n = n + 1; 
    } 

    printf("END VALUE:m = %d, n = %d\n", m, n); 
}

