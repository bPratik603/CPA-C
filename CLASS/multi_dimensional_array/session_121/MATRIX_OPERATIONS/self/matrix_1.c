#include<stdio.h>
#include<stdlib.h>
#include "matrix_1.h"
#include<string.h>

mat2d* get_matrix(size_t M,size_t N)
{
    mat2d* arr = NULL;

    arr = (mat2d*)malloc(sizeof(mat2d*));

    arr->p = (int*)malloc(M * N * sizeof(int));

    memset(arr->p,0,M * N * sizeof(int));
    arr->M = M;
    arr->N = N;

    return(arr);
}

status_t set(mat2d* m,size_t col,size_t row,int Dij)
{
    if(!(0 <= row && row < m->M) || !(0 <= col && col< m->N))
    {
        return(MAT_INVALID_INDEX);
    }

    *(m->p + row * m->N + col) = Dij;
    return(success);
}

status_t add(mat2d* m1,mat2d* m2,mat2d** pp_mat_sum)
{
    mat2d* mat_sum = NULL;
    size_t i,j;

    if(m1->M != m2->M || m1->N != m2->N)
    {
        return(MAT_DIMENSION_MISMATCH);
    }

    mat_sum = get_matrix(m1->M,m1->N);

    for(i=0;i<m1->M;i++)
    {
        for(j=0;j<m1->N;j++)
        {
            *(mat_sum->p + i * mat_sum->N + j) = *(m1->p + i * m1->N + j) + 
                                                 *(m2->p + i * m2->N + j);
        }
    }

    *pp_mat_sum = mat_sum;

    return(success);
}

status_t sub(mat2d* m1,mat2d* m2,mat2d** pp_mat_sub)
{
    mat2d* mat_sub = NULL;
    size_t i,j;

    if(m1->M != m2->M || m1->N != m2->N)
    {
        return(MAT_INVALID_INDEX);
    }

    mat_sub = get_matrix(m1->M,m1->N);

    for(i=0;m1->M;i++)
    {
        for(j=0;j<m1->N;j++)
        {
            *(mat_sub->p + i * mat_sub->N + j) = *(m1->p + i * m1->N + j) + 
                                                  *(m2->p + i * m2->N + j);
        }
    }

    *pp_mat_sub = mat_sub;

    return(success);
}

void show(const char* msg,mat2d* m1)
{
    size_t i,j;
    puts(msg);
    for(i=0;i<m1->M;i++)
    {
        for(j=0;j<m1->N;j++)
        {
            printf("arr[%d][%d]: %d\n",i,j,*(m1->p + i * m1->N + j));
        }
    }
}