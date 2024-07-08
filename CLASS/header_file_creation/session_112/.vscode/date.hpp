/* Guard of header file */
#ifndef _DATE_HPP 
#define _DATE_HPP

#include "date_exceptions.hpp"

const int SUCCESS = 1; 

using day_t=int; 
using month_t=int; 
using year_t=int; 

class Date 
{
    private: 
        day_t day; 
        month_t month; 
        year_t year; 
        static bool is_date_valid(day_t, month_t, year_t); 

    public: 
        Date(day_t, month_t, year_t); 
        Date(); 
        day_t get_month() const; 
        month_t get_month() const; 
        year_t get_year() const; 
        void set_day(day_t); 
        void set_month(month_t); 
        void set_year(year_t); 
        friend std::ostream& operator<<(std::ostream& os, const Date& date_object); 
}; 

#endif /* _DATE_H */