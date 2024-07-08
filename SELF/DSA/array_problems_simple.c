#include<stdio.h>
#include<stdlib.h>


int arr[10] = {1,7,3,28,5,9,18,17,22,30};

void even_numbers(int* p_arr, int N);
void odd_numbers(int* p_arr, int N);
void prime_numbers(int* p_arr, int N);

int main(void)
{
    
    return (0);
}

void even_numbers(int* p_arr, int N)
{
    int i;
   for(i = 0;i<N;++i)
   {
    if(arr[i] %2 == 0)
    {
        printf("arr[%d]:%d\n",i,arr[i]);
    }
   }
}

void odd_numbers(int* p_arr, int N)
{
  int i;
   for(i = 0;i<N;++i)
   {
    if(arr[i] %2 == 1)
    {
        printf("arr[%d]:%d\n",i,arr[i]);
    }
   }
}

void prime_numbers(int* p_arr, int N)
{

}