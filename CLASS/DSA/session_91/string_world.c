#include <stdio.h> 
#include <stdlib.h> 

void test_1(void); 
void test_2(void); 

char* callee_1(int* pN); 
void caller_1(void); 

char** callee_2(int* pN); 
void caller_2(void); 

void callee_3(char*** ppp_str, int* pN); 
void caller_3(void); 

void cpa_strcpy(char* dest, const char* src); 

int main(void)
{
    test_1(); 
    caller_1(); 
    test_2(); 
    caller_2(); 
    caller_3(); 
    return (0); 
}

void test_1(void)
{
    char a[6] = {'H', 'e', 'l', 'l', 'o', '\0'}; 
    int i; 

    for(i = 0; i < 5; ++i)
        printf("a[%d]:%c\n", i, a[i]); 

    /* 
        type(a) == type(&a[0]) == char* 
        char* pa; 

        char* pa = a; 
    */

   char* pa = a; 
   for(i = 0; i < 5; ++i)
        printf("pa[%d]:%c\n", i, pa[i]); 
}

void caller_1(void)
{
    char* p_string = NULL; 
    int str_len = 0; 
    int i; 

    p_string = callee_1(&str_len); 
    for(i = 0; i < str_len; ++i)
        printf("p_string[%d]:%c\n", i, p_string[i]); 

    free(p_string); 
    p_string = NULL; 
}

char* callee_1(int* pN)
{
    int N = 5; 
    char* p_str = NULL; 

    p_str = (char*)malloc(N+1); 
    if(p_str == NULL)
    {
        puts("Error"); 
        exit(-1); 
    }

    p_str[0] = 'H'; 
    p_str[1] = 'e'; 
    p_str[2] = 'l'; 
    p_str[3] = 'l'; 
    p_str[4] = 'o'; 
    p_str[5] = '\0'; 

    *pN = 5; 
    return (p_str); 
}

void test_2(void)
{
    int i; 
    char** pp_str = NULL; 

    char *pchar_arr[5] = 
    {
        "abc", 
        "pqrst", 
        "lm", 
        "uvwsz", 
        "xyz"
    }; 

    puts("In test_2()"); 
    for(i = 0; i < 5; ++i)
        printf("pchar_arr[%d]:%s\n", i, pchar_arr[i]); 

    /* 
        type(pchar_arr) == type(&pchar_arr[0]) == char** 
    */

   pp_str = pchar_arr; 
   /* 
    pp_str[0] == addr('a')
    pp_str[1] == addr('p')
    pp_str[2] == addr('l')
    pp_str[3] == addr('u')
    pp_str[4] == addr('x')
   */
  for(i = 0; i < 5; ++i)
    printf("pp_str[%d]:%s\n", i, pp_str[i]); 
}

/* 
             0     1     2     3     4
pchar_arr    [    ][    ][    ][    ][    ]
             char* char* char* char* char*

pchar_arr[0] == char*
pchar_arr[1] == char* 
pchar_arr[2] == char* 
pchar_arr[3] == char* 
pchar_arr[4] == char* 

type(pp_str) == char** 
type(pp_str[i]) == char* 
type(*pp_str[i]) == char
*/
void caller_2(void)
{
    char** pp_str_of_caller = NULL; 
    int N = -1; 
    int i; 

    pp_str_of_caller = callee_2(&N); 
    puts("CALLER 2"); 
    for(i = 0; i < N; ++i)
        printf("pp_str_of_caller[%d]:%s\n", i, 
                pp_str_of_caller[i]); 

    for(i = 0; i < N; ++i)
        free(pp_str_of_caller[i]); 

    free(pp_str_of_caller); 
    pp_str_of_caller = NULL; 
}


char** callee_2(int* pN)
{
    char** pp_str = NULL; 
    int i; 
    int sizes[5] = {4, 6, 3, 6, 4}; 

    pp_str = (char**)malloc(5 * sizeof(char*)); 
    if(pp_str == NULL)
    {
        puts("error"); 
        exit(-1); 
    }

    for(i = 0; i < 5; ++i)
    {
        pp_str[i] = (char*)malloc(sizes[i] * sizeof(char)); 
        if(pp_str[i] == NULL)
        {
            puts("error"); 
            exit(-1); 
        }
    } 

    cpa_strcpy(pp_str[0], "abc"); 
    cpa_strcpy(pp_str[1], "pqrst");
    cpa_strcpy(pp_str[2], "lm");
    cpa_strcpy(pp_str[3], "uvwsz");
    cpa_strcpy(pp_str[4], "xyz");

    *pN = 5; 
    return (pp_str); 

}


void callee_3(char*** ppp_str, int* pN)
{
    char** pp_str = NULL; 
    int i; 
    int sizes[5] = {4, 6, 3, 6, 4}; 

    pp_str = (char**)malloc(5 * sizeof(char*)); 
    if(pp_str == NULL)
    {
        puts("error"); 
        exit(-1); 
    }

    for(i = 0; i < 5; ++i)
    {
        pp_str[i] = (char*)malloc(sizes[i] * sizeof(char)); 
        if(pp_str[i] == NULL)
        {
            puts("error"); 
            exit(-1); 
        }
    } 

    cpa_strcpy(pp_str[0], "abc"); 
    cpa_strcpy(pp_str[1], "pqrst");
    cpa_strcpy(pp_str[2], "lm");
    cpa_strcpy(pp_str[3], "uvwsz");
    cpa_strcpy(pp_str[4], "xyz");

    *pN = 5; 
    *ppp_str = pp_str;  
}

void caller_3(void)
{
    char** pp_str_of_caller = NULL; 
    int N = -1; 
    int i; 

    callee_3(&pp_str_of_caller, &N); 
    puts("CALLER 3");

    for(i = 0; i < N; ++i)
        printf("pp_str_of_caller[%d]:%s\n", i, 
                pp_str_of_caller[i]); 

    for(i = 0; i < N; ++i)
        free(pp_str_of_caller[i]); 

    free(pp_str_of_caller); 
    pp_str_of_caller = NULL;    
}

void cpa_strcpy(char* dest, const char* src)
{
    int i; 
    for(i = 0; src[i] != '\0'; ++i) 
        dest[i] = src[i]; 

    dest[i] = src[i]; 
}

/* 
    156; 

    156 -> literal integer constant 

    int n; integer variable 

    char msg[6]; // character array variable

    "abcefg" -> literal string constant 

    puts("Hello,World"); 

    scanf("%d", &n); 

    printf("num = %d, fnum = %.3f", num, fnum); 
*/

