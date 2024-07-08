#include <stdio.h> 
#include <stdlib.h> 

int a[5][3]; 

int main(void)
{
    int i; 
    int j; 

    printf("addr(a)=%llu\n", (unsigned long long int)a);
    for(i = 0; i < 5; ++i)
        printf("addr(a[%d]):%llu\n", i, (unsigned long long int)&a[i]); 
    
    for(i = 0; i < 5; ++i) 
        for(j = 0; j < 3; ++j)
            printf("addr(a[%d][%d]):%llu\n", i, j, (unsigned long long int)&a[i][j]); 

    return (0); 
} 

/* 
    int a[5][3]; 
    a is array 5 of array 3 of int. 

    type(a) ==          int     [5][3]
    type(a[i]) ==       int     [3]         where i=0,1,2,3,4
    type(a[i][j]) ==    int                 where i=0,1,2,3,4 and j=0,1,2 

    sizeof(int) == 4 
    sizeof(int [3]) == 12 
    sizeof(int[5][3]) == 60 

    if addr of x is a: 

    addr(a[0]) = x + 0 
    addr(a[1]) = x + 12 
    addr(a[2]) = x + 24 
    addr(a[3]) = x + 36 
    addr(a[4]) = x + 48 

    addr(a[i]) = base addr (a) + i * sizeof(typeof(a[i]))
               = base addr (a) + i * sizeof(int [3]) ... type(a[i]) == int[3]
               = base addr (a) + i * 3 * sizeof(int)
               = base addr (a) + i * 3 * 4 
               = base addr (a) + i * 12    ----- RESULT A

    addr(a[i][j]) == base addr (a) + i * 12 + j * 4 

    addr(a[i][j]) == base addr (a[i]) + j * sizeof(typeof(a[i][j]))
                  == base addr (a[i]) + j * sizeof(int) ...    type(a[i][j]) ==    int 
                  == base addr (a[i]) + j * 4 
                  == base addr (a) + i * 12 + j * 4 

*/