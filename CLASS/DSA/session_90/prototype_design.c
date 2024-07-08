#include <stdio.h> 
#include <stdlib.h> 

/* unsigned long long int -> size_t */

///////////////////////////////////////////////////////////////////////
///// strlen() start 
/* 
    Calculate the length of the string. 
    Input: 
        1) Pointer to string whose length must be computed. 
    Output: 
        1) Length of the string (size_t = because we are using 
            64 bit environment )
*/

/* Option 1: Output via return value: */
size_t cpa_strlen_1(const char* msg); 

/* Implementation */
size_t cpa_strlen_1(const char* msg)
{
    size_t len = 0; 
    size_t i; 

    for(i = 0; msg[i] != '\0'; ++i)
        ++len; 

    return (len); 
}

/* Option 2: Output via parameter (or parameterized return value) */
void cpa_strlen_2(const char* msg, size_t* p_len); 

/* Implementation */
void cpa_strlen_2(const char* msg, size_t* p_len)
{
    size_t len = 0; 
    size_t i; 

    for(i = 0; msg[i] != '\0'; ++i)
        ++len; 

    *p_len = len; 
}
///////////////////////////////////////////////////////////////////////
/////strlen finish 

///////////////////////////////////////////////////////////////////////
/////strcpy start 

/* 
    Copy a source string into a destionation string. 
    Input: 
        1) Source string
    Output: 
        1) Destination string
    
    Variation factors: 
        1) Who should allocated memory for destination string? 
        2) How output should be given to client? 
            a) Via return mechanism
            b) Via parameter 
*/

/* 
    Preconditions: 
        1)  src string is delimited by '\0' 
        2)  dest pointer holds character array 
            whose length is at least as long as 
            length(src) + 1 
        Caller is allocating memory. 
        Output is available via parameter (pass by reference)
*/
void cpa_strcpy_1(char* dest, const char* src); 

/* Implementation */
void cpa_strcpy_1(char* dest, const char* src)
{
    size_t i; 
    while(src[i] != '\0')
    {
        dest[i] = src[i]; 
        ++i; 
    }

    dest[i] = '\0'; 
}

/* 
    The callee, i.e., cpa_strcpy_2 should allocate memory for destination 
    string and the pointer to destination string is returned via return 
    value mechanism 
*/
char* cpa_strcpy_2(const char* src); 

/* Implementation */

char* cpa_strcpy_2(const char* src)
{
    char* dest = NULL; 
    size_t i; 
    size_t N; 

    N = cpa_strlen_1(src); 

    dest = (char*)malloc(N+1); 
    if(dest == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    dest[N] = '\0'; 

    for(i = 0; src[i] != '\0'; ++i)
        dest[i] = src[i]; 

    return (dest); 
}

/* 
    Let callee, i.e. cpa_strcpy_3() allocate memory for 
    destination string and return it via parameter. 
*/

void cpa_strcpy_3(const char* src, char** pp_dest_str); 

/* Implementation */

void cpa_strcpy_3(const char* src, char** pp_dest_str)
{
    char* dest = NULL; 
    size_t i; 
    size_t N; 

    N = cpa_strlen_1(src); 

    dest = (char*)malloc(N+1); 
    if(dest == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    dest[N] = '\0'; 

    for(i = 0; src[i] != '\0'; ++i)
        dest[i] = src[i];    

    *pp_dest_str = dest; 
}

///////////////////////////////////////////////////////////////////////
/////strcpy finish 

///////////////////////////////////////////////////////////////////////
/////strcat start : 3 

/* 
    Preconditions: 
        1) src1 is delimited by '\0' 
        2) src2 is delimited by '\0' 
        3) Dest pointer holds adress of character array 
            whose length is at least as long as 
            len(src1) + len(src2) + 1 
*/
void cpa_strcat_1(char* dest, const char* src1, const char* src2); 

/* Implementation */

void cpa_strcat_1(char* dest, const char* src1, const char* src2)
{
    size_t N1 = cpa_strlen_1(src1); 
    cpa_strcpy_1(dest, src1); 
    cpa_strcpy_1(dest+N1, src2); 
}

/* 
    Precondition: 
        1) src1 and src2 are delimited by '\0' 
    Postcondition: 
        2) A new dynamically allocated string is returned 
            by return value mechanism, 
            returned string is a concatenated version of 
            src1 and src2 
*/
char* cpa_strcat_2(const char* src1, const char* src2); 

/* Implementation */

char* cpa_strcat_2(const char* src1, const char* src2)
{
    char* dest_str = NULL; 
    size_t N1 = cpa_strlen_1(src1); 
    size_t N2 = cpa_strlen_1(src2); 

    dest_str = (char*)malloc(N1+N2+1); 
    if(dest_str == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    cpa_strcpy_1(dest_str, src1); 
    cpa_strcpy_1(dest_str + N1, src2); 

    return (dest_str); 
}

/* 
    Precondition: 
        1) src1 and src2 are delimited by '\0' 
    Postcondition: 
        2) A new dynamically allocated string is returned 
            by parameter (or parameterized return value)
            returned string is a concatenated version of 
            src1 and src2 
*/

void cpa_strcat_3(const char* src1, const char* src2, char** pp_dest_str); 

/* Implementation */

void cpa_strcat_3(const char* src1, const char* src2, char** pp_dest_str)
{
    char* dest_str = NULL; 
    size_t N1 = cpa_strlen_1(src1); 
    size_t N2 = cpa_strlen_1(src2); 

    dest_str = (char*)malloc(N1+N2+1); 
    if(dest_str == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    cpa_strcpy_1(dest_str, src1); 
    cpa_strcpy_1(dest_str + N1, src2); 

    *pp_dest_str = dest_str; 
}

///////////////////////////////////////////////////////////////////////
/////strcat finish 