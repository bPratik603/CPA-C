/* 
    int a[10]; 
    type(a) = type(&a[0]) = int* 

    // 1 
    T A[N]; 
    type(A) = type(&A[0]) = T* 

    // 2 
    T A[N]; 
    type(A) == type(&A[0]) == T* 

    // 3 
    T A[N]; 
    type(A) == type(&A[0]) == T* 

    // 4 
    T A[N]; 
    type(A) == type(&A[0]) == T* 

    // 5 
    T A[N]; 
    type(A) == type(&A[0]) == T* 
*/

void test_1(void); 

int main(void)
{
    test_1(); 
    return (0); 
}

void test_1(void)
{
    int a[5]; 
    int* pa; 

    /* 
        type(a) == type(&a[0]) == int* 
        type(pa) == int* ... given by programmer 

        pa = a; // is valid 
    */

   pa = a; 

   // pa[i] accesses ith element of array 

   int* b[5]; 
   /* 
        b is array 5 of pointers to integer. 
        size of array = 5 
        array element type = int* 

        type(b) == type(&b[0]) == int** 
        int** ppb; 
        type(ppb) == int** ... giveb by programmer 

        ppb = b; 

        ppb[0] == int* 
        ppb[1] == int* 
        ppb[2] == int* 
        ppb[3] == int* 
        ppb[4] == int* 
   */
}


