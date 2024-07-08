/* This program is not for compilation */

/* Using #define directive to create symbolic constants */

int a[5];   /* 5 is a magic constant here */

struct Date{
    int day, month, year; 
}epoch_date = {1, 1, 1970}; /* reader of the source code must 
                                be aware that 1 is epoch day, 
                                1 is epoch month and 1970 is epoch year*/

/* 
    Principle: Magical (= written in program without any additional explanation)
    constants make code UNREADABLE TO OTHER PROGRAMMERS and to THE PROGRAMMER 
    HIMSELF/HERSELF after some time.   

    We can assign a label so to speak with constant. Label can be an English word 
    and therefore will make code more readable. 

    We could have used variable names! 
    int arr_size = 5; 

    But it will cost memory. Therefore, we make use of the preprocessor directive 
    #define 
*/

/* 
    SYNTAX 

    #define  NAME   REPLACEMENT_STR 

    Preprocessor does two tasks: 
        1) When #define statement is encountered it understands that its a command 
           given by programmer to it. And the command means to define PREPROCESSOR SYMBOL 
           'NAME' with its definition 'REPLACEMENT_STR'. Preprocessor takes note of this definition 

           (analogy: PREPROCESSOR SYMBOL is like variable name in programming language 
           but without memory overhead)

    #define ARR_SIZE 5 
    
    NAME is ARR_SIZE 
    REPLACEMENT_STR 5 

    In step 1 preprocessor simply takes a note that PREPROCESSOR SYMBOL 
    ARR_SIZE is defined and its replacement string is 5. 

        1) Wheenever NAME is encountered in any line of source code then preprocessor 
            replaces OCCURRENCE of NAME in that string by REPLACEMENT_STR. 

        int arr[ARR_SIZE]; 

        int arr[5]; 
*/

#define ARR_SIZE  5 

#define EPOCH_DAY   1 
#define EPOCH_MONTH 1 
#define EPOCH_YEAR  1970 

struct Date 
{
    int day; 
    int month; 
    int year; 
} epoch_date = {EPOCH_DAY, EPOCH_MONTH, EPOCH_YEAR}; 

int main(void) 
{
    int arr[ARR_SIZE]; 
}

#define SUCCESS 1 

struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

int insert_after(struct node* p_head_node, int e_data, int new_data)
{
    struct node* p_e_node = NULL; 

    p_e_node = search_node(p_head_node, e_data); 
    if(p_e_node == NULL)
        return (2); 
    
    generic_insert(p_e_node, get_node(new_data), p_e_node->next); 
    return (1); 
}

#define SUCCESS 1 
#define LIST_INVALID_DATA 2 

int insert_after(sturct node* p_head_node, int e_data, int new_data)
{
    struct node* p_e_node = NULL; 

    p_e_node = search_node(p_head_node, e_data); 
    if(p_e_node == NULL)
        return (LIST_INVALID_DATA); 
    
    generic_insert(p_e_node, get_node(new_data), p_e_node->next); 
    return (SUCCESS); 
}