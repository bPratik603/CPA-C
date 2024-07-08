#include <stdio.h> 
#include <stdlib.h> 

#define N 8

void show_array_1( int(*p)[N], int length ); 
void show_array_2( int* p, int length ); 

void populate_array( int* p, int length); 

int main(void)
{
    int A[N] = {100, 200, 300, 400, 500, 600, 700, 800}; 
    int B[N]; 

    show_array_1(&A, N);
    puts("-------------------------") ; 
    show_array_2(A, N); 

    puts("Show array B, before populate array"); 
    show_array_2(B, N); 
    populate_array(B, N); 
    puts("Show array B, after populate array"); 
    show_array_2(B, N); 

    return (0); 
}

void show_array_1( int(*p)[N], int length )
{
    int index; 
    int element; 

    for(index = 0; index < length; ++index)
    {
        element = (*p)[index]; 
        printf("element at index %d = %d\n", index, element); 
    }
}

void show_array_2(int* p, int length)
{
    int index; 
    int element; 

    for(index=0; index < length; ++index)
    {
        element = *(p+index); /* OR element = p[index]*/
        printf("element at index %d = %d\n", index, element); 
    }
}

void populate_array( int* p, int length)
{
    int index; 

    for(index=0; index < length; ++index)
        *(p+index) = (index + 1) * 1000; 
}
