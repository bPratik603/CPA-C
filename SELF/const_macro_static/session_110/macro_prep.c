#include <stdio.h> 
#include <stdlib.h> 

int max_int(int n1, int n2)
{
    if(n1 > n2)
        return (n1); 
    return (n2); 
}

float max_float(float a, float b)
{
    if(a > b)
        return (a); 
    return (b);
}

double max_double(double d1, double d2)
{
    if(d1 > d2) 
        return (d1); 
    return (d2); 
} 

