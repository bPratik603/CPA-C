#include <stdio.h> 
#include <stdlib.h> 

struct Date 
{
    int day; 
    int month; 
    int year; 
};

// 0x7b2 
// 0x 00 00 07 b2 

/* 
[1   ][0  ][0  ][0  ]
[1  ][0 ][0 ][  0]
[B2][07][   0][0    ]
*/ 

unsigned char arr[12] = {
                            0x1, 0x0, 0x0, 0x0, 
                            0x1, 0x0, 0x0, 0x0,
                            0xB2, 0x7, 0x0, 0x0
                        }; 

int main(void)
{
    void* p = NULL; 
    
    p = arr; /* unsigned char* */

    printf("EPOCH DATE: %d-%d-%d\n", 
            ((struct Date*)p)->day, 
            ((struct Date*)p)->month, 
            ((struct Date*)p)->year); 

    return (0); 
}