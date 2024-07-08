/* 
    Second application of macro. 

    In macro_application_1.c file we saw how macro can be used 
    to produce generic definition of small functions (functions with small body)
    but at the cost of type safety. 

    We can say that whatever we can achieve using macro can be achieved using 
    function but we will have to produce different function versions for different 
    types. 

    But second application of macro does something which cannot be achieved by 
    writing function. 

    1) Functions CANNOT ACCEPT type name as actual parameter. 

    But macros can accept type names as arguments. Because macro is not 
    constrained by C language rules. 

*/

#define DEFINE_VAR(T, name)     T name 

#define DEFINE_NODE(type)   struct node_##type\
                            {\
                                type data;\
                                struct node_##type* prev;\
                                struct node_##type* next;\
                            } 
                                
struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

DEFINE_NODE(int);
DEFINE_NODE(float); 

int main(void)
{
    DEFINE_VAR(int, n);                     /* int n; */
    DEFINE_VAR(float, f);                   /* float f; */
    DEFINE_VAR(struct Date, d_instance);    /* struct Date d_instance; */
    return (0); 
}

#define DEFINE_NODE()   struct node\
                        {\
                            int data; \
                            struct node* prev;\
                            struct node* next;\
                        };

DEFINE_NODE();                        

struct node_int
{
    int data; 
    struct node_int* prev; 
    struct node_int* next; 
}; 

struct node_char 
{
    char data; 
    struct node_char* prev; 
    struct node_char* next; 
}; 

struct node_float 
{
    float data; 
    struct node_float* prev; 
    struct node_float* next; 
}; 