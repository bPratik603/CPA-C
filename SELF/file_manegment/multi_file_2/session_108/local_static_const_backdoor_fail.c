#include<stdio.h>
#include<stdlib.h>

void test(void);

int main(void)
{
    test();
}

void test(void)
{
    static const int a = 100;

    int* p = &a;
    printf("*p = %d\n",*p);
    *p = 200;
    printf("*p = %d\n",*p);
}