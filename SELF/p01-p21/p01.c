#include<stdio.h>
#include<stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

void get_struct(struct Date*** pppDate,int* N);
void fill_struct(struct Date** ppDate,int N);
void show_struct(struct Date** ppDate,int N);
void release_struct(struct Date*** pppDate,int N);

int main()
{
    struct Date** ppDate = 0;
    int n = -1;

    get_struct(&ppDate,&n);
    fill_struct(ppDate,n);
    show_struct(ppDate,n);
    release_struct(&ppDate,n);

    return(0);

}

void get_struct(struct Date*** pppDate,int* N)
{
    struct Date** ppDate = 0;
    int n;
    int i;

    printf("Enter the size of struct:");
    scanf("%d",&n);

    ppDate = (struct Date**)malloc(n * sizeof(struct Date*));
    if(ppDate == 0)
    {
        puts("Error in allocating memory");
        exit(-1);
    }

    for(i=0;i<n;i++)
    {
        ppDate[i] = (struct Date*)malloc(sizeof(struct Date));
        if(ppDate[i] == 0)
        {
            puts("Error in allocating memory");
            exit(-1);
        }
    }

    *pppDate = ppDate;
    *N = n;
}

void fill_struct(struct Date** ppDate,int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        ppDate[i]->day = i+1;
        ppDate[i]->month = 10-i;
        ppDate[i]->year = 2015-i;
    }
}

void show_struct(struct Date** ppDate,int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("%d-%d-%d\n",ppDate[i]->day,ppDate[i]->month,ppDate[i]->year);
    }
}

void release_struct(struct Date*** pppDate,int N)
{
    struct Date** ppDate = 0;
    int i;

    ppDate = *pppDate;
    for(i=0;i<N;i++)
    {
        free(ppDate[i]);
        ppDate[i] = 0;
    }

    free(ppDate);
    ppDate = 0;

    *pppDate = 0;
}