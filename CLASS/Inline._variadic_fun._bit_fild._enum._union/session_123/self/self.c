#include<stdio.h>
#include<stdlib.h>

struct a
{
    int a:4;
    char b:1;
    short s:5;
    long  l:8;
};

struct b
{
    char c:2;
    int i:4;
    int i1:4;
    int i2:5;
};

int main()
{
    printf("size of struct a = %llu\n",sizeof(struct a));
    printf("size of struct b = %llu\n",sizeof(struct b));

    exit(EXIT_SUCCESS);
}