#include <stdio.h> 
#include <stdlib.h> 

typedef long long int ssize_t; 

char* join(char** pp_str, ssize_t N, char* join_str); 
void test_join(void); 
ssize_t cpa_strlen(const char* src); 

int main(void)
{
    test_join(); 
    return (0); 
}

char* join(char** pp_str, ssize_t N, char* join_str)
{
    char* result = NULL; 
    ssize_t len_join_str; 
    ssize_t len_curr_str; 
    ssize_t len_result_str = 0; 
    ssize_t old_len; 
    ssize_t i; 
    ssize_t k; 

    len_join_str = cpa_strlen(join_str); 
    if(len_join_str == 0)
    {
        puts("Invalid join string"); 
        exit(EXIT_FAILURE); 
    }

    len_result_str = 0; 
    for(i = 0; i < N-1; ++i)
    {
        len_curr_str = cpa_strlen(pp_str[i]); 
        result = (char*)realloc(
            result, 
            len_result_str + len_curr_str + len_join_str
        ); 
        if(result == NULL)
        {
            puts("Failed to resize a string"); 
            exit(EXIT_FAILURE); 
        }
        old_len = len_result_str; 
        len_result_str += (len_curr_str + len_join_str); 

        for(k = 0; k < len_curr_str; ++k)
            result[old_len + k] = pp_str[i][k]; 
        for(k = 0; k < len_join_str; ++k)
            result[old_len + len_curr_str + k] = join_str[k];    
    }

    len_curr_str = cpa_strlen(pp_str[i]); 
    result = (char*)realloc(result, len_result_str + len_curr_str + 1); 
    if(result == NULL)
    {
        puts("Error in resizing string"); 
        exit(EXIT_FAILURE); 
    }
    old_len = len_result_str; 
    len_result_str += (len_curr_str); 
    for(k = 0; k < len_curr_str; ++k)
        result[old_len + k] = pp_str[i][k]; 
    result[old_len + k] = '\0'; 

    return (result); 
}

void test_join(void) 
{
    char* strings[] = {
        "CoreCode", 
        "Programming", 
        "Academy"
    }; 

    char* join_str = "#$#";
    char* result = NULL; 

    result = join(strings, 3, join_str); 
    printf("result = %s\n", result); 
    /* 
        Expected result: 
        CoreCode#$#Programming#$#Academy#$#Yogeshwar#$#Shukla
    */

   free(result); 
   result = NULL; 
}

ssize_t cpa_strlen(const char* src)
{
    ssize_t i; 
    ssize_t len; 

    len = 0; 
    i = 0; 
    while(src[i] != '\0')
    {
        ++i; 
        ++len; 
    }

    return len; 
}

/* 
    Double subscript: 

    char a[N]; 

    a[i];   // a is array of len N of char 
    
    (expr)[i];  // expr should be array of some type T 


    pp_str: pointer: contains the base address of array of char* 

    pp_str is eligible for subscript 

    pp_str[i] -> you are accessing an element of array of char* 

    pp_str[i] -> char* -> stores base addr of array of char 

    pp_str[i] -> eligible for subscript 

    (pp_str[i])[k]; 

    pp_str[i][k]; 

*/