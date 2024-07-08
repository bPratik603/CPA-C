struct A 
{
    int a;      // 0 
    char b;     // 4 
    float c;    // 8 
    char d;     // 12 
}; 

/* 
    [P  ]   [P  ]   [P  ]   [  ] d 
    [  ]    [  ]    [  ]    [  ] c 
    [ P ]   [ P ]   [ P ]   [  ] b 
    [  ]    [  ]    [  ]    [  ] a 
*/

struct B 
{
    int a;      //  4 
    float b;    //  4 
    char c, d;  //  4 
}; 

/* 
    [ P]    [ P]    [  ]d   [  ] c 
    [  ]    [  ]    [  ]    [  ] b 
    [  ]    [  ]    [  ]    [  ] a 
*/

struct C 
{
    unsigned long long val; 
    int num;
    char c1, c2; 
}; 

/* 
    [P  ][P  ][ c2][ c1 ][   ][   ][   ][   ] num
    [   ][   ][   ][   ][   ][   ][   ][   ] val 
*/

struct D 
{
    int i; 
    long long j; 
}; 

int main(void)
{
    printf("Sizeof(struct A)=%llu\n", sizeof(struct A)); 
    printf("Sizeof(struct B)=%llu\n", sizeof(struct B)); 
    printf("Sizeof(struct C)=%llu\n", sizeof(struct C)); 
    printf("Sizeof(struct D)=%llu\n", sizeof(struct D)); 

    return (0); 
}

