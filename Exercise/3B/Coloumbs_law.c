#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    float r,q1,q2;
    double F;

    printf("Enter 1st charge on particle:\n");
    scanf("%f",&q1);

    printf("Enter 2nd charge on particle:\n");
    scanf("%f",&q2);

    printf("Enter the distance between the charges r:\n");
    scanf("%f",&r);

    if(r<0)
    {
        puts("Distance must be positive");
        exit(EXIT_FAILURE);
    }

    F = (8.988*pow(10.0,9.0)*q1*q2)/r*r;

    printf("Magnitude of force is: %lf\n",F);

    if(F < 0)
    {
        puts("Repusion occures");
    }
   else
        {
            puts("attraction occures");
        }

        return (0);
    
}
