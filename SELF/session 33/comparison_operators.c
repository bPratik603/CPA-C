#include<stdio.h>
#include<stdlib.h>
int main(void)
{

int n1=100;
int n2=50;
int rs;

 rs=(n1>n2);
 printf("rs =%d\n",rs);

 rs=(n1>=n2);
 printf("rs=%d\n",rs);

 rs=(n1<rs);
 printf("rs=%d\n",rs);

 rs=(n1<=n2);
 printf("rs=%d\n",rs);

 rs=(n1==n2);
 printf("rs=%d\n",rs);

rs=(n1!=n2);
printf("rs=%d\n",rs);

exit(0);
}