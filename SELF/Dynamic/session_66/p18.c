#include <stdio.h> 
#include <stdlib.h> 

struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

int main(void)
{
    /* d_arr is array N of pointer to struct Date */
    int N = 5; 
    struct Date *d_arr[5] = {0, 0, 0, 0, 0}; 
    int i; 

    // allocate five instances of struct Date using malloc() 
    // and store their address in array N of pointers to struct Date 
    for(i = 0; i < N; ++i)
    {
        d_arr[i] = (struct Date*)malloc(sizeof(struct Date));
        if(d_arr[i] == 0)
        {
            puts("Error in allocating memory"); 
            exit(EXIT_FAILURE); 
        }
    }

    // write some day,month,year values on instances of 
    // struct Date 
    for(i = 0; i < N; ++i)
    {
        d_arr[i]->day = 10 + i; 
        d_arr[i]->month = 12-i; 
        d_arr[i]->year = 2021 + i; 
    }

    // print all date instances 
    for(i = 0; i < N; ++i)
    {
        printf("DATE INSTANCE %d : %d-%d-%d\n", 
                i, 
                d_arr[i]->day, 
                d_arr[i]->month, 
                d_arr[i]->year
            ); 
    }

    // release all data instances 
    for(i = 0; i < N; ++i)
    {
        free(d_arr[i]); 
        d_arr[i] = 0; 
    }
    
    return (0); 
}

/* 
    d_arr is array N of pointer to struct Date 

    struct Date* d_arr[N]; 

    d_arr[i] (where 0 <= i < N) is struct Date* 
    *d_arr[i] is struct Date 

    (*d_arr[i]).day         ==  d_arr[i]->day
    (*d_arr[i]).month       ==  d_arr[i]->month 
    (*d_arr[i]).year        ==  d_arr[i]->year

    (*pDate).day    == pDate->day

    for(i = 0; i < N; ++i)
    {
        d_arr[i]->day
        d_arr[i]->month 
        d_arr[i]->year
    }

*/