#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "matrix.h"

mat2d* get_matrix(size_t M, size_t N){
    mat2d* m = NULL; 

    m = (mat2d*)malloc(sizeof(mat2d)); 
    if(m == NULL){
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    m->p = (int*)malloc(M * N * sizeof(int)); 
    if(m->p == NULL){
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    memset(m->p, 0, M * N * sizeof(int)); 
    m->M = M; 
    m->N = N; 

    return (m); 
} 

status_t add(mat2d* m1, mat2d* m2, mat2d** pp_mat_sum){
    mat2d* mat_sum = NULL; 
    size_t i, j; 

    if(m1->M != m2->M || m1->N != m2->N)
        return (MAT_DIMENSION_MISMATCH); 

    mat_sum = get_matrix(m1->M, m1->N); 

    for(i = 0; i < m1->M; ++i)
        for(j = 0; j < m1->N; ++j)
            *(mat_sum->p + i * mat_sum->N + j) = *(m1->p + i * m1->N + j) + 
                                                 *(m2->p + i * m2->N + j); 
    
    *pp_mat_sum = mat_sum; 
    return (SUCCESS); 
}

status_t sub(mat2d* m1, mat2d* m2, mat2d** pp_mat_sub){
    mat2d* mat_sub = NULL; 
    size_t i, j; 

    if(m1->M != m2->M || m1->N != m2->N)
        return (MAT_DIMENSION_MISMATCH); 

    mat_sub = get_matrix(m1->M, m1->N); 

    for(i = 0; i < m1->M; ++i)
        for(j = 0; j < m1->N; ++j)
            *(mat_sub->p + i * mat_sub->N + j) = *(m1->p + i * m1->N + j) -
                                                 *(m2->p + i * m2->N + j); 
    
    *pp_mat_sub = mat_sub; 
    return (SUCCESS); 
}

status_t get(mat2d* m, size_t row, size_t col, int* p_Dij)
{
    if(!(0 <= row && row < m->M) || !(0 <= col && col < m->N))
        return (MAT_INVALID_INDEX); 
    *p_Dij = *(m->p + row * m->N + col); 
    return (SUCCESS); 
}

status_t set(mat2d* m, size_t row, size_t col, int Dij)
{
    if(!(0 <= row && row < m->M) || !(0 <= col && col < m->N))
        return (MAT_INVALID_INDEX);  
    *(m->p + row * m->N + col) = Dij; 
    return (SUCCESS); 
}

void show(const char* msg, mat2d* m){
    size_t i, j; 

    if(msg)
        puts(msg); 

    for(i = 0; i < m->M; ++i)
        for(j = 0; j < m->N; ++j)
            printf("m[%llu][%llu]:%d\n", i, j, *(m->p + i * m->N + j)); 
}

void release_matrix(mat2d** pp_m){
    free((*pp_m)->p); 
    free(*pp_m); 
    *pp_m = NULL; 
}