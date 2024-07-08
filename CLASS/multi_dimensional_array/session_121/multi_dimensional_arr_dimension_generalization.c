#include <stdio.h> 
#include <stdlib.h> 

void carve_2d_arr(int* p, size_t N); 
void carve_3d_arr(int* p, size_t N); 

int main(void){
    size_t N = 80; 
    int* p = NULL; 
    size_t i; 

    p = (int*)malloc(N * sizeof(int)); 
    if(p == NULL){
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < N; ++i)
        *(p + i) = (i+1); 

    carve_2d_arr(p, N); 
    carve_3d_arr(p, N); 

    free(p); 
    p = NULL; 

    return (EXIT_SUCCESS); 
}

void carve_2d_arr(int* p, size_t N)
{
    size_t M=10, N=8; 
    size_t i, j; 

    for(i = 0; i < M; ++i)
        for(j = 0; j < N; ++j)
            printf("M[%llu][%llu] = %d\n", i, j, *(p + i * N + j)); 
}

void carve_3d_arr(int* p, size_t N)
{
    size_t DN1 = 4, DN2 = 5, DN3 = 4; 
    size_t i, j, k; 

    for(i = 0; i < DN1; ++i)
        for(j = 0; j < DN2; ++j)
            for(k = 0; k < DN3; ++k)
                printf("M[%llu][%llu][%llu] = %d\n", i, j, k, 
                    *(p + i * DN2 * DN3 + j * DN3 + k)
                ); 
}

// 1cm 3km/h 

//  