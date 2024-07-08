#include <stdio.h> 
#include <stdlib.h> 

// array creation syntax : General 
int a1[5]; 
int a2[5] = {10, 20, 30, 40, 50}; 
int a3[5] = {10}; 
int a4[5] = {0}; 
int a5[] = {100, 200, 300, 400, 500}; 

// string creation 
char s1[5] = "abcd\0"; 
char s2[] = "abcd\0"; 
char* p_str_1 = "abcd"; 

char s[] = {'E', 'n', 't', 'e', 'r', ' ', 'a', 'n', ' ', 
            'i', 'n', 't', 'e', 'g', 'e', 'r', ':', '\0'}; 

char msg[] = "Enter an integer:"; 

char* p = "Hello"; 


/* 
    TAKEAWAY: 
    "Enter an integer:"

    IS A SHORT CUT SYNTAX FOR 

    {'E', 'n', 't', 'e', 'r', ' ', 'a', 'n', ' ', 
    'i', 'n', 't', 'e', 'g', 'e', 'r', ':', '\0'}; 

    EXPLICIT CHARACTER ARRAY INITIALISER 

*/

int main(void)
{

}


char a[] ="abcd\0";