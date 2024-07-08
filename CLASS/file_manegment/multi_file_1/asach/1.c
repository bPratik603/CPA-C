#include<stdio.h>
#include<stdlib.h>

extern void add(int ,int);
extern void sub(int,int);

int a = 10;
int b = 20;

int main()
{
    add(a,b);
    sub(a,b);

    exit(0);
}