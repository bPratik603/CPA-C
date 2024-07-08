#include <stdio.h>  /* PREPROCESSOR DIRECTIVE */
#include <stdlib.h> /* PREPROCESSOR DIRECTIVE */

#define ARR_SIZE    5 
#define EPOCH_DAY   1 
#define EPOCH_MONTH 1 
#define EPOCH_YEAR  1970 

int arr[ARR_SIZE]; 

struct Date 
{
    int day; 
    int month; 
    int year; 
} epoch_date = {EPOCH_DAY, EPOCH_MONTH, EPOCH_YEAR}; 

int main(void)
{

    return (EXIT_SUCCESS); 
}
