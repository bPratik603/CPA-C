#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    printf("Quadratic Eqution is: ax^2 + bx + c\n");
   int a,b,c;
   float r1,r2;
    
    printf("Enter value for a:\n");
    scanf("%d",&a);

    if(a = 0)
    {
        puts("the value should not zero");
        exit(EXIT_FAILURE);
    }

    printf("Enter value for b:\n");
    scanf("%d",&b);

    printf("Enter value for c:\n");
    scanf("%d",&c);

    //r1 = (-b + sqrt(b*b-4*a*c)) / 2*a; 
    //r2 = (-b - sqrt(b*b-4*a*c)) / 2*a; 

 float z = b*b - 4*a*c;

printf("z=%f\n",z);

    /*if(b*b-4*a*c <= 0)
    {
        puts("the eqution ax^2+bx+c does not have roots in real");
        exit(EXIT_FAILURE);
    }

    printf("roots of the eqution is r1= %.2f, r2= %.2f\n",r1,r2);
    */
    return (0);
}