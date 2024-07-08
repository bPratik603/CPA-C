#include <stdio.h> 
#include <stdlib.h> 

int main(void) 
{
    void* p = NULL; 
}

/* 
    When did we get first introduced to void? 

    Function Declarations. 

    return_type function_name(formal parameter list); 

    Question: What should be the return type of function 
    if function does not return anything? 

    PLACEHOLDER KEYWORD WHICH IS TREATED AS A DATA TYPE 

    void is used. 

    void sort(int* p_arr, size_t N)
    {

    }

    void although treated as a data type cannot be used to create any real data 
    because sizeof(void) is not KNOWN. 

    void data_var;  // CTE 

    Cannot create instance of data type 'void' 
*/