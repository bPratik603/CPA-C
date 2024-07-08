int* ex_1()
{
    int n = 500; 
    return &n; 
}

void test_ex_1()
{
    int* p; 

    p = ex_1(); 
    /* p is a dangling pointer */
}

int* ex_2(void)
{
    int A[5] = {100, 200, 300, 400, 500}; 

    return A; 
}

void test_ex_2(void)
{
    int* p; 

    p = ex_2(); 
    /* p is a dangling pointer */
}