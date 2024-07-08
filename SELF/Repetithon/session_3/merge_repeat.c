#include <stdio.h> 
#include <stdlib.h> 
//1 
void merge(int* a, int p, int q, int r)
{
    int* a1 = NULL; 
    int* a2 = NULL; 
    int n1 = 0; 
    int n2 = 0; 
    int k, k1, k2; 

    n1 = q - p + 1; 
    n2 = r - q; 

    a1 = (int*)malloc(n1 * sizeof(int)); 
    if(a1 == NULL)
    {
        puts("error"); 
        exit(EXIT_FAILURE); 
    }

    a2 = (int*)malloc(n2 * sizeof(int)); 
    if(a2 == NULL)
    {
        puts("error"); 
        exit(EXIT_FAILURE); 
    }

    for(k = 0; k < n1; ++k)
        a1[k] = a[p+k]; 

    for(k = 0; k < n2; ++k)
        a2[k] = a[q+1+k]; 

    k = 0; 
    k1 = 0; 
    k2 = 0; 

    while(1)
    {
        if(a1[k1] <= a2[k2])
        {
            a[p+k] = a1[k1]; 
            k++;
            k1++; 
            if(k1 == n1)
            {
                while(k2 < n2)
                {
                    a[p+k] = a2[k2]; 
                    k++; 
                    k2++; 
                }

                break; 
            }
        }
        else 
        {
            a[p+k] = a2[k2]; 
            k++; 
            k2++; 
            if(k2 == n2)
            {
                while(k1 < n1)
                {
                    a[p+k] = a1[k1]; 
                    k++; 
                    k1++; 
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

//2 

void merge(int* a, int p, int q, int r)
{
    int* a1 = NULL; 
    int* a2 = NULL; 
    int n1; 
    int n2; 
    int k; 
    int k1; 
    int k2; 

    n1 = q - p + 1; 
    n2 = r - q; 

    a1 = (int*)malloc(n1 * sizeof(int)); 
    if(a1 == NULL)
    {
        puts("error"); 
        exit(EXIT_FAILURE); 
    }

    a2 = (int*)malloc(n2 * sizeof(int)); 
    if(a2 == NULL)
    {
        puts("error"); 
        exit(EXIT_FAILURE); 
    }

    for(k = 0; k < n1; ++k)
        a1[k1] = a[p+k]; 

    for(k = 0; k < n2; ++k)
        a2[k2] = a[q+1+k]; 

    k = 0; 
    k1 = 0; 
    k2 = 0; 

    while(1)
    {
        if(a1[k1] <= a2[k2])
        {
            a[p+k] = a1[k1]; 
            k++; 
            k1++; 
            if(k1 == n1)
            {
                while(k2 < n2)
                {
                    a[p+k] = a2[k2]; 
                    k++; 
                    k2++; 
                }
                break; 
            }
        }
        else
        {
            a[p+k] = a2[k2]; 
            k++; 
            k2++; 
            if(k2 == n2)
            {
                while(k1 < n1)
                {
                    a[p+k] = a1[k1]; 
                    k++; 
                    k1++; 
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

// 3 
void merge(int* a, int p, int q, int r)
{
    int* a1 = NULL; 
    int* a2 = NULL; 
    int n1; 
    int n2; 
    int k; 
    int k1; 
    int k2; 

    a1 = (int*)malloc(n1 * sizeof(int)); 
    if(a1 == NULL)
    {
        puts("error"); 
        exit(EXIT_FAILURE); 
    }

    a2 = (int*)malloc(n2 * sizeof(n2)); 
    if(a2 == NULL)
    {
        puts("error"); 
        exit(EXIT_FAILURE); 
    }

    for(k = 0; k < n1; ++k)
        a1[k1] = a[p+k]; 

    for(k = 0; k < n2; ++k)
        a2[k2] = a[q+1+k]; 

    k = 0; 
    k1 = 0; 
    k2 = 0; 

    while(1)
    {
        if(a1[k2] <= a2[k2])
        {
            a[p+k] = a1[k1]; 
            k++; 
            k1++; 
            if(k1 == n1)
            {
                while(k2 < n2)
                {
                    a[p+k]  = a2[k2]; 
                    k++; 
                    k2++; 
                }

                break; 
            }
        }
        else 
        {
            a[p+k] = a2[k2]; 
            k++; 
            k2++; 
            if(k2 == n2)
            {
                while(k1 < n1)
                {
                    a[p+k] = a1[k1]; 
                    k++;
                    k1++; 
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

// 4 
void merge(int* a, int p, int q, int r)
{
    int* a1 = NULL; 
    int* a2 = NULL; 
    int n1; 
    int n2; 
    int k; 
    int k1; 
    int k2; 

    n1 = q - p + 1; 
    n2 = r - q; 

    a1 = (int*)malloc(n1 * sizeof(int)); 
    if(a1 == NULL)
    {
        puts("error"); 
        exit(EXIT_FAILURE); 
    }

    a2 = (int*)malloc(n2 * sizeof(int)); 
    if(a2 == NULL)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    for(k = 0; k < n1; ++k)
        a1[k1] = a[p+k]; 

    for(k = 0; k < n2; ++k)
        a2[k2] = a[q+1+k]; 

    k = 0; 
    k1 = 0; 
    k2 = 0; 

    while(1)
    {
        if(a1[k1] <= a2[k2])
        {
            a[p+k] = a1[k1]; 
            k++; 
            k1++;
            if(k1 == n1)
            {
                while(k2 < n2)
                {
                    a[p+k] = a2[k2]; 
                    k++; 
                    k2++; 
                }
                break; 
            }
        }
        else 
        {
            a[p+k] = a2[k2]; 
            k++; 
            k2++; 
            if(k2 == n2)
            {
                while(k1 < n1)
                {
                    a[p+k] = a1[k1]; 
                    k++; 
                    k1++; 
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

// 5 
void merge(int* a, int p, int q, int r)
{
    int* a1 = NULL; 
    int* a2 = NULL; 
    int n1; 
    int n2; 
    int k; 
    int k1; 
    int k2; 

    n1 = q - p + 1; 
    n2 = r - q; 

    a1 = (int*)malloc(n1 * sizeof(int)); 
    if(a1 == NULL)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    a2 = (int*)malloc(n2 * sizeof(int)); 
    if(a2 == NULL)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    for(k = 0; k < n1; ++k)
        a1[k1] = a[p+k]; 

    for(k = 0; k < n2; ++k)
        a2[k2] = a[q+1+k]; 

    k = 0; 
    k1 = 0; 
    k2 = 0; 

    while(1)
    {
        if(a1[k1] <= a2[k2])
        {
            a[p+k] = a1[k1]; 
            k++; 
            k1++; 
            if(k1 == n1)
            {
                while(k2 < n2)
                {
                    a[p+k] = a2[k2]; 
                    k++; 
                    k2++; 
                }
                break; 
            }
        }
        else 
        {
            a[p+k] = a2[k2]; 
            k++; 
            k2++; 
            if(k2 == n2)
            {
                while(k1 < n1)
                {
                    a[p+k] = a1[k1]; 
                    k++; 
                    k1++; 
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