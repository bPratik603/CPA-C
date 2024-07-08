/* 
    Let s be a string of N characters. 
    Create dyanamically allocated substring s1 
    such that s1 contains only those characters 
    which have appeared more than twice in s. 

    Version 1: Case sensitive 
    Version 2: Case insensitive

    S1: abackjhfabnmb
    S2: abAckjhfAbnmb

    In case-sensitive version, 
        in case of S2, 'a' will not be counted 
    In case in-sensitive version 
        in case of S2, 'a' will be counted.
*/

#include <stdio.h> 
#include <stdlib.h> 

size_t cpa_strlen(const char* s); 
void get_substring(const char* s, size_t N, char** pp_str, size_t* pN_output); 

int main(void)
{
    char* s = NULL; 
    size_t s_len; 

    char* s_multi = NULL; 
    size_t s_multi_len = 0; 

    s = "abcaabbdefgccekoieertuwwwwqkgg"; 
    s_len = cpa_strlen(s); 

    /* 
        after returning from function s_multi in main() 
        should contain a string of all characters appearning 
        more than two times in s. 

        s_multi_len should contain a length of string pointed by s_multi. 
    */    
    get_substring(s, s_len, &s_multi, &s_multi_len); 
    printf("s_multi = %s\n", s_multi); 
    printf("s_multi_len = %llu\n", s_multi_len); 
    
    free(s_multi); 
    s_multi = NULL; 

    return (0); 
}

void get_substring(const char* s, size_t N, char** pp_str, size_t* pN_output)
{
    size_t i;   /* Index to go through all characters of s*/
    size_t k;   /* Index to move from 0 to i-1 to check if 
                    current character has encountered for the 
                    first time or was it encountered before */
    size_t repeat_count; /* Number of times the current character appears in s*/
    char* s_output = NULL; /* Pointer to output string */
    size_t N_output = 0;   /* Length of output string */
    size_t k_output = 0; /* index cariable in output string */

    for(i = 0; i < N; ++i)
    {
        for(k = 0; k < i; ++k)
            if(s[k] == s[i])
                break; 
        
        if(k < i)
            continue; 

        repeat_count = 0; 
        for(k = i; k < N; ++k)
            if(s[k] == s[i])
                ++repeat_count; 

        if(repeat_count > 2)
            N_output++; 
    }

    s_output = (char*)malloc(sizeof(char) * N_output + 1); 
    if(s_output == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }
    
    s_output[N_output] = '\0'; 

    for(i = 0; i < N; ++i)
    {
        for(k = 0; k < i; ++k)
            if(s[k] == s[i])
                break; 
        
        if(k < i)
            continue; 

        repeat_count = 0; 
        for(k = i; k < N; ++k)
            if(s[k] == s[i])
                ++repeat_count; 

        if(repeat_count > 2)
        {
            s_output[k_output] = s[i]; 
            k_output++; 
        }
    } 

    *pp_str = s_output; 
    *pN_output = N_output; 
}

size_t cpa_strlen(const char* s)
{
    size_t i; 

    i = 0; 
    while(s[i] != '\0')
        ++i; 

    return (i); 
}