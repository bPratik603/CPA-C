char c1; 
unsigned char uc1; 

short s_num; 
unsigned short us_num; 

int i_num; 
unsigned int u_num; 

long l_num; 
unsigned long ul_num; 

long long ll_num; 
unsigned long long ull_num; 

float f; 
double d; 
long double lng_d; 

/////////////////////////////////////

char *p_char; 
unsigned char *p_uchar; 

short* p_short; 
unsigned short* p_ushort; 

int* p_int; 
unsigned int* p_uint; 

long* p_lng; 
unsigned long* p_ulng; 

long long* p_llng; 
unsigned long long* p_ullng; 

float* p_float;             /* WINDOWS */
double * p_dbl;             /* NOBODY's STYLE */
long double *p_lng_dbl;     /* LINUX / K&R */


int main(void)
{
    p_char = &c1; 
    p_uchar = &uc1; 

    p_short = &s_num; 
    p_ushort = &us_num; 

    p_int = &i_num; 
    p_uint = &u_num; 

    p_lng = &l_num; 
    p_ulng = &ul_num; 

    p_llng = &ll_num; 
    p_ullng = &ull_num; 

    p_float = &f; 
    p_dbl = &d; 
    p_lng_dbl = &lng_d; 

    *p_int = 500;   /* Using pointer to write on pointee */ 
    int m; 
    m = *p_int;     /* Using pointer to read from pointee */
    return (0); 
}

/* 
    PRINCE 
    PRINCESS 

    VILLAIN -> DEMON -> MAGIC 

    DOLL -> 

    Pointer 
    Pointee 

    Employer 
    Employee

    Mentor 
    Mentee 

    a*b; 

    * 
        -> BINARY 
        -> INFIX 
        
    *p 
        -> UNARY 
        -> PREFIX

    DE-REFERENCE OPERATOR 

*/

/* 
    int n, m; 
    int* p; 
    p = &n;

    *p = 100; 
    m = *p; 

    Let M[1000:1003] -> n 
        M[1004:1007] -> m 

        M[2000:2007] -> p 

        p = &n;     M[2000:2007] <- 1000 

        *p = 100; 

        RHS -> No evalulation needed. 100 

        it is assigned to *p 

        Applying de-reference operator on pointer 
        == 
        Bringing out address stored inside it. 
        M[2000:2007] -> address -> BRING OUT 

        M[1000] --> Step 1: Bringing out address stored inside poitner 

        Step 2: Decide the operation to be performed on it. 
                Possible operations
                (i) read (ii) write (iii) execute / call / transfer the control 

                How to decide? 

                *p is on RHS then read from pointee. 
                *p is on LHS then write on pointee. 

                In our case *p = 100; 
                *p is on LHS and therefore, we are going to WRITE (MODIFY)
                M[1000]

        Step 3: How many bytes from address should be used to perform 
                read / write operation? 

                Refer to the type of pointee. 
                int* p;

                M[1000:1000+sizeof(pointee)-1]

                M[ADDR IN PTR : ADDR IN PTR + SIZEOF(POINTEE)-1]

                M[1000:1003] <- 100 

        m = *p; 

        1) RHS 
            *p 

            Bring out address in p 
            Bring out address in M[2000:2007]
            Comes out to be 1000. 

        2) Decide operation (R/W)
            Ans: Read 
            Why? because *p is in ON RHS 

        3) How many bytes from M[1000] should be used to read 

            M[ADDR IN PTR : ADDR IN PTR + sizeof(POINTEE) - 1]
            M[1000:1000+sizeof(int)-1]
            M[1000:1000+4-1]
            M[1000:1003]

            Therefore, read M[1000:1003]

        2) LHS 
            m -> M[1004:1007]

            M[1004:1007] <- M[1000:1003]
            [
                R <- M[1000:1003]
                M[1004:1007] <- R 
            ]


    EXERCISE 1     

    short p, q; 
    short* x; 

    x=&p; 
    *x = 500; 
    q = *x; 

    EXERCISE 2 

    double x, y; 
    double* p_dbl; 

    p_dbl = &y; 
    *p_dbl = 1.1415; 
    x = *p_dbl; 
*/

