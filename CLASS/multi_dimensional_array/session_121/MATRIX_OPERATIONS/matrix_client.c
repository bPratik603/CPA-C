#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#include "matrix.h" 

int main(void){
    mat2d* m1 = NULL; 
    mat2d* m2 = NULL; 
    mat2d* mat_sum = NULL; 
    mat2d* mat_sub = NULL; 
    size_t M = 6, N = 4; 
    size_t i, j; 
    status_t status; 

    m1 = get_matrix(M, N); 
    m2 = get_matrix(M, N); 

    for(i = 0; i < M; ++i)
        for(j = 0; j < N; ++j){
            set(m1, i, j, i + j); 
            set(m2, i, j, i * j); 
        }

    status = add(m1, m2, &mat_sum); 
    status = sub(m1, m2, &mat_sub); 

    show("m1:", m1); 
    show("m2:", m2); 
    show("Sum:", mat_sum); 
    show("Sub:", mat_sub); 

    release_matrix(&m1); 
    release_matrix(&m2);
    release_matrix(&mat_sum); 
    release_matrix(&mat_sub); 

    return (EXIT_SUCCESS); 
}