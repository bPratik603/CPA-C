#include <stdio.h> 
#include <stdlib.h> 

struct Date
{
    int day; 
    int month; 
    int year; 
}; 

struct Date** allocate_array_of_pointer_to_struct_Date(int* pN); 
void initialise_date_instances(struct Date** ppDate, int N); 
void show_date_instances(struct Date** ppDate, int N); 
void release_date_instances_and_array(struct Date*** ppp_date, int N); 

int main(void)
{
    struct Date** ppDate = 0; 
    int N; 

    ppDate = allocate_array_of_pointer_to_struct_Date(&N); 
    initialise_date_instances(ppDate, N); 
    show_date_instances(ppDate, N); 
    release_date_instances_and_array(&ppDate, N); 

    return (0); 
}

struct Date** allocate_array_of_pointer_to_struct_Date(int* pN)
{
    struct Date** ppDate = 0; 
    int N; 
    int i; 

    printf("Enter length of array:"); 
    scanf("%d", &N); 

    if(N <= 0)
    {
        puts("Bad value for length of the array"); 
        exit(EXIT_FAILURE); 
    }

    ppDate = (struct Date**)malloc(N * sizeof(struct Date*)); 
    if(ppDate == 0)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < N; ++i)
    {
        ppDate[i] = (struct Date*)malloc(sizeof(struct Date)); 
        if(ppDate[i] == 0)
        {
            puts("Error in allocating memory"); 
            exit(EXIT_FAILURE); 
        }
    }

    *pN = N; 
    return (ppDate); 
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

void release_date_instances_and_array(struct Date*** ppp_date, int N)
{
    int i; 
    struct Date** ppDate = 0; 

    ppDate = *ppp_date; 
    for(i = 0; i < N; ++i)
    {
        free(ppDate[i]); 
        ppDate[i] = 0; 
    }

    free(ppDate); 
    ppDate = 0; 

    *ppp_date = 0; 
}