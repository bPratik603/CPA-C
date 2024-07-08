#include <stdio.h> 
#include <stdlib.h> 

typedef long long int ssize_t; 

ssize_t cpa_strlen(const char* src); 
ssize_t cpa_substr_index(const char* target_str, const char* sub_str); 
void test_cpa_substr_index(void); 

/* 
    Returns: 
        Index of first char of sub_str in target_str if sub_str is indeed a substring of target_string 
        -1 otherwise 
*/

/* 
    len(sub_str) == N 

    There should exist an index i such that 

    target_str[i:i+N-1] == sub_str[0:N-1]
*/

int main(void)
{
    test_cpa_substr_index(); 
    return (0); 
}


ssize_t cpa_substr_index(const char* target_str, const char* sub_str)
{
    ssize_t i; 
    ssize_t k; 
    ssize_t len_target_str; 
    ssize_t len_sub_str; 
    
    len_target_str = cpa_strlen(target_str); 
    len_sub_str = cpa_strlen(sub_str); 
    for(i = 0; i <= len_target_str - len_sub_str; ++i)
    {
        for(k = 0; k < len_sub_str; ++k)
            if(target_str[i+k] != sub_str[k])
                break; 
        if(k == len_sub_str)
            return (i); 
    }

    return (-1); 
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

void test_cpa_substr_index(void)
{
    char* target = "aaBBBBaaBBBBCCCCCCaaBBBX"; 
    char* sub_str_1 = "ABC"; 
    char* sub_str_2 = "aa"; 
    char* sub_str_3 = "CCC"; 
    char* sub_str_4 = "aaBBBX";
    ssize_t i; 

    i = cpa_substr_index(target, sub_str_1); 
    if(i == -1)
        printf("%s is not substring of %s\n", sub_str_1, target); 
    else 
        printf("%s is substr of %s at index %lld\n", sub_str_1, target, i); 

    i = cpa_substr_index(target, sub_str_2); 
    if(i == -1)
        printf("%s is not substring of %s\n", sub_str_2, target); 
    else 
        printf("%s is substr of %s at index %lld\n", sub_str_2, target, i); 

    i = cpa_substr_index(target, sub_str_3); 
    if(i == -1)
        printf("%s is not substring of %s\n", sub_str_3, target); 
    else 
        printf("%s is substr of %s at index %lld\n", sub_str_3, target, i); 

    i = cpa_substr_index(target, sub_str_4); 
    if(i == -1)
        printf("%s is not substring of %s\n", sub_str_4, target); 
    else 
        printf("%s is substr of %s at index %lld\n", sub_str_4, target, i); 
}

