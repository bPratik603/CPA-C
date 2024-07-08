#define _CRT_RAND_S 

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define TRUE    1 
#define CAP     20000001
#define N_MAX   10000001

void get_array(int** pp_arr, int* pN); 
void show(int* pA, int N, const char* msg); 
void merge(int* a, int p, int q, int r); 
void merge_sort(int* a, int start_index, int end_index); 

int main(void)
{
    int* a = NULL; 
    int N = -1; 
    time_t t_start, t_end, t_delta; 

    get_array(&a, &N); 
    // show(a, N, "Before sort:"); 
    t_start = time(0); 
    merge_sort(a, 0, N-1);
    t_end = time(0); 
    t_delta = t_end - t_start; 
    // show(a, N, "After sort:"); 
    printf("Time required:%lld\n", t_delta); 

    free(a); 
    a = NULL; 

    return (EXIT_SUCCESS); 
}

/* start_index == p, mid_index == q, end_index == r */
void merge_sort(int* a, int start_index, int end_index)
{
    int mid_index; 

    if(start_index < end_index)
    {
        mid_index = (start_index + end_index)/2;
        merge_sort(a, start_index, mid_index); 
        merge_sort(a, mid_index + 1, end_index); 
        merge(a, start_index, mid_index, end_index); 
    }
}

void merge(int* a, int p, int q, int r)
{
    int N1 = q - p + 1; 
    int N2 = r - q; 
    int* a1 = NULL; 
    int* a2 = NULL; 
    int k1, k2, k; 

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
        a1[k] = a[p+k]; 

    for(k = 0; k < N2; ++k)
        a2[k] = a[q+1+k]; 

    k = 0; 
    k1 = 0; 
    k2 = 0; 
    while(TRUE)
    {
        if(a1[k1] <= a2[k2])
        {
            a[p+k] = a1[k1]; 
            k1 += 1; 
            k +=1; 
            if(k1 == N1)
            {
                while(k2 < N2)
                {
                    a[p+k] = a2[k2]; 
                    k2 += 1; 
                    k += 1; 
                }

                break; 
            }
        }
        else 
        {
            a[p+k] = a2[k2]; 
            k2 += 1; 
            k += 1;  
            if(k2 == N2)
            {
                while(k1 < N1)
                {
                    a[p+k] = a1[k1]; 
                    k1 += 1; 
                    k += 1;
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

void get_array(int** pp_arr, int* pN)
{
    int* pA = NULL; 
    int N; 
    unsigned int num; 
    int i; 

    printf("Enter N[Between 1-1,00,00,000]:"); 
    scanf("%d", &N); 

    if(N <= 0 || N > N_MAX)
    {
        printf("Size of array must be between 0 to %d\n", N_MAX); 
        exit(EXIT_FAILURE); 
    }

    pA = (int*)malloc(N * sizeof(int)); 
    if(pA == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < N; ++i)
    {
        rand_s(&num); 
        pA[i] = num % CAP; 
    }

    *pp_arr = pA; 
    *pN = N; 
}

void show(int* pA, int N, const char* msg)
{
    int i; 

    if(msg)
        puts(msg); 

    for(i = 0; i < N; ++i)
        printf("pA[%d]:%d\n", i, pA[i]); 
}
