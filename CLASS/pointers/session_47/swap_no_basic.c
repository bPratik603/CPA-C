#include<stdio.h>
#include<stdlib.h>


void test_1(int* a1,int* b1);;
//void test_2(void);

void main(void)
{
    int a=100,b=200;
    printf("bfore swap: a=%d,b=%d\n",a,b);
    test_1(&a,&b);
    printf("after swap: a=%d,b=%d\n",a,b);
  //  test_2();
      exit (0);


}

void test_1(int* a1,int* b1)
{
    int tmp;
    tmp= *a1;
    *a1=*b1;
    *b1=tmp;

}



