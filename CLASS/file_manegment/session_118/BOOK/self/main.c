#include<stdio.h>
#include<stdlib.h>
#include"book_1.h"
#include"sort_1.h"


struct Book bk_arr[5] = {
    {3, 300, 560.5}, 
    {1, 589, 600.0}, 
    {2, 150, 250.0}, 
    {1, 1000, 1250.5}, 
    {5, 1235, 1780.5}
}; 

int compare_by_bk_edition(const struct Book* bk1,const struct Book* bk2);
int compare_by_bk_nr_pages(const struct Book* bk1,const struct Book* bk2);
int compare_by_bk_price(const struct Book* bk1,const struct Book* bk2);


int main()
{
    show(bk_arr,5,"Before sort");
    cpa_sort(bk_arr,5,sizeof(struct Book),compare_by_bk_edition);
    show(bk_arr,5,"After sort by book edition");
    cpa_sort(bk_arr,5,sizeof(struct Book),compare_by_bk_nr_pages);
    show(bk_arr,5,"After sort by book nr pages");
    cpa_sort(bk_arr,5,sizeof(struct Book),compare_by_bk_price);
    show(bk_arr,5,"After sort by book price");

    return(0);
}





int compare_by_bk_edition(const struct Book* bk1,const struct Book* bk2)
{
    if(bk1->bk_edition > bk1->bk_edition)
    {
        return(1);
    }
    else if(bk1->bk_edition < bk2->bk_edition)
    {
        return(0);
    }
    else
    {
        return(1);
    }
}

int compare_by_bk_nr_pages(const struct Book* bk1,const struct Book* bk2)
{
    if(bk1->bk_nr_pages > bk2->bk_nr_pages)
    {
        return(1);
    }
    else if(bk1->bk_nr_pages < bk2->bk_nr_pages)
    {
        return(0);
    }
    else
    {
        return(-1);
    }
}

int compare_by_bk_price(const struct Book* bk1,const struct Book* bk2)
{
     if(bk1->bk_price > bk2->bk_price)
    {
        return(1);
    }
    else if(bk1->bk_price < bk2->bk_price)
    {
        return(0);
    }
    else
    {
        return(-1);
    }
}

void show(struct Book* arr,int N,const char* msg)
{
    int i;
    puts(msg);

    for(i=0;i<N;i++)
    {
        printf("%d-%d-%2.lf\n",arr[i].bk_edition,arr[i].bk_nr_pages,arr[i].bk_price);
    }
}