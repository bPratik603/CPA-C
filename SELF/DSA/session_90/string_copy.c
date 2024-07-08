#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    char* str_1 = "Core Programming Academy"; 
    char* str_2 = NULL; 
    int len_str1 = 0; 
    int i; 

    i = 0; 
    while(str_1[i] != '\0')
    {
        len_str1 += 1; 
        i += 1; 
    }
    printf("len_str1 = %d\n", len_str1);

    str_2 = (char*)malloc(len_str1 + 1);
    if(str_2 == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    } 

    str_2[len_str1] = '\0'; 

    for(i = 0; i < len_str1; ++i)
        str_2[i] = str_1[i]; 

    printf("str_2 = %s\n", str_2); 

    free(str_2); 
    str_2 = NULL; 

    return (0); 
}

