struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

struct A 
{

    struct B
    {
        unsigned char arr[24]; 
    }inB; 
}inA;

unsigned char arr[12]; 

int main(void)
{
    void* p1, *p2; 

    p1 =  &inA.inB.arr[12]; 
    p2 = arr; 

    ((struct Date*)p1)->day; 
    ((struct Date*)p1)->month; 
    ((struct Date*)p1)->year; 

    ((struct Date*)p2)->day; 
    ((struct Date*)p2)->month; 
    ((struct Date*)p2)->year; 
}

/* 
    N byte block -> malloc(), data type instance 

    define a data type whose length is N bytes. 

    struct T 
    {
        // desirable layout 
    }; 

    sizeof(struct T) == N bytes 

    void* p = N byte block base addressl 

    ((struct T*)p)->mem in struct T 

*/