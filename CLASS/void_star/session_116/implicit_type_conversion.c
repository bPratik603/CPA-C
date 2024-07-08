int main(void) 
{
    int n; 

    n = 'A'; 

    // type(rhs) == type('A') == char 
    // type(lhs) == type(n) == int 

    n = (int)'A'; 

    // 0x41
    // 0x00 00 00 41

    // = 'A'; 

    float x; 

    x = 'A'; 

    // x = (float)'A'; 
    // 65 -> st(0) -> 65.0

    // 0100 0001 -> char -> 'A'
    // 0100 0001 -> int  -> 65 
    // 0100 0001 -> float -> 65.0 

    int n; 
    float f; 

    struct Date {int day, month, year; } myDateInstance; 

    void* p; 

    
    p = &n; 
    p = &f; 
    p = &myDateInstance; 

    struct A* pA = &n; 

    void* p = &n; 

    *p = 100; 

}


void test()
{
    void* p; 
    int n = 0x1a2b3c4d; 

    p = &n; 
    *(int*)p = 500; 
    n = 0x1a2b3c4d;
    *(char*)p = 0xff; 
    n = 0x1a2b3c4d;
    *(short*)p = 0xa0b0; 

}