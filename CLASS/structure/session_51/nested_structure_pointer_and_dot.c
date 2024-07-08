struct B
{
    double x; 
    double y; 
}; 

struct A 
{
    int num; 
    struct B* pB; 
    float fnum; 
}; 

int main(void)
{
    struct B inB; 
    struct A inA; 

    inA.pB = &inB; 

    struct A* pA = &inA; 

    (*(*pA).pB).x; 
    (*(*pA).pB).y; 

    (*pA).num; 
    (*pA).fnum; 
    (*pA).pB; 

    struct B* p = &inB; 

    (*p).x;
    (*p).y;

    (*(*pA).pB).x; 


}


