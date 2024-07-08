#include <stdio.h> 
#include <stdlib.h> 

typedef long long int ssize_t; 

struct vector_str
{
    char** pp_str; 
    ssize_t N; 
}; 

struct vector_str* create_str_vector(void); 
void destroy_str_vector(struct vector_str* p_vec_str); 
void show(struct vector_str* p_vec_str, const char* msg); 

char* cpa_strdup(const char* src); 
ssize_t cpa_strlen(const char* src); 

void push_back(
                struct vector_str* p_vec_str, 
                char* new_str
            );

void push_front(
    struct vector_str* p_vec_str, 
    char* new_str
);

int main(void)
{
    struct vector_str* p_vec_str = NULL; 

    p_vec_str = create_str_vector(); 

    push_back(p_vec_str, "Hello"); 
    push_back(p_vec_str, "World"); 
    push_back(p_vec_str, "CoreCode"); 
    push_back(p_vec_str, "Programming"); 
    push_back(p_vec_str, "Academy"); 

    show(p_vec_str, "After pushing back few strings:"); 

    destroy_str_vector(p_vec_str); 
    p_vec_str = NULL; 

    return (0); 
}

void push_back(
        struct vector_str* p_vec_str, 
        char* new_str
    )
{
    p_vec_str->pp_str = (char**)realloc(
                                    p_vec_str->pp_str, 
                                    (p_vec_str->N + 1) * sizeof(char*)
                                ); 
    if(p_vec_str->pp_str == NULL)
    {
        puts("Error in resizing array"); 
        exit(EXIT_FAILURE); 
    }

    p_vec_str->N += 1; 
    p_vec_str->pp_str[p_vec_str->N - 1] = cpa_strdup(new_str); 
}

struct vector_str* create_str_vector(void)
{
    struct vector_str* p_vec_str = NULL;

    p_vec_str = (struct vector_str*)malloc(sizeof(struct vector_str)); 
    if(p_vec_str == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    p_vec_str->pp_str = NULL; 
    p_vec_str->N = 0; 

    return (p_vec_str); 
}

void show(struct vector_str* p_vec_str, const char* msg)
{
    ssize_t i; 

    if(msg)
        puts(msg); 

    for(i = 0; i < p_vec_str->N; ++i)
        printf("p_vec_str->pp_str[%lld]:%s\n", i, p_vec_str->pp_str[i]); 
}

void destroy_str_vector(struct vector_str* p_vec_str)
{
    ssize_t i; 

    for(i = 0; i < p_vec_str->N; ++i)
        free(p_vec_str->pp_str[i]); 
    
    free(p_vec_str->pp_str); 
    free(p_vec_str); 
}

char* cpa_strdup(const char* src)
{
    char* dest_str = NULL; 
    ssize_t src_len = 0; 
    ssize_t i; 

    src_len = cpa_strlen(src); 
    dest_str = (char*)malloc(src_len+1); 
    if(dest_str == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    dest_str[src_len] = '\0'; 
    for(i = 0; i < src_len; ++i)
        dest_str[i] = src[i]; 

    return (dest_str); 
}

ssize_t cpa_strlen(const char* src)
{
    ssize_t i; 
    ssize_t len; 

    len = 0; 
    i = 0; 
    while(src[i] != '\0')
    {
        ++len; 
        ++i; 
    }

    return (len); 
}

/* 
void test(void)
{
    FILE* fp = NULL; 
    struct vector_str* file_lines = NULL; 

    #define MAX_LINE_LEN    2048 
    static char line[MAX_LINE_LEN]; 

    file_lines = create_str_vector(); 
    fp = fopen("tmp.txt", "r"); 
    if(fp == NULL)
    {
        puts("Cannot open file in read mode"); 
        exit(EXIT_FAILURE); 
    }

    while(fgets(line, MAX_LINE_LEN, fp))
    {
        if(cpa_strlen(line) > 0)
            push_back(file_lines, line); 
    }

    // all lines in tmp.txt will be in file_lines vector 
}

*/
