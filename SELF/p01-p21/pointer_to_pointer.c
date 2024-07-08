#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int n = 100; 
    int m = 200; 
    
    int* p1 = 0; 
    int* p2 = 0; 

    int** pp = 0; 

    p1 = &n; 
    p2 = &m; 

    pp = &p1; 

    printf("Before:**pp = -100:n = %d\n", n); 
    **pp = -100; 
    printf("After:**pp = -100:n=%d\n", n); 

    printf("Before:*pp = &m:pp = %p, *p1 = %d\n", pp, *p1); 
    *pp = &m; //*pp = *p1
    printf("After:*pp = &m:pp = %p, *p1 = %d\n", pp, *p1); 

    return (0); 
}

/* 
    BIRTHDAY PARTY : FRIEND 

    HALL : DOOR : 

    int n = 10;
    n;  

    INDIRECTION 
    PROFESSOR : RETIREMENT CEREMONY 
    GIFT WRAP 
    int* p; 
    *GIFT WRAP == PRESENT 

    NEPHEW / NIECE 
    PRESET = GIFT WRAP = CUPBOARD LOCKER 
    int n  = int* p    = int** pp 

    GIFT_WRAP = &PRESENT; 
    p=&n; 

    CUPBOARD_LOCKER = &GIFT_WRAP; 
    pp = &p; 

    *pp == p 

    *CUPBOARD_LOCKER == GIFT_WRAP 

    *GIFT_WRAP == PRESENT 

    *p == n 

    **pp 

    **CUPBOARD_LOCKER = PRESENT 

    **pp == n 
    ----------------------------------------------
    n is of the type int. 
    
    To create a block of memory capable of holding 
    address of n is 
    int* p;

    Now it is possible to generalise above process 
    further (upto any level)

    Can you create a block of memory ( = 8 bytes )
    capable of holding the address of pointer to int 

    int** pp; 
    pp is a pointer to pointer to int

    p = &n; 
    pp = &p; 

    Type system wise analysis 

    type(n) == int 
    type(&n) == int* 

    RHS == &n 
    LHS == must be of type int* 

    int* p = &n; 

    int* p; 

    type(p) == int* 
    type(&p) == int** 

    Therefore, if you want &p on RHS 
    then LHS must be of type int** 

    int** pp = &p; 

    --------------------------------------

    assuming p contains address of n. 
    to access (=read/write) n through p, 

    *p is used. 

    int* p; 

    type(*p) == int 
    and therefore, *p on RHS reads from n 
    *p on LHS writes on in 

    Assuming p contains address of n 
    and pp contains address of p. 

    int** pp; 
    type(**pp) == int 

    Using **pp on RHS will read from n 
    Using **pp on LHS will write on n 

    int **pp; 

    type(pp) == int** 
    type(**pp) == int 

    type(*pp) == int* 

    threfore, 

    Using *pp on RHS will read from p 
    (address in p can fetched by using *pp on RHS)

    *pp on LHS will write on p
    (address in p can be used using *pp on LHS 
    i.e you can make p point to some other integer 
    by puting *pp on LHS)

    (to which integer p is currently pointing to 
    can be known by using *pp on RHS)

*/

// Full year 2006 
//------------------
// 2007,08
// Nov 08
// Nov 09 
// Jan 2010 
// Jan 2010 

// 2010-Sep 11 INDIA  12-16, 20
// Sept 13 to Dec 14    

//  Jan 2015 
//  CPA 
//  2015, 2016, 2017, 2018, 2019, 2020 COVID
//  NO HOLIDAY 
//  55 hours BOLAYCH 
//  Mon Fri : morning 1, evening 2 
//  Sat: 8am to 8pm -> 12x2=24
//  52 -> abhyas, katta, 
//  July 2020
//  105 CHL
//  NE

//  50K + TECHNOLOGY
//  1L 
//  1-1.5L