#include<stdio.h>
#include<stdlib.h>


void patterns(int* arr,int n);

int main()
{
    int arr[5] = {0,1,2,3,4};
    int n = 5;

    patterns(arr,n);
}

void patterns(int* arr,int n)
{
    int i,j;

    puts("all ele");
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
          printf("(%d , %d)\n",arr[i],arr[j]);

        }
    }

    puts("sum of two element less than or equal to 5");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i] + arr[j] <= 5)
            {
                 printf("(%d , %d)\n",arr[i],arr[j]);

            }
        }
    }

    puts("two numbers not same");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j!=i)
            {
                           printf("(%d , %d)\n",arr[i],arr[j]);

            }
        }
    }

    puts("upper trangular matrix");
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
                        printf("(%d , %d)\n",arr[i],arr[j]);

        }
    }

    puts("upper trangular matrix digonal");
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
                        printf("(%d , %d)\n",arr[i],arr[j]);

        }
    }

    puts("lower trangular matrix");
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
                        printf("(%d , %d)\n",arr[i],arr[j]);

        }
    }

    puts("lower trangular matrix digonal");
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(j!=i)
            {
                            printf("(%d , %d)\n",arr[i],arr[j]);

            }
        }
    }

    puts("Number pattern 1");
    for(i=0;i<4;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf("1");
        }
        printf("\n");
    }

    puts("Number pattern 2");
    for(i=1;i<=4;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }

 int k = 1;
    puts("number pattern 3");
    for(i=1;i<=4;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d",k);
            k++;
        }
        printf("\n");
    }
}