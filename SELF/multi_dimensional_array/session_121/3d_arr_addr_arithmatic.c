/* 
    int a[N1][N2][N3]; 
    size_t i, j, k; 

    int* p = (int*)malloc(N1 * N2 * N3 * sizeof(int)); 
    if(p == NULL){
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < N1; ++i)
        for(j = 0; j < N2; ++j)
            for(k = 0; k < N3; ++k)
                *(p + i * N2 * N3 + j * N3 + k) // == a[i][j][k]
*/ 