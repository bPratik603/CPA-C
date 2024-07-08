/* 
    Rule of pointer variable. 

    If pointer variable p is a pointer to type T
    then you must store base address of instance of 
    type T in p. (any other address = meaning address 
    which is not a base address of some instance of type T 
    is not a valid address to be placed in p)

    struct A 
    {
        int a; 
        char b; 
        float c; 
    }; 

    struct B 
    {
        int c; 
        double d_arr[5]; 
    }; 

    struct B inB; 
    struct B* pB = &inB; // ok Assume that base address of inB is 20000. 
    pointer to any data type is 8 bytes long in 64 bit machines. 
    Therefore, pointer is able to store any address in range of 
    0 to 2 ^ 64 - 1. 
    Because virtual address space itself is limited to 2 ^ 48 we CAN STORE 
    ANY ADDRESS in pointer p and it will fit in p. 

    struct A* pA = &inB; 

    // struct B* cannot be implicitly converted into struct A*  

    struct A* pA = (struct A*)&inB; 

    pA->c will compute the offset of 'c' with respect to struct A 
    but that offset will be applied to instance of struct B. 

    Therefore, such unrestrained (=विधीनिषेधशून्य) type casting is ALWAYS BAD! 

    char -> char* 
    int -> int* 
    double -> double* 
    struct Date -> struct Date* 

    TYPE *p;

    char c; 
    char* p = &c; 
    char* p = "hello"; 
    char* p = address of data type; 

    p + 0, p + N - 1 

    char* p; 

    void f(char* p)
    {

    }

    void* p; 

    struct A* p; 

    void n; 

    p = &n;

    void* p = RHS; // RHS is pointer to T where T is any data type.  

    void* p = RHS; 
    // RULE 

*/ 
