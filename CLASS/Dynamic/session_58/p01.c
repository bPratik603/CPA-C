#include<stdio.h>
#include<stdlib.h>

int* fill_int(int* no1, int* no2);

int main(void)
{
    int* p = 0;
    int a,b;

    p = fill_int(&a, &b);
    *p = a + b ;

    printf("add of no is = %d\n",*p);

    free(p);
    p = 0;
}

int* fill_int(int* no1, int* no2)
{
    int* p = 0;
    int a,b;

    printf("Enter a no1:\n");
    scanf("%d",&a);

    printf("Enter a no2:\n");
    scanf("%d",&b);

    p = (int*)malloc(sizeof(int));

    *no1 = a;
    *no2 = b;
    
    return(p);
}