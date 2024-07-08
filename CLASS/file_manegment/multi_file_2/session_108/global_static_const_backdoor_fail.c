#include<stdio.h>
#include<stdlib.h>

static const int a = 100;

int main(void)
{
    int* p = &a;
    printf("*p = %d\n",*p);
    *p = 200;
    printf("*p = %d\n",*p);
}