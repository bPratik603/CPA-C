#include <stdio.h> 
#include <stdlib.h> 

// 1 
struct Date
{
    int day; 
    int month; 
    int year; 
}; 

// 2 
struct Date
{
    int day; 
    int month; 
    int year; 
}; 

//3 
struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

// 4 
struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

// 5 
struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

// 1 
struct Date* get_date_instance_1(int init_day, int init_month, int init_year)
{
    struct Date* pDate = NULL; 

    pDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(pDate == NULL)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    pDate->day = init_day; 
    pDate->month = init_month; 
    pDate->year = init_year; 

    return (pDate); 
}

//2 
struct Date* get_date_instance_1(int init_day, int init_month, int init_year)
{
    struct Date* pDate = NULL; 

    pDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(pDate == NULL)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    pDate->day = init_day; 
    pDate->month = init_month; 
    pDate->year = init_year; 

    return (pDate); 
}

//3 
struct Date* get_date_instance_1(int init_day, int init_month, int init_year)
{
    struct Date* pDate = NULL; 

    pDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(pDate == NULL)
    {
        puts("error"); 
        exit(EXIT_FAILURE); 
    }

    pDate->day = init_day; 
    pDate->month = init_month; 
    pDate->year = init_year; 

    return (pDate); 
}

// 4 
struct Date* get_date_instance_1(int init_day, int init_month, int init_year)
{
    struct Date* pDate = NULL; 

    pDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(pDate == NULL)
    {
        puts("error"); 
        exit(EXIT_FAILURE); 
    }

    pDate->day = init_day; 
    pDate->month = init_month; 
    pDate->year = init_year; 

    return (pDate); 
}

// 5 
struct Date* get_date_instance_1(int init_day, int init_month, int init_year)
{
    struct Date* pDate = NULL; 

    pDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(pDate == NULL)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    pDate->day = init_day; 
    pDate->month = init_month; 
    pDate->year = init_year; 

    return (pDate); 
}

// 1 
void get_date_instance_1_caller(void)
{
    struct Date* p = NULL; 

    p = get_date_instance_1(1, 3, 1999); 
    printf("%d-%d-%d\n", p->day, p->month, p->year); 
    free(p); 
    p = NULL; 
}

//2 
voidate(void)
{
    struct Date* p = NULL; 

    p = get_date_instance_1(15, 8, 1947); 
    printf("%d-%d-%d\n", p->day, p->month, p->year); 
    free(p); 
    p = NULL; 
}

//3 
voidate(void)
{
    struct Date* pDate = NULL; 

    pDate = get_date_instance_1(3, 4, 1932); 
    printf("%d-%d-%d\n", pDate->day, pDate->month, pDate->year); 
    free(pDate); 
    pDate = NULL;     
}

// 4 
voidate(void)
{
    struct Date* p = NULL; 

    p  = get_date_instance_1(23, 4, 2020); 
    printf("%d-%d-%d\n", p->day, p->month, p->year); 
    free(p); 
    p = NULL; 
}

// 5 
voidate(void)
{
    struct Date* p = NULL; 

    p = get_date_instance_1(12, 4, 2023); 
    printf("%d-%d-%d\n", p->day, p->month, p->year); 
    free(p); 
    p = NULL; 
}

////////////////////////////////////////////////////////////////////////////////

// 1 
void get_date_instance_2(struct Date** ppDate, int init_day, int init_month, int init_year)
{
    struct Date* pDate = NULL; 

    pDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(pDate == NULL)
    {
        puts("error"); 
        exit(EXIT_FAILURE); 
    }

    pDate->day = init_day; 
    pDate->month = init_month; 
    pDate->year = init_year; 

    *ppDate = pDate; 
}

// 2 
void get_date_instance_2(struct Date** ppDate, int init_day, int init_month, int init_year)
{
    struct Date* pDate = NULL; 

    pDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(pDate == NULL)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    pDate->day = init_day; 
    pDate->month = init_month; 
    pDate->year = init_year; 

    *ppDate = pDate; 
}

// 3 
void get_date_instance_3(struct Date** ppDate, int init_day, int init_month, int init_year)
{
    struct Date* pDate = NULL; 

    pDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(pDate == NULL)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    pDate->day = init_day; 
    pDate->month = init_month; 
    pDate->year = init_year; 

    *ppDate = pDate; 
}

//4 
void get_date_instance_2(struct Date** ppDate, int init_day, int init_month, int init_year)
{
    struct Date* pDate = NULL; 

    pDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(pDate == NULL)
    {
        puts("error"); 
        exit(EXIT_FAILURE); 
    }
    pDate->day = init_day; 
    pDate->month = init_month; 
    pDate->year = init_year; 

    *ppDate = pDate; 
}

// 5 
void get_date_instance_2(struct Date** ppDate, int init_day, int init_month, int init_year)
{
    struct Date* pDate = NULL; 

    pDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(pDate == NULL)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    pDate->day = init_day; 
    pDate->month = init_month; 
    pDate->year = init_year; 

    *ppDate = pDate; 
}

// 1 
void caller_of_get_day_instance_2(void)
{
    struct Date* pDate = NULL; 

    get_date_instance_2(&pDate, 1, 1, 1970); 
    printf("%d-%d-%d\n", pDate->day, pDate->month, pDate->year); 
    free(pDate); 
    pDate = NULL; 
}

// 2 
void caller_of_get_day_instance_2(void)
{
    struct Date* pDate = NULL; 

    get_day_instance_2(&pDate, 1, 1, 1970); 
    printf("%d-%d-%d\n", pDate->day, pDate->month, pDate->year); 
    free(pDate); 
    pDate = NULL; 
}

// 3 
void caller_of_get_date_instance_2(void)
{
    struct Date* pDate = NULL; 

    get_date_instance_2(&pDate, 1, 1, 1970); 
    printf("%d-%d-%d\n", pDate->day, pDate->month, pDate->year); 
    free(pDate); 
    pDate = NULL; 
}

// 4 
void caller_of_get_date_instance_2(void)
{
    struct Date* pDate = NULL; 

    get_date_instance_2(&pDate, 1, 1, 1970); 
    printf("%d-%d-%d\n", pDate->day, pDate->month, pDate->year); 
    free(pDate); 
    pDate = NULL; 
}

// 5 
void caller_of_get_date_instance_2(void)
{
    struct Date* pDate = NULL; 

    get_date_instance_2(&pDate, 1, 1, 1970); 
    printf("%d-%d-%d\n", pDate->day, pDate->month, pDate->year); 
    free(pDate); 
    pDate = NULL; 
}

/////////////////////////////////////////////////////////////////////////
// 1

struct Date* get_date_array_1(int* pN)
{
    struct Date* pDate = NULL; 
    int N; 
    int i; 

    printf("Enter N:"); 
    scanf("%d", &N); 

    if(N <= 0)
    {
        puts("bad size for array"); 
        exit(EXIT_FAILURE); 
    }

    pDate = (struct Date*)malloc(N * sizeof(struct Date)); 
    if(pDate == NULL)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < N; ++i)
    {
        pDate[i].day = 1; 
        pDate[i].month = 1; 
        pDate[i].year = 1970; 
    }

    *pN = N; 
    return (pDate); 
}

// 2 
struct Date* get_date_array_1(int* pN)
{
    struct Date* pDate = NULL; 
    int N; 
    int i; 

    printf("Enter N"); 
    scanf("%d", &N); 

    if(N <= 0)
    {
        puts("error"); 
        exit(EXIT_FAILURE); 
    }

    pDate = (struct Date*)malloc(N * sizeof(struct Date)); 
    if(pDate == NULL)
    {
        puts("error"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < N; ++i)
    {
        pDate[i].day = 1; 
        pDate[i].month = 1; 
        pDate[i].year = 1970; 
    }

    *pN = N; 
    return (pDate); 
}

// 3 
struct Date* get_date_array_1(int* pN)
{
    struct Date* pDate = NULL; 
    int N; 
    int i; 

    printf("Enter N"); 
    scanf("%d", &N); 

    if(N <= 0)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    pDate = (struct Date*)malloc(N * sizeof(struct Date)); 
    if(pDate == NULL)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < N; ++i)
    {
        pDate[i].day = 1; 
        pDate[i].month =1; 
        pDate[i].year = 1970; 
    }

    *pN = N; 
    return (pDate); 
}

// 4 
struct Date* get_date_array_1(int* pN)
{
    struct Date* pDate = NULL; 
    int N; 
    int i; 

    printf("Enter N:"); 
    scanf("%d", &N); 

    if(N <= 0)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    pDate = (struct Date*)malloc(N * sizeof(struct Date)); 
    if(pDate == NULL)
    {
        puts("error"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < N; ++i)
    {
        pDate[i].day = 1; 
        pDate[i].month = 1; 
        pDate[i].year = 1970; 
    }

    *pN = N; 
    return (pDate); 
}

// 5 
struct Date* get_date_array_1(int* pN)
{
    struct Date* pDate = NULL; 
    int N; 
    int i; 

    printf("Enter N:"); 
    scanf("%d", &N); 

    if(N <= 0)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    pDate = (struct Date*)malloc(N * sizeof(struct Date)); 
    if(pDate == NULL)
    {
        puts("error"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < N; ++i)
    {
        pDate[i].day = 1; 
        pDate[i].month = 1; 
        pDate[i].year = 1970; 
    }

    *pN = N; 
    return (pDate); 
}

void test_1(void)
{
    struct Date** ppDate = NULL; 
    int N; 
    int i; 

    printf("Enter N:"); 
    scanf("%d", &N); 

    if(N <= 0)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    ppDate = (struct Date**)malloc(N * sizeof(struct Date*)); 
    if(ppDate == NULL)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < N; ++i)
    {
        ppDate[i] = (struct Date*)malloc(sizeof(struct Date)); 
        if(ppDate[i] == NULL)
        {
            puts("Error"); 
            exit(EXIT_FAILURE); 
        }
    }

    for(i = 0; i < N; ++i)
    {
        ppDate[i]->day = 1; 
        ppDate[i]->month = 1; 
        ppDate[i]->year = 1970; 
    }

    for(i = 0; i < N; ++i)
        free(ppDate[i]); 

    free(ppDate); 
    ppDate = NULL; 
}

/* 
    struct Date* a_pDate[5]; 
    type(a_pDate) == type(&a_pDate[0])

    type(a_pDate[0]) == struct Date* ... given by programmer 
    type(&a_pDate[0]) == struct Date** ... derived by logic 

*/

// 2 
void test_2(void)
{
    struct Date** ppDate = NULL; 
    int N; 
    int i; 

    printf("Enter N:"); 
    scanf("%d", &N); 

    if(N <= 0)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    ppDate = (struct Date**)malloc(N * sizeof(struct Date*)); 
    if(ppDate == NULL)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < N; ++i)
    {
        ppDate[i] = (struct Date*)malloc(sizeof(struct Date)); 
        if(ppDate[i] == NULL)
        {
            puts("Error"); 
            exit(EXIT_FAILURE); 
        }
    }

    for(i = 0; i < N; ++i)
    {
        ppDate[i]->day = 1; 
        ppDate[i]->month = 1; 
        ppDate[i]->year = 1970; 
    }

    for(i = 0; i < N; ++i)
        free(ppDate[i]); 

    free(ppDate); 
    ppDate = NULL; 
}

// 3 
void test_3(void)
{
    struct Date** ppDate = NULL; 
    int i; 
    int N; 

    printf("Enter N:"); 
    scanf("%d", &N); 

    if(N <= 0)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    ppDate = (struct Date**)malloc(N * sizeof(struct Date*)); 
    if(ppDate == NULL)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < N; ++i)
    {
        ppDate[i] = (struct Date*)malloc(sizeof(struct Date)); 
        if(ppDate[i] == NULL)
        {
            puts("Error"); 
            exit(EXIT_FAILURE); 
        }
    }

    for(i = 0; i < N; ++i)
    {
        ppDate[i]->day = 1; 
        ppDate[i]->month = 1; 
        ppDate[i]->year = 1970; 
    }

    for(i = 0; i < N; ++i)
        free(ppDate[i]); 

    free(ppDate); 
    ppDate = NULL; 
}

// 4 
void test_4(void)
{
    struct Date** ppDate = NULL; 
    int N; 
    int i; 

    printf("Enter N:"); 
    scanf("%d", &N); 

    if(N <= 0)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    ppDate = (struct Date**)malloc(N * sizeof(struct Date*)); 
    if(ppDate == NULL)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < N; ++i)
    {
        ppDate[i] = (struct Date*)malloc(sizeof(struct Date)); 
        if(ppDate[i] == NULL)
        {
            puts("Error"); 
            exit(EXIT_FAILURE);  
        }
    }

    for(i = 0; i < N; ++i)
        free(ppDate[i]); 

    free(ppDate); 
}

// 5 
void test_5(void)
{
    struct Date** ppDate = NULL; 
    int N; 
    int i; 

    printf("Enter N:"); 
    scanf("%d", &N); 

    if(N <= 0)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    ppDate = (struct Date**)malloc(N * sizeof(struct Date*)); 
    if(ppDate == NULL)
    {
        puts("Error"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < N; ++i)
    {
        ppDate[i] = (struct Date*)malloc(sizeof(struct Date)); 
        if(ppDate[i] == NULL)
        {
            puts("Error"); 
            exit(EXIT_FAILURE); 
        }
    }

    for(i = 0; i < N; ++i)
    {
        ppDate[i]->day = 1; 
        ppDate[i]->month = 1; 
        ppDate[i]->year = 1970; 
    }

    for(i = 0; i < N; ++i)
        free(ppDate[i]); 

    free(ppDate); 
    ppDate = NULL; 
}

struct Date** get_array_of_pointer_to_date_1(int* pN); 
void get_array_of_pointer_to_date_2(struct Date*** pppDate, int* pN); 

struct C
{

}; 

struct B
{
    // member 
    struct C* pC; 
    // member 

}; 

struct A 
{
    // other member 
    struct B* pB; 
    // other ember 
}; 

void test(void)
{
    struct A* pA = malloc(sizeof(struct A)); 

    pA->pB = malloc(sizeof(struct B)); 

    pA->pB->pC = malloc(sizeof(struct C)); 

    pA->pB->pC->mem; 

    free(pA->pB->pC); 
    free(pA->pB); 
    free(pA); 

    pA = NULL; 
}