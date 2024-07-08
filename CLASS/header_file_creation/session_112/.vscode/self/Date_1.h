#ifndef _DATE_H
#define _DATE_H

#define success                  1
#define INVALID_DATE             2
#define TRUE                     1
#define FALSE                    0

typedef int day_t;
typedef int month_t;
typedef int year_t;
typedef int status_t;
typedef struct Date Date_t;

struct Date
{
   day_t day;
   month_t month;
   year_t year;
};

extern Date_t* set_date(day_t init_day,month_t init_month,year_t init_year);
extern status_t set_day(Date_t* p_date,day_t new_day);
extern status_t set_month(Date_t* p_date,month_t new_month);
extern status_t set_year(Date_t* p_date,month_t new_year);

extern void destroy_date(Date_t** pp_date);
extern void show_date(Date_t* p_date);
extern status_t is_valid(day_t day,month_t month,year_t year);
#endif