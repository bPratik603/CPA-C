#include "lib.h"

struct student s;

int main(void)
{
    s.size = sizeof(struct student);
    s.mask = ST_ALL;
    s.i_roll = 10;
    s.i_attnd = 70;
    s.i_marks = 80;

    set(&s);

    s.mask = ST_ROLL | ST_MARKS;
    get(&s);
    show(&s);

    return(0);
}