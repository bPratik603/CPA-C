/* 
    int a[]  
        Let p and r be indices in array. 
        a[p]        a[r]
    Condition on p and r 
        0 <= p < r < N
    No condition on 
        a[0] to a[p-1]
        and a[r+1] to a[N-1]

    Consider an index q, such that 
    p <= q < r 

    Additional Condition: 
    a[p...q] should be sorted 
    a[q+1...r] should be sorted. 

    Goal: 
        a[p...r] should be sorted. 

    N elements. N > 0 

    We have sub-array from p, r 
    (Cond on p, r: 0 <= p < r < N)

    Then we have index q, 
    p <= q < r 

    a[p...q] is sorted 
    a[q+1...r] is sorted. 


    Goal: a[p...r] is sorted. 

    Repeat: This time all conditions together. 

    Let A be an array of N elements. Let p, q, r be indices in array such that 
    0 <= p <= q < r < N and A[p...q] and A[q+1...r]
    are sorted. Write a procedure, merge, accepting A, p, q, r so that 
    A[p...r] is sorted.     
*/

#include <stdio.h> 
#include <stdlib.h> 

void merge(int* pa, int p, int q, int r); 

int main(void)
{
    int a[15] = {   
                    1,2,3,4,5,6,7,8,9,10,11,12,13,14,15       /* 12 to 14 */
                }; 

    merge(a, 4, 6, 11); 

    return (0); 
}

void merge(int* pa, int p, int q, int r)
{
    int N1; 
    int N2; 
    int* a1 = NULL; 
    int* a2 = NULL; 

    N1 = q - p + 1; 
    N2 = r - q; 

    int k; 

    a1 = (int*)malloc(N1 * sizeof(int)); 
    if(a1 == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    a2 = (int*)malloc(N2 * sizeof(int)); 
    if(a2 == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    for(k = 0; k < N1; ++k)
        a1[k] = pa[p+k]; 

    for(k = 0; k < N2; ++k)
        a2[k] = pa[q+1+k]; 

    /* Print a1 and a2 for testing */
    for(k = 0; k < N1; ++k)
        printf("a1[%d]:%d\n", k, a1[k]); 

    for(k = 0; k < N2; ++k)
        printf("a2[%d]:%d\n", k, a2[k]); 

    free(a1); 
    a1 = NULL; 

    free(a2); 
    a2 = NULL; 
}

/* 
    Logic development: 
    
    Cloning array a[p...q] to a1[0...N1-1]

    Let k be any index into 0 to N1-1
    a1[k] should get assigned a[p+k]
    (simply because sub-array 1 starts from index p in a)

    to generalise it for all k in 0 to N-1, put loop 
    
    as N1 is computed from p and q. 
    Length of a1 (==N1) and length of a[p...q] are same. 
    (making loop possible)

    for(k = 0; k < N1; ++k)
        a1[k] = a[p+k]; 

    Cloning array a[q+1...r] to a2[0...N2-1]

    Let a2[k] be any valid element in a2 (i.e. 0 <= k < N2)

    a2[k] should get assigned to a[q+1+k]
    because sub-array 2, starts from q+1 

    to generalise it for all k in a2. 

    for(k = 0; k < N2; ++k)
        a2[k] = a[q+1+k]; 


*/