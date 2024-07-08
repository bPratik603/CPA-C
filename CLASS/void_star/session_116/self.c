#include<stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

unsigned char arr[12] = {
                            0x1, 0x0, 0x0, 0x0, 
                            0x1, 0x0, 0x0, 0x0,
                            0xB2, 0x7, 0x0, 0x0
                        };

int main()
{
    void* p = NULL;

    p = arr;

    printf("%d-%d-%d",
           ((struct Date*)p)->day,
           ((struct Date*)p)->month,
           ((struct Date*)p)->year);
}