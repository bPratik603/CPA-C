#include<stdio.h>
#include<stdlib.h>
#define G 6.67

int main(void)
{
    int m1,m2,r;

    printf("Enter frist mass:\n ");
    scanf("%d",&m1);

    printf("Enter second mass:\n");
    scanf("%d",&m2);

    printf("Enter distance between masses:\n");
    scanf("%d",&r);
    int x= 2;
   double F= G(m1*m2)/r^x;
   
    printf("gravitational force of attraction is = %lf",F);

   exit (0);
}