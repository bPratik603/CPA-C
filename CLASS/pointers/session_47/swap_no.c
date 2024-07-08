#include<stdio.h>
#include<conio.h>

void test_1(void);
void test_2(void);
void test_3(void);
void swap_1(int num_1, int num_2);
void swap_2(int* p_num1, int* p_num2);

int main(void)
{
    test_1();
    test_2();
    test_3();
    return (0);
}

void test_1(void)
{
    int a=100,b=200;
    int tmp;

    printf("Before swaping: a = %d, b= %d",a,b);
    tmp=a;
    a=b;
    b=tmp;
    printf("After swaping : a = %d, b = %d",a,b);
    puts("------end of test_1\n\n");

}

void test_2(void)
{
    int a=1000, b=2000;
    
        printf("Before calling swap_1(): a = %d, b= %d\n",a,b);
        swap_1(a,b);
        printf("After calling swap_1(): a = %d, b = %d\n",a,b);
    puts("-----end of test_2()-----\n\n");
}

void test_3(void)
{
    int a=1000,b=2000;
    printf("Before calling swap_2: a = %d,b = %d\n",a,b);
    swap_2(&a,&b);
    printf("After calling swap_2: a= %d, b = %d\n",a,b);
    puts("------end of test_3-----\n\n");
}
void swap_1(int a1, int a2)
{
    int tmp;
    tmp=a1;
    a1=a2;
    a2=tmp;
}

void swap_2(int* p_num1, int* p_num2)
{
    int t;
    t= *p_num1;
    *p_num1=*p_num2;
    *p_num2=t;
}