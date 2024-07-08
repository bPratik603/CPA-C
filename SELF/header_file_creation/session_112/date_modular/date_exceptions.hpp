#ifndef _DATE_EXCEPTIONS_HPP
#define _DATE_EXCEPTIONS_HPP

#include <stdexcept> 

class invalid_date: public std::domain_error 
{
    public: 
        invalid_date(const char* msg) : std::domain_error(msg) 
        {
            
        }
}; 

#endif /* _DATE_EXCEPTIONS_HPP */