#define N1  5   /* Replace 5 by any positive integer of your choice */
#define N2  3   /* Replace 3 by any positive integer of your choice */

int a[N1][N2];  /* where N1 > 0 and N2 > 0 and N1 and N2 are integers */

void read(void)
{
    /* read all elements of array */
    int i, j; 
    int curr_element; 

    for(i = 0; i < N1; ++i)
        for(j = 0; j < N2; ++j)
            curr_element = a[i][j]; 
}

void write(void)
{
    /* write : summation of indices on each element */
    int i, j; 

    for(i = 0; i < N1; ++i)
        for(j = 0; j < N2; ++j)
            a[i][j] = i + j; 
}