#include <stdio.h> 
#include <stdlib.h> 

struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

void initialise_date_instances(struct Date** ppDate, int N); 
void show_date_instances(struct Date** ppDate, int N); 

int main(void)
{
    int N = 5; 
    struct Date** ppDate = 0; 
    int i; 
    
    ppDate = (struct Date**)malloc(N * sizeof(struct Date*)); 
    if(ppDate == 0)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < 5; ++i)
    {
        ppDate[i] = (struct Date*)malloc(sizeof(struct Date)); 
        if(ppDate[i] == 0)
        {
            puts("Error in allocating memory"); 
            exit(EXIT_FAILURE); 
        }
    }

    initialise_date_instances(ppDate, N); 
    show_date_instances(ppDate, N); 

    //release all instances of struct Date first 
    for(i = 0; i < N; ++i)
    {
        free(ppDate[i]); 
        ppDate[i] = 0; 
    }

    // free array of pointer to struct Date* 
    free(ppDate); 
    ppDate = 0; 

    return (0); 
}

void initialise_date_instances(struct Date** ppDate, int N)
{
    int i; 
    for(i = 0; i < N; ++i)
    {
        ppDate[i]->day = 10 + i; 
        ppDate[i]->month = 12-i; 
        ppDate[i]->year = 2021 + i; 
    }
}

void show_date_instances(struct Date** ppDate, int N)
{
    int i; 

    for(i = 0; i < N; ++i)
    {
        printf("DATE INSTANCE %d : %d-%d-%d\n", 
                i, 
                ppDate[i]->day, 
                ppDate[i]->month, 
                ppDate[i]->year
            ); 
    }
}

/* 
    struct Date* d_arr[5]; 
    struct Date**  p = d_arr; 

*/