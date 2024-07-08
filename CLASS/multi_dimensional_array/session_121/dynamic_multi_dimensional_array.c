#include <stdio.h> 
#include <stdlib.h> 

void matrix_M_N(void); 

int main(void){
    matrix_M_N(); 
    return (EXIT_SUCCESS); 
}

void matrix_M_N(void)
{
    size_t M, N; 
    int* pM = NULL; 
    size_t i, j; 

    printf("Enter the number of rows of Matrix:"); 
    scanf("%llu", &M); 

    printf("Enter the number of cols of Matrix:"); 
    scanf("%llu", &N); 

    pM = (int*)malloc(M * N * sizeof(int)); 
    if(pM == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < M; ++i)
        for(j = 0; j < N; ++j)
            *(pM + i * N + j) = i + j; 

    for(i = 0; i < M; ++i)
        for(j = 0; j < N; ++j)
            printf("Matrix[%llu][%llu] == %d\n", i, j, *(pM + i * N + j)); 

    free(pM); 
    pM = NULL; 
}

/* 
    int a[5][3]; 

    int a[N1][N2];


*/

