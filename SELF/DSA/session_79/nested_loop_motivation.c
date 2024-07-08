#include <stdio.h> 
#include <stdlib.h> 

/* 
    Let A be the array of N elements. (N > 1) 
    Let S be any given integer. 

    print all pairs of 2 two distinct elements in array 
    whose sum is less than or equal to S. 
*/

void p_arr(int* pp, int N);

int main(void)
{
      int arr[5] = {0,1,2,3,4};
      int n = 5;

      p_arr(arr,n);

}


void p_arr(int* pp, int N)
{
    int i,j;
      printf("Same numbers allowed:\n");

    for(i = 0;i<N;++i)
    {
        for(j = 0;j<N;++j)
        {
            if((pp[i] + pp[j]) <= 5)
            {
                printf("i:%d j:%d %d %d\n",i,j,pp[i],pp[j]);
            }
        }
    }

   printf("Same numbers not allowed:\n");

   for(i = 0;i<N;++i)
   {
    for(j = 0;j<N;++j)
    {
        if(i!=j && (pp[i] + pp[j]) <=5)
        {
            printf("i:%d j:%d %d %d\n",i,j,pp[i],pp[j]);
        }
    }
   }

   printf("Upper trangular matrix\n");

   for(i = 0;i<N;++i)
   {
    for(j = i;j<N;++j)
    {
       printf("i:%d j:%d %d %d\n",i,j,pp[i],pp[j]);
        
    }
   }

  printf("Upper trangular matrix - digonal\n");

    for(i = 0;i<N;++i)
    {
        for(j = i;j<N;++j)
        {
            if(i != j)
            {
             printf("i:%d j:%d %d %d\n",i,j,pp[i],pp[j]);

            }
        }
        
    }

    printf("Lower trangular matrix: \n");

    for(i = 0;i<N;++i)
    {
        for(j = 0;j<=i;++j)
        {
               printf("i:%d j:%d %d %d\n",i,j,pp[i],pp[j]);

            
        }
    }

  printf("Lower trangular matrix- digonal:\n");

    for(i = 0;i<N;++i)
    {
        for(j = 0;j<i;++j)
        {
           printf("i:%d j:%d %d %d\n",i,j,pp[i],pp[j]);   
        }
    }
}


