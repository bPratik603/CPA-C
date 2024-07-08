#include <stdio.h> 
#include <stdlib.h> 
#include <stdarg.h>     // S1 

unsigned long long int vsum(unsigned int nr, ...); 

int main(void){
    unsigned long long int rs; 

    rs = vsum(0);
    printf("rs = %llu\n", rs);  
    rs = vsum(1, 100); 
    printf("rs = %llu\n", rs); 
    rs = vsum(2, 500, 200); 
    printf("rs = %llu\n", rs); 
    rs = vsum(3, 1000, 200, 300);
    printf("rs = %llu\n", rs);  
    rs = vsum(5, 1500, 200, 300, 400, 500);
    printf("rs = %llu\n", rs); 

    return (0); 
}

unsigned long long int vsum(unsigned int nr, ...){
    va_list ap;     // S2 
    unsigned long long int summation = 0; 
    unsigned int i; 

    va_start(ap, nr);   // S3 

    for(i = 0; i < nr; ++i)
        summation += va_arg(ap, int);   // S4 

    va_end(ap); 

    return (summation); 
} 

