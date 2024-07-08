#include<stdio.h>
#include<stdlib.h>


void for_loop_1(void);
void for_loop_2(void);
void for_loop_3(void);
void for_loop_4(void);


int main(void)
{
    int i;
 for_loop_1();
 for_loop_2();
 for_loop_3();
 for_loop_4();
    exit (0);
}

/////////////////////////////////////////////////////////////

void for_loop_1(void)
{
    for(int i = 0;i<20;++i)
    {
        printf("for_loop_1: i       = %d\n",i);
    }
}
////////////////////////////////////////////////////////////
void for_loop_2(void)
{
    for(int i = 0;i<=20;i=i+2)//i=i+2;
    {
    printf("for_loop_2: i           = %d\n",i);
    }
}
////////////////////////////////////////////////////////////
void for_loop_3(void)
{
    for(int i = 1;i<=20;i*=2)//i=i*2;
    {
        printf("for_loop_3: i            = %d\n",i);
    }
}
///////////////////////////////////////////////////////////
void for_loop_4(void)
{
     for(int i=1;i<=20;i = i<<3)
     {
        printf("for_loop_4: i            =%d\n", i);
     }
}