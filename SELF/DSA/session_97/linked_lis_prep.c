#include <stdio.h> 
#include <stdlib.h> 

struct node
{
    int data; 
    struct node* next; 
}; 

int main(void)
{
    struct node N1, N2, N3; 

    N1.data = 10; 
    N1.next = &N2; 

    N2.data = 20; 
    N2.next = &N3; 

    N3.data = 30; 
    N3.next = NULL; 

    return (0); 
}

/* 

struct T 
{
    T1 mem1; 


    Tk memk; 
}; 

*/