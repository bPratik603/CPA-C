#ifndef _BOOK_H
#define _BOOK_H

struct Book
{
    int bk_edition;
    int bk_nr_pages;
    double bk_price;
};

extern void show(struct Book* arr,int N,const char* msg);

#endif 