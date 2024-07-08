void test(void)
{
    malloc(-1); 

    void* malloc(size_t); 
    void* malloc(unsigned long long int); 

    malloc(-1); 

    /* 
        1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 
        malloc(-1)
        malloc(2^64-1); 
    */

   /* 
    small negative numbers -> represent -> 2's complement
    -> bit pattern -> unsigned int. 

    Data Value: 
    Interpretation given to a bit pattern in the context of type! 

    1111 1111 -> 255 
    -1 
   */

}

