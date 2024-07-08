/* 
    Let N1 and N2 be integers whose value may be determined at run time. 
    if we want to create an array, with these dimensions, then we need 
    something like below 

    T a[N1][N2];  // T is some defined data type

    We know that variable expressions N1 and N2 will generate compile time error. 
    Therefore, data definition statement is not the way to achieve this. 

    But it serves as a useful reminder to know what is the final goal. 

    Step 1 : Compute the size: N1 * N2 * sizeof(T)
    Step 2 : Define a pointer to T. 
             T* pT = NULL; 
    Step 3: Allocate Memory: 

    T* pT = (T*)malloc(N1 * N2 * sizeof(T)); 
    if(pT == NULL){
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    Step 4: Define index variables, one for each dimension: 
    int i;  // Index variable for dimension 1, 0 <= i < N1 
    int j;  // Index variable for dimension 2, 0 <= j < N2 

    Step 5: Figure out address arithmetic for reach to each element of array. 

    int a[5][3]; 

    a is array 5 of array 3 of ints. 

    addr(a[i]) = Base addr (a) + i * sizeof(int [3]) 
               = Base addr (a) + i * 3 * sizeof(int) 

    addr(a[i][j]) = Base addr (a[i]) + j * sizeof(int) 
                  = Base addr (a) + i * 3 * sizeof(int) + j * sizeof(int)

    for(i = 0; i < 5; ++i)
        for(j = 0; j < 3; ++j)
            Base addr (a) + i * 3 * sizeof(int) + j * sizeof(int)

    addr(a[i]) = (a + i * sizeof(int))

    &a[i] == base addr (a) + i * sizeof(int)

    a + i

    &a[i] == a + i
    *(&a[i]) == *(a+i)
    a[i] == *(a+i) 


    int* p 

    p + i == p + i * sizeof(int)

    int a[N1][N2]; 

    &a[i][j] (Mathematically) == Base addr (a) + i * N2 * sizeof(int) + j * sizeof(int)
    where 0 <= i < N1, 0 <= j < N2

    &a[i][j] == Base addr(a) + i * N2 + j 

    *(&a[i][j]) = *(Base addr(a) + i * N2 + j) 

    Repeating the code from above steps:

    // Goal : To emulate T a[N1][N2]; where N1 and N2 are variables. 

    T* pT = NULL; 

    pT = (T*)malloc(N1 * N2 * sizeof(T)); 
    if(pT==NULL){
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    int i, j; 

    for(i = 0; i < N1; ++i)
        for(j = 0; j < N2; ++j)
            *(pT + i * N2 + j)      // == a[i][j]

    int** pp = NULL; 
    (*arr)[4][3];

    int *p = 0; 

    p + 1 == 0 + 1 * sizeof(int)

    pT + i * N2 + j 

    (Let K = i * N2 + j)

    pT + K = ADDRESS IN pT + K * sizeof(T)
           = ADDRESS IN pT + (i * N2 + j) * sizeof(T)
           
*/