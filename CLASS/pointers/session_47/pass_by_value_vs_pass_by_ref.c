/* #include <stdio.h> 
#include <stdlib.h> 

void test_1(int m); 
void test_2(int* p); 

int main(void) 
{
    int n; 

    n = 100; 

    printf("main():VALUE(n)=%d, ADDRESS_OF_n=%p\n", n, &n); 
    printf("main():Before call to test_1():n=%d\n", n); 
    test_1(n);  /* Pass by Value */
    
/*    printf("main():After call to test_1():n=%d\n", n); 

    printf("main():Before call to test_2():n=%d, ADDR(n)=%p\n", 
            n, &n); 
    test_2(&n); /* Pass by reference */
  /*  printf("main():After call to test_2():n=%d\n", n); 

    return (0); 
} 

void test_1(int m)
{
    printf("test_1():VALUE(m)=%d, ADDRESS_OF_m=%p\n", m, &m); 
    m = 500; 
    printf("test_1():While returning m = %d\n", m); 
}

void test_2(int* p)
{
    printf("test_2():ADDRESS IN p = %p\n", p); 
    *p = 1000; 
}  */
   

   #include<stdio.h>

   void f1(char* a,unsigned char* b, short* c , unsigned short* d,int* e, unsigned int* f ,
           long* g, unsigned long* h, long long* i, unsigned long long* j,
            float* k, double* l );

          int main(void)
          {
            char c ='A';
            unsigned char uc1= 100;

            short sn  = -200;
            unsigned short usn = 500;

            int n = -12345;
            unsigned int un = 12345;

            long lng_n = -1234567;
            unsigned long u_lng_n = 1234567;

            long long lng_lng_n = -4567890;
            unsigned long long u_lng_lng_n = 4567890;

            float flt_1= -1.2345;
            double d1 = 1.2345;

            puts("BEFORE CALLS TO FUNCTIONS");
            printf("c=%c, uc1=%hhu, sn=%hd, usn=%hu, n=%d, un=%u, lng_n=%ld, u_lng_n= %lu\n"
             , c,uc1,sn, usn, n ,un , lng_n, u_lng_n);

             printf("lng_lng_n=%hhu, u_lng_lng_n=%llu, flt_1=%f, d1=%lf\n",
            lng_lng_n, u_lng_lng_n, flt_1,d1);

            f1(&c,&uc1,&sn,&usn,&n,&un,&lng_n,&u_lng_n,&lng_lng_n,&u_lng_lng_n,&flt_1,&d1);
          
            puts("AFTER CALLS TO FUNCTION\n");

            printf("c=%c, uc1=%hhu, sn=%hd, usn=%hu, n=%d, un=%u, lng_n=%ld, u_lng_n= %lu\n"
             , c,uc1,sn, usn, n ,un , lng_n, u_lng_n);

             printf("lng_lng_n=%hhu, u_lng_lng_n=%llu, flt_1=%f, d1=%lf\n",
            lng_lng_n, u_lng_lng_n, flt_1,d1);

            return (0);

          }  
   
   void f1(char* a,unsigned char* b, short* c , unsigned short* d,int* e, unsigned int* f ,
           long* g, unsigned long* h, long long* i, unsigned long long* j,
            float* k, double* l )
            {
                *a='z';
                *b=200;
                *c= 12345;
                *d= 678908;
                *e= 12345678;
                *f= 8765432;
                *g= -12345;
                *h= 8746323;
                *i= -1234543;
                *j= 4743793;
                *k= 3637.3783;
                *l= 1234567.654332;
            }