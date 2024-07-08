#include <stdio.h> 
#include <stdlib.h> 
#include "student.h" 
#include "sort.h"

struct Student st_arr[5] = {
    {2, 89.54, 89.12}, 
    {4, 77.32, 91.23}, 
    {5, 98.3, 99.93}, 
    {3, 74.91, 65.63},
    {1, 72.69, 56.79}  
}; 

int main(void)
{
    show("Before sort:", st_arr, 5); 
    cpa_sort(st_arr, 5, sizeof(struct Student), compare_by_roll); 
    show("After sort by roll:", st_arr, 5); 
    cpa_sort(st_arr, 5, sizeof(struct Student), compare_by_marks); 
    show("After sort by marks:", st_arr, 5); 
    cpa_sort(st_arr, 5, sizeof(struct Student), compare_by_attnd); 
    show("After sort_by_attnd:", st_arr, 5); 
  

    return (EXIT_SUCCESS); 
}

void show(const char* msg, const struct Student* p_st_arr, int N)
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

int compare_by_roll(const struct Student* ps1, const struct Student* ps2)
{
    if(ps1->roll > ps2->roll)
        return (1); 
    else if(ps1->roll < ps2->roll)
        return (-1); 
    else 
        return (0); 
}

int compare_by_marks(const struct Student* ps1, const struct Student* ps2)
{
    if(ps1->marks > ps2->marks)
        return (1); 
    else if(ps1->marks < ps2->marks)
        return (-1); 
    else 
        return (0); 
}

int compare_by_attnd(const struct Student* ps1, const struct Student* ps2)
{
    if(ps1->attnd > ps2->attnd)
        return (1); 
    else if(ps1->attnd < ps2->attnd)
        return (-1); 
    else 
        return (0); 
} 
