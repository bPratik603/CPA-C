#include <stdio.h> 
#include <stdlib.h> 

#define SUCCESS 1 

typedef int status_t; 

struct vector_str
{
    char** pp_str; 
    size_t N; 
}; 

struct create_vector_str* create_vector(void)
{
    return (struct vector_str*)calloc(1, sizeof(struct vector_str)); 
}

void destroy_vector_str(struct vector_str** pp_vec_str)
{
    struct vector_str* p_vec_str = *pp_vec_str; 
    size_t i; 

    for(i = 0; i < p_vec_str->N; ++i)
        free(p_vec_str->pp_str[i]); 
    free(p_vec_str); 
    *pp_vec_str = NULL; 
}

status_t push_back(struct vector_str* p_vec_str, char* new_str)
{
    p_vec_str->pp_str = (char**)realloc(p_vec_str->pp_str, (p_vec_str->N+1) * sizeof(char*)); 
    assert(p_vec_str->pp_str != NULL); 
    p_vec_str->N += 1; 
    p_vec_str->pp_str[p_vec_str->N-1] = new_str; 
    return (SUCCESS); 
}