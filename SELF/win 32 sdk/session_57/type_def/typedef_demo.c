#include <stdio.h> 

typedef int day_t; 
typedef int month_t; 
typedef int year_t; 

struct Date 
{
    day_t day; 
    month_t month; 
    year_t year; 
}; 

typedef struct Date Date_t; 

int main(void)
{
    Date_t my_exam_date; 
    day_t exam_day; 
    month_t exam_month; 
    year_t exam_year; 

    my_exam_date.day = 1; 
    my_exam_date.month = 4; 
    my_exam_date.year = 2022; 

    exam_day = my_exam_date.day; 
    exam_month = my_exam_date.month; 
    exam_year = my_exam_date.year; 

    printf("EXAM DATE:%d-%d-%d\n", exam_day, exam_month, exam_year); 

    return (0); 
}

