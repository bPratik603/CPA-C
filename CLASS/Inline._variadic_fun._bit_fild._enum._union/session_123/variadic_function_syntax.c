#include <stdio.h> 
#include <stdlib.h> 

/* 
Variadic function must have AT LEAST ONE named parameter. 
After the LAST named parameter, a variadic function declaration 
specifies ELLIPSIS OPERATOR     '...'

as a formal paraemter. 

Rule: 
    1) If you want to specify the ellipsis as a formal parameter then 
        it MUST BE the LAST formal parameter of the function. 
        Named parameter CANNOT appear after ellipsis. 
    2) There must be at least one named parameter in the formal parameter 
        list of the function i.e. ONLY ellipsis cannot be a formal parameter list. 

        void f(...);    // not allowed 
        void f(int n, int m, ..., int k);   // not allowed 

        void f(int n, ...); // ok 
        void f(char *s, int n, float f, ...);

        all three dots must be contiguous and there must be only three dots. 
*/
void test_variadic_function(int n, ...); 

int main(void){
    char c = 'A'; 
    short s = -145; 
    long long int nl = 34563525; 
    char* msg = "Hello"; 
    
    test_variadic_function(100);    // ok 
    test_variadic_function(100, 1.1, "Hello"); // ok 
    test_variadic_function(100, c); // ok 
    test_variadic_function(100, c, s); // ok 
    test_variadic_function(100, c, s, nl); // ok 
    test_variadic_function(100, c, s, nl, msg); // ok 
    test_variadic_function(100, msg, s, c, nl); // ok 

    return (0); 
}

void test_variadic_function(int n, ...){
    puts("Inside test_variadic_function"); 
}