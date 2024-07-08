#include <stdio.h> 
#include <stdlib.h> 
#include "my_header.h" 

int main(void)
{
    int n; 
    int rs; 

    printf("Enter n:"); 
    scanf("%d", &n); 

    rs = my_square(n); 
    printf("rs = %d\n", rs); 

    return (0); 
}