#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct student 
{
    int roll; 
    double marks; 
    double attnd; 
}; 

void show(const char* msg, struct student* p_st_arr, int N); 

void sort(  
            struct student* arr, 
            int N, 
            int (*compare)(const struct student*, const struct student*)
        ); 

int compare_by_roll(const struct student* ps1, const struct student* ps2); 
int compare_by_marks(const struct student* ps1, const struct student* ps2); 
int compare_by_attnd(const struct student* ps1, const struct student* ps2); 

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
    sort(st_arr, 5, compare_by_roll); 
    show("After sort by roll:", st_arr, 5); 
    sort(st_arr, 5, compare_by_marks); 
    show("After sort by marks:", st_arr, 5); 
    sort(st_arr, 5, compare_by_attnd); 
    show("After sort_by_attnd:", st_arr, 5); 
    puts("DONE UNIFORMLY!"); 

    return (EXIT_SUCCESS); 
}


void sort(  
            struct student* arr, 
            int N, 
            int(*compare)(const struct student*, const struct student*)
        )
{
    int i, j; 
    struct student key; 

    for(j = 1; j < N; ++j)
    {
        // key = arr[j]; 
        memcpy(&key, &arr[j], sizeof(struct student)); 
        i = j - 1; 
        while(i > -1 && compare(&arr[i], &key) > 0)
        {
            // arr[i+1] = arr[i]; 
            memcpy(&arr[i+1], &arr[i], sizeof(struct student)); 
            i = i - 1; 
        }
        // arr[i+1] = key; 
        memcpy(&arr[i+1], &key, sizeof(struct student)); 
    }
}

void show(const char* msg, struct student* p_st_arr, int N)
{
    int i; 

    if(msg)
        puts(msg); 

    for(i = 0; i < N; ++i)
        printf("Roll=%d\tMarks=%.2lf\tAttendance=%.2lf\n", 
                p_st_arr[i].roll, 
                p_st_arr[i].marks, 
                p_st_arr[i].attnd
        ); 
}

int compare_by_roll(const struct student* ps1, const struct student* ps2)
{
    if(ps1->roll > ps2->roll)
        return (1); 
    else if(ps1->roll < ps2->roll)
        return (-1); 
    else 
        return (0); 
}

int compare_by_marks(const struct student* ps1, const struct student* ps2)
{
    if(ps1->marks > ps2->marks)
        return (1); 
    else if(ps1->marks < ps2->marks)
        return (-1); 
    else 
        return (0); 
}

int compare_by_attnd(const struct student* ps1, const struct student* ps2)
{
    if(ps1->attnd > ps2->attnd)
        return (1); 
    else if(ps1->attnd < ps2->attnd)
        return (-1); 
    else 
        return (0); 
} 

///////////////////////////////////////////////////////////////////