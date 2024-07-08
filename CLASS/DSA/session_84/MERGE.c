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

#define TRUE 1 

void merge(int* pa, int p, int q, int r); 
void show_array(int* a, int N, const char* msg); 

int main(void)
{
    int a[15] = {   
                    -1, 8, 99, 87,      /* 0 to 3   */
                    10, 20, 30,         /* 4 to 6   */
                    5, 15, 17, 25, 35,  /* 7 to 11  */
                    -11, 2, 520         /* 12 to 14 */
                }; 

    show_array(a, 15, "Before merge:"); 
    merge(a, 4, 6, 11); 
    show_array(a, 15, "After merge:"); 

    return (EXIT_SUCCESS); 
}

void merge(int* pa, int p, int q, int r)
{
    /* 
        Preconditions: 
            Let N be the length of array pa. 

            Pre-condition 1: 0 <= p <= q < r < N 
            Pre-condition 2: pa[p...q] is sorted 
                             pa[q+1...r] is sorted. 

            Post-condition: 
                pa[p...r] is sorted. 
    */

    int* a1 = NULL;  /* Base addr of sub-array 1*/
    int N1;          /* Size of subarray 1 */

    int* a2 = NULL;  /* Base addr of sub-array 2*/
    int N2;          /* Size of sub-array 2*/

    int k;           /* Tracker Index into main array pa */
    int k1;          /* Tracker index into sub-array a1*/
    int k2;          /* Tracker index into sub-array a2*/

    N1 = q - p + 1; 
    N2 = r - q; 

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

    /* Copy pa[p..q] into a1*/
    for(k = 0; k < N1; ++k)
        a1[k] = pa[p + k]; 

    /* Copy pa[q+1...r] into a2*/
    for(k = 0; k < N2; ++k)
        a2[k] = pa[q + 1 + k]; 

    k = 0;      /* Set Tracker into pa */
    k1 = 0;     /* Set trakcer into a1 */
    k2 = 0;     /* Set tracker into a2 */

    while(TRUE)
    {
        if(a1[k1] <= a2[k2])
        {
            pa[p + k] = a1[k1]; 
            k = k + 1; 
            k1 = k1 + 1; 
            /* If we have reached to the end of a1 
                then copy rest of a2 back into pa 
                and exit from infinite loop using break */
            if(k1 == N1)
            {
                while(k2 < N2)
                {
                    pa[p + k] = a2[k2]; 
                    k = k + 1; 
                    k2 = k2 + 1; 
                }
                break; 
            }
        }
        else 
        {
            pa[p + k] = a2[k2]; 
            k = k + 1; 
            k2 = k2 + 1; 
            /* If we have  reached to the end of a2 then 
                copy remaining a1 into pa and exit from 
                infinitie loop using break */
            if(k2 == N2)
            {
                while(k1 < N1)
                {
                    pa[p + k] = a1[k1]; 
                    k = k + 1; 
                    k1 = k1 + 1; 
                }
                break; 
            }
        }
    }

    free(a1); 
    a1 = NULL; 

    free(a2); 
    a2 = NULL; 
}

void show_array(int* a, int N, const char* msg)
{
    int k; 

    if(msg)
        puts(msg); 

    for(k = 0; k < N; ++k)
        printf("a[%d]:%d\n", k, a[k]); 
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