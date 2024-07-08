#include <stdio.h>
#include<stdlib.h>
#include "sort.h"
#include "book.h"

struct Book bk_arr[5] = {
    {3, 300, 560.5}, 
    {1, 589, 600.0}, 
    {2, 150, 250.0}, 
    {1, 1000, 1250.5}, 
    {5, 1235, 1780.5}
};


int main(void)
{
    show("Before sort:",bk_arr,5);
    cpa_sort(bk_arr,5,sizeof(struct Book),compare_by_edition);
    show("After sort by pages:",bk_arr,5);
    cpa_sort(bk_arr,5,sizeof(struct Book),compare_by_pages);
    show("After sort by pages:",bk_arr,5);
    cpa_sort(bk_arr,5,sizeof(struct Book),compare_by_price);
    show("After sort by price",bk_arr,5);

    return(0);


}

void show(const char* msg,struct Book* book_arr,int N)
{
    int i;
    if(msg)
    {
        puts(msg);
    }

    for(i=0;i<N;++i)
    {
        printf("EDITION=%d\tNR_PAGES=%d\tPRICE=%.2lf\n",
               book_arr[i].bk_edition,
               book_arr[i].bk_nr_pages,
               book_arr[i].bk_price);
    }
}

int compare_by_edition(const struct Book* pb1,const struct Book* pb2)
{
    if(pb1->bk_edition > pb2->bk_edition)
    {
        return(1);
    }
    else if(pb1->bk_edition < pb2->bk_edition)
    {
        return(-1);
    }
    else
    {
        return(0);
    }
}

int compare_by_pages(const struct Book* pb1,const struct Book* pb2)
{
    if(pb1->bk_nr_pages > pb2->bk_nr_pages){
        return(1);
    }
    else if(pb1->bk_nr_pages < pb2->bk_nr_pages)
    {
        return(-1);
    }

    else
    {
        return(0);
    }
}

int comapre_by_price(const struct Book* pb1,const struct Book* pb2)
{
    if(pb1->bk_price > pb2->bk_price)
    {
        return(1);
    }
    else if(pb1->bk_price < pb2->bk_price)
    {
        return(-1);
    }
    else
    {
        return(0);
    }
}