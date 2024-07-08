#ifndef _MATRIX_H
#define _MATRIX_H

#define success                1
#define TRUE                   1
#define FALSE                  0
#define MAT_DIMENSION_MISMATCH 2
#define MAT_INVALID_INDEX      3

typedef int status_t;
typedef struct matrix_2d mat2d;

struct matrix_2d
{
    int* p;
    size_t M;
    size_t N;
};

extern mat2d* get_matrix(size_t M,size_t N);
extern status_t set(mat2d* m,size_t col,size_t row,int Dij);
extern status_t add(mat2d* m1,mat2d* m2,mat2d** pp_mat_sum);
extern status_t sub(mat2d* m1,mat2d* m2,mat2d** pp_mat_sub);

extern void show(const char* msg,mat2d* m1);

#endif