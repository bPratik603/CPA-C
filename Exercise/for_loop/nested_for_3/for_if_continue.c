#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i;
    //////////////////////////////////////////////////////////////////////
    puts("----------------------------------prog: 1----------------------------");

    for(i = 0;i<10;++i)
    {
        printf("i=%d\n",i);
        if(i % 2 == 0)
        {
              continue;
              printf("i=%d\n",i);
        }
    }

    exit(0);
}