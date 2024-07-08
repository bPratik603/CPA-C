#include<stdio.h>
#include<stdlib.h>


int my_add(int,int);
int my_sub(int,int);

int main(void)
{
    int (*pfn)(int,int);
     int ret;

    pfn = my_add;
    ret = pfn(200,100);
    printf("add is = %d\n",ret);
    pfn = my_sub;
    ret = pfn(200,100);
    printf("sub is = %d\n",ret);

    return(0);

}

int my_add(int a,int b)
{
    return(a+b);
}

int my_sub(int a,int b)
{
    return(a-b);
}