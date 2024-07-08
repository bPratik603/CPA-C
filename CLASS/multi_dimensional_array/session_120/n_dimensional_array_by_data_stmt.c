/* 
    Using data definition statement we can deal with N dimensional arrays: 
    provided: 
    i) Total number of dimensions: 
        such as 2D, 3D, 7D, 13D 
        is known at compile time 
        (i.e. dimension of array should be available NUMERICALLY 
        while writing source code)

    ii) Magnitude of each dimension should be known NUMERICALLY 
        at the time of writing source code. 
*/

/* Lets write 5D array */

#define N1  4 
#define N2  2 
#define N3  5 
#define N4  7 
#define N5  3 


int a[N1][N2][N3][N4][N5]; 
/* 
    Scientific reading: 
    a is array N1 of array N2 of array N3 of array N4 of array N5 of int 
*/

/* 
addr(a[i1]) = base addr (a) + i1 * sizeof(int) * N2 * N3 * N4 * N5, i1=0,1,2,3,...,N1-1
addr(a[i1][i2]) = base addr (a) + i1 * sizeof(int) * N2 * N3 * N4 * N5 + 
                  i2 * N3 * N4 * N5 (0<=i1<N1, 0<=i2<N2)
addr(a[i1][i2][i3]) == base addr (a) + i1 * sizeof(int) * N2 * N3 * N4 * N5 + 
                        i2 * sizeof(int) * N3 * N4 * N5 + i3 * sizeof(int) * N4 * N5 
                        (0<=i1<N1, 0<=i2<N2, 0<=i3<N3) 
addr(a[i1][i2][i3][i4]) ==  base addr (a) + i1 * sizeof(int) * N2 * N3 * N4 * N5 + 
                        i2  * sizeof(int) *  N3 * N4 * N5 + i3 * sizeof(int) * N4 * N5 + 
                        i4 * sizeof(int) * N5 
                        (0<=i1<N1, 0<=i2<N2, 0<=i3<N3, 0<=i4<N4) 
addr(a[i1][i2][i3][i4][i5]) ==  base addr (a) + i1 * sizeof(int) * N2 * N3 * N4 * N5 + 
                        i2 *  sizeof(int) * N3 * N4 * N5 + i3 * sizeof(int) * N4 * N5 + 
                        i4 * sizeof(int) * N5 + i5 * sizeof(int)
                        (0<=i1<N1, 0<=i2<N2, 0<=i3<N3, 0<=i4<N4, 0<=i5<N5) 



*/

