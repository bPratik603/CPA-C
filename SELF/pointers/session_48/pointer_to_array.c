
#include <stdio.h> 
#include <stdlib.h> 

/* 
    100   200  300  400  500 
    [   ][   ][   ][   ][   ]
    0     1    2    3    4 
*/

int main(void) 
{
    int A[5] = {100, 200, 300, 400, 500}; 
    int i, n; 
    int (*p_arr)[5]; 

    puts("Print array using its name"); 
    for(i=0; i<5; ++i)
        printf("A[%d]:%d\n", i, A[i]); 

    puts("Print array using its pointer"); 
    p_arr =&A; 
    for(i=0; i<5; ++i)
    {
        n = (*p_arr)[i];
        printf("n = %d\n", n); 
    }

    return (0); 
}