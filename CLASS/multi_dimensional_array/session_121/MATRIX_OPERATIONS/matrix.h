#ifndef _MATRIX_H 
#define _MATRIX_H 

#define SUCCESS 1 
#define TRUE    1 
#define FALSE   0 
#define MAT_DIMENSION_MISMATCH 2 
#define MAT_INVALID_INDEX 3 

typedef int status_t; 
typedef struct matrix_2d mat2d; 

struct matrix_2d{
    int* p; 
    size_t M;   /* Dimension 1 */
    size_t N;   /* Dimension 2 */
}; 

mat2d* get_matrix(size_t M, size_t N); 

status_t add(mat2d* m1, mat2d* m2, mat2d** pp_mat_sum); 
status_t sub(mat2d* m1, mat2d* m2, mat2d** pp_mat_sub); 
status_t get(mat2d* m, size_t row, size_t col, int* p_Dij); 
status_t set(mat2d* m, size_t row, size_t col, int Dij); 

void show(const char* msg, mat2d* m); 
void release_matrix(mat2d** pp_m); 

#endif 