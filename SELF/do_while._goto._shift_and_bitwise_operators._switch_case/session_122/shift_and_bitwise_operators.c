#include <stdio.h> 
#include <stdlib.h> 

void bitwise_and_demo(void); 
void bitwise_or_demo(void); 
void bitwise_xor_demo(void); 
void bitwise_not_demo(void); 
void left_shift_demo(void); 
void right_shift_demo(void); 
void logical_not_demo(void); 

int main(void){

    bitwise_and_demo(); 
    bitwise_or_demo(); 
    bitwise_xor_demo(); 
    bitwise_not_demo(); 
    logical_not_demo(); 
    left_shift_demo(); 
    right_shift_demo(); 

    exit(EXIT_SUCCESS); 
}

void bitwise_and_demo(void){
    int n1 = 0xa0b0c0d0; 
    int n2 = 0x4982a2d4; 
    int rs; 
    /*                      x+3         x+2         x+1         x 
        n1 Bitwise Repr:    10100000   10110000  11000000  11010000
        n2 Bitwise Repr:    01001001   10000010  10100010  11010100
    */

   rs = n1 & n2; 
   printf("rs = %x\n", rs); 
}

void bitwise_or_demo(void){
    int n1 = 0xa0b0c0d0; 
    int n2 = 0x4982a2d4; 
    int rs; 
    /*                      x+3         x+2         x+1         x 
        n1 Bitwise Repr:    10100000   10110000  11000000  11010000
        n2 Bitwise Repr:    01001001   10000010  10100010  11010100
    */

   rs = n1 | n2; 
   printf("rs = %x\n", rs); 

}

void bitwise_xor_demo(void){
    int n1 = 0xa0b0c0d0; 
    int n2 = 0x4982a2d4; 
    int rs; 
    /*                      x+3         x+2         x+1         x 
        n1 Bitwise Repr:    10100000   10110000  11000000  11010000
        n2 Bitwise Repr:    01001001   10000010  10100010  11010100
    */

   rs = n1 ^ n2; 
   printf("rs = %x\n", rs); 
}

void bitwise_not_demo(void){
    int n1 = 0x0; 
    int n2 = 0xffffffff; 
    int n3 = 0xa0b0c0d0; 
    int rs; 

    rs = ~n1; 
    printf("rs = %x\n", rs); 

    rs = ~n2;
    printf("rs = %x\n", rs); 

    rs = ~n3; 
    printf("rs = %x\n", rs); 
}

void left_shift_demo(void){
    int n = 20; 
    int rs; 

    rs = n << 1; 
    printf("rs = %d\n", rs); 
}

void right_shift_demo(void){
    int n = 20; 
    int rs; 

    rs = n >> 1; 
    printf("rs = %d\n", rs); 
}

void logical_not_demo(void){
    int n1 = -45; 
    int n2 = 0; 
    int n3 = 1; 
    int rs; 

    rs = !n1; 
    printf("rs = %d\n", rs); 

    rs = !n2; 
    printf("rs = %d\n", rs); 

    rs = !n3; 
    printf("rs = %d\n", rs); 
} 

/* 
    Let N be an integer type. 
    Let k be an unsigned integer 
    satsifying following relationship. 

    1 <= k < 8  * sizeof(N)

    Let rs be of same integer type as that of N. 
    rs = N << k; 

    Most significant k bits (bits numbered from 
    k + 1 to 8 * sizeof(N) will be lost) and 
    bits from 1 to 8 * sizeof(N) - k will be shifted 
    to k + 1 to 8 * sizeof(N). 

    Bits nubmered from 1 to k will be 0.  

    Right Shift: 

    rs = N >> k; 

    First k bits numbered from 1 to k will be lost. 
    bits from 8 * sizeof(N) down to 8 * sizeof(N) - k+1 will be 
    shifted to 8 * sizeof(N) - k downto 1. 

    Bits from 8 * sizeof(N) - k + 1 to 8 * sizeof(N) will be zero.  
*/

void test(void)
{
    int n = 35346; 
    int rs; 

    rs = n << 3; 
    rs = n >> 3; 

    n = n << 3; 

    /* n = n + k  | n += k*/

    n <<= 3; 
    n >>= 3; 
}