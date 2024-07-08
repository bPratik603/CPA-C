#include <stdio.h> 
#include <stdlib.h> 

struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

/* pDate is an IN parameter */
void show_date(struct Date* pDate); 

int main(void)
{
    struct Date exam_date = {1, 2, 2023}; 
    struct Date* p_result_date = 0; 

    p_result_date = (struct Date*)malloc(sizeof(struct Date)); 
    if(p_result_date == 0)
    {
        puts("Error in memory allocation"); 
        exit(-1); 
    }
    
    p_result_date->day = 30; 
    p_result_date->month = 3; 
    p_result_date->year = 2023; 

    show_date(&exam_date); 
    show_date(p_result_date); 

    free(p_result_date); 
    p_result_date = 0; 

    return (0); 
}

void show_date(struct Date* pDate)
{
    printf("%d-%d-%d\n", pDate->day, pDate->month, pDate->year); 
}