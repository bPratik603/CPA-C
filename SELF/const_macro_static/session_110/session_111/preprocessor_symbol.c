/* 
    C Programming Language -> Variables: 
    Preprocessor -> Symbol 

    C Lang : data definition statement is a way to introduce 
    new variable name 

    Preprocessor -> #define is a way to define new symbol 
    Preprocessor internally maintains the list of all symbols 
    that are defined along with their definition. 

    In extrement case a symbol MAY NOT Have any definition 
*/

#define ARR_SIZE    5 
/* Preprocessor internally stores symbol named ARR_SIZE with 5 as its definition */

#define MAX(a, b)   ((a) > (b) ? (a) : (b))
/* Preprocessor internally stores symbol named MAX with  ((a) > (b) ? (a) : (b)) 
    as its definition. Preprocessor, moreover, stores that MAX is a macro 
    and has a and b as its parametes*/

#define X 
/* 
    Preprocessor internally stores symbol named X with no definition 
    But X will be a defined symbol 
*/

/* 
    It is possible to un-define a preprocessor symbol. 
    
    This makes it different than C variable. 
    C variable cannot be undefined. Storage associated 
    with C variable gets deallocated when control flow 
    of program goes outside the scope of the definition 
*/

/* Undefine Preprocessor symbol X */
#undef X

/* 
    Subsequent C source code cannot contain preprocessor symbol X 
    and even if its used it will not be expanded to its definition 
    by preprocessor as it has been asked to undefine it 
*/

#undef ARR_SIZE 

#undef MAX 

/* 
    #define V 
    #undef V 

#define has three options 

1) Only define symbol with no definition 
#define V 

2) Define symbol with definition (but no parameter)
    i.e. Preprocessor symbol is being used as symbolic constant 
    but not as macro 

#define V   <constant> 

3) Define symbol with definition and parameters 
    i.e. define macro 

#define V(p1,  , pn)    DEFINITION(INVOLVING p1, ,pn)

Symbol V defined in all three cases can be undefined using a single line 

#undef V 


*/