#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    int roll;
    double marks;
    double attnd;
};

struct student st_arr[5] = {
    {5,77.96,90.00},
    {2,89.55,78.23},
    {3,56.77,45.88},
    {1,75.12,89.98},
    {4,67.78,56.55}
    };

void show(const char* msg,struct student* p_st_arr,int N);

void sort(struct student* p_st_arr,int N,
          int (*compare)(struct student*,struct student*));

int compare_by_roll(struct student* ps1,struct student* ps2);






int main(void)
{
    show("Before sort",st_arr,5);
    sort(st_arr,5,compare_by_roll);
}

void sort(struct student* p_st_arr,int N,
           int (*compare)(struct student* ps1,struct student* ps2))
{
    int i,j;
    struct student* key;
    for(j=0;j<N;++j)
    {
        memcpy(&key,&p_st_arr[i],sizeof(struct student));
        i = j-1;
        while(i > -1 && compare(&p_st_arr[i],&key) > 0)
        {
            
        }
    }
}


void show(const char* msg,struct student* p_st_arr,int N)
{
    int i;
    if(msg)
    {
        puts(msg);
    }

    for(i=0;i<N;++i)
    {
        printf("Roll=%d\tMarks=%d\tAttendance=%d\n",
               p_st_arr[i].roll,p_st_arr[i].marks,p_st_arr[i].attnd);
    }
}

int compare_by_roll(struct student* ps1,struct student* ps2)
{
    if(ps1->roll > ps2->roll)
    {
        return(1);
    }
    else if(ps1->roll < ps2->roll)
    {
        return(-1);
    }
    else
    {
        return(0);
    }
}