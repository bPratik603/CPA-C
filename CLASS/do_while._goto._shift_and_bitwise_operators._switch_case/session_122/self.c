#include<stdio.h>


int main()
{
    int i;
    int rs = 5;
    for(i=0;i<=rs;i++)
    {
        rs = rs << 1;
        printf("i = %d\n",rs);
    }
}