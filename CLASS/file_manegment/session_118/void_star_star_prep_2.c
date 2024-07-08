/* CALLBACK */

struct A {
    /* some members */
};  

void func(struct A** ppA)
{
    struct A* pA = NULL; 

    pA = malloc(sizeof(struct A)); 
    if(pA == NULL) {/*ERROR HANDLING BLOCK */}

    *ppA = pA; 
}

int main(void)
{
    struct A* pA = NULL; 

    func(&pA); 
}

///////////////////////////////////////////////////////////////////

void allocator_of_A(struct A** ppA)
{

}

void allocator_of_B(struct B** ppB)
{

}

void allocator_of_C(struct C** ppC)
{

}

//////////////////////////////////////////////////////////////
typedef unsigned long long int size_t; 
#define NULL ((void*)0)
void allocator(size_t nmem, void** pp)
{
    void* p = malloc(nmem); 
    if(p == NULL) { 
        puts("Error"); 
        exit(-1); 
    }

    *pp = p; 
}

int main(void)
{
    struct A {int mem; }; 
    struct B {char mem; }; 
    struct C {double mem; };

    struct A* pA = NULL; 
    struct B* pB = NULL; 
    struct C* pC = NULL; 

    allocator(sizeof(struct A), &pA); 
    allocator(sizeof(struct B), &pB); 
    allocator(sizeof(struct C), &pC); 

    /* type(&pA) == struct A**  */
    /* type(&pB) == struct B**  */ 
    /* type(&pC) == struct C**  */
}

/* 
    Let func be a function having void** pp as its formal parameter 

    void func(void** pp)
    {

    }

    void caller(void)
    {
        //
        //    declare a pointer variable of an appropriate type. 
        //    appropriate type -> function, file, program 
        //    T* pT;  where T is a built in or user defined data type 

        func((void**)&pT); 


    }

    pp = &pT; 

    void**  T** 

    pp = (void**)(&pT); 

*/