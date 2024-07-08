#include <stdio.h> 
#include <stdlib.h> 

void built_in_data_type(void); 
void array_of_builtin_data_type(void); 
void user_defined_data_type(void); 

struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

int main(void) 
{
    built_in_data_type(); 
    array_of_builtin_data_type(); 
    user_defined_data_type(); 

    return (0); 
}

void built_in_data_type(void)
{
    float* fp = 0; 

    fp = (float*)malloc(sizeof(float)); 
    if(fp == 0)
    {
        puts("Memory allocation failed"); 
        exit(EXIT_FAILURE); 
    }

    printf("Enter a fractional number:"); 
    scanf("%f", fp); 

    printf("Entered Number = %.2f\n", *fp); 

    free(fp); 
    fp = 0; 
}

void array_of_builtin_data_type(void)
{
    int* p_array = 0; 
    unsigned int size = 0; 
    unsigned int i; 

    printf("Enter size of array:"); 
    scanf("%u", &size); 

    if(size <= 0)
    {
        puts("Array size must be positive"); 
        exit(EXIT_FAILURE); 
    }

    p_array = (int*)malloc(size * sizeof(int)); //if size8 =4,4,4,4,4,4,4
    if(p_array == 0)
    {
        puts("Memory allocation failed"); 
        exit(EXIT_FAILURE); 
    }

    for(i=0; i < size; ++i)
    {
        printf("Enter data value for index %d:", i); 
        scanf("%u", p_array + i); //a[i],but values not addres
    }

    for(i=0; i < size; ++i)    
        printf("*(p_array + %u) = %u\n", i, *(p_array + i)); 

    free(p_array); 
    p_array = 0; 
}

void user_defined_data_type(void)
{
    struct Date* p = 0; 

    p = (struct Date*)malloc(sizeof(struct Date)); 
    if(p == 0)
    {
        puts("Memory allocation failed"); 
        exit(EXIT_FAILURE); 
    }

    p->day = 1;     //(*p).day
    p->month = 1; 
    p->year = 1970; 

    printf("EPOCH:%d-%d-%d\n", p->day, p->month, p->year); 

    free(p); 
    p = 0; 
}