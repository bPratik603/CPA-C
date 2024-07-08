
#include"Date_1.h"

#ifndef NULL
#define NULL  ((void*)0)
#endif

int main()
{
    Date_t* p_date;

    p_date = set_date(15,12,2023);
    show_date(p_date);
    set_day(p_date,10);
    set_month(p_date,1);
    set_year(p_date,2000);

    show_date(p_date);

     destroy_date(&p_date);
     
    return(0);

}