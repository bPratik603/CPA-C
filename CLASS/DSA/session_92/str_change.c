#include <stdio.h> 
#include <stdlib.h> 

char* s1 = "Hello"; 
char s2[] = "Hello"; 

int main(void)
{
    printf("Before assignment:s1 = %s, s2 = %s\n", s1, s2); 
    s1[0] = 'Y'; 
    s2[0] = 'Y'; 
    printf("After assignment:s1 = %s, s2 = %s\n", s1, s2); 
    return (0); 
}   