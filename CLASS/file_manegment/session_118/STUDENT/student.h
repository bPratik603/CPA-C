#ifndef _STUDENT_H 
#define _STUDENT_H 

struct Student 
{
    int roll; 
    double marks; 
    double attnd; 
}; 

void show(const char* msg, const struct Student* p_st_arr, int N); 
int compare_by_roll(const struct Student* ps1, const struct Student* ps2); 
int compare_by_marks(const struct Student* ps1, const struct Student* ps2); 
int compare_by_attnd(const struct Student* ps1, const struct Student* ps2); 

#endif /* _STUDENT_H */