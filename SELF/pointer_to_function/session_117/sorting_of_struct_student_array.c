#include <stdio.h> 
#include <stdlib.h> 

struct student 
{
    int st_roll; 
    double st_marks; 
    double st_attnd; 
}; 

void show(const char* msg, struct student* p_st_arr, int N); 
void sort_by_roll(struct student* p_st_arr, int N); 
void sort_by_attnd(struct student* p_st_arr, int N); 
void sort_by_marks(struct student* p_st_arr, int N); 

struct student st_arr[5] = {
    {2, 89.54, 89.12}, 
    {4, 77.32, 91.23}, 
    {5, 98.3, 99.93}, 
    {3, 74.91, 65.63},
    {1, 72.69, 56.79}  
}; 

int main(void) 
{
    show("Before sort:", st_arr, 5); 
    sort_by_roll(st_arr, 5); 
    show("After sort by roll:", st_arr, 5); 
    sort_by_marks(st_arr, 5); 
    show("After sort by marks:", st_arr, 5); 
    sort_by_attnd(st_arr, 5); 
    show("After sort_by_attnd:", st_arr, 5); 

    return (EXIT_SUCCESS); 
}

void show(const char* msg, struct student* p_st_arr, int N)
{
    int i; 

    if(msg)
        puts(msg); 

    for(i = 0; i < N; ++i)
        printf("Roll=%d\tMarks=%.2lf\tAttendance=%.2lf\n", 
                p_st_arr[i].st_roll, 
                p_st_arr[i].st_marks, 
                p_st_arr[i].st_attnd
        ); 
}

void sort_by_roll(struct student* p_st_arr, int N)
{
    int i, j; 
    struct student key; 

    for(j = 1; j < N; ++j)
    {
        key.st_roll  = p_st_arr[j].st_roll; 
        key.st_marks = p_st_arr[j].st_marks; 
        key.st_attnd = p_st_arr[j].st_attnd; 
        
        i = j - 1; 

        while(i > -1 && p_st_arr[i].st_roll > key.st_roll)
        {
            // memcpy(p_st_arr + i + 1, p_st_arr + i, sizeof(struct student)); 
            p_st_arr[i+1].st_roll = p_st_arr[i].st_roll; 
            p_st_arr[i+1].st_marks = p_st_arr[i].st_marks; 
            p_st_arr[i+1].st_attnd = p_st_arr[i].st_attnd; 
            i = i - 1; 
        }

        p_st_arr[i+1].st_roll  = key.st_roll; 
        p_st_arr[i+1].st_marks = key.st_marks; 
        p_st_arr[i+1].st_attnd = key.st_attnd; 
        
    }
}

void sort_by_marks(struct student* p_st_arr, int N)
{
    int i, j; 
    struct student key; 

    for(j = 1; j < N; ++j)
    {
        key.st_roll  = p_st_arr[j].st_roll; 
        key.st_marks = p_st_arr[j].st_marks; 
        key.st_attnd = p_st_arr[j].st_attnd; 
        
        i = j - 1; 

        while(i > -1 && p_st_arr[i].st_marks > key.st_marks)
        {
            // memcpy(p_st_arr + i + 1, p_st_arr + i, sizeof(struct student)); 
            p_st_arr[i+1].st_roll = p_st_arr[i].st_roll; 
            p_st_arr[i+1].st_marks = p_st_arr[i].st_marks; 
            p_st_arr[i+1].st_attnd = p_st_arr[i].st_attnd; 
            i = i - 1; 
        }

        p_st_arr[i+1].st_roll  = key.st_roll; 
        p_st_arr[i+1].st_marks = key.st_marks; 
        p_st_arr[i+1].st_attnd = key.st_attnd; 
        
    }
}

void sort_by_attnd(struct student* p_st_arr, int N)
{
    int i, j; 
    struct student key; 

    for(j = 1; j < N; ++j)
    {
        key.st_roll  = p_st_arr[j].st_roll; 
        key.st_marks = p_st_arr[j].st_marks; 
        key.st_attnd = p_st_arr[j].st_attnd; 
        
        i = j - 1; 

        while(i > -1 && p_st_arr[i].st_attnd > key.st_attnd)
        {
            // memcpy(p_st_arr + i + 1, p_st_arr + i, sizeof(struct student)); 
            p_st_arr[i+1].st_roll = p_st_arr[i].st_roll; 
            p_st_arr[i+1].st_marks = p_st_arr[i].st_marks; 
            p_st_arr[i+1].st_attnd = p_st_arr[i].st_attnd; 
            i = i - 1; 
        }

        p_st_arr[i+1].st_roll  = key.st_roll; 
        p_st_arr[i+1].st_marks = key.st_marks; 
        p_st_arr[i+1].st_attnd = key.st_attnd; 
        
    }
}

void insertion_sort(int* arr, int N)
{
    int i, j; 
    int key; 

    for(j = 1; j < N; ++j)
    {
        key = arr[j]; 
        i = j - 1;  
        while(i > -1 && arr[i] > key)
        {
            arr[i+1] = arr[i]; 
            i = i - 1; 
        }
        arr[i+1] = key; 
    }
}

