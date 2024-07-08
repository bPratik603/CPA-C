#include<stdio.h>
#include<stdlib.h>

void test(void);

int main(void)
{
    test();
    return(0);
}

void test(void)
{
    const int n = 100;
    int* p = &n;    // waring

    printf("*p = %d\n",*p); //100
    *p = 500;
    printf("*p = %d\n",*p);  //500
}