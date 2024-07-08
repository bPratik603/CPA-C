#include<stdio.h>
#include<stdlib.h>

int arr[5][3];

int main()
{
    int i,j;
    printf("arr : %llu\n",(unsigned long long int)arr);

   for(i=0;i<5;i++)
   {
    printf("arr[%d]: %llu\n",i,(unsigned long long int)&arr[i]);
   }

   for(i=0;i<5;i++)
   {
    for(j=0;j<3;j++)
    {
        printf("arr[%d][%d]: %llu\n",i,j,(unsigned long long int)&arr[i][j]);
    }
   }
}