#include<stdio.h>
#include<stdlib.h>


int main(void)
{
    float m1,m2,r,f;
    printf("Enter the mass of object 1:\n");
    scanf("%f",&m1);

    if(m1 < 0)
    {
        puts("Number must positive");
        exit(EXIT_FAILURE);
    }

    printf("Enter the mass of object 2:\n");
    scanf("%f",&m2);

    if(m2 < 0)
    {
        puts("Number must positive");
        exit(EXIT_FAILURE);
    }

    printf("Enter the radious of object\n");
    scanf("%f",&r);

    if(r < 0)
    {
        puts("Number must positive");
        exit(EXIT_FAILURE);
    }

    f = (6.67*pow(10.0,-11.0)*m1*m2)/r*r;


    printf("Gravitaional force: %f\n",f);

    return(0);
     
     


}