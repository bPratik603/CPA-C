#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

void even_no(int* p_arr, int N);
void odd_no(int* p_arr, int N);
void prime_no_1(int* p_arr, int N);
void prime_no_2(int* p_arr, int N);

int is_prime(int N);

int main(void)
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;

    even_no(arr,n);
    odd_no(arr,n);
    prime_no_1(arr,n);
    prime_no_2(arr,n);

    return (0);
}

void even_no(int* p_arr, int N)
{
    int i;
    for(i = 0;i<N;++i)
    {
        if(p_arr[i] %2 == 0)
        {
            printf("even: p_arr[%d]: %d\n", i,p_arr[i]);
        }
    }
}

void odd_no(int* p_arr, int N)
{
    int i;
    for(i = 0;i<N;++i)
    {
        if(p_arr[i] %2 == 1)
        {
            printf("odd: p_arr[%d]: %d\n",i,p_arr[i]);
        }
    }
}

void prime_no_1(int* p_arr, int N)
{
    int i,k,flag;
    for(i = 0;i<N;++i)
    {
        if(p_arr[i] <= 1)
        {
            continue;
        }

        else if(p_arr[i] == 2)
        {
            printf("prime: p_arr[%d]: %d\n",i,p_arr[i]);
        }

        else
        {
           flag = true;
           for(k = 2;k < p_arr[i];++k)
           {
              if(p_arr[i] %k == 0)
              {
                flag = false;
                break;
              }
           }
           
           if(flag == true)
           {
               printf("prime: p_arr[%d]: %d\n",i,p_arr[i]);
           }
        }
    }
}

void prime_no_2(int* p_arr, int N)
{
    int i;

    for(i = 0;i<N;++i)
    {
        if(is_prime(p_arr[i]) == true)
        {
           printf("prime: p_arr[%d]: %d\n",i,p_arr[i]);
        }
    }
}

int is_prime(int N)
{
    int i;

    if(N <= 1)
    {
        return (false);
    }

   if(N == 2)
    {
        return (true);
    }

    
        for(i = 2;i<N;++i)
        {
            if(N %i == 0)
            {
                return false;
            }
        }
    

    return (true);
}