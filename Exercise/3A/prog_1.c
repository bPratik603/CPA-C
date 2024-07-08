#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int a=10,
        b= 20,
        c= 3,
        d= 2,
        rs;
puts("a=10\nb=20\nc=3\nd=2\n");

puts("-----------------------------------prog: 1------------------------------");
    rs = a*c + b*d;
    puts("a*c + b*d");
    printf("rs= %d\n",rs);    

puts("-----------------------------------prog: 2------------------------------");
   rs = a/c + b*d;
    puts("a/c + b*d");
    printf("rs= %d\n",rs);    

puts("-----------------------------------prog: 3------------------------------");
    rs = (a+b) * (c-d);
    puts("(a+b) * (c-d)");
    printf("rs= %d\n",rs);    

puts("-----------------------------------prog: 4------------------------------");
   rs = ((a+b) * (c-d)) / (a*(b+(c-d)*b));
   puts("((a+b) * (c-d))/(a*(b+(c-d)*b))");
    printf("rs= %d\n",rs);    

   return (0);
}