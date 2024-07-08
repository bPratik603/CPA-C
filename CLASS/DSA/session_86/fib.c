#include <stdio.h> 
#include <stdlib.h> 

size_t fib(size_t N); 

int main(void)
{
    puts("5th term of fibonacci sequence"); 
    printf("fib(5)=%llu\n", fib(5)); 

    puts("11th term of fibbonacci sequence"); 
    printf("fib(11)=%llu\n", fib(11)); 

    return (0); 
}

size_t fib(size_t N)
{
    if(N == 0)
        return (0); 
    if(N == 1)
        return (1); 
    return (fib(N-1) + fib(N-2)); 
}