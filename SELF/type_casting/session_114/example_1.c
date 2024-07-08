#include <stdio.h> 
#include <stdlib.h> 

/* 
    Assume n is at M[1000:1003]
    As per the little endian organization, 
    the value 0x0a0b0c0d is stored in n as follows: 

    M[1000]     M[1001]     M[1002]     M[1003]
    0d          0c          0b          0a 

    As per the big endian organization, 
    the value 0x0a0b0c0d is stroed in n as follows: 
    M[1000]     M[1001]     M[1002]     M[1003]
    0a          0b          0c          0d

    To write a program to determine an endianness of machine, 
    you should compare the contents of memory location M[1000]
    with 0xd and 0xa. 

    If comparison with 0xd is true then its a little endian machine 
    else if comparison 0xa is true then its a big endian machine 
*/

int main(void) 
{
    int n = 0x0a0b0c0d; 

    if(*(char*)&n == 0xd) 
        puts("Machine is little endian"); 
    else if(*(char*)&n == 0xa)
        puts("Machine is big endian"); 
    else 
        puts("Invalid control flow"); 

    return (0); 
}

/* 
    type(n) = int ... given by programmer 
    type(&n) = int* ... Def of '&' operator 

    *(&n) will read 4 bytes from starting address of n. 

    What should have been the type of expr &n so that 
    application of dereference operator '*' would have 
    resulted into read 1 byte from starting address. 

    Ans: char*
*/