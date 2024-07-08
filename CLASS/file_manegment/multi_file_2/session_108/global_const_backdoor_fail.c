#include<stdio.h>
#include<stdlib.h>


const int n = 100;

int main(void)
{
    int* p = &n; //waring

    printf("*p = %d\n",*p); //100
    *p = 200;               //segfault(linux),Memory violetion exseption (MVE)(windows)
    printf("*p = %d\n",*p); //
}