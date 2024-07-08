int *get_dynamically_allocated_integer()
{
    int* p = malloc(sizeof(int)); 
    assert(p != NULL); 
    return p; 
}

int get_int()
{
    return 100; 
}

void get_int(int *p)
{
    *p = 100; 
}

int* get_dynamic_int_1(void)
{
    int* p = 0; 

    p = malloc(sizeof(int)); 
    assert(p != NULL); // __LINE__ ANSI C

    /* C standard */
    printf("LINE NUMBER = %d\n", __LINE__); 
    printf("SRC = %s\n", __FILE__); 
    
    return (p); 
}

void caller(void)
{
    int* p = NULL; 

    p = get_dynamic_int_1(); 
    *p = 500; // user kar 

    free(p); 
}

/////////////////////////////

void get_dyanmic_int_2(int** pp)
{
    int* q = malloc(sizeof(int)); 

    *pp = q; 
}

void caller(void)
{
    int* p = NULL; 

    get_dynamic_int_2(&p); 

}


/* 
    MSDN : C COMPILER MSVC 
    GNU C COMPIER : USER MANUAL 
    GCC COMPLETE REFERENCE 1,2
*/
