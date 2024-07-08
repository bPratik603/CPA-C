#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i,j;

 printf("-------------------prg: 1-----------------------------------\n");

 for(i = -5;i<5;++i)
   for(j = -3;j<3;++j)
    {
        if((i+j) < 0)
        {
            printf("i:%d + j:%d is less than zero\n",i,j);
        }
        else if((i+j) == 0)
        {
            printf("i:%d + j:%d is equal to zero\n",i,j);
        }
        else
        {
            printf("i:%d + j:%d is greter than zero\n",i,j);

        }
    }     
////////////////////////////////////////////////////////////////////////////////

printf("-------------------prg: 2-----------------------------------\n");

 for(i = -5;i<5;++i)
   for(j = -3;j<3;++j)
    {
        if((i*j) < 0)
        {
            printf("i:%d * j:%d is less than zero\n",i,j);
        }
        else if((i*j) == 0)
        {
            printf("i:%d * j:%d is equal to zero\n",i,j);
        }
        else
        {
            printf("i:%d * j:%d is greter than zero\n",i,j);

        }
    }     
    exit(0);         
}