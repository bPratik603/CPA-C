#include<stdio.h>
#include"Date_1.h"

Date_t* set_date(day_t init_day,month_t init_month,year_t init_year)
{
    Date_t* p_date;

    if(is_valid(init_day,init_month,init_year) == FALSE)
    {
        return(NULL);
    }

    p_date = (Date_t*)malloc(sizeof(Date_t));

    p_date->day = init_day;
    p_date->month = init_month;
    p_date->year = init_year;

    return(p_date);
}

status_t set_day(Date_t* p_date,day_t new_day)
{
    if(is_valid(new_day,p_date->month,p_date->year) == FALSE)
    {
        return(FALSE);
    }

    p_date->day = new_day;
    return(success);
}

status_t set_month(Date_t* p_date,month_t new_month)
{
    if(is_valid(p_date->day,new_month,p_date->year) == FALSE)
    {
        return(FALSE);
    }

    p_date->month = new_month;

    return(success);
}

status_t set_year(Date_t* p_date,year_t new_year)
{
    if(is_valid(p_date->day,p_date->month,new_year) == FALSE)
    {
           return(FALSE);
    }
}



void show_date(Date_t* p_date)
{
    printf("%d-%d-%d\n",p_date->day,p_date->month,p_date->year);
}


void destroy_date(Date_t** pp_date)
{
    free(*pp_date);
    *pp_date = 0;
}

status_t is_valid(day_t day,month_t month,year_t year)
{
    if(day < 1 && day > 31)
    {
        return(FALSE);
    }

    if(month < 1 && month > 12)
    {
        return(FALSE);
    }

    if(year < 1)
    {
        return(FALSE);
    }

    return(success);
}