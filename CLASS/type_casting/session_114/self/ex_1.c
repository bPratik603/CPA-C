#include<stdio.h>

unsigned long long int x;

int main()
{
   printf("1.x = %llx\n",x);

   *(unsigned char*)&x = 0x1a;

   printf("2.x = %llx\n",x);

   *(unsigned short*)((char*)&x + 1) = 0x2b3c;

   printf("3.x = %llx\n",x);

   *(unsigned int*)((char*)&x + 3) = 0x0a0b0c0d;

   printf("4.x = %llx\n",x);

   *(unsigned char*)((char*)&x + 7) = 0x0a;

   printf("5.x = %llx\n",x);

   return(0);  
}