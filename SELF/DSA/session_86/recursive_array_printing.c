/* 
    Let A be an array of N integers. 
    N > 0. 

    Develop a recursive algorithm to print 
    elements of A in forward direction 
    (i.e. from 0 to N-1)

    Develop a recursive algorithm to 
    print elements of A in reverse direction 
    (i.e. from N-1 to 0)

*/

/* 
    Forward printing: Mathematical definition 

                            STOP                            if k == N 
    prn_fwd(a, N, k) == 
                            printf("a[%d]:%d\n", k, a[k]);  if 0 <= k < N 
                            prn_fwd(a, N, k+1)

    CALL 
        prn_fwd(a, N, 0); 
*/  

/* 
    Backward printing: Mathematical definition 
                                STOP                    if k == N 
    prn_bkwd(a, N, k)   ==
                                prn_bkwd(a, N, k+1)     if 0 <= k < N
                                printf("a[%d]:%d\n", k, a[k]); 

    CALL 
        prn_bkwd(a, N, 0)
*/

/* 
    Backward printing: Alterantive: Mathematical definition 
                                STOP        if k < 0 
    prn_bkwd_alt(a, k)  == 
                                printf("a[%d]:%d\n", k, a[k]); 
                                prn_bkwd_alt(a, k-1); 
    CALL 
        prn_bkwd_alt(a, N-1); 

*/

#include <stdio.h> 
#include <stdlib.h> 

void prn_fwd(int* a, size_t N, int k); 
void prn_bkwd(int* a, size_t N, int k); 
void prn_bkwd_alt(int* a, int k); 

int main(void)
{
    int a[10] = {   
                    10, 23, 45, 62, 17, 
                    83, 44, 65, 32, 12
                }; 

    puts("Forward printing of array a:"); 
    prn_fwd(a, 10, 0); 

    puts("Backward printing of array a:"); 
    prn_bkwd(a, 10, 0); 

    puts("Backward printing of array a:"); 
    prn_bkwd_alt(a, 9); 

    return (0); 
}

void prn_fwd(int* a, size_t N, int k)
{
    if(k == N)
        return; 
    printf("a[%d]:%d\n", k, a[k]); 
    prn_fwd(a, N, k+1); 
}

void prn_bkwd(int* a, size_t N, int k)
{
    if(k == N)
        return; 
    prn_bkwd(a, N, k+1); 
    printf("a[%d]:%d\n", k, a[k]); 
}

void prn_bkwd_alt(int* a, int k)
{
    if(k < 0)
        return; 
    printf("a[%d]:%d\n", k, a[k]); 
    prn_bkwd_alt(a, k-1); 
}
