#include<stdio.h>

int add_num(int,int);
int sub_num(int,int);

int main()
{
    int (*pfn)(int,int);
    int ret;

    pfn = add_num;
    ret = pfn(100,200);
    printf("addd = %d\n",ret);

    pfn = sub_num;
    ret = pfn(100,200);
    printf("sub = %d\n",ret);

    return(0);
}

int add_num(int a,int b)
{
    return(a+b);
}

int sub_num(int a,int b)
{
    return(a-b);
}