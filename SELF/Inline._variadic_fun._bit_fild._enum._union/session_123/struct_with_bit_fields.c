#include <stdio.h> 
#include <stdlib.h> 

struct Date {
    int day:5; 
    int month:4; 
    short    :0;  
    int year; 
}; 

struct Test 
{
    char:0; 
    int a:3; 
    int b:2; 
    int c:2; 
   
}; 

int main(void){
    printf("sizeof(struct Date)=%llu\n", sizeof(struct Date)); 
    printf("sizeof(struct Test)=%llu\n", sizeof(struct Test)); 
    return (0); 
}